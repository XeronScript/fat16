#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define SECTOR_SIZE 512
#define CEIL(x, y) ( ((x) / (y)) + (((x) % (y)) != 0) )


void get_fat16_chain(struct clusters_chain_t* dest, const void * const buffer, size_t size, uint16_t first_cluster)
{
    if (size == 0 || !buffer || first_cluster > size/2) return;

    // Counting clusters
    uint16_t i = first_cluster;
    int tab_size = 1;
    while ( *((uint16_t*)buffer + i) != 0 && *((uint16_t*)buffer + i) != 0xff )
    {
        if ( *((uint16_t*)buffer + i) == 0 ) break;
        i = *((uint16_t*)buffer + i);
        if (i > size/2) break;
        tab_size++;
    }

    dest->clusters = malloc(tab_size * sizeof(uint16_t));
    *(dest->clusters) = first_cluster;
    dest->size = 1;
    uint16_t next_cluster = *((uint16_t*)buffer + first_cluster);
    if ( !next_cluster || next_cluster > size/2 ) return;

    i = 1;
    while (1)
    {
        *(dest->clusters + i) = next_cluster;
        dest->size++;

        if (*((uint16_t*)buffer + next_cluster) == 0 )
            return;

        i++;
        next_cluster = *((uint16_t*)buffer + next_cluster);
        if (next_cluster > size/2) return;
    }
}

void trim_filename(const char* filename, char* dest)
{
    uint8_t j = 0, i = 0;

    for (; i < 8; ++i)
        if ( *(filename + i) == 0x20 )
            break;

    for (; j < 3; ++j)
        if ( *(filename + 8 + j ) == 0x20 )
            break;

    memset(dest, 0, strlen(dest));
    strncpy(dest, filename, i);
    if (j != 0) {
        strcat(dest, ".");
        strncat(dest, filename + 8, j);
    }
}

void all_to_upper(const char* src, char* dest)
{
    memset(dest, 0, strlen(dest));
    for (size_t i = 0; i < strlen(src); ++i)
        *(dest + i) = (char) toupper(*(src + i));
}

int count_higher_tier_callbacks(const char *filename)
{
    size_t len = strlen(filename);
    if (*(filename + len - 1) == '.' || *(filename + len - 1) == '\\')
        return -1;

    int i = 0, counter = 0;
    while (*(filename + i) != '\0')
    {
        if (*(filename + i) == '.')
            if (i != (uint8_t)strlen(filename) - 1 && *(filename + i + 1) == '.')
                counter++;
        i++;
    }
    return counter;
}

int count_child_callbacks(const char *filename)
{
    size_t len = strlen(filename);
    if (*(filename + len - 1) == '.' || *(filename + len - 1) == '\\')
        return -1;

    int i = 0, child_dirs_count = 0;
    int flag = 1;
    while (*(filename + i) != '\0')
    {
        if (*(filename + i) == '\\')
            flag = 1;
        if (isalpha(*(filename + i)) && flag)
        {
            child_dirs_count++;
            flag = 0;
        }
        i++;
    }
    return child_dirs_count;
}

int validate_filename(const char* filename, int* total_dirs)
{
    const char str[] = "\\";
    if ( strcmp(filename, str) == 0 ) return 0;

    size_t len = strlen(filename);
    if ( *(filename + len - 1) == '.' || *(filename + len - 1) == '\\' )
        return -1;

    int prev = count_higher_tier_callbacks(filename);
    if (prev == -1) return prev;

    int next = count_child_callbacks(filename);
    if (next == -1) return next;

    int i = 0;
    int flag = 1;
    *total_dirs = 0;
    while ( *(filename + i) != '\0' )
    {
        if (*(filename + i) == '\\')
            flag = 1;
        if ( (isalpha(*(filename + i)) || *(filename + i) == '.') && flag)
        {
            (*total_dirs)++;
            flag = 0;
        }
        i++;
    }

    return prev < next ? 0 : -1;
}

