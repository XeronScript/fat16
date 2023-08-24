#ifndef FAT16_FILE_READER_H
#define FAT16_FILE_READER_H

typedef uint16_t lba_t;

struct clusters_chain_t {
    uint16_t *clusters;
    size_t size;
};

struct __attribute__((packed)) super_fat_t {
    uint8_t assembly_code[3];
    char OEM_name[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;          // ukryte sektory w boot_sector (n)
    uint8_t fat_count;                  // ilość tablic FAT
    uint16_t root_dir_capacity;         // liczba wpisów w roocie
    uint16_t logical_sectors16;         // ilość sektorów w woluminie (dla większych woluminów, sprawdzana jest zmienna logical_sectors32)
    uint8_t media_type;                 // typ nośnika (0x80 albo 0x00 (dyskietka))
    uint16_t sectors_per_fat;
    uint16_t chs_sectors_per_track;     // useless
    uint16_t chs_tracks_per_cylinder;   // useless
    uint32_t hidden_sectors;            // raczej useless
    uint32_t logical_sectors32;         // większa wartość opisująca ilość sektorów w woluminie (obie zmienne logical_sectors nie mogą mieć wartości 0!!!)
    uint8_t media_id;                   // chyba musi być 0x80
    uint8_t chs_head;                   // useless
    uint8_t ext_bpb_signature;          // 0x29 albo 0x28 (musi być!)
    uint32_t serial_number;
    char volume_name[11];
    char file_system_id[8];             // nie sugerować się zbytnio tą nazwą systemu plików
    uint8_t not_used[448];
    uint16_t signature_value;           // musi być 0xAA55
};

struct disk_t
{
    FILE* fdisk;
};
struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

//    położenie n-tego klastra: data_start + (cluster - 2) * scetors_per_cluster
struct volume_t {
    struct super_fat_t* super_fat;
    struct disk_t* disk;
    uint16_t* fat;                       // Tablica FATów, oczytana z dysku

    lba_t fat_start;
    lba_t root_dir_start;
    lba_t sectors_per_root;
    uint32_t root_size_in_bytes;
    lba_t data_start;
    lba_t available_clusters;
    lba_t fat_entry_count;
};
struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);


struct file_t {
    struct clusters_chain_t* clusters_chain;
    struct volume_t* volume;
    struct entry_t* entry;

    uint8_t* cluster_buff;
//    uint8_t curr_sector;
    uint8_t curr_cluster;
    uint32_t current_position;
};
struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);


struct dir_t {
    struct clusters_chain_t* clusters_chain;
    struct volume_t* volume;
    struct entry_t* entry;

    uint8_t is_root;
    uint16_t curr_entry;
};

struct __attribute__((packed)) entry_t {
    char name[11];                // "." jest między 7 a 8 bajtem
    uint8_t file_attributes;      // 0x01 - do odczytu; 0x02 - ukryty; 0x04 - systemowy; 0x08 - etykieta woluminu; 0x0f - długa nazwa; 0x10 - folder; 0x20 - archiwalny(?)
    uint8_t reserved;             // zielonego pojęcia nie mam, co to jest :thinking_emoji:
    uint8_t file_creation_time;   // w 10ms (zakres 0-199)
    uint16_t creation_time;       // godziny, minuty, sekundy
    uint16_t creation_date;
    uint16_t access_date;
    uint16_t reserved_for_fat32;  // 0 dla FAT12 i FAT16
    uint16_t modified_time;       // godziny, minuty, sekundy
    uint16_t modified_date;
    uint16_t starting_cluster;    // pierwszy klaster
    uint32_t file_size;           // 0 dla folderów
};

struct dir_entry_t {
    char name[13];
    uint32_t size;
    uint8_t is_archived;
    uint8_t is_readonly;
    uint8_t is_system;
    uint8_t is_hidden;
    uint8_t is_directory;
};

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);

#endif //FAT16_FILE_READER_H