void read_dirs(const char *filename, char ***dirs, int* actual_dirs)
{
    char* temp_filename = malloc(strlen(filename) + 1);
    memset(temp_filename, 0, strlen(filename) + 1);
    strcat(temp_filename, filename);
    const char delim[] = "\\";
    char* temp = strtok(temp_filename, delim);

//    size_t i = 0;
    size_t dir_len;
    *actual_dirs = 0;

    while (temp != NULL)
    {
        dir_len = strlen(temp);
        *(*dirs + *actual_dirs) = malloc(dir_len * sizeof(char) + 1);
        memset(*(*dirs + *actual_dirs), 0, dir_len + 1 );
        strcpy(*(*dirs + *actual_dirs), temp);

        if ( strcmp(temp, ".") == 0 ) {
            free(*(*dirs + *actual_dirs));
        }
        else if ( strcmp(temp, "..") == 0 ) {
            free(*(*dirs + *actual_dirs));
            free(*(*dirs + *actual_dirs - 1));
            (*actual_dirs)--;
        }
        else {
            (*actual_dirs)++;
        }
        temp = strtok(NULL, delim);
    }
    free(temp_filename);
}

void free_dirs(char ***dirs, int len)
{
    int i = 0;
    for (; i < len; ++i)
        free(*(*dirs + i));

    // free(*(*dirs + i));
    free(*dirs);
}

//==============================================================================================
//==========================================   DISK   ==========================================
//==============================================================================================
struct disk_t* disk_open_from_file(const char* volume_file_name)
{
    if (!volume_file_name) {
        errno = EFAULT;
        return NULL;
    }

    struct disk_t* disk = malloc(sizeof(struct disk_t));
    if (!disk) {
        errno = ENOMEM;
        return NULL;
    }

    // Opening disk
    disk->fdisk = fopen(volume_file_name, "rb");
    if (!disk->fdisk) {
        free(disk);
        errno = ENOENT;
        return NULL;
    }

    return disk;
}

int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read)
{
    if (!pdisk || !buffer || !pdisk->fdisk) { errno = EFAULT; return -1; }
    if (!sectors_to_read) return 0;

    uint8_t buff[SECTOR_SIZE];
    uint32_t sectors_amount;

    fseek(pdisk->fdisk, 0, SEEK_SET);
    fread((void*)buff, SECTOR_SIZE, 1, pdisk->fdisk);
    sectors_amount = *(uint16_t*)((char*)buff + 19) == 0
            ? *(uint32_t*)((char*)buff + 32)
            : *(uint16_t*)((char*)buff + 19);

    if (sectors_amount < (uint32_t)(first_sector + sectors_to_read)) {
        errno = ERANGE;
        return -1;
    }

    fseek(pdisk->fdisk, first_sector * SECTOR_SIZE, SEEK_SET);
    fread(buffer, SECTOR_SIZE, sectors_to_read, pdisk->fdisk);

    return sectors_to_read;
}
int disk_close(struct disk_t* pdisk)
{
    if (!pdisk || !pdisk->fdisk) { errno = EFAULT; return -1; }
    fclose(pdisk->fdisk);
    free(pdisk);
    return 0;
}


//==============================================================================================
//=========================================   VOLUMES   ========================================
//==============================================================================================
struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector)
{
    if (!pdisk || !pdisk->fdisk) {
        errno = EFAULT;
        return NULL;
    }

    struct volume_t* volume = malloc(sizeof(struct volume_t));
    if (!volume) {
        errno = ENOMEM;
        return NULL;
    }

    volume->super_fat = malloc(sizeof(struct super_fat_t));
    if (!volume->super_fat) {
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    volume->disk = pdisk;
    int v = disk_read(pdisk, (int32_t)first_sector, volume->super_fat, 1);
    if (v == -1) {
        free(volume->super_fat);
        free(volume);
        return NULL;
    }

    //======================================== Walidacja super sectora =======================================
    if ( (volume->super_fat->reserved_sectors == 0 || (volume->super_fat->fat_count != 1 && volume->super_fat->fat_count != 2))
         || (volume->super_fat->root_dir_capacity * sizeof(struct entry_t) % volume->super_fat->bytes_per_sector != 0)
         || (volume->super_fat->logical_sectors16 == 0 && volume->super_fat->logical_sectors32 == 0)
         || (volume->super_fat->logical_sectors16 == 0 && volume->super_fat->logical_sectors32 <= 65535)
         || (volume->super_fat->logical_sectors16 != 0 && volume->super_fat->logical_sectors32 > 65535)
         || (volume->super_fat->logical_sectors16 != 0 && volume->super_fat->logical_sectors32 != 0)
         || (volume->super_fat->media_id != 0x80 && volume->super_fat->media_id != 0x00)
         || (volume->super_fat->ext_bpb_signature != 0x29 && volume->super_fat->ext_bpb_signature != 0x28)
         || (volume->super_fat->signature_value != 0xaa55)
         || (volume->super_fat->bytes_per_sector == 0) )
    {
        free(volume->super_fat);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    // Sprawdzanie poprawności wartości sektorów per klaster
    uint8_t mask = 1, flag = 0;

    for (int i = 0; mask != 0 && i < 8; mask <<= 1, ++i)
        if (mask == volume->super_fat->sectors_per_cluster) flag++;

    if (flag != 1) {
        free(volume->super_fat);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    //======================= Wypełnianie struktury woluminu =======================
    volume->fat_start = first_sector + volume->super_fat->reserved_sectors;
    volume->root_dir_start = volume->fat_start + volume->super_fat->sectors_per_fat * volume->super_fat->fat_count;
    volume->sectors_per_root = CEIL(volume->super_fat->root_dir_capacity * sizeof(struct entry_t), volume->super_fat->bytes_per_sector);
    volume->root_size_in_bytes = volume->sectors_per_root * volume->super_fat->bytes_per_sector;
    volume->data_start = volume->root_dir_start + volume->sectors_per_root;

    uint32_t logical_sectors = volume->super_fat->logical_sectors16 != 0
            ? volume->super_fat->logical_sectors16
            : volume->super_fat->logical_sectors32;

    volume->available_clusters = (uint32_t) (( logical_sectors - volume->super_fat->reserved_sectors
            - volume->super_fat->fat_count * volume->super_fat->sectors_per_fat
            - volume->sectors_per_root ) / volume->super_fat->sectors_per_cluster);

    volume->fat_entry_count = volume->available_clusters + 2;

    volume->fat = malloc(volume->fat_entry_count * sizeof(uint16_t));
    if (!volume->fat) {
        free(volume->super_fat);
        free(volume);
        errno = ENOMEM;
        return NULL;
    }

    v = disk_read(volume->disk, (int32_t)volume->fat_start, volume->fat, volume->super_fat->sectors_per_fat);
    if (v == -1) {
        free(volume->fat);
        free(volume->super_fat);
        free(volume);
        return NULL;
    }


    return volume;
}
int fat_close(struct volume_t* pvolume)
{
    if (!pvolume || !pvolume->disk->fdisk || !pvolume->super_fat ||
        !pvolume->disk || !pvolume->fat)
    {
        errno = EFAULT;
        return -1;
    }

    free(pvolume->super_fat);
    free(pvolume->fat);
    free(pvolume);

    return 0;
}


//==============================================================================================
//==========================================  FILES  ===========================================
//==============================================================================================
struct file_t* file_open(struct volume_t* pvolume, const char* file_name)
{
    // Data validation
    if (!pvolume || !file_name) {
        errno = EFAULT;
        return NULL;
    }
    int total_dirs;
    int valid = validate_filename(file_name, &total_dirs);
    if (valid == -1) {
        errno = ENOENT;
        return NULL;
    }

    //-----------------------------
    //------- OPENING FILE --------
    //-----------------------------
    char** dirs = malloc(total_dirs * sizeof(char*));
    int actual_dirs;
    read_dirs(file_name, &dirs, &actual_dirs);

    struct file_t* file = malloc(sizeof(struct file_t));
    if (!file) {
        errno = ENOMEM;
        return NULL;
    }

    file->volume = pvolume;
    file->entry = malloc(sizeof(struct entry_t));
    file->clusters_chain = malloc(sizeof(struct clusters_chain_t));

    uint8_t* root = malloc(file->volume->root_size_in_bytes);
    disk_read(file->volume->disk, (int32_t) file->volume->root_dir_start, root, (int32_t) file->volume->sectors_per_root);

    //===> Looping through root_dir to find first directory <====//
    int i;
    char name[13] = {0}, to_cmp[13] = {0};
    for (i = 0; i < file->volume->super_fat->root_dir_capacity; ++i)
    {
        memcpy(file->entry, root + i * sizeof(struct entry_t), sizeof(struct entry_t));
        if ( *(uint8_t*)file->entry == 0xe5 ) continue;
        if ( *(uint8_t*)file->entry == 0x00 ) break;
        trim_filename(file->entry->name, name);
        all_to_upper(*dirs, to_cmp);

        if ( strcmp(name, to_cmp) == 0 )
            break;
    }
    free(root);

    //====> Looping through nested directories <====//
    uint32_t fat_size = file->volume->super_fat->sectors_per_fat * file->volume->super_fat->bytes_per_sector;
    uint32_t cluster_size = file->volume->super_fat->sectors_per_cluster * file->volume->super_fat->bytes_per_sector;
    struct clusters_chain_t chain = {0};
    for (i = 1; i < actual_dirs; ++i)
    {
        // Reading directory's clusters
        get_fat16_chain(&chain, file->volume->fat, fat_size, file->entry->starting_cluster);
        uint8_t* dirs_cluster = malloc(cluster_size * chain.size);
        for (size_t j = 0; j < chain.size; ++j)
        {
            int32_t first_sector =
                    file->volume->data_start + (chain.clusters[j] - 2) * file->volume->super_fat->sectors_per_cluster;
            int32_t sectors_to_read = file->volume->super_fat->sectors_per_cluster;
            disk_read(file->volume->disk, first_sector, dirs_cluster + j * cluster_size, sectors_to_read);
        }

        // Checking if current directory exists in current path
        int j = 0;
        while ( *(uint8_t*)(file->entry) != 0x00 )
        {
            memcpy(file->entry, dirs_cluster + j * sizeof(struct entry_t), sizeof(struct entry_t));
            j++;
            if ( *(uint8_t*)file->entry == 0xe5 ) continue;
            trim_filename(file->entry->name, name);
            all_to_upper(*(dirs + i), to_cmp);

            if ( strcmp(name, to_cmp) == 0 ) {
                free(dirs_cluster);
                free(chain.clusters);
                break;
            }
        }
        if ( *(uint8_t*)file->entry == 0x00 ) {
            free(dirs_cluster);
            free(chain.clusters);
            break;
        }
    }

    // Validating parsed data
    if (i == file->volume->super_fat->root_dir_capacity || *(uint8_t*)file->entry == 0x00 ) {
        errno = ENOENT;
        free(file->clusters_chain);
        free(file->entry);
        free(file);
        free_dirs(&dirs, actual_dirs);
        return NULL;
    }
    if (file->entry->file_attributes == 0x10 || file->entry->file_size == 0) {
        errno = EISDIR;
        free(file->clusters_chain);
        free(file->entry);
        free(file);
        free_dirs(&dirs, actual_dirs);
        return NULL;
    }


    // Filling file's struct
    get_fat16_chain(file->clusters_chain, file->volume->fat, fat_size, file->entry->starting_cluster);
    file->current_position = 0;
//    file->curr_sector = 1;
    file->curr_cluster = 1;
    file->cluster_buff = malloc(cluster_size);
    int first_sector = file->volume->data_start + (file->clusters_chain->clusters[0] - 2) * file->volume->super_fat->sectors_per_cluster;
    disk_read(file->volume->disk, first_sector, file->cluster_buff, file->volume->super_fat->sectors_per_cluster);
//    int32_t first_sector = file->volume->data_start + (file->clusters_chain->clusters[0] - 2) * file->volume->super_fat->sectors_per_cluster;
//    file->cluster_buff = malloc(file->volume->super_fat->bytes_per_sector);
//    disk_read(file->volume->disk, first_sector, file->cluster_buff, 1);


    free_dirs(&dirs, actual_dirs);
    return file;
}
int file_close(struct file_t* stream)
{
    if (!stream) {
        errno = EFAULT;
        return -1;
    }
    free(stream->clusters_chain->clusters);
    free(stream->clusters_chain);
    free(stream->cluster_buff);
    free(stream->entry);
    free(stream);

    return 0;
}
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream)
{
    if (!ptr || !stream || !size || !nmemb) {
        errno = EFAULT;
        return -1;
    }
    if (stream->current_position > stream->entry->file_size) {
        errno = ENXIO;
        return -1;
    }

    uint8_t sectors_per_cluster = stream->volume->super_fat->sectors_per_cluster;
    uint32_t cluster_size = sectors_per_cluster * stream->volume->super_fat->bytes_per_sector;
    uint16_t sector_size = stream->volume->super_fat->bytes_per_sector;
    uint32_t abs_iter = 0;
    uint32_t res = 0;

    if (size > cluster_size && nmemb == 1)
    {
        int sectors_per_user_size = CEIL(size, sector_size);
        int clusters_per_user_size = CEIL(sectors_per_user_size, sectors_per_cluster);
        uint8_t* file_buff = malloc(stream->entry->file_size);

        for (int i = 0; i < clusters_per_user_size; ++i)
        {
            int first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[i] - 2) * sectors_per_cluster;
            disk_read(stream->volume->disk, first_sector, file_buff + i * cluster_size, sectors_per_cluster);
        }

        memcpy( (char*)ptr, file_buff, size);
        free(file_buff);
        return 1;
    }

//    for (size_t i = 0; i < stream->clusters_chain->size; ++i) {
//        int32_t first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[i] - 2) * sectors_per_cluster;
//        int v = disk_read(stream->volume->disk, first_sector, cluster_buff + i * cluster_size, sectors_per_cluster);
//        if (v == -1) {
//            errno = ERANGE;
//            free(cluster_buff);
//            return -1;
//        }
//    }

    // Reading file
    while (nmemb != 0) //j < cluster_size * stream->clusters_chain->size &&
    {
        if (stream->current_position + size == cluster_size * stream->curr_cluster)
        {
            memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, size);
            abs_iter += size;
            stream->current_position += size;
            nmemb--;
            res++;

            int32_t first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[stream->curr_cluster] - 2) * sectors_per_cluster;
            disk_read(stream->volume->disk, first_sector, stream->cluster_buff, sectors_per_cluster);
            stream->curr_cluster++;
        }
        else if (stream->current_position + size > cluster_size * stream->curr_cluster)
        {
            if (stream->current_position > cluster_size * stream->curr_cluster)
            {
                int32_t first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[stream->curr_cluster] - 2) * sectors_per_cluster;
                disk_read(stream->volume->disk, first_sector, stream->cluster_buff, sectors_per_cluster);
                stream->curr_cluster++;

                memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, size);
                abs_iter += size ;
                stream->current_position += size;
                nmemb--;
                res++;
            }
            else if (stream->current_position <= cluster_size * stream->curr_cluster)
            {
                size_t gap = cluster_size * stream->curr_cluster - stream->current_position;
                memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, gap );
                abs_iter += gap;
                stream->current_position += gap;

                int32_t first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[stream->curr_cluster] - 2) * sectors_per_cluster;
                disk_read(stream->volume->disk, first_sector, stream->cluster_buff, sectors_per_cluster);
                stream->curr_cluster++;

//                if (stream->current_position + (size - gap) > cluster_size * stream->curr_cluster) {}
                memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, size - gap);
                abs_iter += size - gap;
                stream->current_position += size;
                nmemb--;
                res++;
            }
//            size_t gap = cluster_size * stream->curr_cluster - stream->current_position;
//            memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, gap );
//            abs_iter += gap;
//            stream->current_position += size;
//
//            int32_t first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[stream->curr_cluster] - 2) * sectors_per_cluster;
//            disk_read(stream->volume->disk, first_sector, stream->cluster_buff, sectors_per_cluster);
//            stream->curr_cluster++;
//
//            memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, size - gap);
//            abs_iter += size - gap;
//            stream->current_position += size;
//            nmemb--;
//            res++;
//
//            continue;
        }

        // If our current_position exceeded current sector's size
//        if (stream->current_position >= cluster_size * stream->curr_cluster)
//        {
//            stream->curr_cluster = (uint8_t) (stream->curr_sector / sectors_per_cluster);
//            disk_read(stream->volume->disk, first_sector, stream->cluster_buff, 1);
//            stream->curr_sector++;
//
//            int32_t first_sector = stream->volume->data_start + (stream->clusters_chain->clusters[stream->curr_cluster] - 2) * sectors_per_cluster;
//            disk_read(stream->volume->disk, first_sector, stream->cluster_buff, sectors_per_cluster);
//            stream->curr_cluster++;
//        }

        // If we don't have as much data in our file as user want
        if (stream->current_position + size > stream->entry->file_size)
        {
            uint32_t end_gap = stream->entry->file_size - stream->current_position;
            memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, end_gap);
            stream->current_position += end_gap;
            return res;
        }

        // Reading data from current sector
        memcpy( (char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, size);

        nmemb--;
        abs_iter += size;
        stream->current_position += size;
        res++;
    }
    // Condition on which user want to read more data than file has left
//    if (stream->current_position + size > stream->entry->file_size)
//    {
//        uint32_t end_gap = stream->entry->file_size - stream->current_position;
//        memcpy((char*)ptr + abs_iter, stream->cluster_buff + stream->current_position % cluster_size, end_gap);
//
//        stream->current_position += end_gap;
//    }

//    free(cluster_buff);
    return res;
}
int32_t file_seek(struct file_t* stream, int32_t offset, int whence)
{
    if (!stream) {
        errno = EFAULT;
        return -1;
    }
    if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) {
        errno = EINVAL;
        return -1;
    }


    if (whence == SEEK_SET)
    {
        stream->current_position = offset;
        if (stream->current_position > stream->entry->file_size) {
            errno = ENXIO;
            return -1;
        }

        return (int32_t) stream->current_position;
    }
    else if (whence == SEEK_CUR)
    {
        stream->current_position += offset;
        if (stream->current_position > stream->entry->file_size) {
            errno = ENXIO;
            return -1;
        }

        return (int32_t) stream->current_position;
    }
    else
    {
        stream->current_position = stream->entry->file_size + offset;
        if (stream->current_position > stream->entry->file_size) {
            errno = ENXIO;
            return -1;
        }

        return (int32_t) stream->current_position;
    }
}


//==============================================================================================
//=======================================   DIRECTORIES   ======================================
//==============================================================================================
struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path)
{
    // Data validation
    if (!pvolume || !dir_path) {
        errno = EFAULT;
        return NULL;
    }
    int total_dirs;
    int valid = validate_filename(dir_path, &total_dirs);
    if (valid == -1) {
        errno = ENOENT;
        return NULL;
    }

    //----------------------------------
    //------- OPENING DIRECTORY --------
    //----------------------------------
    struct dir_t* dir = calloc(1, sizeof(struct dir_t));
    if (!dir) {
        errno = ENOMEM;
        return NULL;
    }
    dir->volume = pvolume;
    dir->curr_entry = 0;

    // Reading root directory to temp variable
    dir->clusters_chain = malloc(sizeof(struct clusters_chain_t));
    uint8_t* root = calloc(1, pvolume->root_size_in_bytes);
    disk_read(dir->volume->disk, (int32_t) dir->volume->root_dir_start, root, (int32_t) dir->volume->sectors_per_root);

    dir->entry = calloc(1, sizeof(struct entry_t));
    if ( strcmp(dir_path, "\\") == 0 )
    {
        free(dir->clusters_chain);
        free(root);
        dir->is_root = 1;
        return dir;
    }

    char** dirs = malloc(total_dirs * sizeof(char*));
    int actual_dirs;
    read_dirs(dir_path, &dirs, &actual_dirs);

    //===> Looping through root_dir to find first directory <====//
    int i;
    char name[13] = {0}, to_cmp[13] = {0};
    for (i = 0; i < dir->volume->super_fat->root_dir_capacity && !dir->is_root; ++i)
    {
        memcpy(dir->entry, root + i * sizeof(struct entry_t), sizeof(struct entry_t));
        if ( *(uint8_t*)dir->entry == 0xe5 ) continue;
        if ( *(uint8_t*)dir->entry == 0x00 ) break;
        trim_filename(dir->entry->name, name);
        all_to_upper(*dirs, to_cmp);

        if ( strcmp(name, to_cmp) == 0 )
            break;
    }
    free(root);

    //====> Looping through nested directories <====//
    uint32_t fat_size = dir->volume->super_fat->sectors_per_fat * dir->volume->super_fat->bytes_per_sector;
    uint32_t cluster_size = dir->volume->super_fat->sectors_per_cluster * dir->volume->super_fat->bytes_per_sector;
    struct clusters_chain_t chain = {0};

    for (i = 1; i < actual_dirs && !dir->is_root; ++i)
    {
        // Reading directory's clusters
        get_fat16_chain(&chain, dir->volume->fat, fat_size, dir->entry->starting_cluster);
        uint8_t *dirs_cluster = malloc(cluster_size * chain.size);

        for (size_t j = 0; j < chain.size; ++j)
        {
            int32_t first_sector =
                    dir->volume->data_start + (chain.clusters[j] - 2) * dir->volume->super_fat->sectors_per_cluster;
            int32_t sectors_to_read = dir->volume->super_fat->sectors_per_cluster;
            disk_read(dir->volume->disk, first_sector, dirs_cluster + j * cluster_size, sectors_to_read);
        }

        // Checking if current directory exists in current path
        int j = 0;
        while (*(uint8_t *)(dir->entry) != 0x00)
        {
            memcpy(dir->entry, dirs_cluster + j * sizeof(struct entry_t), sizeof(struct entry_t));
            j++;
            if (*(uint8_t *)dir->entry == 0xe5)
                continue;
            trim_filename(dir->entry->name, name);
            all_to_upper(*(dirs + i), to_cmp);

            if (strcmp(name, to_cmp) == 0)
            {
                free(dirs_cluster);
                free(chain.clusters);
                break;
            }
        }
        if (*(uint8_t *)dir->entry == 0x00)
        {
            free(dirs_cluster);
            free(chain.clusters);
            break;
        }
    }

    // Validating parsed data
    if (i == dir->volume->super_fat->root_dir_capacity || *(uint8_t*) dir->entry == 0x00)
    {
        errno = ENOENT;
        free(dir->clusters_chain);
        free(dir->entry);
        free(dir);
        free_dirs(&dirs, actual_dirs);
        return NULL;
    }
    if (dir->entry->file_size != 0)
    {
        errno = ENOTDIR;
        free(dir->clusters_chain);
        free(dir->entry);
        free(dir);
        free_dirs(&dirs, actual_dirs);
        return NULL;
    }

    // Reading dir's clusters
    get_fat16_chain(dir->clusters_chain, dir->volume->fat, fat_size, dir->entry->starting_cluster);

    free_dirs(&dirs, actual_dirs);
    return dir;
}
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry)
{
    if (!pdir || !pentry) {
        errno = EFAULT;
        return -1;
    }

    int32_t first_sector = pdir->volume->root_dir_start;
    uint16_t root_capacity = pdir->volume->super_fat->root_dir_capacity;
    uint32_t cluster_size = pdir->volume->super_fat->sectors_per_cluster * pdir->volume->super_fat->bytes_per_sector;

    char name[13] = {0};

    if (pdir->is_root)
    {
        // Reading root directory
        void* root = malloc(pdir->volume->root_size_in_bytes);
        disk_read(pdir->volume->disk, first_sector, root, pdir->volume->sectors_per_root);

        for (int i = pdir->curr_entry; i < root_capacity; ++i) {
            // Reading next entry
            memcpy(pdir->entry, (char *) root + pdir->curr_entry * sizeof(struct entry_t), sizeof(struct entry_t));
            if (*((uint8_t *) pdir->entry) == 0xe5) {
                pdir->curr_entry++;
                continue;
            }
            if (*((uint8_t *) pdir->entry) == 0x00) break;

            trim_filename(pdir->entry->name, name);
            strcpy(pentry->name, name);
            pentry->size = pdir->entry->file_size;

            uint8_t attr = pdir->entry->file_attributes;
            switch (attr) {
                case 0x01: pentry->is_readonly = 1;  break;
                case 0x02: pentry->is_hidden = 1;    break;
                case 0x04: pentry->is_system = 1;    break;
                case 0x10: pentry->is_directory = 1; break;
                case 0x20: pentry->is_archived = 1;  break;
                default: break;
            }

            pdir->curr_entry++;
            free(root);
            return 0;
        }
        free(root);
    }
    else
    {
        uint8_t* clusters = malloc(cluster_size * pdir->clusters_chain->size);
        uint8_t sectors_per_cluster = pdir->volume->super_fat->sectors_per_cluster;
        for (size_t i = 0; i < pdir->clusters_chain->size; ++i)
        {
            uint16_t starting_pos = pdir->volume->data_start + (pdir->clusters_chain->clusters[i] - 2) * sectors_per_cluster;
            disk_read(pdir->volume->disk, starting_pos, clusters + i * cluster_size, sectors_per_cluster);
        }

        while ( *(uint8_t*)pdir->entry != 0x00 )
        {
            memcpy(pdir->entry, clusters + pdir->curr_entry * sizeof(struct entry_t), sizeof(struct entry_t));

            if ( *(uint8_t*)pdir->entry == 0xe5 ) {
                pdir->curr_entry++;
            }
            else if ( *(uint8_t*)pdir->entry == 0x00 ) {
                free(clusters);
                return 1;
            }
            else {
                trim_filename(pdir->entry->name, name);
                strcpy(pentry->name, name);
                pentry->size = pdir->entry->file_size;

                uint8_t attr = pdir->entry->file_attributes;
                switch (attr) {
                    case 0x01: pentry->is_readonly = 1;  break;
                    case 0x02: pentry->is_hidden = 1;    break;
                    case 0x04: pentry->is_system = 1;    break;
                    case 0x10: pentry->is_directory = 1; break;
                    case 0x20: pentry->is_archived = 1;  break;
                    default: break;
                }

                pdir->curr_entry++;
                free(clusters);
                return 0;
            }
        }

        free(clusters);
    }

    return 1;
}

int dir_close(struct dir_t* pdir)
{
    if (!pdir) {
        errno = EFAULT;
        return -1;
    }

    if (!pdir->is_root) {
        free(pdir->clusters_chain->clusters);
        free(pdir->clusters_chain);
    }
    free(pdir->entry);
    free(pdir);

    return 0;
}

