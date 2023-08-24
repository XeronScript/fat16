/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: ścieżki bezwzględne, wielkości liter (4,0)
 * Autor testowanej odpowiedzi: Kamil Sasin
 * Test wygenerowano automatycznie o 2022-01-08 15:29:24.182512
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("NOON");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("remember.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(4248, 1);
                char expected_filecontent[4249] = "";
        
                strcat(expected_filecontent, "s needed help\nOf vision to interpret.  As when breaks\nIn act to be discharg\'d, a cross-bow bent\nBeyond its pitch, both nerve and bow o\'erstretch\'d,\nThe flagging weapon feebly hits the mark;\nThus, tears and sighs forth gushing, did I burst\nBeneath the heavy load, and thus my voice\nWas slacken\'d on its way.  She straight began:\n\"When my desire invited thee to love\nThe good, which sets a bound to our aspirings,\nWhat bar of thwarting foss or linked chain\nDid meet thee, that thou so should\'st quit the hope\nOf further progress, or what bait of ease\nOr promise of allurement led thee on\nElsewhere, that thou elsewhere should\'st rather wait?\"\n     A bitter sigh I drew, then scarce found voice\nTo answer, hardly to these sounds my lips\nGave utterance, wailing:  \"Thy fair looks withdrawn,\nThings present, with deceitful pleasures, turn\'d\nMy steps aside.\"  She answering spake:  \"Hadst thou\nBeen silent, or denied what thou avow\'st,\nThou hadst not hid thy sin the more: such eye\nObserves it.  But whene\'er the sinner\'s cheek\nBreaks forth into the precious-streaming tears\nOf self-accusing, in our court the wheel\nOf justice doth run counter to the edge.\nHowe\'er that thou may\'st profit by thy shame\nFor errors past, and that henceforth more strength\nMay arm thee, when thou hear\'st the Siren-voice,\nLay thou aside the motive to this grief,\nAnd lend attentive ear, while I unfold\nHow opposite a way my buried flesh\nShould have impell\'d thee.  Never didst thou spy\nIn art or nature aught so passing sweet,\nAs were the limbs, that in their beauteous frame\nEnclos\'d me, and are scatter\'d now in dust.\nIf sweetest thing thus fail\'d thee with my death,\nWhat, afterward, of mortal should thy wish\nHave tempted?  When thou first hadst felt the dart\nOf perishable things, in my departing\nFor better realms, thy wing thou should\'st have prun\'d\nTo follow me, and never stoop\'d again\nTo \'bide a second blow for a slight girl,\nOr other gaud as transient and as vain.\nThe new and inexperienc\'d bird awaits,\nTwice it may be, or thrice, the fowler\'s aim;\nBut in the sight of one, whose plumes are full,\nIn vain the net is spread, the arrow wing\'d.\"\n     I stood, as children silent and asham\'d\nStand, list\'ning, with their eyes upon the earth,\nAcknowledging their fault and self-condemn\'d.\nAnd she resum\'d:  \"If, but to hear thus pains thee,\nRaise thou thy beard, and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in ");
    strcat(expected_filecontent, "the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HIGH");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 4248, file);
                test_error(size == 4248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4248 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4248);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 4248);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(4098, 1);
                char expected_filecontent[4099] = "";
        
                strcat(expected_filecontent, " solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefly.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit");
    strcat(expected_filecontent, ".  ");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ALlOw.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 4098, file);
                test_error(size == 4098, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4098 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4098);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 4098);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(674, 1);
                char expected_filecontent[675] = "";
        
                strcat(expected_filecontent, "Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SQUArE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 674, file);
                test_error(size == 674, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 674 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 674);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 674);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(7813, 1);
                char expected_filecontent[7814] = "";
        
                strcat(expected_filecontent, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ThEN.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7813, file);
                test_error(size == 7813, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7813 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7813);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7813);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6333, 1);
                char expected_filecontent[6334] = "";
        
                strcat(expected_filecontent, "o my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few words I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld");
    strcat(expected_filecontent, ".  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their w");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "ORDeR.txT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6333, file);
                test_error(size == 6333, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6333 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6333);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6333);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";
        
                strcat(expected_filecontent, "m in their warfare for the faith.\nThe preacher now provides himself with store\nOf jests and gibes; and, so there be no lack\nOf laughter, while he vents them, his big cowl\nDistends, and he has won the meed he sought:\nCould but the vulgar catch a glimpse the while\nOf that dark bird which nestles in his hood,\nThey scarce would wait to hear the blessing said.\nWhich now the dotards hold in such esteem,\nThat every counterfeit, who spreads abroad\nThe hands of holy promise, finds a throng\nOf credulous fools beneath.  Saint Anthony\nFattens with this his swine, and others worse\nThan swine, who diet at his lazy board,\nPaying with unstamp\'d metal for their fare.\n     \"But (for we far have wander\'d) let us seek\nThe forward path again; so as the way\nBe shorten\'d with the time.  No mortal tongue\nNor thought of man hath ever reach\'d so far,\nThat of these natures he might count the tribes.\nWhat Daniel of their thousands hath reveal\'d\nWith finite number infinite conceals.\nThe fountain at whose source these drink their beams,\nWith light supplies them in as many modes,\nAs there are splendours, that it shines on: each\nAccording to the virtue it conceives,\nDiffering in love and sweet affection.\nLook then how lofty and how huge in breadth\nThe\' eternal might, which, broken and dispers\'d\nOver such countless mirrors, yet remains\nWhole in itself and one, as at the first.\"\n\n\n\nCANTO XXX\n\nNoon\'s fervid hour perchance six thousand miles\nFrom hence is distant; and the shadowy cone\nAlmost to level on our earth declines;\nWhen from the midmost of this blue abyss\nBy turns some star is to our vision lost.\nAnd straightway as the handmaid of the sun\nPuts forth her radiant brow, all, light by light,\nFade, and the spangled firmament shuts in,\nE\'en to the loveliest of the glittering throng.\nThus vanish\'d gradually from my sight\nThe triumph, which plays ever round the point,\nThat overcame me, seeming (for it did)\nEngirt by that it girdeth.  Wherefore love,\nWith loss of other object, forc\'d me bend\nMine eyes on Beatrice once again.\n     If all, that hitherto is told of her,\nWere in one praise concluded, \'t were too weak\nTo furnish out this turn.  Mine eyes did look\nOn beauty, such, as I believe in sooth,\nNot merely to exceed our human, but,\nThat save its Maker, none can to the full\nEnjoy it.  At this point o\'erpower\'d I fail,\nUnequal to my theme, as never bard\nOf buskin or of sock hath fail\'d before.\nFor, as the sun doth to the feeblest sight,\nE\'en so remembrance of that witching smile\nHath dispossess my spirit of itself.\nNot from that day, when on this earth I first\nBeheld her charms, up to that view of them,\nHave I with song applausive ever ceas\'d\nTo follow, but not follow them no more;\nMy course here bounded, as each artist\'s is,\nWhen it doth touch the limit of his skill.\n     She (such as I bequeath her to the bruit\nOf louder trump than mine, which hasteneth on,\nUrging its arduous matter to the close),\nHer words resum\'d, in gesture and in voice\nResembling one accustom\'d to command:\n\"Forth from the last corporeal are we come\nInto the heav\'n, that is unbodied light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradise; and one in that array,\nWhich in the final judgment thou shalt see.\"\n     As when the lightning, in a sudden spleen\nUnfolded, dashes from the blinding eyes\nThe visive spirits dazzled and bedimm\'d;\nSo, round about me, fulminating streams\nOf living radiance play\'d, and left me swath\'d\nAnd veil\'d in dense impenetrable blaze.\nSuch weal is in the love, that stills this heav\'n;\nFor its own flame the torch this fitting ever!\n     No sooner to my list\'ning ear had come\nThe brief assurance, than I understood\nNew virtue into me infus\'d, and sight\nKindled afresh, with vigour to sustain\nExcess of light, however pure.  I look\'d;\nAnd in the likeness of a river saw\nLight flowing, from whose amber-seeming waves\nFlash\'d up effulgence, as they glided on\n\'Twixt banks, on either side, painted with spring,\nIncredible how fair; and, from the t");
    strcat(expected_filecontent, "ide,\nThere ever and anon, outstarting, flew\nSparkles instinct with life; and in the flow\'rs\nDid set them, like to rubies chas\'d in gold;\nThen, as if drunk with odors, plung\'d again\nInto the wondrous flood; from which, as one\nRe\'enter\'d, still another rose.  \"The thirst\nOf knowledge high, whereby thou art inflam\'d,\nTo search the meaning of what here thou seest,\nThe more it warms thee, pleases me the more.\nBut first behooves thee of this water drink,\nOr ere that longing be allay\'d.\"  So spake\nThe day-star of mine eyes; then thus subjoin\'d:\n\"This stream, and these, forth issuing from its gulf,\nAnd diving back, a living topaz each,\nWith all this laughter on its bloomy shores,\nAre but a preface, shadowy of the truth\nThey emblem: not that, in themselves, the things\nAre crude; but on thy part is the defect,\nFor that thy views not yet aspire so high.\"\nNever did babe, that had outslept his wont,\nRush, with such eager straining, to the milk,\nAs I toward the water, bending me,\nTo make the better mirrors of mine eyes\nIn the refining wave; and, as the eaves\nOf mine eyelids did drink of it, forthwith\nSeem\'d it unto me turn\'d from length to round,\nThen as a troop of maskers, when they put\nTheir vizors off, look other than before,\nThe counterfeited semblance thrown aside;\nSo into greater jubilee were chang\'d\nThose flowers and sparkles, and distinct I saw\nBefore me either court of heav\'n displac\'d.\n     O prime enlightener!  thou who crav\'st me strength\nOn the high triumph of thy realm to gaze!\nGrant virtue now to utter what I kenn\'d,\n    There is in heav\'n a light, whose goodly shine\nMakes the Creator visible to all\nCreated, that in seeing him alone\nHave peace; and in a circle spreads so far,\nThat the circumference were too loose a zone\nTo girdle in the sun.  All is one beam,\nReflected from the summit of the first,\nThat moves, which being hence and vigour takes,\nAnd as some cliff, that from the bottom eyes\nIts image mirror\'d in the crystal flood,\nAs if \'t admire its brave appareling\nOf verdure and of flowers: so, round about,\nEye");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "HAPpEN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 6144, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 6144);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(537, 1);
                char expected_filecontent[538] = "";
        
                strcat(expected_filecontent, " evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLa");
                
        
                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "iNSTrUME.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 537, file);
                test_error(size == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 537);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 537);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(4248, 1);
                char expected_filecontent[4249] = "";

                strcat(expected_filecontent, "s needed help\nOf vision to interpret.  As when breaks\nIn act to be discharg\'d, a cross-bow bent\nBeyond its pitch, both nerve and bow o\'erstretch\'d,\nThe flagging weapon feebly hits the mark;\nThus, tears and sighs forth gushing, did I burst\nBeneath the heavy load, and thus my voice\nWas slacken\'d on its way.  She straight began:\n\"When my desire invited thee to love\nThe good, which sets a bound to our aspirings,\nWhat bar of thwarting foss or linked chain\nDid meet thee, that thou so should\'st quit the hope\nOf further progress, or what bait of ease\nOr promise of allurement led thee on\nElsewhere, that thou elsewhere should\'st rather wait?\"\n     A bitter sigh I drew, then scarce found voice\nTo answer, hardly to these sounds my lips\nGave utterance, wailing:  \"Thy fair looks withdrawn,\nThings present, with deceitful pleasures, turn\'d\nMy steps aside.\"  She answering spake:  \"Hadst thou\nBeen silent, or denied what thou avow\'st,\nThou hadst not hid thy sin the more: such eye\nObserves it.  But whene\'er the sinner\'s cheek\nBreaks forth into the precious-streaming tears\nOf self-accusing, in our court the wheel\nOf justice doth run counter to the edge.\nHowe\'er that thou may\'st profit by thy shame\nFor errors past, and that henceforth more strength\nMay arm thee, when thou hear\'st the Siren-voice,\nLay thou aside the motive to this grief,\nAnd lend attentive ear, while I unfold\nHow opposite a way my buried flesh\nShould have impell\'d thee.  Never didst thou spy\nIn art or nature aught so passing sweet,\nAs were the limbs, that in their beauteous frame\nEnclos\'d me, and are scatter\'d now in dust.\nIf sweetest thing thus fail\'d thee with my death,\nWhat, afterward, of mortal should thy wish\nHave tempted?  When thou first hadst felt the dart\nOf perishable things, in my departing\nFor better realms, thy wing thou should\'st have prun\'d\nTo follow me, and never stoop\'d again\nTo \'bide a second blow for a slight girl,\nOr other gaud as transient and as vain.\nThe new and inexperienc\'d bird awaits,\nTwice it may be, or thrice, the fowler\'s aim;\nBut in the sight of one, whose plumes are full,\nIn vain the net is spread, the arrow wing\'d.\"\n     I stood, as children silent and asham\'d\nStand, list\'ning, with their eyes upon the earth,\nAcknowledging their fault and self-condemn\'d.\nAnd she resum\'d:  \"If, but to hear thus pains thee,\nRaise thou thy beard, and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in ");
    strcat(expected_filecontent, "the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HIgH");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4569, file);
                test_error(size == 4248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4248 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4248);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 4248);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(4098, 1);
                char expected_filecontent[4099] = "";

                strcat(expected_filecontent, " solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefly.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit");
    strcat(expected_filecontent, ".  ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ALLOw.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4520, file);
                test_error(size == 4098, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4098 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4098);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 4098);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(674, 1);
                char expected_filecontent[675] = "";

                strcat(expected_filecontent, "Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "sQUAre.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 845, file);
                test_error(size == 674, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 674 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 674);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 674);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(7813, 1);
                char expected_filecontent[7814] = "";

                strcat(expected_filecontent, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "THeN.biN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 8200, file);
                test_error(size == 7813, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7813 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7813);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7813);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6333, 1);
                char expected_filecontent[6334] = "";

                strcat(expected_filecontent, "o my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few words I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld");
    strcat(expected_filecontent, ".  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their w");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "OrDER.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6781, file);
                test_error(size == 6333, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6333 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6333);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6333);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "m in their warfare for the faith.\nThe preacher now provides himself with store\nOf jests and gibes; and, so there be no lack\nOf laughter, while he vents them, his big cowl\nDistends, and he has won the meed he sought:\nCould but the vulgar catch a glimpse the while\nOf that dark bird which nestles in his hood,\nThey scarce would wait to hear the blessing said.\nWhich now the dotards hold in such esteem,\nThat every counterfeit, who spreads abroad\nThe hands of holy promise, finds a throng\nOf credulous fools beneath.  Saint Anthony\nFattens with this his swine, and others worse\nThan swine, who diet at his lazy board,\nPaying with unstamp\'d metal for their fare.\n     \"But (for we far have wander\'d) let us seek\nThe forward path again; so as the way\nBe shorten\'d with the time.  No mortal tongue\nNor thought of man hath ever reach\'d so far,\nThat of these natures he might count the tribes.\nWhat Daniel of their thousands hath reveal\'d\nWith finite number infinite conceals.\nThe fountain at whose source these drink their beams,\nWith light supplies them in as many modes,\nAs there are splendours, that it shines on: each\nAccording to the virtue it conceives,\nDiffering in love and sweet affection.\nLook then how lofty and how huge in breadth\nThe\' eternal might, which, broken and dispers\'d\nOver such countless mirrors, yet remains\nWhole in itself and one, as at the first.\"\n\n\n\nCANTO XXX\n\nNoon\'s fervid hour perchance six thousand miles\nFrom hence is distant; and the shadowy cone\nAlmost to level on our earth declines;\nWhen from the midmost of this blue abyss\nBy turns some star is to our vision lost.\nAnd straightway as the handmaid of the sun\nPuts forth her radiant brow, all, light by light,\nFade, and the spangled firmament shuts in,\nE\'en to the loveliest of the glittering throng.\nThus vanish\'d gradually from my sight\nThe triumph, which plays ever round the point,\nThat overcame me, seeming (for it did)\nEngirt by that it girdeth.  Wherefore love,\nWith loss of other object, forc\'d me bend\nMine eyes on Beatrice once again.\n     If all, that hitherto is told of her,\nWere in one praise concluded, \'t were too weak\nTo furnish out this turn.  Mine eyes did look\nOn beauty, such, as I believe in sooth,\nNot merely to exceed our human, but,\nThat save its Maker, none can to the full\nEnjoy it.  At this point o\'erpower\'d I fail,\nUnequal to my theme, as never bard\nOf buskin or of sock hath fail\'d before.\nFor, as the sun doth to the feeblest sight,\nE\'en so remembrance of that witching smile\nHath dispossess my spirit of itself.\nNot from that day, when on this earth I first\nBeheld her charms, up to that view of them,\nHave I with song applausive ever ceas\'d\nTo follow, but not follow them no more;\nMy course here bounded, as each artist\'s is,\nWhen it doth touch the limit of his skill.\n     She (such as I bequeath her to the bruit\nOf louder trump than mine, which hasteneth on,\nUrging its arduous matter to the close),\nHer words resum\'d, in gesture and in voice\nResembling one accustom\'d to command:\n\"Forth from the last corporeal are we come\nInto the heav\'n, that is unbodied light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradise; and one in that array,\nWhich in the final judgment thou shalt see.\"\n     As when the lightning, in a sudden spleen\nUnfolded, dashes from the blinding eyes\nThe visive spirits dazzled and bedimm\'d;\nSo, round about me, fulminating streams\nOf living radiance play\'d, and left me swath\'d\nAnd veil\'d in dense impenetrable blaze.\nSuch weal is in the love, that stills this heav\'n;\nFor its own flame the torch this fitting ever!\n     No sooner to my list\'ning ear had come\nThe brief assurance, than I understood\nNew virtue into me infus\'d, and sight\nKindled afresh, with vigour to sustain\nExcess of light, however pure.  I look\'d;\nAnd in the likeness of a river saw\nLight flowing, from whose amber-seeming waves\nFlash\'d up effulgence, as they glided on\n\'Twixt banks, on either side, painted with spring,\nIncredible how fair; and, from the t");
    strcat(expected_filecontent, "ide,\nThere ever and anon, outstarting, flew\nSparkles instinct with life; and in the flow\'rs\nDid set them, like to rubies chas\'d in gold;\nThen, as if drunk with odors, plung\'d again\nInto the wondrous flood; from which, as one\nRe\'enter\'d, still another rose.  \"The thirst\nOf knowledge high, whereby thou art inflam\'d,\nTo search the meaning of what here thou seest,\nThe more it warms thee, pleases me the more.\nBut first behooves thee of this water drink,\nOr ere that longing be allay\'d.\"  So spake\nThe day-star of mine eyes; then thus subjoin\'d:\n\"This stream, and these, forth issuing from its gulf,\nAnd diving back, a living topaz each,\nWith all this laughter on its bloomy shores,\nAre but a preface, shadowy of the truth\nThey emblem: not that, in themselves, the things\nAre crude; but on thy part is the defect,\nFor that thy views not yet aspire so high.\"\nNever did babe, that had outslept his wont,\nRush, with such eager straining, to the milk,\nAs I toward the water, bending me,\nTo make the better mirrors of mine eyes\nIn the refining wave; and, as the eaves\nOf mine eyelids did drink of it, forthwith\nSeem\'d it unto me turn\'d from length to round,\nThen as a troop of maskers, when they put\nTheir vizors off, look other than before,\nThe counterfeited semblance thrown aside;\nSo into greater jubilee were chang\'d\nThose flowers and sparkles, and distinct I saw\nBefore me either court of heav\'n displac\'d.\n     O prime enlightener!  thou who crav\'st me strength\nOn the high triumph of thy realm to gaze!\nGrant virtue now to utter what I kenn\'d,\n    There is in heav\'n a light, whose goodly shine\nMakes the Creator visible to all\nCreated, that in seeing him alone\nHave peace; and in a circle spreads so far,\nThat the circumference were too loose a zone\nTo girdle in the sun.  All is one beam,\nReflected from the summit of the first,\nThat moves, which being hence and vigour takes,\nAnd as some cliff, that from the bottom eyes\nIts image mirror\'d in the crystal flood,\nAs if \'t admire its brave appareling\nOf verdure and of flowers: so, round about,\nEye");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "haPPeN.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6353, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6144);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(537, 1);
                char expected_filecontent[538] = "";

                strcat(expected_filecontent, " evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLa");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "inSTRUMe.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 971, file);
                test_error(size == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 537);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 537);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(4248, 1);
                char expected_filecontent[4249] = "";

                strcat(expected_filecontent, "s needed help\nOf vision to interpret.  As when breaks\nIn act to be discharg\'d, a cross-bow bent\nBeyond its pitch, both nerve and bow o\'erstretch\'d,\nThe flagging weapon feebly hits the mark;\nThus, tears and sighs forth gushing, did I burst\nBeneath the heavy load, and thus my voice\nWas slacken\'d on its way.  She straight began:\n\"When my desire invited thee to love\nThe good, which sets a bound to our aspirings,\nWhat bar of thwarting foss or linked chain\nDid meet thee, that thou so should\'st quit the hope\nOf further progress, or what bait of ease\nOr promise of allurement led thee on\nElsewhere, that thou elsewhere should\'st rather wait?\"\n     A bitter sigh I drew, then scarce found voice\nTo answer, hardly to these sounds my lips\nGave utterance, wailing:  \"Thy fair looks withdrawn,\nThings present, with deceitful pleasures, turn\'d\nMy steps aside.\"  She answering spake:  \"Hadst thou\nBeen silent, or denied what thou avow\'st,\nThou hadst not hid thy sin the more: such eye\nObserves it.  But whene\'er the sinner\'s cheek\nBreaks forth into the precious-streaming tears\nOf self-accusing, in our court the wheel\nOf justice doth run counter to the edge.\nHowe\'er that thou may\'st profit by thy shame\nFor errors past, and that henceforth more strength\nMay arm thee, when thou hear\'st the Siren-voice,\nLay thou aside the motive to this grief,\nAnd lend attentive ear, while I unfold\nHow opposite a way my buried flesh\nShould have impell\'d thee.  Never didst thou spy\nIn art or nature aught so passing sweet,\nAs were the limbs, that in their beauteous frame\nEnclos\'d me, and are scatter\'d now in dust.\nIf sweetest thing thus fail\'d thee with my death,\nWhat, afterward, of mortal should thy wish\nHave tempted?  When thou first hadst felt the dart\nOf perishable things, in my departing\nFor better realms, thy wing thou should\'st have prun\'d\nTo follow me, and never stoop\'d again\nTo \'bide a second blow for a slight girl,\nOr other gaud as transient and as vain.\nThe new and inexperienc\'d bird awaits,\nTwice it may be, or thrice, the fowler\'s aim;\nBut in the sight of one, whose plumes are full,\nIn vain the net is spread, the arrow wing\'d.\"\n     I stood, as children silent and asham\'d\nStand, list\'ning, with their eyes upon the earth,\nAcknowledging their fault and self-condemn\'d.\nAnd she resum\'d:  \"If, but to hear thus pains thee,\nRaise thou thy beard, and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in ");
    strcat(expected_filecontent, "the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HIGh");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4427, file);
                test_error(size == 4248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4248 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4248);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 4248);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(4098, 1);
                char expected_filecontent[4099] = "";

                strcat(expected_filecontent, " solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefly.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit");
    strcat(expected_filecontent, ".  ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ALLoW.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 4518, file);
                test_error(size == 4098, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4098 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 4098);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 4098);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(674, 1);
                char expected_filecontent[675] = "";

                strcat(expected_filecontent, "Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SQuaRe.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1071, file);
                test_error(size == 674, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 674 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 674);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 674);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(7813, 1);
                char expected_filecontent[7814] = "";

                strcat(expected_filecontent, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "tHEN.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 8228, file);
                test_error(size == 7813, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7813 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7813);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7813);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6333, 1);
                char expected_filecontent[6334] = "";

                strcat(expected_filecontent, "o my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few words I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld");
    strcat(expected_filecontent, ".  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their w");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "ORdER.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6768, file);
                test_error(size == 6333, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6333 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6333);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6333);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(6144, 1);
                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "m in their warfare for the faith.\nThe preacher now provides himself with store\nOf jests and gibes; and, so there be no lack\nOf laughter, while he vents them, his big cowl\nDistends, and he has won the meed he sought:\nCould but the vulgar catch a glimpse the while\nOf that dark bird which nestles in his hood,\nThey scarce would wait to hear the blessing said.\nWhich now the dotards hold in such esteem,\nThat every counterfeit, who spreads abroad\nThe hands of holy promise, finds a throng\nOf credulous fools beneath.  Saint Anthony\nFattens with this his swine, and others worse\nThan swine, who diet at his lazy board,\nPaying with unstamp\'d metal for their fare.\n     \"But (for we far have wander\'d) let us seek\nThe forward path again; so as the way\nBe shorten\'d with the time.  No mortal tongue\nNor thought of man hath ever reach\'d so far,\nThat of these natures he might count the tribes.\nWhat Daniel of their thousands hath reveal\'d\nWith finite number infinite conceals.\nThe fountain at whose source these drink their beams,\nWith light supplies them in as many modes,\nAs there are splendours, that it shines on: each\nAccording to the virtue it conceives,\nDiffering in love and sweet affection.\nLook then how lofty and how huge in breadth\nThe\' eternal might, which, broken and dispers\'d\nOver such countless mirrors, yet remains\nWhole in itself and one, as at the first.\"\n\n\n\nCANTO XXX\n\nNoon\'s fervid hour perchance six thousand miles\nFrom hence is distant; and the shadowy cone\nAlmost to level on our earth declines;\nWhen from the midmost of this blue abyss\nBy turns some star is to our vision lost.\nAnd straightway as the handmaid of the sun\nPuts forth her radiant brow, all, light by light,\nFade, and the spangled firmament shuts in,\nE\'en to the loveliest of the glittering throng.\nThus vanish\'d gradually from my sight\nThe triumph, which plays ever round the point,\nThat overcame me, seeming (for it did)\nEngirt by that it girdeth.  Wherefore love,\nWith loss of other object, forc\'d me bend\nMine eyes on Beatrice once again.\n     If all, that hitherto is told of her,\nWere in one praise concluded, \'t were too weak\nTo furnish out this turn.  Mine eyes did look\nOn beauty, such, as I believe in sooth,\nNot merely to exceed our human, but,\nThat save its Maker, none can to the full\nEnjoy it.  At this point o\'erpower\'d I fail,\nUnequal to my theme, as never bard\nOf buskin or of sock hath fail\'d before.\nFor, as the sun doth to the feeblest sight,\nE\'en so remembrance of that witching smile\nHath dispossess my spirit of itself.\nNot from that day, when on this earth I first\nBeheld her charms, up to that view of them,\nHave I with song applausive ever ceas\'d\nTo follow, but not follow them no more;\nMy course here bounded, as each artist\'s is,\nWhen it doth touch the limit of his skill.\n     She (such as I bequeath her to the bruit\nOf louder trump than mine, which hasteneth on,\nUrging its arduous matter to the close),\nHer words resum\'d, in gesture and in voice\nResembling one accustom\'d to command:\n\"Forth from the last corporeal are we come\nInto the heav\'n, that is unbodied light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradise; and one in that array,\nWhich in the final judgment thou shalt see.\"\n     As when the lightning, in a sudden spleen\nUnfolded, dashes from the blinding eyes\nThe visive spirits dazzled and bedimm\'d;\nSo, round about me, fulminating streams\nOf living radiance play\'d, and left me swath\'d\nAnd veil\'d in dense impenetrable blaze.\nSuch weal is in the love, that stills this heav\'n;\nFor its own flame the torch this fitting ever!\n     No sooner to my list\'ning ear had come\nThe brief assurance, than I understood\nNew virtue into me infus\'d, and sight\nKindled afresh, with vigour to sustain\nExcess of light, however pure.  I look\'d;\nAnd in the likeness of a river saw\nLight flowing, from whose amber-seeming waves\nFlash\'d up effulgence, as they glided on\n\'Twixt banks, on either side, painted with spring,\nIncredible how fair; and, from the t");
    strcat(expected_filecontent, "ide,\nThere ever and anon, outstarting, flew\nSparkles instinct with life; and in the flow\'rs\nDid set them, like to rubies chas\'d in gold;\nThen, as if drunk with odors, plung\'d again\nInto the wondrous flood; from which, as one\nRe\'enter\'d, still another rose.  \"The thirst\nOf knowledge high, whereby thou art inflam\'d,\nTo search the meaning of what here thou seest,\nThe more it warms thee, pleases me the more.\nBut first behooves thee of this water drink,\nOr ere that longing be allay\'d.\"  So spake\nThe day-star of mine eyes; then thus subjoin\'d:\n\"This stream, and these, forth issuing from its gulf,\nAnd diving back, a living topaz each,\nWith all this laughter on its bloomy shores,\nAre but a preface, shadowy of the truth\nThey emblem: not that, in themselves, the things\nAre crude; but on thy part is the defect,\nFor that thy views not yet aspire so high.\"\nNever did babe, that had outslept his wont,\nRush, with such eager straining, to the milk,\nAs I toward the water, bending me,\nTo make the better mirrors of mine eyes\nIn the refining wave; and, as the eaves\nOf mine eyelids did drink of it, forthwith\nSeem\'d it unto me turn\'d from length to round,\nThen as a troop of maskers, when they put\nTheir vizors off, look other than before,\nThe counterfeited semblance thrown aside;\nSo into greater jubilee were chang\'d\nThose flowers and sparkles, and distinct I saw\nBefore me either court of heav\'n displac\'d.\n     O prime enlightener!  thou who crav\'st me strength\nOn the high triumph of thy realm to gaze!\nGrant virtue now to utter what I kenn\'d,\n    There is in heav\'n a light, whose goodly shine\nMakes the Creator visible to all\nCreated, that in seeing him alone\nHave peace; and in a circle spreads so far,\nThat the circumference were too loose a zone\nTo girdle in the sun.  All is one beam,\nReflected from the summit of the first,\nThat moves, which being hence and vigour takes,\nAnd as some cliff, that from the bottom eyes\nIts image mirror\'d in the crystal flood,\nAs if \'t admire its brave appareling\nOf verdure and of flowers: so, round about,\nEye");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "HAPPEN.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 6639, file);
                test_error(size == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 6144);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 6144);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(537, 1);
                char expected_filecontent[538] = "";

                strcat(expected_filecontent, " evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLa");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "INSTRUME.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1010, file);
                test_error(size == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 537);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 537);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char expected_filecontent[491] = "";

            strcat(expected_filecontent, ".\nThe city\'s malady hath ever source\nIn the confusion of its persons, as\nThe body\'s, in variety of food:\nAnd the blind bull falls with a steeper plunge,\nThan the blind lamb; and oftentimes one sword\nDoth more and better execution,\nThan five.  Mark Luni, Urbisaglia mark,\nHow they are gone, and after them how go\nChiusi and Sinigaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselve");

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "\\leArN\\.\\cLOSE\\sHOULD\\OCeAn\\..\\OcEAN\\dIVIDe\\TRIANGLE\\WEEK");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 490; ++i)
            {
                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
            }

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "und corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his baleful train, he dragg\'d\nPart of the bottom forth, and went his way\nExulting.  What remain\'d, as lively turf\nWith green herb, so did clothe itself with plumes,\nWhich haply had with purpose chaste and kind\nBeen offer\'d; and therewith were cloth\'d the wheels,\nBoth one and other, and the beam, so quickly\nA sigh were not breath\'d sooner.  Thus transform\'d,\nThe holy structure, through its several parts,\nDid put forth heads, three on the beam, and one\nOn every side; the first like oxen horn\'d,\nBut with a single horn upon their front\nThe four.  Like monster sight hath never seen.\nO\'er it methought there sat, secure as rock\nOn mountain\'s lofty top, a shameless whore,\nWhose ken rov\'d loosely round her.  At her side,\nAs \'t were that none might bear her off, I saw\nA giant stand; and ever, and anon\nThey mingled kisses.  But, her lustful eyes\nChancing on me to wander, that fell minion\nScourg\'d her from head to foot all o\'er; then full\nOf jealousy, and fierce with rage, unloos\'d\nThe monster, and dragg\'d on, so far across\nThe forest, that from me its shades alone\nShielded the harlot and the new-form\'d brute.\n\n\n\nCANTO XXXIII\n\n\"The heathen, Lord!  are come!\" responsive thus,\nThe trinal now, and now the virgin band\nQuaternion, their sweet psalmody began,\nWeeping; and Beatrice listen\'d, sad\nAnd sighing, to the song\', in such a mood,\nThat Mary, as she stood beside the cross,\nWas scarce more chang\'d.  But when they gave her place\nTo speak, then, risen upright on her feet,\nShe, with a colour glowing bright as fire,\nDid answer: \"Yet a little while, and ye\nShall see me not; and, my beloved sisters,\nAgain a little while, and ye shall see me.\"\n     Before her then she marshall\'d all the seven,\nAnd, beck\'ning only motion\'d me, the dame,\nAnd that remaining sage, to follow her.\n     So on she pass\'d; and had not set, I ween,\nHer tenth step to the ground, when with mine eyes\nHer eyes encounter\'d; and, with visage mild,\n\"So mend thy pace,\" she cried, \"that if my words\nAddress thee, thou mayst still be aptly plac\'d\nTo hear them.\"  Soon as duly to her side\nI now had hasten\'d:  \"Brother!\" she began,\n\"Why mak\'st thou no attempt at questioning,\nAs thus we walk together?\"  Like to those\nWho, speaking with too reverent an awe\nBefore their betters, draw not forth the voice\nAlive unto their lips, befell me shell\nThat I in sounds imperfect thus began:\n\"Lady!  what I have need of, that thou know\'st,\nAnd what will suit my need.\"  She answering thus:\n\"Of fearfulness and shame, I will, that thou\nHenceforth do rid thee: that thou speak no more,\nAs one who dreams.  Thus far be taught of me:\nThe vessel, which thou saw\'st the serpent break,\nWas and is not: let him, who hath the blame,\nHope not to scare God\'s vengeance with a sop.\nWithout an heir for ever shall not be\nThat eagle, he, who left the chariot plum\'d,\nWhich monster made it first and next a prey.\nPlainly I view, and therefore speak, the stars\nE\'en now approaching, whose conjunction, free\nFrom all impediment and bar, brings on\nA season, in the which, one sent from God,\n(Five hundred, five, and ten, do mark him out)\nThat foul one, and th\' accomplice of her guilt,\nThe giant, both shall slay.  And if perchance\nMy saying, dark as Themis or as Sphinx,\nFail to persuade thee, (since like them it foils\nThe intellect with blindness) yet ere long\nEvents shall be the Naiads, that will solve\nThis knotty riddle, and no damage light\nOn flock or field.  Take heed; and as these words\nBy me are utter\'d, teach them even so\nTo those who live that life, which is a race\nTo death: and when thou writ\'st t");
    strcat(expected_filecontent, "hem, keep in mind\nNot to conceal how thou hast seen the plant,\nThat twice hath now been spoil\'d.  This whoso robs,\nThis whoso plucks, with blasphemy of deed\nSins against God, who for his use alone\nCreating hallow\'d it.  For taste of this,\nIn pain and in desire, five thousand years\nAnd upward, the first soul did yearn for him,\nWho punish\'d in himself the fatal gust.\n     \"Thy reason slumbers, if it deem this height\nAnd summit thus inverted of the plant,\nWithout due cause: and were not vainer thoughts,\nAs Elsa\'s numbing waters, to thy soul,\nAnd their fond pleasures had not dyed it dark\nAs Pyramus the mulberry, thou hadst seen,\nIn such momentous circumstance alone,\nGod\'s equal justice morally implied\nIn the forbidden tree.  But since I mark thee\nIn understanding harden\'d into stone,\nAnd, to that hardness, spotted too and stain\'d,\nSo that thine eye is dazzled at my word,\nI will, that, if not written, yet at least\nPainted thou take it in thee, for the cause,\nThat one brings home his staff inwreath\'d with palm.\n    ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEiNA\\FEEl\\NEighBOr\\sHEET\\DANGER.Bin");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[538] = "";

                strcat(expected_filecontent, "ning, grace of heaven Hell, Canto\nII. 97.\n\nv. 85.  The lowest stair.]  By the white step is meant the\ndistinctness with which the conscience of the penitent reflects\nhis offences, by the burnt and cracked one, his contrition on,\ntheir account; and by that of porphyry, the fervour with which he\nresolves on the future pursuit of piety and virtue.  Hence, no\ndoubt, Milton describing \"the gate of heaven,\" P. L. b.\niii. 516.\n\nEach stair mysteriously was meant.\n\nv. 100.  Seven times.] Seven P\'s, to denote the seven sins\n(Peccata) of whic");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEInA\\sTONE\\BanK\\ENErGy\\TRAde.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 537; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[187] = "";

                strcat(expected_filecontent, "wide;\nThen homeward to thy bosom turn, and mark\nIf any part of the sweet peace enjoy.\nWhat boots it, that thy reins Justinian\'s hand\nBefitted, if thy saddle be unpress\'d?\nNought doth he ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SIT\\COMPANy\\MUCH\\WENt\\rEASON\\THICK.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 186; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[858] = "";

                strcat(expected_filecontent, "terpret.  As when breaks\nIn act to be discharg\'d, a cross-bow bent\nBeyond its pitch, both nerve and bow o\'erstretch\'d,\nThe flagging weapon feebly hits the mark;\nThus, tears and sighs forth gushing, did I burst\nBeneath the heavy load, and thus my voice\nWas slacken\'d on its way.  She straight began:\n\"When my desire invited thee to love\nThe good, which sets a bound to our aspirings,\nWhat bar of thwarting foss or linked chain\nDid meet thee, that thou so should\'st quit the hope\nOf further progress, or what bait of ease\nOr promise of allurement led thee on\nElsewhere, that thou elsewhere should\'st rather wait?\"\n     A bitter sigh I drew, then scarce found voice\nTo answer, hardly to these sounds my lips\nGave utterance, wailing:  \"Thy fair looks withdrawn,\nThings present, with deceitful pleasures, turn\'d\nMy steps aside.\"  She answering spake:  \"Hadst tho");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEINa\\BIRD\\pASS\\BANK\\JOB\\oFFER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 857; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4384] = "";

                strcat(expected_filecontent, "    We from the bridge\'s head descended, where\nTo the eighth mound it joins, and then the chasm\nOpening to view, I saw a crowd within\nOf serpents terrible, so strange of shape\nAnd hideous, that remembrance in my veins\nYet shrinks the vital current.  Of her sands\nLet Lybia vaunt no more:  if Jaculus,\nPareas and Chelyder be her brood,\nCenchris and Amphisboena, plagues so dire\nOr in such numbers swarming ne\'er she shew\'d,\nNot with all Ethiopia, and whate\'er\nAbove the Erythraean sea is spawn\'d.\n     Amid this dread exuberance of woe\nRan naked spirits wing\'d with horrid fear,\nNor hope had they of crevice where to hide,\nOr heliotrope to charm them out of view.\nWith serpents were their hands behind them bound,\nWhich through their reins infix\'d the tail and head\nTwisted in folds before.  And lo!  on one\nNear to our side, darted an adder up,\nAnd, where the neck is on the shoulders tied,\nTranspierc\'d him.  Far more quickly than e\'er pen\nWrote O or I, he kindled, burn\'d, and chang\'d\nTo ashes, all pour\'d out upon the earth.\nWhen there dissolv\'d he lay, the dust again\nUproll\'d spontaneous, and the self-same form\nInstant resumed.  So mighty sages tell,\nThe\' Arabian Phoenix, when five hundred years\nHave well nigh circled, dies, and springs forthwith\nRenascent.  Blade nor herb throughout his life\nHe tastes, but tears of frankincense alone\nAnd odorous amomum:  swaths of nard\nAnd myrrh his funeral shroud.  As one that falls,\nHe knows not how, by force demoniac dragg\'d\nTo earth, or through obstruction fettering up\nIn chains invisible the powers of man,\nWho, risen from his trance, gazeth around,\nBewilder\'d with the monstrous agony\nHe hath endur\'d, and wildly staring sighs;\nSo stood aghast the sinner when he rose.\n     Oh!  how severe God\'s judgment, that deals out\nSuch blows in stormy vengeance!  Who he was\nMy teacher next inquir\'d, and thus in few\nHe answer\'d:  \"Vanni Fucci am I call\'d,\nNot long since rained down from Tuscany\nTo this dire gullet.  Me the beastial life\nAnd not the human pleas\'d, mule that I was,\nWho in Pistoia found my worthy den.\"\n     I then to Virgil:  \"Bid him stir not hence,\nAnd ask what crime did thrust him hither:  once\nA man I knew him choleric and bloody.\"\n     The sinner heard and feign\'d not, but towards me\nHis mind directing and his face, wherein\nWas dismal shame depictur\'d, thus he spake:\n\"It grieves me more to have been caught by thee\nIn this sad plight, which thou beholdest, than\nWhen I was taken from the other life.\nI have no power permitted to deny\nWhat thou inquirest.\"  I am doom\'d thus low\nTo dwell, for that the sacristy by me\nWas rifled of its goodly ornaments,\nAnd with the guilt another falsely charged.\nBut that thou mayst not joy to see me thus,\nSo as thou e\'er shalt \'scape this darksome realm\nOpen thine ears and hear what I forebode.\nReft of the Neri first Pistoia pines,\nThen Florence changeth citizens and laws.\nFrom Valdimagra, drawn by wrathful Mars,\nA vapour rises, wrapt in turbid mists,\nAnd sharp and eager driveth on the storm\nWith arrowy hurtling o\'er Piceno\'s field,\nWhence suddenly the cloud shall burst, and strike\nEach helpless Bianco prostrate to the ground.\nThis have I told, that grief may rend thy heart.\"\n\n\n\nCANTO XXV\n\nWHEN he had spoke, the sinner rais\'d his hands\nPointed in mockery, and cried:  \"Take them, God!\nI level them at thee!\"  From that day forth\nThe serpents were my friends; for round his neck\nOne of then rolling twisted, as it said,\n\"Be silent, tongue!\"  Another to his arms\nUpgliding, tied them, riveting itself\nSo close, it took from them the power to move.\n     Pistoia!  Ah Pistoia!  why dost doubt\nTo turn thee into ashes, cumb\'ring earth\nNo longer, since in evil act so far\nThou hast outdone thy seed?  I did not mark,\nThrough all the gloomy circles of the\' abyss,\nSpirit, that swell\'d so proudly \'gainst his God,\nNot him, who headlong fell from Thebes.  He fled,\nNor utter\'d more; and after him there came\nA centaur full of fury, shouting, \"Where\nWhere is the caitiff?\"  On Maremma\'s marsh\nSwarm not the serpent tribe, as on his haunch\nThey swarm\'d, to where the human face begins.\nBe");
    strcat(expected_filecontent, "hind his head upon the shoulders lay,\nWith open wings, a dragon breathing fire\nOn whomsoe\'er he met.  To me my guide:\n\"Cacus is this, who underneath the rock\nOf Aventine spread oft a lake of blood.\nHe, from his brethren parted, here must tread\nA different journey, for his fraudful theft\n");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\INsECt\\SLIp\\DESIGn\\SIstER\\sTilL\\COmPleTE\\iCe.txT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4383; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[732] = "";

                strcat(expected_filecontent, "this laughter on its bloomy shores,\nAre but a preface, shadowy of the truth\nThey emblem: not that, in themselves, the things\nAre crude; but on thy part is the defect,\nFor that thy views not yet aspire so high.\"\nNever did babe, that had outslept his wont,\nRush, with such eager straining, to the milk,\nAs I toward the water, bending me,\nTo make the better mirrors of mine eyes\nIn the refining wave; and, as the eaves\nOf mine eyelids did drink of it, forthwith\nSeem\'d it unto me turn\'d from length to round,\nThen as a troop of maskers, when they put\nTheir vizors off, look other than before,\nThe counterfeited semblance thrown aside;\nSo into greater jubilee were chang\'d\nThose flowers and sparkles, and distinct I saw\nBefore me eithe");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SIT\\CReATe\\FRuIT\\SURprisE\\fRuiT\\STEad\\MILlIoN.biN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 731; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[246] = "";

                strcat(expected_filecontent, " Spenser, F. Q. b. iv. c. viii. st. 15.\n        For he whose daies in wilful woe are worne\n        The grace of his Creator doth despise,\n        That will not use his gifts for thankless\nnigardise.\n\nv. 53.  Cahors.]  A city in Guienne, much fre");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SIT\\sTUDY\\TWEnty\\TALK\\DID\\SUN.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 245; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[648] = "";

                strcat(expected_filecontent, "le girds the world)\nOf that lov\'d monarch, in whose happy reign\nNo ill had power to harm, I saw rear\'d up,\nIn colour like to sun-illumin\'d gold.\nA ladder, which my ken pursued in vain,\nSo lofty was the summit; down whose steps\nI saw the splendours in such multitude\nDescending, ev\'ry light in heav\'n, methought,\nWas shed thence.  As the rooks, at dawn of day\nBestirring them to dry their feathers chill,\nSome speed their way a-field, and homeward some,\nReturning, cross their flight, while some abide\nAnd wheel around their airy lodge; so seem\'d\nThat glitterance, wafted on alternate wing,\nAs upon certain stair it met, and clash\'d\nIts shining. An");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SIT\\If\\WITH\\FIsh\\sTOOD\\BY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 647; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[504] = "";

                strcat(expected_filecontent, "Ulisse,\n        Che per veder nell\' altro mondo gisse.\n               Morg. Magg. c. xxv\nAnd by Tasso, G. L. c. xv. 25.\n\nv. 106.  The strait pass.]  The straits of Gibraltar.\n\nv. 122.  Made our oars wings.l So Chiabrera, Cant. Eroiche. xiii\n               Faro de\'remi un volo.\nAnd Tasso Ibid. 26.\n\nv. 128.  A mountain dim.] The mountain of Purgatorg\n\nCANTO XXVII.\n\nv. 6.  The Sicilian Bull.] The engine of torture invented by\nPerillus, for the tyrant Phalaris.\n\nv. 26.  Of the mountains there.]  Montef");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SOFt\\ME\\nATURE\\WAIt\\aLl\\HAt\\FISh.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 503; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[181] = "";

                strcat(expected_filecontent, "Ye citizens\nWere wont to name me Ciacco.  For the sin\nOf glutt\'ny, damned vice, beneath this rain,\nE\'en as thou see\'st, I with fatigue am worn;\nNor I sole spirit in this woe:  all ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SIT\\CoMpANY\\MUCh\\bAND\\BETTER.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 180; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[417] = "";

                strcat(expected_filecontent, "be increas\'d,\nOr mitigated, or as now severe?\"\n     He then:  \"Consult thy knowledge; that decides\nThat as each thing to more perfection grows,\nIt feels more sensibly both good and pain.\nThough ne\'er to true perfection may arrive\nThis race accurs\'d, yet nearer then than now\nThey shall approach it.\"  Compassing that path\nCircuitous we journeyed, and discourse\nMuch more than I relate between us pass\'d:\nTill at the ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITeiNA\\PApER\\DON'T\\WaRM.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 416; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7070] = "";

                strcat(expected_filecontent, ", ye to my caves approach?\"\n     My guide, then laying hold on me, by words\nAnd intimations given with hand and head,\nMade my bent knees and eye submissive pay\nDue reverence; then thus to him replied.\n     \"Not of myself I come; a Dame from heaven\nDescending, had besought me in my charge\nTo bring.  But since thy will implies, that more\nOur true condition I unfold at large,\nMine is not to deny thee thy request.\nThis mortal ne\'er hath seen the farthest gloom.\nBut erring by his folly had approach\'d\nSo near, that little space was left to turn.\nThen, as before I told, I was dispatch\'d\nTo work his rescue, and no way remain\'d\nSave this which I have ta\'en.  I have display\'d\nBefore him all the regions of the bad;\nAnd purpose now those spirits to display,\nThat under thy command are purg\'d from sin.\nHow I have brought him would be long to say.\nFrom high descends the virtue, by whose aid\nI to thy sight and hearing him have led.\nNow may our coming please thee.  In the search\nOf liberty he journeys: that how dear\nThey know, who for her sake have life refus\'d.\nThou knowest, to whom death for her was sweet\nIn Utica, where thou didst leave those weeds,\nThat in the last great day will shine so bright.\nFor us the\' eternal edicts are unmov\'d:\nHe breathes, and I am free of Minos\' power,\nAbiding in that circle where the eyes\nOf thy chaste Marcia beam, who still in look\nPrays thee, O hallow\'d spirit!  to own her shine.\nThen by her love we\' implore thee, let us pass\nThrough thy sev\'n regions; for which best thanks\nI for thy favour will to her return,\nIf mention there below thou not disdain.\"\n     \"Marcia so pleasing in my sight was found,\"\nHe then to him rejoin\'d, \"while I was there,\nThat all she ask\'d me I was fain to grant.\nNow that beyond the\' accursed stream she dwells,\nShe may no longer move me, by that law,\nWhich was ordain\'d me, when I issued thence.\nNot so, if Dame from heaven, as thou sayst,\nMoves and directs thee; then no flattery needs.\nEnough for me that in her name thou ask.\nGo therefore now: and with a slender reed\nSee that thou duly gird him, and his face\nLave, till all sordid stain thou wipe from thence.\nFor not with eye, by any cloud obscur\'d,\nWould it be seemly before him to come,\nWho stands the foremost minister in heaven.\nThis islet all around, there far beneath,\nWhere the wave beats it, on the oozy bed\nProduces store of reeds. No other plant,\nCover\'d with leaves, or harden\'d in its stalk,\nThere lives, not bending to the water\'s sway.\nAfter, this way return not; but the sun\nWill show you, that now rises, where to take\nThe mountain in its easiest ascent.\"\n     He disappear\'d; and I myself uprais\'d\nSpeechless, and to my guide retiring close,\nToward him turn\'d mine eyes.  He thus began;\n\"My son!  observant thou my steps pursue.\nWe must retreat to rearward, for that way\nThe champain to its low extreme declines.\"\n     The dawn had chas\'d the matin hour of prime,\nWhich deaf before it, so that from afar\nI spy\'d the trembling of the ocean stream.\n     We travers\'d the deserted plain, as one\nWho, wander\'d from his track, thinks every step\nTrodden in vain till he regain the path.\n     When we had come, where yet the tender dew\nStrove with the sun, and in a place, where fresh\nThe wind breath\'d o\'er it, while it slowly dried;\nBoth hands extended on the watery grass\nMy master plac\'d, in graceful act and kind.\nWhence I of his intent before appriz\'d,\nStretch\'d out to him my cheeks suffus\'d with tears.\nThere to my visage he anew restor\'d\nThat hue, which the dun shades of hell conceal\'d.\n     Then on the solitary shore arriv\'d,\nThat never sailing on its waters saw\nMan, that could after measure back his course,\nHe girt me in such manner as had pleas\'d\nHim who instructed, and O, strange to tell!\nAs he selected every humble plant,\nWherever one was pluck\'d, another there\nResembling, straightway in its place arose.\n\n\n\nCANTO II\n\nNow had the sun to that horizon reach\'d,\nThat covers, with the most exalted point\nOf its meridian circle, Salem\'s walls,\nAnd night, that opposite to him her orb\nSounds, from the stream of Ganges issued forth,\nHolding the ");
    strcat(expected_filecontent, "scales, that from her hands are dropp\'d\nWhen she reigns highest: so that where I was,\nAurora\'s white and vermeil-tinctur\'d cheek\nTo orange turn\'d as she in age increas\'d.\n     Meanwhile we linger\'d by the water\'s brink,\nLike men, who, musing on their road, in thought\nJourney, while motionless the body rests.\nWhen lo!  as near upon the hour of dawn,\nThrough the thick vapours Mars with fiery beam\nGlares down in west, over the ocean floor;\nSo seem\'d, what once again I hope to view,\nA light so swiftly coming through the sea,\nNo winged course might equal its career.\nFrom which when for a space I had withdrawn\nThine eyes, to make inquiry of my guide,\nAgain I look\'d and saw it grown in size\nAnd brightness: thou on either side appear\'d\nSomething, but what I knew not of bright hue,\nAnd by degrees from underneath it came\nAnother.  My preceptor silent yet\nStood, while the brightness, that we first discern\'d,\nOpen\'d the form of wings: then when he knew\nThe pilot, cried aloud, \"Down, down; bend low\nThy knees; behold God\'s angel: fold thy hands:\nNow shalt thou see true Ministers indeed.\nLo how all human means he sets at naught!\nSo that nor oar he needs, nor other sail\nExcept his wings, between such distant shores.\nLo how straight up to heaven he holds them rear\'d,\nWinnowing the air with those eternal plumes,\nThat not like mortal hairs fall off or change!\"\n     As more and more toward us came, more bright\nAppear\'d the bird of God, nor could the eye\nEndure his splendor near:  I mine bent down.\nHe drove ashore in a small bark so swift\nAnd light, that in its course no wave it drank.\nThe heav\'nly steersman at the prow was seen,\nVisibly written blessed in his looks.\nWithin a hundred spirits and more there sat.\n\"In Exitu Israel de Aegypto;\"\nAll with one voice together sang, with what\nIn the remainder of that hymn is writ.\nThen soon as with the sign of holy cross\nHe bless\'d them, they at once leap\'d out on land,\nThe swiftly as he came return\'d. The crew,\nThere left, appear\'d astounded with the place,\nGazing around as one who sees new sights.\n     From every side the sun darted his beams,\nAnd with his arrowy radiance from mid heav\'n\nHad chas\'d the Capricorn, when that strange tribe\nLifting their eyes towards us: If ye know,\nDeclare what path will Lead us to the mount.\"\n     Them Virgil answer\'d.  \"Ye suppose perchance\nUs well acquainted with this place: but here,\nWe, as yourselves, are strangers.  Not long erst\nWe came, before you but a little space,\nBy other road so rough and hard, that now\nThe\' ascent will seem to us as play.\"  The spirits,\nWho from my breathing had perceiv\'d I liv\'d,\nGrew pale with wonder.  As the multitude\nFlock round a herald, sent with olive branch,\nTo hear what news he brings, and in their haste\nTread one another down, e\'en so at sight\nOf me those happy spirits were fix\'d, each one\nForgetful of its errand, to depart,\nWhere cleans\'d from sin, it might be made all fair.\n     Then one I saw darting before the rest\nWith suc");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\SIT\\IF\\NEIgHBOR\\cELl\\SYmBOL\\We\\bRiGHT.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7069; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[894] = "";

                strcat(expected_filecontent, "Those waters, that grief forces out from one\nBy deep resentment stung, who seem\'d to say:\n\"If thou, Pisistratus, be lord indeed\nOver this city, nam\'d with such debate\nOf adverse gods, and whence each science sparkles,\nAvenge thee of those arms, whose bold embrace\nHath clasp\'d our daughter; \"and to fuel, meseem\'d,\nBenign and meek, with visage undisturb\'d,\nHer sovran spake:  \"How shall we those requite,\nWho wish us evil, if we thus condemn\nThe man that loves us?\"  After that I saw\nA multitude, in fury burning, slay\nWith stones a stripling youth, and shout amain\n\"Destroy, destroy: \"and him I saw, who bow\'d\nHeavy with death unto the ground, yet made\nHis eyes, unfolded upward, gates to heav\'n,\nPraying forgiveness of th\' Almighty Sire,\nAmidst that cruel conflict, on his foes,\nWith looks, that With compassion to their aim.\n     Soon as my spirit, from her airy flight\nReturning, sought ag");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\INsECT\\sLiP\\DESIGN\\SISTeR\\scaLE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 893; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[680] = "";

                strcat(expected_filecontent, "e.\"\n\nv. 43.  Such diff\'rence.]  The material world and the\nintelligential (the copy and the pattern) appear to Dante to\ndiffer in this respect, that the orbits of the latter are more\nswift, the nearer they are to the centre, whereas the contrary is\nthe case with the orbits of the former. The seeming contradiction\nis thus accounted for by Beatrice.  In the material world, the\nmore ample the body is, the greater is the good of which itis\ncapable supposing all the parts to be equally perfect. But in the\nintelligential world, the circles are more excellent and\npowerful, the more they approximate to the central point, which\nis God.  Thus the first circle, that of the seraphim");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\LEARn\\cLOsE\\SHOUlD\\pAss\\CLAIm\\hUrrY");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 679; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5673] = "";

                strcat(expected_filecontent, "llers in this world, where power to sin\nNo longer tempts us.\"  Haply to make way\nFor one, that follow\'d next, when that was said,\nHe vanish\'d through the fire, as through the wave\nA fish, that glances diving to the deep.\n     I, to the spirit he had shown me, drew\nA little onward, and besought his name,\nFor which my heart, I said, kept gracious room.\nHe frankly thus began:  \"Thy courtesy\nSo wins on me, I have nor power nor will\nTo hide me.  I am Arnault; and with songs,\nSorely lamenting for my folly past,\nThorough this ford of fire I wade, and see\nThe day, I hope for, smiling in my view.\nI pray ye by the worth that guides ye up\nUnto the summit of the scale, in time\nRemember ye my suff\'rings.\"  With such words\nHe disappear\'d in the refining flame.\n\n\n\nCANTO XXVII\n\nNow was the sun so station\'d, as when first\nHis early radiance quivers on the heights,\nWhere stream\'d his Maker\'s blood, while Libra hangs\nAbove Hesperian Ebro, and new fires\nMeridian flash on Ganges\' yellow tide.\n     So day was sinking, when the\' angel of God\nAppear\'d before us.  Joy was in his mien.\nForth of the flame he stood upon the brink,\nAnd with a voice, whose lively clearness far\nSurpass\'d our human, \"Blessed are the pure\nIn heart,\" he Sang:  then near him as we came,\n\"Go ye not further, holy spirits!\"  he cried,\n\"Ere the fire pierce you: enter in; and list\nAttentive to the song ye hear from thence.\"\n     I, when I heard his saying, was as one\nLaid in the grave.  My hands together clasp\'d,\nAnd upward stretching, on the fire I look\'d,\nAnd busy fancy conjur\'d up the forms\nErewhile beheld alive consum\'d in flames.\n     Th\' escorting spirits turn\'d with gentle looks\nToward me, and the Mantuan spake:  \"My son,\nHere torment thou mayst feel, but canst not death.\nRemember thee, remember thee, if I\nSafe e\'en on Geryon brought thee: now I come\nMore near to God, wilt thou not trust me now?\nOf this be sure: though in its womb that flame\nA thousand years contain\'d thee, from thy head\nNo hair should perish.  If thou doubt my truth,\nApproach, and with thy hands thy vesture\'s hem\nStretch forth, and for thyself confirm belief.\nLay now all fear, O lay all fear aside.\nTurn hither, and come onward undismay\'d.\"\nI still, though conscience urg\'d\' no step advanc\'d.\n     When still he saw me fix\'d and obstinate,\nSomewhat disturb\'d he cried:  \"Mark now, my son,\nFrom Beatrice thou art by this wall\nDivided.\"  As at Thisbe\'s name the eye\nOf Pyramus was open\'d (when life ebb\'d\nFast from his veins), and took one parting glance,\nWhile vermeil dyed the mulberry; thus I turn\'d\nTo my sage guide, relenting, when I heard\nThe name, that springs forever in my breast.\n     He shook his forehead; and, \"How long,\" he said,\n\"Linger we now?\"  then smil\'d, as one would smile\nUpon a child, that eyes the fruit and yields.\nInto the fire before me then he walk\'d;\nAnd Statius, who erewhile no little space\nHad parted us, he pray\'d to come behind.\n     I would have cast me into molten glass\nTo cool me, when I enter\'d; so intense\nRag\'d the conflagrant mass.  The sire belov\'d,\nTo comfort me, as he proceeded, still\nOf Beatrice talk\'d.  \"Her eyes,\" saith he,\n\"E\'en now I seem to view.\"  From the other side\nA voice, that sang, did guide us, and the voice\nFollowing, with heedful ear, we issued forth,\nThere where the path led upward.  \"Come,\" we heard,\n\"Come, blessed of my Father.\"  Such the sounds,\nThat hail\'d us from within a light, which shone\nSo radiant, I could not endure the view.\n\"The sun,\" it added, \"hastes: and evening comes.\nDelay not: ere the western sky is hung\nWith blackness, strive ye for the pass.\"  Our way\nUpright within the rock arose, and fac\'d\nSuch part of heav\'n, that from before my steps\nThe beams were shrouded of the sinking sun.\n     Nor many stairs were overpass, when now\nBy fading of the shadow we perceiv\'d\nThe sun behind us couch\'d: and ere one face\nOf darkness o\'er its measureless expanse\nInvolv\'d th\' horizon, and the night her lot\nHeld individual, each of us had made\nA stair his pallet: not that will, but power,\nHad fail\'d us, by the nature of that mount\nForbidden further travel.  As");
    strcat(expected_filecontent, " the goats,\nThat late have skipp\'d and wanton\'d rapidly\nUpon the craggy cliffs, ere they had ta\'en\nTheir supper on the herb, now silent lie\nAnd ruminate beneath the umbrage brown,\nWhile noonday rages; and the goatherd leans\nUpon his staff, and leaning watches them:\nAnd as the swain, that lodges out all night\nIn quiet by his flock, lest beast of prey\nDisperse them; even so all three abode,\nI as a goat and as the shepherds they,\nClose pent on either side by shelving rock.\n     A little glimpse of sky was seen above;\nYet by that little I beheld the stars\nIn magnitude and rustle shining forth\nWith more than wonted glory.  As I lay,\nGazing on them, and in that fit of musing,\nSleep overcame me, sleep, that bringeth oft\nTidings of future hap.  About the hour,\nAs I believe, when Venus from the east\nFirst lighten\'d on the mountain, she whose orb\nSeems always glowing with the fire of love,\nA lady young and beautiful, I dream\'d,\nWas passing o\'er a lea; and, as she came,\nMethought I saw her ever and anon\nBending to cull the flowers; and thus she sang:\n\"Know ye, whoever of my name would ask,\nThat I am Leah: for my brow to weave\nA garland, these fair hands unwearied ply.\nTo please me at the crystal mirror, here\nI deck me.  But my sister Rachel, she\nBefore her glass abides the livelong day,\nHer radiant eyes beholding, charm\'d no less,\nThan I with this delightful task.  Her joy\nIn contemplation, as in labour mine.\"\n     And now as glimm\'ring dawn appear\'d, that breaks\nMore welcome to the pilgrim still, as he\nSojourns less distant on his homeward way,\nDarkness from al");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRitEINA\\fEel\\SING\\CONSidER\\weRE\\sHAPE.txT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5672; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[855] = "";

                strcat(expected_filecontent, " the confession and sorrow of the offender.\"\n\nv. 58.  Bird.]  Prov. c. i. 17\n\nv. 69.  From Iarbas\' land.]  The south.\n\nv. 71.  The beard.]  \"I perceived, that when she desired me to\nraise my beard, instead of telling me to lift up my head, a\nsevere reflection was implied on my want of that wisdom which\nshould accompany the age of manhood.\"\n\nv. 98.  Tu asperges me.]  A prayer repeated by the priest at\nsprinkling the holy water.\n\nv. 106.  And in the heaven are stars.]  See Canto I. 24.\n\nv. 116.  The emeralds.]  The eyes of Beatrice.\n\nCANTO XXXII\n\nv. 2.  Their ten years\' thirst.]  Beatrice had been dead ten\nyears.\n\nv. 9.  Two fix\'d a gaze.]  The allegorical interpretation of\nVellutello whether it be considered as justly terrible from the\ntext or not, conveys so useful a lesson, that it deserves our\nnotice. \"The understanding is sometimes so inte");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRiTEiNA\\knoW.BIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 854; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[698] = "";

                strcat(expected_filecontent, "s existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be app");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WriTEInA\\BE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 697; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[332] = "";

                strcat(expected_filecontent, "\nCame to Antaeus, who five ells complete\nWithout the head, forth issued from the cave.\n     \"O thou, who in the fortunate vale, that made\nGreat Scipio heir of glory, when his sword\nDrove back the troop of Hannibal in flight,\nWho thence of old didst carry for thy spoil\nAn hundred lions; and if thou hadst fought\nIn the high conflic");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRiteiNA\\WEST.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 331; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[951] = "";

                strcat(expected_filecontent, "ht of the last day of the month of any such announcement.\nThe official release date of all Project Gutenberg Etexts is at\nMidnight, Central Time, of the last day of the stated month.  A\npreliminary version may often be posted for suggestion, comment\nand editing by those who wish to do so.  To be sure you have an\nup to date first edition [xxxxx10x.xxx] please check file sizes\nin the first week of the next month.  Since our ftp program has\na bug in it that scrambles the date [tried to fix and failed] a\nlook at the file size will have to do, but we will try to see a\nnew copy has at least one byte more or less.\n\n\nInformation about Project Gutenberg (one page)\n\nWe produce about two million dollars for each hour we work.  The\nfifty hours is one conservative estimate for how long it we take\nto get any etext selected, entered, proofread, edited, copyright\nsearched and analyzed, the copyright letters written, etc.  This\nprojected audience is one");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITEiNA\\SMILE.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 950; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7187] = "";

                strcat(expected_filecontent, " I left the bank,\nAlong the champain leisurely my way\nPursuing, o\'er the ground, that on all sides\nDelicious odour breath\'d.  A pleasant air,\nThat intermitted never, never veer\'d,\nSmote on my temples, gently, as a wind\nOf softest influence: at which the sprays,\nObedient all, lean\'d trembling to that part\nWhere first the holy mountain casts his shade,\nYet were not so disorder\'d, but that still\nUpon their top the feather\'d quiristers\nApplied their wonted art, and with full joy\nWelcom\'d those hours of prime, and warbled shrill\nAmid the leaves, that to their jocund lays\ninept tenor; even as from branch to branch,\nAlong the piney forests on the shore\nOf Chiassi, rolls the gath\'ring melody,\nWhen Eolus hath from his cavern loos\'d\nThe dripping south.  Already had my steps,\nThough slow, so far into that ancient wood\nTransported me, I could not ken the place\nWhere I had enter\'d, when behold!  my path\nWas bounded by a rill, which to the left\nWith little rippling waters bent the grass,\nThat issued from its brink.  On earth no wave\nHow clean soe\'er, that would not seem to have\nSome mixture in itself, compar\'d with this,\nTranspicuous, clear; yet darkly on it roll\'d,\nDarkly beneath perpetual gloom, which ne\'er\nAdmits or sun or moon light there to shine.\n     My feet advanc\'d not; but my wond\'ring eyes\nPass\'d onward, o\'er the streamlet, to survey\nThe tender May-bloom, flush\'d through many a hue,\nIn prodigal variety: and there,\nAs object, rising suddenly to view,\nThat from our bosom every thought beside\nWith the rare marvel chases, I beheld\nA lady all alone, who, singing, went,\nAnd culling flower from flower, wherewith her way\nWas all o\'er painted.  \"Lady beautiful!\nThou, who (if looks, that use to speak the heart,\nAre worthy of our trust), with love\'s own beam\nDost warm thee,\" thus to her my speech I fram\'d:\n\"Ah!  please thee hither towards the streamlet bend\nThy steps so near, that I may list thy song.\nBeholding thee and this fair place, methinks,\nI call to mind where wander\'d and how look\'d\nProserpine, in that season, when her child\nThe mother lost, and she the bloomy spring.\"\n     As when a lady, turning in the dance,\nDoth foot it featly, and advances scarce\nOne step before the other to the ground;\nOver the yellow and vermilion flowers\nThus turn\'d she at my suit, most maiden-like,\nValing her sober eyes, and came so near,\nThat I distinctly caught the dulcet sound.\nArriving where the limped waters now\nLav\'d the green sward, her eyes she deign\'d to raise,\nThat shot such splendour on me, as I ween\nNe\'er glanced from Cytherea\'s, when her son\nHad sped his keenest weapon to her heart.\nUpon the opposite bank she stood and smil\'d\nthrough her graceful fingers shifted still\nThe intermingling dyes, which without seed\nThat lofty land unbosoms.  By the stream\nThree paces only were we sunder\'d: yet\nThe Hellespont, where Xerxes pass\'d it o\'er,\n(A curb for ever to the pride of man)\nWas by Leander not more hateful held\nFor floating, with inhospitable wave\n\'Twixt Sestus and Abydos, than by me\nThat flood, because it gave no passage thence.\n     \"Strangers ye come, and haply in this place,\nThat cradled human nature in its birth,\nWond\'ring, ye not without suspicion view\nMy smiles: but that sweet strain of psalmody,\n\'Thou, Lord!  hast made me glad,\' will give ye light,\nWhich may uncloud your minds.  And thou, who stand\'st\nThe foremost, and didst make thy suit to me,\nSay if aught else thou wish to hear: for I\nCame prompt to answer every doubt of thine.\"\n     She spake; and I replied:  \"l know not how\nTo reconcile this wave and rustling sound\nOf forest leaves, with what I late have heard\nOf opposite report.\"  She answering thus:\n\"I will unfold the cause, whence that proceeds,\nWhich makes thee wonder; and so purge the cloud\nThat hath enwraps thee.  The First Good, whose joy\nIs only in himself, created man\nFor happiness, and gave this goodly place,\nHis pledge and earnest of eternal peace.\nFavour\'d thus highly, through his own defect\nHe fell, and here made short sojourn; he fell,\nAnd, for the bitterness of sorrow, chang\'d\nLaughter unblam\'d and ever-new delight");
    strcat(expected_filecontent, ".\nThat vapours none, exhal\'d from earth beneath,\nOr from the waters (which, wherever heat\nAttracts them, follow), might ascend thus far\nTo vex man\'s peaceful state, this mountain rose\nSo high toward the heav\'n, nor fears the rage\n0f elements contending, from that part\nExempted, where the gate his limit bars.\nBecause the circumambient air throughout\nWith its first impulse circles still, unless\nAught interpose to cheek or thwart its course;\nUpon the summit, which on every side\nTo visitation of th\' impassive air\nIs open, doth that motion strike, and makes\nBeneath its sway th\' umbrageous wood resound:\nAnd in the shaken plant such power resides,\nThat it impregnates with its efficacy\nThe voyaging breeze, upon whose subtle plume\nThat wafted flies abroad; and th\' other land\nReceiving (as \'t is worthy in itself,\nOr in the clime, that warms it), doth conceive,\nAnd from its womb produces many a tree\nOf various virtue.  This when thou hast heard,\nThe marvel ceases, if in yonder earth\nSome plant without apparent seed be found\nTo fix its fibrous stem.  And further learn,\nThat with prolific foison of all seeds,\nThis holy plain is fill\'d, and in itself\nBears fruit that ne\'er was pluck\'d on other soil.\n \"The water, thou behold\'st, springs not from vein,\nAs stream, that intermittently repairs\nAnd spends his pulse of life, but issues forth\nFrom fountain, solid, undecaying, sure;\nAnd by the will omnific, full supply\nFeeds whatsoe\'er On either side it pours;\nOn this devolv\'d with power to take away\nRemembrance of offence, on that to bring\nRemembrance back of every good deed done.\nFrom whence its name of Lethe on this part;\nOn th\' other Eunoe: both of which must first\nBe tasted ere it work; the last exceeding\nAll flavours else.  Albeit thy thirst may now\nBe well contented, if I here break off,\nNo more revealing: yet a corollary\nI freely give beside: nor deem my words\nLess grateful to thee, if they somewhat pass\nThe stretch of promise.  They, whose verse of yore\nThe golden age recorded and its bliss,\nOn the Parnassian mountain, of this place\nPerhaps had dream\'d.  Here was man guiltless, here\nPerpetual spring and every fruit, and this\nThe far-fam\'d nectar.\"  Turning to the bards,\nWhen she had ceas\'d, I noted in their looks\nA smile at her conclusion; then my face\nAgain directed to the lovely dame.\n\n\n\nCANTO XXIX\n\nSinging, as if enamour\'d, she resum\'d\nAnd clos\'d the song, with \"Blessed they whose sins\nAre cover\'d.\"  Like the wood-nymphs then, that tripp\'d\nSingly across the sylvan shadows, one\nEager to view and one to \'scape the sun,\nSo mov\'d she on, against the current, up\nThe verdant rivage.  I, her mincing step\nObserving, with as tardy step pursued.\n     Between us not an hundred paces trod,\nThe bank, on each side bending equally,\nGave me to face the orient.  Nor our way\nFar onward brought us, when to me at once\nShe turn\'d, and cried:  \"My brother!  look and hearken.\"\nAnd lo!  a sudden lustre ran across\nThrough the great forest on all parts, so bright\nI doubted whether lightning were abroad;\nBut that expiring ever in the spleen,\nThat doth unfold it, and this d");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRitEINA\\miNE.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7186; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3637] = "";

                strcat(expected_filecontent, "all city on the same coast in the patrimony of the church.\n\nv. 12.  The Strophades.]  See Virg. Aen. l. iii. 210.\n\nv. 14.  Broad are their pennons.]  From Virg. Aen. l. iii. 216.\n\nv. 48.  In my verse described.]  The commentators explain this,\n\"If he could have believed, in consequence of my assurances\nalone, that of which he hath now had ocular proof, he would not\nhave stretched forth his hand against thee.\"  But I am of opinion\nthat Dante makes Virgil allude to his own story of Polydorus in\nthe third book of the Aeneid.\n\nv. 56.  That pleasant word of thine.]  \"Since you have inveigled\nme to speak my holding forth so gratifying an expectation, let it\nnot displease you if I am as it were detained in the snare you\nhave spread for me, so as to be somewhat prolix in my answer.\"\n\nv. 60. I it was.]  Pietro delle Vigne, a native of Capua, who,\nfrom a low condition, raised himself by his eloquence and legal\nknowledge to the office of Chancellor to the Emperor Frederick\nII. whose confidence in him was such, that his influence in the\nempire became unbounded.  The courtiers, envious of his exalted\nsituation, contrived, by means of forged letters, to make\nFrederick believe that he held a secret and traitorous\nintercourse with the Pope, who was then at enmity with the\nEmperor.  In consequence of this supposed crime he was cruelly\ncondemned by his too credulous sovereign to lose his eyes, and,\nbeing driven to despair by his unmerited calamity and disgrace,\nhe put an end to his life by dashing out his brains against the\nwalls of a church, in the year 1245.  Both Frederick and Pietro\ndelle Vigne composed verses in the Sicilian dialect which are yet\nextant.\n\nv. 67.  The harlot.]  Envy.  Chaucer alludes to this in the\nPrologue to the Legende of Good women.\n        Envie is lavender to the court alway,\n        For she ne parteth neither night ne day\n        Out of the house of Cesar; thus saith Dant.\n\nv. 119.  Each fan o\' th\' wood.]  Hence perhaps Milton:\n        Leaves and fuming rills, Aurora\'s fan.\n               P. L. b. v. 6.\n\nv. 122.  Lano.]  Lano, a Siennese, who, being reduced by\nprodigality to a state of extreme want, found his existence no\nlonger supportable; and, having been sent by his countrymen on a\nmilitary expedition, to assist the Florentine against the\nAretini, took that opportunity of exposing himself to certain\ndeath, in the engagement which took place at Toppo near Arezzo.\nSee G. Villani, Hist. l. 7. c. cxix.\n\nv. 133.               O Giocomo\n        Of Sant\' Andrea!]\nJacopo da Sant\' Andrea, a Paduan, who, having wasted his property\nin the most wanton acts of profusion, killed himself in despair.\nv. 144.  In that City.]  \"I was an inhabitant of Florence, that\ncity which changed her first patron Mars for St. John the\nBaptist, for which reason the vengeance of the deity thus\nslighted will never be appeased:  and, if some remains of his\nstatus were not still visible on the bridge over the Arno, she\nwould have been already leveled to the ground; and thus the\ncitizens, who raised her again from the ashes to which Attila had\nreduced her, would have laboured in vain.\"  See Paradise, Canto\nXVI. 44.\nThe relic of antiquity to which the superstition of Florence\nattached so high an importance, was carried away by a flood, that\ndestroyed the bridge on which it stood, in the year 1337, but\nwithout the ill effects that were apprehended from the loss of\ntheir fancied Palladium.\n\nv. 152.  I slung the fatal noose.]  We are not informed who this\nsuicide was.\n\n\nCANTO XIV\n\nv. 15.  By Cato\'s foot.]  See Lucan, Phars, l. 9.\n\nv. 26. Dilated flakes of fire.]  Compare Tasso.  G. L. c. x. st.\n6");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRITeInA\\OLD.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3636; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6999] = "";

                strcat(expected_filecontent, "!\nWhat canst thou more, who hast subdued our blood\nSo wholly to thyself, they feel no care\nOf their own flesh?  To hide with direr guilt\nPast ill and future, lo!  the flower-de-luce\nEnters Alagna!  in his Vicar Christ\nHimself a captive, and his mockery\nActed again! Lo!  to his holy lip\nThe vinegar and gall once more applied!\nAnd he \'twixt living robbers doom\'d to bleed!\nLo!  the new Pilate, of whose cruelty\nSuch violence cannot fill the measure up,\nWith no degree to sanction, pushes on\nInto the temple his yet eager sails!\n     \"O sovran Master!  when shall I rejoice\nTo see the vengeance, which thy wrath well-pleas\'d\nIn secret silence broods?--While daylight lasts,\nSo long what thou didst hear of her, sole spouse\nOf the Great Spirit, and on which thou turn\'dst\nTo me for comment, is the general theme\nOf all our prayers: but when it darkens, then\nA different strain we utter, then record\nPygmalion, whom his gluttonous thirst of gold\nMade traitor, robber, parricide: the woes\nOf Midas, which his greedy wish ensued,\nMark\'d for derision to all future times:\nAnd the fond Achan, how he stole the prey,\nThat yet he seems by Joshua\'s ire pursued.\nSapphira with her husband next, we blame;\nAnd praise the forefeet, that with furious ramp\nSpurn\'d Heliodorus.  All the mountain round\nRings with the infamy of Thracia\'s king,\nWho slew his Phrygian charge: and last a shout\nAscends:  \"Declare, O Crassus!  for thou know\'st,\nThe flavour of thy gold.\"  The voice of each\nNow high now low, as each his impulse prompts,\nIs led through many a pitch, acute or grave.\nTherefore, not singly, I erewhile rehears\'d\nThat blessedness we tell of in the day:\nBut near me none beside his accent rais\'d.\"\n     From him we now had parted, and essay\'d\nWith utmost efforts to surmount the way,\nWhen I did feel, as nodding to its fall,\nThe mountain tremble; whence an icy chill\nSeiz\'d on me, as on one to death convey\'d.\nSo shook not Delos, when Latona there\nCouch\'d to bring forth the twin-born eyes of heaven.\n     Forthwith from every side a shout arose\nSo vehement, that suddenly my guide\nDrew near, and cried: \"Doubt not, while I conduct thee.\"\n\"Glory!\" all shouted (such the sounds mine ear\nGather\'d from those, who near me swell\'d the sounds)\n\"Glory in the highest be to God.\"  We stood\nImmovably suspended, like to those,\nThe shepherds, who first heard in Bethlehem\'s field\nThat song: till ceas\'d the trembling, and the song\nWas ended: then our hallow\'d path resum\'d,\nEying the prostrate shadows, who renew\'d\nTheir custom\'d mourning.  Never in my breast\nDid ignorance so struggle with desire\nOf knowledge, if my memory do not err,\nAs in that moment; nor through haste dar\'d I\nTo question, nor myself could aught discern,\nSo on I far\'d in thoughtfulness and dread.\n\n\n\nCANTO XXI\n\nThe natural thirst, ne\'er quench\'d but from the well,\nWhereof the woman of Samaria crav\'d,\nExcited: haste along the cumber\'d path,\nAfter my guide, impell\'d; and pity mov\'d\nMy bosom for the \'vengeful deed, though just.\nWhen lo!  even as Luke relates, that Christ\nAppear\'d unto the two upon their way,\nNew-risen from his vaulted grave; to us\nA shade appear\'d, and after us approach\'d,\nContemplating the crowd beneath its feet.\nWe were not ware of it; so first it spake,\nSaying, \"God give you peace, my brethren!\" then\nSudden we turn\'d: and Virgil such salute,\nAs fitted that kind greeting, gave, and cried:\n\"Peace in the blessed council be thy lot\nAwarded by that righteous court, which me\nTo everlasting banishment exiles!\"\n     \"How!\" he exclaim\'d, nor from his speed meanwhile\nDesisting, \"If that ye be spirits, whom God\nVouchsafes not room above, who up the height\nHas been thus far your guide?\"  To whom the bard:\n\"If thou observe the tokens, which this man\nTrac\'d by the finger of the angel bears,\n\'Tis plain that in the kingdom of the just\nHe needs must share.  But sithence she, whose wheel\nSpins day and night, for him not yet had drawn\nThat yarn, which, on the fatal distaff pil\'d,\nClotho apportions to each wight that breathes,\nHis soul, that sister is to mine and thine,\nNot of herself could mount, for not like ours\nHe");
    strcat(expected_filecontent, "r ken: whence I, from forth the ample gulf\nOf hell was ta\'en, to lead him, and will lead\nFar as my lore avails.  But, if thou know,\nInstruct us for what cause, the mount erewhile\nThus shook and trembled: wherefore all at once\nSeem\'d shouting, even from his wave-wash\'d foot.\"\n     That questioning so tallied with my wish,\nThe thirst did feel abatement of its edge\nE\'en from expectance.  He forthwith replied,\n\"In its devotion nought irregular\nThis mount can witness, or by punctual rule\nUnsanction\'d; here from every change exempt.\nOther than that, which heaven in itself\nDoth of itself receive, no influence\nCan reach us.  Tempest none, shower, hail or snow,\nHoar frost or dewy moistness, higher falls\nThan that brief scale of threefold steps: thick clouds\nNor scudding rack are ever seen: swift glance\nNe\'er lightens, nor Thaumantian Iris gleams,\nThat yonder often shift on each side heav\'n.\nVapour adust doth never mount above\nThe highest of the trinal stairs, whereon\nPeter\'s vicegerent stands.  Lower perchance,\nWith various motion rock\'d, trembles the soil:\nBut here, through wind in earth\'s deep hollow pent,\nI know not how, yet never trembled: then\nTrembles, when any spirit feels itself\nSo purified, that it may rise, or move\nFor rising, and such loud acclaim ensues.\nPurification by the will alone\nIs prov\'d, that free to change society\nSeizes the soul rejoicing in her will.\nDesire of bliss is present from the first;\nBut strong propension hinders, to that wish\nBy the just ordinance of heav\'n oppos\'d;\nPropension now as eager to fulfil\nTh\' allotted torment, as erewhile to sin.\nAnd I who in this punishment had lain\nFive hundred years and more, but now have felt\nFree wish for happier clime.  Therefore thou felt\'st\nThe mountain tremble, and the spirits devout\nHeard\'st, over all his limits, utter praise\nTo that liege Lord, whom I entreat their joy\nTo hasten.\"  Thus he spake: and since the draught\nIs grateful ever as the thirst is keen,\nNo words may speak my fullness of content.\n     \"Now,\" said the instructor sage, \"I see the net\nThat takes ye here, and how the toils are loos\'d,\nWhy rocks the mountain and why ye rejoice.\nVouchsafe, that from thy lips I next may learn,\nWho on the earth thou wast, and wherefore here\nSo many an age wert prostrate.\" --\"In that time,\nWhen the good Titus, with Heav\'n\'s King to help,\nAveng\'d those piteous gashes, whence the blood\nBy Judas sold did issue, with the name\nMost lasting and most honour\'d there was I\nAbundantly renown\'d,\" the shade reply\'d,\n\"Not yet with faith endued.  So passing sweet\nMy vocal Spirit, from Tolosa, Rome\nTo herself drew me, where I merited\nA myrtle garland to inwreathe my brow.\nStatius they name me still.  Of Thebes I sang,\nAnd next of great Achilles: but i\' th\' way\nFell with the second burthen.  Of my flame\nThose sparkles were the seeds, which I deriv\'d\nFrom the bright fountain of celestial fire\nThat feeds unnumber");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRiteinA\\iNTEREsT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6998; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[866] = "";

                strcat(expected_filecontent, "e rest.  But now,\nAs under snow the ground, if the warm ray\nSmites it, remains dismantled of the hue\nAnd cold, that cover\'d it before, so thee,\nDismantled in thy mind, I will inform\nWith light so lively, that the tremulous beam\nShall quiver where it falls.  Within the heaven,\nWhere peace divine inhabits, circles round\nA body, in whose virtue dies the being\nOf all that it contains.  The following heaven,\nThat hath so many lights, this being divides,\nThrough  different essences, from it distinct,\nAnd yet contain\'d within it.  The other orbs\nTheir separate distinctions variously\nDispose, for their own seed and produce apt.\nThus do these organs of the world proceed,\nAs thou beholdest now, from step to step,\nTheir influences from above deriving,\nAnd thence transmitting downwards.  Mark me well,\nHow through this passage to the truth I ford,\nThe truth thou lov");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEInA\\LEVEL.tXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 865; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5316] = "";

                strcat(expected_filecontent, " Eroiche. 32.\n        Onorando l\'altissimo poeta.\n\nv. 79.  Of semblance neither sorrowful nor glad.]\n        She nas to sober ne to glad.\n               Chaucer\'s Dream.\n\nv. 90.  The Monarch of sublimest song.]  Homer.\n\nv. 100.  Fitter left untold.]\n        Che\'l tacere e bello,\nSo our Poet, in Canzone 14.\n        La vide in parte che\'l tacere e bello,\nRuccellai, Le Api, 789.\n        Ch\'a dire e brutto ed a tacerlo e bello\nAnd Bembo,\n        \"Vie pui bello e il tacerle, che il favellarne.\"\n               Gli. Asol. lib. 1.\n\nv. 117.  Electra.]  The daughter of Atlas, and mother of Dardanus\nthe founder of Troy.  See Virg. Aen. b. viii. 134. as referred to\nby Dante in treatise \"De Monarchia,\" lib. ii. \"Electra, scilicet,\nnata magni nombris regis Atlantis, ut de ambobus testimonium\nreddit poeta noster in octavo ubi Aeneas ad Avandrum sic ait\n        \"Dardanus Iliacae,\" &c.\n\nv. 125.  Julia.]  The daughter of Julius Caesar, and wife of\nPompey.\n\nv. 126.  The Soldan fierce.]  Saladin or Salaheddin, the  rival\nof  Richard coeur de lion.  See D\'Herbelot, Bibl. Orient. and\nKnolles\'s Hist. of the Turks p. 57 to 73 and the Life of Saladin,\nby Bohao\'edin Ebn Shedad, published by Albert Schultens, with a\nLatin translation. He is introduced by Petrarch in the Triumph of\nFame, c. ii\n\nv. 128.  The master of the sapient throng.]\n        Maestro di color che sanno.\nAristotle--Petrarch assigns the first place to Plato. See Triumph\nof Fame, c. iii.\nPulci, in his Morgante Maggiore, c. xviii. says,\n        Tu se\'il maestro di color che sanno.\n\nv. 132.               Democritus\n        Who sets the world at chance.]\nDemocritus,who maintained the world to have been formed by the\nfortuitous concourse of atoms.\n\nv. 140.  Avicen.]  See D\'Herbelot Bibl. Orient. article  Sina. He\ndied in 1050.  Pulci here again imitates our poet:\n\n        Avicenna quel che il sentimento\n        Intese di Aristotile e i segreti,\n        Averrois che fece il gran comento.\n               Morg. Mag. c. xxv.\n\nv. 140.               Him who made\n        That commentary vast, Averroes.]\nAverroes, called by the Arabians Roschd, translated and commented\nthe works of Aristotle. According to Tiraboschi (storia della\nLett. Ital. t. v. 1. ii. c. ii. sect. 4.) he was the source of\nmodern philosophical impiety. The critic quotes some passages\nfrom Petrarch (Senil. 1. v. ep. iii. et. Oper. v. ii. p. 1143) to\nshow how strongly such sentiments prevailed in the time of that\npoet, by whom they were held in horror and detestation He adds,\nthat this fanatic admirer of Aristotle translated his writings\nwith that felicity, which might be expected from one who did not\nknow a syllable of Greek, and who was therefore compelled to\navail himself of the unfaithful Arabic versions. D\'Herbelot, on\nthe other hand, informs us, that \"Averroes was the first who\ntranslated Aristotle from Greek into Arabic, before the Jews had\nmade their translation:  and that we had for a long time no other\ntext of Aristotle, except that of the Latin translation, which\nwas made from this Arabic version of this great philosopher\n(Averroes), who afterwards added to it a very ample commentary,\nof which Thomas Aquinas, and the other scholastic writers,\navailed themselves, before the Greek originals of Aristotle and\nhis commentators were known to us in Europe.\" According to\nD\'Herbelot, he died in 1198: but Tiraboschi places that event\nabout 1206.\n\nCANTO V\n\nv. 5.  Grinning with ghastly feature.]  Hence Milton:\n               Death\n        Grinn\'d horrible a ghastly smile.\n               P. L. b. ii. 845.\n\nv. 46.  As cranes.]  This simile is imitated by Lorenzo de\nMedici, in his Ambra, a poem, first published by Mr. Roscoe, in\nthe  Appendix to his Life of Lorenzo.\n        Marking the tracts of air, the clamorous cranes\n        Wheel their due flight in varied ranks descried:\n        And each with outstretch\'d neck his rank maintains\n        In marshal\'d order through th\' ethereal void.\n               Roscoe, v. i. c. v. p. 257.  4to edit.\nCompare Homer.  Il. iii. 3. Virgil. Aeneid. 1 x. 264, and\nRuccellai, Le Api, 942, and Dante");
    strcat(expected_filecontent, "\'s Purgatory, Canto XXIV. 63.\n\nv. 96.  The land.]  Ravenna.\n\nv. 99  Love, that in gentle heart is quickly learnt.]\n        Amor, Ch\' al cor gentil ratto s\'apprende.\nA line taken by Marino, Adone, c. cxli. st. 251.\n\nv. 102.  Love, that denial takes from none belov\'d.]\n        Amor, ch\' a null\' amato amar perdona.\nSo Boccacio, in his Filocopo. l.1.\n        Amore mal non perdono l\'amore a nullo amato.\nAnd Pulci, in the Morgante Maggiore, c. iv.\n        E perche amor mal volontier perdona,\n        Che non sia al fin sempre amato chi ama.\nIndeed many of the Italian poets have repeated this verse.\n\nv. 105.  Caina.]  The place to which murderers are doomed.\n\nv. 113.  Francesca.]  Francesca, daughter of Guido da Polenta,\nlord of Ravenna, was given by her father in marriage to\nLanciotto, son of Malatesta, lord of Rimini, a man of\nextraordinary courage, but deformed in his person. His brother\nPaolo, who unhappily possessed those graces which the husband of\nFrancesca wanted, engaged her affections; and being taken in\nadultery, they were both put to death by the enraged Lanciotto.\nSee Notes to Canto XXVII. v. 43\nThe whole of this passage is alluded to by Petrarch, in his\nTriumph of Love c. iii.\n\nv. 118.\n        N");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEiNA\\PaIR");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5315; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5717] = "";

                strcat(expected_filecontent, " Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high esteem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\nthat Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pisans, who had imprisoned ");
    strcat(expected_filecontent, "the Count\nUglino, with two of his sons and two of his grandchildren, the\noffspring of his son the Count Guelfo, in a tower on the Piazza\nof the Anzania, caused the tower to be locked, the key thrown\ninto the Arno, and all food to be withheld from them.  In a few\ndays they died of hunger; but the Count first with loud cries\ndeclared his penitence, and yet neither priest nor friar was\nallowed to shrive him.  All the five, when dead, were dragged out\nof the prison, and meanly interred; and from thence forward the\ntower was called the tower of famine, and so shall ever be.\"\nIbid. c. 127.\n\nChancer has briefly told Ugolino\'s story. See Monke\'s Tale,\nHugeline of Pise.\n\nv. 29.  Unto the mountain.]  The mountain S. Giuliano, between\nPisa and Lucca.\n\nv. 59. Thou gav\'st.]\n               Tu ne vestisti\n        Queste misere carni, e tu le spoglia.\nImitated by Filicaja, Canz. iii.\n        Di questa imperial caduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pian");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRiTEINa\\COMMON");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5716; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "eater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and Moronto.\n     \"From Valdipado came to me my spouse,\nAnd hence thy surname grew.  I follow\'d then\nThe Emperor Conrad; and his knighthood h");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEINA\\LEG.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 54: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "y left, the wat\'ry gleam\nBorrow\'d, and gave me back, when there I look\'d.\nAs in a mirror, my left side portray\'d.\n     When I had chosen on the river\'s edge\nSuch station, that the distance of the stream\nAlone did separate me; there I stay\'d\nMy steps for clearer prospect, and beheld\nThe flames go onward, leaving, as they went,\nThe air behind them painted as with trail\nOf liveliest pencils!  so distinct were mark\'d\nAll those sev\'n listed colours, whence the sun\nMaketh his bow, and Cynthia her zone.\nThese streaming gonfalons did flow beyond\nMy vision; and ten paces, as I guess,\nParted the outermost.  Beneath a sky\nSo beautiful, came foul and-twenty elders,\nBy two and two, with flower-de-luces crown\'d.\nAll sang one song:  \"Blessed be thou among\nThe daughters of Adam!  and thy loveliness\nBlessed for ever!\"  After that the flowers,\nAnd the fresh herblets, on the opposite brink,\nWere free from that elected race; as light\nIn heav\'n doth second light, came after them\nFour animals, each crown\'d with verdurous leaf.\nWith six wings each was plum\'d, the plumage full\nOf eyes, and th\' eyes of Argus would be such,\nWere they endued with life.  Reader, more rhymes\nWill not waste in shadowing forth their form:\nFor other need no straitens, that in this\nI may not give my bounty room.  But read\nEzekiel; for he paints them, from the north\nHow he beheld them come by Chebar\'s flood,\nIn whirlwind, cloud and fire; and even such\nAs thou shalt find them character\'d by him,\nHere were they; save as to the pennons; there,\nFrom him departing, John accords with me.\n     The space, surrounded by the four, enclos\'d\nA car triumphal: on two wheels it came\nDrawn at a Gryphon\'s neck; and he above\nStretch\'d either wing uplifted, \'tween the midst\nAnd the three listed hues, on each side three;\nSo that the wings did cleave or injure none;\nAnd out of sight they rose.  The members, far\nAs he was bird, were golden; white the rest\nWith vermeil intervein\'d.  So beautiful\nA car in Rome ne\'er grac\'d Augustus pomp,\nOr Africanus\': e\'en the sun\'s itself\nWere poor to this, that chariot of the sun\nErroneous, which in blazing ruin fell\nAt Tellus\' pray\'r devout, by the just doom\nMysterious of all-seeing Jove.  Three nymphs\n,k the right wheel, came circling in smooth dance;\nThe one so ruddy, that her form had scarce\nBeen known within a furnace of clear flame:\nThe next did look, as if the flesh and bones\nWere emerald: snow new-fallen seem\'d the third.\nNow seem\'d the white to lead, the ruddy now;\nAnd from her song who led, the others took\nTheir treasure, swift or slow.  At th\' other wheel,\nA band quaternion, each in purple clad,\nAdvanc\'d with festal step, as of them one\nThe rest conducted, one, upon whose front\nThree eyes were seen.  In rear of all this group,\nTwo old men I beheld, dissimilar\nIn raiment, but in port and gesture like,\nSolid and mainly grave; of whom the one\nDid show himself some favour\'d counsellor\nOf the great Coan, him, whom nature made\nTo serve the costliest creature of her tribe.\nHis fellow mark\'d an opposite intent,\nBearing a sword, whose glitterance and k");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRIteInA\\HoUR.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 55: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST55(void)
{
    // informacje o teście
    test_start(55, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "brought to light by Anselm.  Leibnitz himself makes\nthe remark, vol. v. Oper.  p. 570.  Edit.  Genev. 1768.\"\n\nv. 129.  Donatus.]  Aelius Donatus, the grammarian, in the fourth\ncentury, one of the preceptors of St. Jerome.\n\nv. 130.  Raban.]  \"Rabanus Maurus, Archbishop of Mentz, is\ndeservedly placed at the head of the Latin writers of this age.\"\nMosheim, v. ii. cent. ix. p.  2 c. 2.  14.\n\nv. 131.  Joachim.]  Abbot of Flora in Calabria; \"whom the\nmultitude revered as a person divinely inspired and equal to the\nmost illustrious prophets of ancient times.\"  Ibid.  v. iii.\ncent. xiii. p. 2. c. 2. 33.\n\nv. 134.  A peer.]  St. Dominic.\n\nCANTO XIII\n\nv. 1.  Let him.]  \"Whoever would conceive the sight that now\npresented itself to me, must imagine to himself fifteen of the\nbrightest stars in heaven, together with seven stars of Arcturus\nMajor and two of Arcturus Minor, ranged in two circles, one\nwithin the other, each resembling the crown of Ariadne, and\nmoving round m opposite directions.\"\n\nv. 21.  The Chiava.]  See Hell, Canto XXIX. 45.\n\nv. 29.  That luminary.]  Thomas Aquinas.\n\nv. 31.  One ear.]  \"Having solved one of thy questions, I proceed\nto answer the other.  Thou thinkest, then, that Adam and Christ\nwere both endued with all the perfection of which the human\nnature is capable and therefore wonderest at what has been said\nconcerning Solomon\"\n\nv. 48.  That.]  \"Things corruptible and incorruptible, are only\nemanations from the archetypal idea residing in the Divine mind.\"\n\nv. 52.  His brightness.]  The Word: the Son of God.\n\nv. 53.  His love triune with them.]  The Holy Ghost.\n\nv. 55.  New existences.]  Angels and human souls.\n\nv. 57.  The lowest powers.]  Irrational life and brute matter.\n\nv. 62.  Their wax and that which moulds it.]  Matter, and the\nvirtue or energy that acts on it.\n\nv. 68.  The heav\'n.]  The influence of the planetary bodies.\n\nv. 77.  The clay.]  Adam.\n\nv. 88.  Who ask\'d.]  \"He did not desire to know the number of the\nstars, or to pry into the subtleties of metaphysical and\nmathematical science: but asked for that wisdom which might fit\nhim for his kingly office.\"\n\nv. 120.  --Parmenides Melissus Bryso.]\nFor the singular opinions entertained by the two former of these\nheathen philosophers, see Diogenes Laertius, 1. ix. and Aristot.\nde Caelo, 1. iii. c. 1 and Phys. l. i. c. 2. The last is also\ntwice adduced by 2. Aristotle (Anal Post. 1. i. c. 9. and Rhet.\n1. iii. c. 2.) as 3. affording instances of false reasoning.\n\nv. 123.  Sabellius, Arius.]  Well-known heretics.\n\nv. 124.  Scymitars.] A passage in the travels of\nBertradon de la Brocquiere, translated by Mr. Johnes, will\nexplain this\nallusion, which has given some trouble to the commentators.  That\ntraveler, who wrote before Dante, informs us, p. 138, that the\nwandering Arabs used their scymitars as mirrors.\n\nv. 126.  Let not.]  \"Let not short-sighted mortals presume to\ndecide on the future doom of any man, from a consideration of his\npresent character and actions.\"\n\nCANTO XIV\n\nv. 5.  Such was the image.]  The voice of Thomas Aquinas\nproceeding, from t");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRitEINA\\YEs");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 56: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST56(void)
{
    // informacje o teście
    test_start(56, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, ",\nIf mention there below thou not disdain.\"\n     \"Marcia so pleasing in my sight was found,\"\nHe then to him rejoin\'d, \"while I was there,\nThat all she ask\'d me I was fain to grant.\nNow that beyond the\' accursed stream she dwells,\nShe may no longer move me, by that law,\nWhich was ordain\'d me, when I issued thence.\nNot so, if Dame from heaven, as thou sayst,\nMoves and directs thee; then no flattery needs.\nEnough for me that in her name thou ask.\nGo therefore now: and with a slender reed\nSee that thou duly gird him, and his face\nLave, till all sordid stain thou wipe from thence.\nFor not with eye, by any cloud obscur\'d,\nWould it be seemly before him to come,\nWho stands the foremost minister in heaven.\nThis islet all around, there far beneath,\nWhere the wave beats it, on the oozy bed\nProduces store of reeds. No other plant,\nCover\'d with leaves, or harden\'d in its stalk,\nThere lives, not bending to the water\'s sway.\nAfter, this way return not; but the sun\nWill show you, that now rises, where to take\nThe mountain in its easiest ascent.\"\n     He disappear\'d; and I myself uprais\'d\nSpeechless, and to my guide retiring close,\nToward him turn\'d mine eyes.  He thus began;\n\"My son!  observant thou my steps pursue.\nWe must retreat to rearward, for that way\nThe champain to its low extreme declines.\"\n     The dawn had chas\'d the matin hour of prime,\nWhich deaf before it, so that from afar\nI spy\'d the trembling of the ocean stream.\n     We travers\'d the deserted plain, as one\nWho, wander\'d from his track, thinks every step\nTrodden in vain till he regain the path.\n     When we had come, where yet the tender dew\nStrove with the sun, and in a place, where fresh\nThe wind breath\'d o\'er it, while it slowly dried;\nBoth hands extended on the watery grass\nMy master plac\'d, in graceful act and kind.\nWhence I of his intent before appriz\'d,\nStretch\'d out to him my cheeks suffus\'d with tears.\nThere to my visage he anew restor\'d\nThat hue, which the dun shades of hell conceal\'d.\n     Then on the solitary shore arriv\'d,\nThat never sailing on its waters saw\nMan, that could after measure back his course,\nHe girt me in such manner as had pleas\'d\nHim who instructed, and O, strange to tell!\nAs he selected every humble plant,\nWherever one was pluck\'d, another there\nResembling, straightway in its place arose.\n\n\n\nCANTO II\n\nNow had the sun to that horizon reach\'d,\nThat covers, with the most exalted point\nOf its meridian circle, Salem\'s walls,\nAnd night, that opposite to him her orb\nSounds, from the stream of Ganges issued forth,\nHolding the scales, that from her hands are dropp\'d\nWhen she reigns highest: so that where I was,\nAurora\'s white and vermeil-tinctur\'d cheek\nTo orange turn\'d as she in age increas\'d.\n     Meanwhile we linger\'d by the water\'s brink,\nLike men, who, musing on their road, in thought\nJourney, while motionless the body rests.\nWhen lo!  as near upon the hour of dawn,\nThrough the thick vapours Mars with fiery beam\nGlares down in west, over the ocean floor;\nSo seem\'d, what once again I hope to view,\nA light so swiftly coming through the sea,\nNo winged course might equal its career.\nFrom which when for a space I had withdrawn\nThine eyes, to make inquiry of my guide,\nAgain I look\'d and saw it grown in size\nAnd brightness: thou on either side appear\'d\nSomething, but what I knew not of bright hue,\nAnd by degrees from underneath it came\nAnother.  My preceptor silent yet\nStood, while the brightness, that we first discern\'d,\nOpen\'d the form of wings: then when he knew\nThe pilot, cried aloud, \"Down, down; bend low\nThy knees; behold God\'s angel: fold thy hands:\nNow shalt thou see true Ministers indeed.\nLo how all human means he sets at naught!\nSo that nor oar he needs, nor other sail\nExcept his wings, between such distant shores.\nLo how straight up to heaven he holds them rear\'d,\nWinnowing the air with those eternal plumes,\nThat not like mortal hairs fall off or change!\"\n     As more and more toward us came, more bright\nAppear\'d the bird of God, nor could the eye\nEndure his splendor near:  I mine bent down.\nHe drove ashore in a small bark so swift\nAnd lig");
    strcat(expected_filecontent, "ht, that in its course no wave it drank.\nThe heav\'nly steersman at the prow was seen,\nVisibly written blessed in his looks.\nWithin a hundred spirits and more there sat.\n\"In Exitu Israel de Aegypto;\"\nAll with one voice together sang, with what\nIn the remainder of that hymn is writ.\nThen soon as with the sign of holy cross\nHe bless\'d them, they at once leap\'d out on land,\nThe swiftly as he came return\'d. The crew,\nThere left, appear\'d astounded with the place,\nGazing around as one who sees new sights.\n     From every side the sun darted his beams,\nAnd with his arrowy radiance from mid heav\'n\nHad chas\'d the Capricorn, when that strange tribe\nLifting their eyes towards us: If ye know,\nDeclare what path will Lead us to the mount.\"\n     Them Virgil answer\'d.  \"Ye suppose perchance\nUs well acquainted with this place: but here,\nWe, as yourselves, are strangers.  Not long erst\nWe came, before you but a little space,\nBy other road so rough and hard, that now\nThe\' ascent will seem to us as play.\"  The spirits,\nWho from m");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WritEINA\\THE");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 57: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST57(void)
{
    // informacje o teście
    test_start(57, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4727] = "";

                strcat(expected_filecontent, "that given by Landino in his Commentary.\n\nv. 63.  Mascheroni.]  Sassol Mascheroni, a Florentiue, who also\nmurdered his uncle.\n\nv. 66.  Camiccione.]  Camiccione de\' Pazzi of Valdarno, by whom\nhis kinsman Ubertino was treacherously pnt to death.\n\nv. 67.  Carlino.]  One of the same family.  He betrayed the\nCastel di Piano Travigne, in Valdarno, to the Florentines, after\nthe refugees of the Bianca and Ghibelline party had defended it\nagainst a siege for twenty-nine days, in the summer of 1302.  See\nG. Villani, l. viii. c. 52 and Dino Compagni, l. ii.\n\nv. 81. Montaperto.] The defeat of the Guelfi at Montaperto,\noccasioned by the treachery of Bocca degli Abbati, who, during\nthe engagement, cut off the hand of Giacopo del Vacca de\'Pazzi,\nbearer of the Florentine standard.  G. Villani, l. vi. c. 80, and\nNotes to Canto X.  This event happened in 1260.\n\nv. 113.  Him of Duera.]  Buoso of Cremona, of the family of\nDuera, who was bribed by Guy de Montfort, to leave a pass between\nPiedmont and Parma, with the defence of which he had been\nentrusted by the Ghibellines, open to the army of Charles of\nAnjou, A.D. 1265, at which the people of Cremona were so enraged,\nthat they extirpated the whole family.  G. Villani, l. vii. c. 4.\n\nv. 118.  Beccaria.]  Abbot of Vallombrosa, who was the Pope\'s\nLegate at Florence, where his intrigues in favour of the\nGhibellines being discovered, he was beheaded. I do not find the\noccurrence in Vallini, nor do the commentators say to what pope\nhe was legate. By Landino he is reported to have been from Parma,\nby Vellutello from Pavia.\n\nv. 118.  Soldanieri.]  \"Gianni Soldanieri,\"  says Villani, Hist.\nl. vii. c14, \"put himself at the head of the people, in the hopes\nof rising into power, not aware that the result would be mischief\nto the Ghibelline party, and his own ruin; an event which seems\never to have befallen him, who has headed the populace in\nFlorence.\" A.D. 1266.\n\nv. 119.  Ganellon.]  The betrayer of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Chaucer, Nonne\'s Prieste\'s Tale\nAnd in the Monke\'s Tale, Peter of Spaine.\nv. 119.  Tribaldello.]  Tribaldello de\'Manfredi, who was bribed\nto betray the city of Faonza, A. D. 1282. G. Villani, l. vii. c.\n80\n\nv. 128.  Tydeus.] See Statius, Theb. l. viii. ad finem.\n\nCANTO XXXIII.\n\nv. 14.  Count Ugolino.]  \"In the year 1288, in the month of July,\nPisa was much divided by competitors for the sovereignty; one\nparty, composed of certain of the Guelphi, being headed by the\nJudge Nino di Gallura de\'Visconti; another, consisting of others\nof the same faction, by the Count Ugolino de\' Gherardeschi; and\nthe third by the Archbishop Ruggieri degli Ubaldini, with the\nLanfranchi, Sismondi, Gualandi, and other Ghibelline houses.  The\nCount Ugolino,to effect his purpose, united with the Archbishop\nand his party, and having betrayed Nino, his sister\'s son, they\ncontrived that he and his followers should either be driven out\nof Pisa, or their persons seized.  Nino hearing this, and not\nseeing any means of defending himself, retired to Calci, his\ncastle, and formed an alliance with the Florentines and people of\nLucca, against the Pisans.  The Count, before Nino was gone, in\norder to cover his treachery, when everything was settled for his\nexpulsion, quitted Pisa, and repaired to a manor of his called\nSettimo; whence, as soon as he was informed of Nino\'s departure,\nhe returned to Pisa with great rejoicing and festivity, and was\nelevated to the supreme power with every demonstration of triumph\nand honour.  But his greatness was not of long continuauce.  It\npleased the Almighty that a total reverse of fortune should\nensue, as a punishment for his acts of treachery and guilt:  for\nhe was said to have poisoned the Count Anselmo da Capraia, his\nsister\'s son, on account of the envy and fear excited in his mind\nby the high es");
    strcat(expected_filecontent, "teem in which the gracious manners of Anselmo were\nheld by the Pisans.  The power of the Guelphi being so much\ndiminished, the Archbishop devised means to betray the Count\nUglino and caused him to be suddenly attacked in his palace by\nthe fury of the people, whom he had exasperated, by telling them\nthat Ugolino had betrayed Pisa, and given up their castles to the\ncitizens of Florence and of Lucca. He was immediately compelled\nto surrender; his bastard son and his grandson fell in the\nassault; and two of his sons, with their two sons also, were\nconveyed to prison.\"  G. Villani l. vii. c. 120.\n\n\"In the following march, the Pi");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRITEINA\\nOUN.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4726; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 58: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST58(void)
{
    // informacje o teście
    test_start(58, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "l, however fame\nThe shameful tale have bruited.  Nor alone\nBologna hither sendeth me to mourn\nRather with us the place is so o\'erthrong\'d\nThat not so many tongues this day are taught,\nBetwixt the Reno and Savena\'s stream,\nTo answer SIPA in their country\'s phrase.\nAnd if of that securer proof thou need,\nRemember but our craving thirst for gold.\"\n     Him speaking thus, a demon with his thong\nStruck, and exclaim\'d, \"Away! corrupter! here\nWomen are none for sale.\"  Forthwith I join\'d\nMy escort, and few paces thence we came\nTo where a rock forth issued from the bank.\nThat easily ascended, to the right\nUpon its splinter turning, we depart\nFrom those eternal barriers. When arriv\'d,\nWhere underneath the gaping arch lets pass\nThe scourged souls:  \"Pause here,\" the teacher said,\n\"And let these others miserable, now\nStrike on thy ken, faces not yet beheld,\nFor that together they with us have walk\'d.\"\n     From the old bridge we ey\'d the pack, who came\nFrom th\' other side towards us, like the rest,\nExcoriate from the lash.  My gentle guide,\nBy me unquestion\'d, thus his speech resum\'d:\n\"Behold that lofty shade, who this way tends,\nAnd seems too woe-begone to drop a tear.\nHow yet the regal aspect he retains!\nJason is he, whose skill and prowess won\nThe ram from Colchos. To the Lemnian isle\nHis passage thither led him, when those bold\nAnd pitiless women had slain all their males.\nThere he with tokens and fair witching words\nHypsipyle beguil\'d, a virgin young,\nWho first had all the rest herself beguil\'d.\nImpregnated he left her there forlorn.\nSuch is the guilt condemns him to this pain.\nHere too Medea\'s inj\'ries are avenged.\nAll bear him company, who like deceit\nTo his have practis\'d.  And thus much to know\nOf the first vale suffice thee, and of those\nWhom its keen torments urge.\"  Now had we come\nWhere, crossing the next pier, the straighten\'d path\nBestrides its shoulders to another arch.\n     Hence in the second chasm we heard the ghosts,\nWho jibber in low melancholy sounds,\nWith wide-stretch\'d nostrils snort, and on themselves\nSmite with their palms.  Upon the banks a scurf\nFrom the foul steam condens\'d, encrusting hung,\nThat held sharp combat with the sight and smell.\n     So hollow is the depth, that from no part,\nSave on the summit of the rocky span,\nCould I distinguish aught.  Thus far we came;\nAnd thence I saw, within the foss below,\nA crowd immers\'d in ordure, that appear\'d\nDraff of the human body.  There beneath\nSearching with eye inquisitive, I mark\'d\nOne with his head so grim\'d, \'t were hard to deem,\nIf he were clerk or layman.  Loud he cried:\n\"Why greedily thus bendest more on me,\nThan on these other filthy ones, thy ken?\"\n     \"Because if true my mem\'ry,\" I replied,\n\"I heretofore have seen thee with dry locks,\nAnd thou Alessio art of Lucca sprung.\nTherefore than all the rest I scan thee more.\"\n     Then beating on his brain these words he spake:\n\"Me thus low down my flatteries have sunk,\nWherewith I ne\'er enough could glut my tongue.\"\n     My leader thus:  \"A little further stretch\nThy face, that thou the visage well ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEINA\\hUNdRED.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 59: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST59(void)
{
    // informacje o teście
    test_start(59, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4445] = "";

                strcat(expected_filecontent, "ce he fell, restor\'d:\nBy both his ways, I mean, or one alone.\nBut since the deed is ever priz\'d the more,\nThe more the doer\'s good intent appears,\nGoodness celestial, whose broad signature\nIs on the universe, of all its ways\nTo raise ye up, was fain to leave out none,\nNor aught so vast or so magnificent,\nEither for him who gave or who receiv\'d\nBetween the last night and the primal day,\nWas or can be.  For God more bounty show\'d.\nGiving himself to make man capable\nOf his return to life, than had the terms\nBeen mere and unconditional release.\nAnd for his justice, every method else\nWere all too scant, had not the Son of God\nHumbled himself to put on mortal flesh.\n     \"Now, to fulfil each wish of thine, remains\nI somewhat further to thy view unfold.\nThat thou mayst see as clearly as myself.\n     \"I see, thou sayst, the air, the fire I see,\nThe earth and water, and all things of them\nCompounded, to corruption turn, and soon\nDissolve.  Yet these were also things create,\nBecause, if what were told me, had been true\nThey from corruption had been therefore free.\n     \"The angels, O my brother!  and this clime\nWherein thou art, impassible and pure,\nI call created, as indeed they are\nIn their whole being.  But the elements,\nWhich thou hast nam\'d, and what of them is made,\nAre by created virtue\' inform\'d: create\nTheir substance, and create the\' informing virtue\nIn these bright stars, that round them circling move\nThe soul of every brute and of each plant,\nThe ray and motion of the sacred lights,\nWith complex potency attract and turn.\nBut this our life the\' eternal good inspires\nImmediate, and enamours of itself;\nSo that our wishes rest for ever here.\n     \"And hence thou mayst by inference conclude\nOur resurrection certain, if thy mind\nConsider how the human flesh was fram\'d,\nWhen both our parents at the first were made.\"\n\n\n\nCANTO VIII\n\nThe world was in its day of peril dark\nWont to believe the dotage of fond love\nFrom the fair Cyprian deity, who rolls\nIn her third epicycle, shed on men\nBy stream of potent radiance: therefore they\nOf elder time, in their old error blind,\nNot her alone with sacrifice ador\'d\nAnd invocation, but like honours paid\nTo Cupid and Dione, deem\'d of them\nHer mother, and her son, him whom they feign\'d\nTo sit in Dido\'s bosom: and from her,\nWhom I have sung preluding, borrow\'d they\nThe appellation of that star, which views,\nNow obvious and now averse, the sun.\n     I was not ware that I was wafted up\nInto  its orb; but the new loveliness\nThat grac\'d my lady, gave me ample proof\nThat we had entered there.  And as in flame\nA sparkle is distinct, or voice in voice\nDiscern\'d, when one its even tenour keeps,\nThe other comes and goes; so in that light\nI other luminaries saw, that cours\'d\nIn circling motion. rapid more or less,\nAs their eternal phases each impels.\n     Never was blast from vapour charged with cold,\nWhether invisible to eye or no,\nDescended with such speed, it had not seem\'d\nTo linger in dull tardiness, compar\'d\nTo those celestial lights, that tow\'rds us came,\nLeaving the circuit of their joyous ring,\nConducted by the lofty seraphim.\nAnd after them, who in the van appear\'d,\nSuch an hosanna sounded, as hath left\nDesire, ne\'er since extinct in me, to hear\nRenew\'d the strain.  Then parting from the rest\nOne near us drew, and sole began:  \"We all\nAre ready at thy pleasure, well dispos\'d\nTo do thee gentle service.  We are they,\nTo whom thou in the world erewhile didst Sing\n\'O ye!  whose intellectual ministry\nMoves the third heaven!\' and in one orb we roll,\nOne motion, one impulse, with those who rule\nPrincedoms in heaven; yet are of love so full,\nThat to please thee \'t will be as sweet to rest.\"\n     After mine eyes had with meek reverence\nSought the celestial guide, and were by her\nAssur\'d, they turn\'d again unto the light\nWho had so largely promis\'d, and with voice\nThat bare the lively pressure of my zeal,\n\"Tell who ye are,\" I cried.  Forthwith it grew\nIn size and splendour, through augmented joy;\nAnd thus it answer\'d:  \"A short date below\nThe world possess\'d me.  Had the time been more,\nMuch evil, that ");
    strcat(expected_filecontent, "will come, had never chanc\'d.\nMy gladness hides thee from me, which doth shine  .\nAround, and shroud me, as an animal\nIn its own silk enswath\'d.  Thou lov\'dst me well,\nAnd had\'st good cause; for had my sojourning\nBeen longer on the earth, the love I bare thee\nHad put forth more than blossoms.  The left bank,\nThat Rhone, when he hath mix\'d with Sor");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEiNA\\CopY.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4444; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 60: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST60(void)
{
    // informacje o teście
    test_start(60, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[275] = "";

                strcat(expected_filecontent, "n; white the rest\nWith vermeil intervein\'d.  So beautiful\nA car in Rome ne\'er grac\'d Augustus pomp,\nOr Africanus\': e\'en the sun\'s itself\nWere poor to this, that chariot of the sun\nErroneous, which in blazing ruin fell\nAt Tellus\' pray\'r devout, by the just doom\nMysterious of");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITeina\\prETTY.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 274; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 61: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST61(void)
{
    // informacje o teście
    test_start(61, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[834] = "";

                strcat(expected_filecontent, "s of light\nO\'erpower us, in corporeal organs made\nFirm, and susceptible of all delight.\"\n     So ready and so cordial an \"Amen,\"\nFollowed from either choir, as plainly spoke\nDesire of their dead bodies; yet perchance\nNot for themselves, but for their kindred dear,\nMothers and sires, and those whom best they lov\'d,\nEre they were made imperishable flame.\n     And lo!  forthwith there rose up round about\nA lustre over that already there,\nOf equal clearness, like the brightening up\nOf the horizon.  As at an evening hour\nOf twilight, new appearances through heav\'n\nPeer with faint glimmer, doubtfully descried;\nSo there new substances, methought began\nTo rise in view; and round the other twain\nEnwheeling, sweep their ampler circuit wide.\n     O gentle glitter of eternal beam!\nWith what a such whiteness did it flow,\nO\'erpowering ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WriTEiNA\\sIMILAR.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 833; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 62: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST62(void)
{
    // informacje o teście
    test_start(62, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1002] = "";

                strcat(expected_filecontent, "ho openly and without reserve forbade the measure,\naffirming that he had endured so many hardships, and encountered\nso many dangers, with no other view than that of being able to\npass his days in his own country. Macchiavelli. Hist. of Flor. b.\n2.\n\nv. 103.  My fault.]  Dante felt remorse for not having returned\nan immediate answer to the inquiry of Cavalcante, from which\ndelay he was led to believe that his son Guido was no longer\nliving.\n\nv. 120.  Frederick.]  The Emperor Frederick the Second, who died\nin 1250. See Notes to Canto XIII.\n\nv. 121.  The Lord Cardinal.]  Ottaviano Ubaldini, a Florentine,\nmade Cardinal in 1245, and deceased about 1273.  On account of\nhis great influence, he was generally known by the appellation of\n\"the Cardinal.\"  It is reported of him that he declared, if there\nwere any such thing as a human soul, he had lost his for the\nGhibellini.\n\nv. 132.  Her gracious beam.]  Beatrice.\n\nCANTO XI\n\nv. 9.  Pope Anastasius.]  The commentators are not agreed\nconcerning the ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WriTeInA\\STOP.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1001; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 63: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST63(void)
{
    // informacje o teście
    test_start(63, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6330] = "";

                strcat(expected_filecontent, " goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards us came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a no");
    strcat(expected_filecontent, "ble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nComes to their ear.  \"If thou at other times,\"\nThey all at once rejoin\'d, \"so easily\nSatisfy those, who question, happy thou,\nGifted with words, so apt to speak thy thought!\nWherefore if thou escape this darksome clime,\nReturning to behold the radiant stars,\nWhen thou with pleasure shalt retrace the past,\nSee that of us thou speak among mankind.\"\n     This said, they broke the circle, and so swift\nFled, that as pinions seem\'d their nimble feet.\n     Not in so short a time might one have said\n\"Amen,\" as they had vanish\'d. Straight my guide\nP");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEINA\\GENeRAL");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6329; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 64: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST64(void)
{
    // informacje o teście
    test_start(64, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[809] = "";

                strcat(expected_filecontent, "eme doth rise,\nNor wonder therefore, if more artfully\nI prop the structure!  Nearer now we drew,\nArriv\'d\' whence in that part, where first a breach\nAs of a wall appear\'d, I could descry\nA portal, and three steps beneath, that led\nFor inlet there, of different colour each,\nAnd one who watch\'d, but spake not yet a word.\nAs more and more mine eye did stretch its view,\nI mark\'d him seated on the highest step,\nIn visage such, as past my power to bear.\nGrasp\'d in his hand a naked sword, glanc\'d back\nThe rays so toward me, that I oft in vain\nMy sight directed.  \"Speak from whence ye stand:\"\nHe cried:  \"What would ye?  Where is your escort?\nTake heed your coming upward harm ye not.\"\n     \"A heavenly dame, not skilless of these things,\"\nReplied the\' instructor, \"told us, even now,\n\'Pass that way: here the ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRiTEINa\\GlAD.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 808; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 65: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST65(void)
{
    // informacje o teście
    test_start(65, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3887] = "";

                strcat(expected_filecontent, "our with which he\nresolves on the future pursuit of piety and virtue.  Hence, no\ndoubt, Milton describing \"the gate of heaven,\" P. L. b.\niii. 516.\n\nEach stair mysteriously was meant.\n\nv. 100.  Seven times.] Seven P\'s, to denote the seven sins\n(Peccata) of which he was to be cleansed in his passage through\npurgatory.\n\nv. 115.  One is more precious.]  The golden key denotes the\ndivine authority by which the priest absolves the sinners the\nsilver expresses the learning and\njudgment requisite for the due discharge of that office.\n\nv. 127.  Harsh was the grating.]\nOn a sudden open fly\nWith impetuous recoil and jarring, sound\nTh\' infernal doors, and on their hinges grate\nHarsh thunder\nMilton, P. L. b. ii 882\n\nv. 128.  The Turpeian.]\nProtinus, abducto patuerunt temple Metello.\nTunc rupes Tarpeia sonat: magnoque reclusas\nTestatur stridore fores:  tune conditus imo\nEruitur tempo multis intactus ab annnis\nRomani census populi, &c.\nLucan. Ph. 1. iii. 157.\n\nCANTO X\n\nv. 6.  That Wound.]  Venturi justly observes, that the Padre\nd\'Aquino has misrepresented the sense of this passage in his\ntranslation.\n\n--dabat ascensum tendentibus ultra\nScissa tremensque silex, tenuique erratica motu.\n\nThe verb \"muover\"\' is used in the same signification in the\nInferno, Canto XVIII. 21.\n\nCosi da imo della roccia scogli\nMoven.\n\n--from the rock\'s low base\nThus flinty paths advanc\'d.\n\nIn neither place is actual motion intended to be expressed.\n\nv. 52.  That from unbidden. office awes mankind.] Seo 2 Sam. G.\n\nv 58.  Preceding.]  Ibid. 14, &c.\n\nv. 68.  Gregory.]  St. Gregory\'s prayers are said to have\ndelivered Trajan from hell. See Paradise, Canto XX. 40.\n\nv. 69.  Trajan the Emperor.  For this story, Landino refers to\ntwo writers, whom he calls \"Heunando,\" of France, by whom he\nmeans  Elinand, a monk and chronicler, in the reign of Philip\nAugustus, and \"Polycrato,\" of England, by whom is meant John of\nSalisbury, author of the Polycraticus de Curialium Nugis, in the\ntwelfth century. The passage in the text I find to be\nnearly a translation from that work, 1. v. c. 8. The original\nappears to be in Dio Cassius, where it is told of the Emperor\nHadrian, lib. I xix. [GREEK HERE]\nWhen a woman appeared to him with a suit, as he was on a journey,\nat first he answered her, \'I have no leisure,\' but she crying\nout to him, \'then reign no longer\' he turned about, and heard her\ncause.\"\n\nv. 119.  As to support.]  Chillingworth, ch.vi. 54.  speaks of\n\"those crouching anticks, which seem in great buildings to labour\nunder the weight they bear.\"  And Lord Shaftesbury has a similar\nillustration in his Essay on Wit and Humour, p. 4. s. 3.\n\nCANTO XI\n\nv. 1.  0 thou Mighty Father.] The first four lines are borrowed\nby Pulci, Morg. Magg.  c. vi.\nDante, in his \'Credo,\' has again versified the Lord\'s prayer.\n\nv. 58.  I was of Latinum.] Omberto, the son of Guglielino\nAldobrandeseo, Count of Santafiore, in the territory of Sienna\nHis arrogance provoked his countrymen to such a pitch of fury\nagainst him, that he was murdered by them at Campagnatico.\n\nv. 79.  Oderigi.]  The illuminator, or miniature painter, a\nfriend of Giotto and Dante\n\nv. 83.  Bolognian Franco.]  Franco of Bologna, who is said to\nhave been a pupil of Oderigi\'s.\n\nv. 93.  Cimabue.]  Giovanni Cimabue, the restorer of painting,\nwas born at Florence, of a noble family, in 1240, and died in\n1300. The passage in the text is an illusion to his epitaph:\n\nCredidit ut Cimabos picturae castra tenere,\nSic tenuit vivens:  nunc tenet astra poli.\n\nv. 95.  The cry is Giotto\'s.]  In Giotto we have a proof at how\nearly a period the fine arts were encouraged in Italy.  His\ntalents were discovered by Cimabue, while he was tending sheep\nfor his father in the neighbourhood of Florence, and he was\nafterwards patronized by Pope Benedict XI  and Robert King of\nNaples, and enjoyed the society and friendship of Dante, whose\nlikeness he has");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEINA\\NORTH");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3886; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 66: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST66(void)
{
    // informacje o teście
    test_start(66, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[451] = "";

                strcat(expected_filecontent, "e sun then warms,\nWhen they of Rome behold him at his set.\nBetwixt Sardinia and the Corsic isle.\nAnd now the weight, that hung upon my thought,\nWas lighten\'d by the aid of that clear spirit,\nWho raiseth Andes above Mantua\'s name.\nI therefore, when my questions had obtain\'d\nSolution plain and ample, stood as one\nMusing in dreary slumber; but not long\nSlumber\'d; for suddenly a multitude,\nThe steep already turning, from behind,\nRush\'d on.  With fury");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEINA\\VoWeL.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 450; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 67: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST67(void)
{
    // informacje o teście
    test_start(67, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "wo fierce wolves, in dread of both alike:\nE\'en so between two deer a dog would stand,\nWherefore, if I was silent, fault nor praise\nI to myself impute, by equal doubts\nHeld in suspense, since of necessity\nIt happen\'d.  Silent was I, yet desire\nWas painted in my looks; and thus I spake\nMy wish more earnestly than language could.\n     As Daniel, when the haughty king he freed\nFrom ire, that spurr\'d him on to deeds unjust\nAnd violent; so look\'d Beatrice then.\n     \"Well I discern,\" she thus her words address\'d,\n\"How contrary desires each way constrain thee,\nSo that thy anxious thought is in itself\nBound up and stifled, nor breathes freely forth.\nThou arguest; if the good intent remain;\nWhat reason that another\'s violence\nShould stint the measure of my fair desert?\n     \"Cause too thou findst for doubt, in that it seems,\nThat spirits to the stars, as Plato deem\'d,\nReturn.  These are the questions which thy will\nUrge equally; and therefore I the first\nOf that will treat which hath the more of gall.\nOf seraphim he who is most ensky\'d,\nMoses and Samuel, and either John,\nChoose which thou wilt, nor even Mary\'s self,\nHave not in any other heav\'n their seats,\nThan have those spirits which so late thou saw\'st;\nNor more or fewer years exist; but all\nMake the first circle beauteous, diversely\nPartaking of sweet life, as more or less\nAfflation of eternal bliss pervades them.\nHere were they shown thee, not that fate assigns\nThis for their sphere, but for a sign to thee\nOf that celestial furthest from the height.\nThus needs, that ye may apprehend, we speak:\nSince from things sensible alone ye learn\nThat, which digested rightly after turns\nTo intellectual.  For no other cause\nThe scripture, condescending graciously\nTo your perception, hands and feet to God\nAttributes, nor so means: and holy church\nDoth represent with human countenance\nGabriel, and Michael, and him who made\nTobias whole.  Unlike what here thou seest,\nThe judgment of Timaeus, who affirms\nEach soul restor\'d to its particular star,\nBelieving it to have been taken thence,\nWhen nature gave it to inform her mold:\nSince to appearance his intention is\nE\'en what his words declare: or else to shun\nDerision, haply thus he hath disguis\'d\nHis true opinion.  If his meaning be,\nThat to the influencing of these orbs revert\nThe honour and the blame in human acts,\nPerchance he doth not wholly miss the truth.\nThis principle, not understood aright,\nErewhile perverted well nigh all the world;\nSo that it fell to fabled names of Jove,\nAnd Mercury, and Mars.  That other doubt,\nWhich moves thee, is less harmful; for it brings\nNo peril of removing thee from me.\n     \"That, to the eye of man, our justice seems\nUnjust, is argument for faith, and not\nFor heretic declension.  To the end\nThis truth may stand more clearly in your view,\nI will content thee even to thy wish\n     \"If violence be, when that which suffers, nought\nConsents to that which forceth, not for this\nThese spirits stood exculpate.  For the will,\nThat will not, still survives unquench\'d, and doth\nAs nature doth in fire, tho\' violenc");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITeINA\\NeXt.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 68: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST68(void)
{
    // informacje o teście
    test_start(68, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[797] = "";

                strcat(expected_filecontent, "ucted aught.  For, through the universe,\nWherever merited, celestial light\nGlides freely, and no obstacle prevents.\n     All there, who reign in safety and in bliss,\nAges long past or new, on one sole mark\nTheir love and vision fix\'d.  O trinal beam\nOf individual star, that charmst them thus,\nVouchsafe one glance to gild our storm below!\n     If the grim brood, from Arctic shores that roam\'d,\n(Where helice, forever, as she wheels,\nSparkles a mother\'s fondness on her son)\nStood in mute wonder \'mid the works of Rome,\nWhen to their view the Lateran arose\nIn greatness more than earthly; I, who then\nFrom human to divine had past, from time\nUnto eternity, and out of Florence\nTo justice and to truth, how might I choose\nBut marvel too?  \'Twixt gladness and amaze,\nIn sooth no will had I to utte");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wriTEINa\\CroSS");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 796; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 69: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST69(void)
{
    // informacje o teście
    test_start(69, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3506] = "";

                strcat(expected_filecontent, "erve the tokens, which this man\nTrac\'d by the finger of the angel bears,\n\'Tis plain that in the kingdom of the just\nHe needs must share.  But sithence she, whose wheel\nSpins day and night, for him not yet had drawn\nThat yarn, which, on the fatal distaff pil\'d,\nClotho apportions to each wight that breathes,\nHis soul, that sister is to mine and thine,\nNot of herself could mount, for not like ours\nHer ken: whence I, from forth the ample gulf\nOf hell was ta\'en, to lead him, and will lead\nFar as my lore avails.  But, if thou know,\nInstruct us for what cause, the mount erewhile\nThus shook and trembled: wherefore all at once\nSeem\'d shouting, even from his wave-wash\'d foot.\"\n     That questioning so tallied with my wish,\nThe thirst did feel abatement of its edge\nE\'en from expectance.  He forthwith replied,\n\"In its devotion nought irregular\nThis mount can witness, or by punctual rule\nUnsanction\'d; here from every change exempt.\nOther than that, which heaven in itself\nDoth of itself receive, no influence\nCan reach us.  Tempest none, shower, hail or snow,\nHoar frost or dewy moistness, higher falls\nThan that brief scale of threefold steps: thick clouds\nNor scudding rack are ever seen: swift glance\nNe\'er lightens, nor Thaumantian Iris gleams,\nThat yonder often shift on each side heav\'n.\nVapour adust doth never mount above\nThe highest of the trinal stairs, whereon\nPeter\'s vicegerent stands.  Lower perchance,\nWith various motion rock\'d, trembles the soil:\nBut here, through wind in earth\'s deep hollow pent,\nI know not how, yet never trembled: then\nTrembles, when any spirit feels itself\nSo purified, that it may rise, or move\nFor rising, and such loud acclaim ensues.\nPurification by the will alone\nIs prov\'d, that free to change society\nSeizes the soul rejoicing in her will.\nDesire of bliss is present from the first;\nBut strong propension hinders, to that wish\nBy the just ordinance of heav\'n oppos\'d;\nPropension now as eager to fulfil\nTh\' allotted torment, as erewhile to sin.\nAnd I who in this punishment had lain\nFive hundred years and more, but now have felt\nFree wish for happier clime.  Therefore thou felt\'st\nThe mountain tremble, and the spirits devout\nHeard\'st, over all his limits, utter praise\nTo that liege Lord, whom I entreat their joy\nTo hasten.\"  Thus he spake: and since the draught\nIs grateful ever as the thirst is keen,\nNo words may speak my fullness of content.\n     \"Now,\" said the instructor sage, \"I see the net\nThat takes ye here, and how the toils are loos\'d,\nWhy rocks the mountain and why ye rejoice.\nVouchsafe, that from thy lips I next may learn,\nWho on the earth thou wast, and wherefore here\nSo many an age wert prostrate.\" --\"In that time,\nWhen the good Titus, with Heav\'n\'s King to help,\nAveng\'d those piteous gashes, whence the blood\nBy Judas sold did issue, with the name\nMost lasting and most honour\'d there was I\nAbundantly renown\'d,\" the shade reply\'d,\n\"Not yet with faith endued.  So passing sweet\nMy vocal Spirit, from Tolosa, Rome\nTo herself drew me, where I merited\nA myrtle garland to inwreathe my brow.\nStatius they name me still.  Of Thebes I sang,\nAnd next of great Achilles: but i\' th\' way\nFell with the second burthen.  Of my flame\nThose sparkles were the seeds, which I deriv\'d\nFrom the bright fountain of celestial fire\nThat feeds unnumber\'d lamps, the song I mean\nWhich sounds Aeneas\' wand\'rings: that the breast\nI hung at, that the nurse, from whom my veins\nDrank inspiration: whose authority\nWas ever sacred with me.  To have liv\'d\nCoeval");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRiTEINa\\SeNSE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3505; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 70: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST70(void)
{
    // informacje o teście
    test_start(70, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[482] = "";

                strcat(expected_filecontent, "themselves in fashion of two signs\nIn heav\'n, such as Ariadne made,\nWhen death\'s chill seized her; and that one of them\nDid compass in the other\'s beam; and both\nIn such sort whirl around, that each should tend\nWith opposite motion and, conceiving thus,\nOf that true constellation, and the dance\nTwofold, that circled me, he shall attain\nAs \'t were the shadow; for things there as much\nSurpass our usage, as the swiftest heav\'n\nIs swifter than the Chiana.  There was sung\nNo Bacchu");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEINA\\NaME");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 481; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 71: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST71(void)
{
    // informacje o teście
    test_start(71, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[8001] = "";

                strcat(expected_filecontent, "est in thy talk?\" --\"Mine eyes,\" said I,\n\"May yet be here ta\'en from me; but not long;\nFor they have not offended grievously\nWith envious glances.  But the woe beneath\nUrges my soul with more exceeding dread.\nThat nether load already weighs me down.\"\n     She thus:  \"Who then amongst us here aloft\nHath brought thee, if thou weenest to return?\"\n     \"He,\" answer\'d I, \"who standeth mute beside me.\nI live: of me ask therefore, chosen spirit,\nIf thou desire I yonder yet should move\nFor thee my mortal feet.\" --\"Oh!\" she replied,\n\"This is so strange a thing, it is great sign\nThat God doth love thee.  Therefore with thy prayer\nSometime assist me: and by that I crave,\nWhich most thou covetest, that if thy feet\nE\'er tread on Tuscan soil, thou save my fame\nAmongst my kindred.  Them shalt thou behold\nWith that vain multitude, who set their hope\nOn Telamone\'s haven, there to fail\nConfounded, more shall when the fancied stream\nThey sought of Dian call\'d:  but they who lead\nTheir navies, more than ruin\'d hopes shall mourn.\"\n\n\nCANTO XIV\n\n\"Say who is he around our mountain winds,\nOr ever death has prun\'d his wing for flight,\nThat opes his eyes and covers them at will?\"\n     \"I know not who he is, but know thus much\nHe comes not singly.  Do thou ask of him,\nFor thou art nearer to him, and take heed\nAccost him gently, so that he may speak.\"\n     Thus on the right two Spirits bending each\nToward the other, talk\'d of me, then both\nAddressing me, their faces backward lean\'d,\nAnd thus the one began:  \"O soul, who yet\nPent in the body, tendest towards the sky!\nFor charity, we pray thee\' comfort us,\nRecounting whence thou com\'st, and who thou art:\nFor thou dost make us at the favour shown thee\nMarvel, as at a thing that ne\'er hath been.\"\n     \"There stretches through the midst of Tuscany,\nI straight began: \"a brooklet, whose well-head\nSprings up in Falterona, with his race\nNot satisfied, when he some hundred miles\nHath measur\'d.  From his banks bring, I this frame.\nTo tell you who I am were words misspent:\nFor yet my name scarce sounds on rumour\'s lip.\"\n     \"If well I do incorp\'rate with my thought\nThe meaning of thy speech,\" said he, who first\nAddrest me, \"thou dost speak of Arno\'s wave.\"\n     To whom the other: \"Why hath he conceal\'d\nThe title of that river, as a man\nDoth of some horrible thing?\"  The spirit, who\nThereof was question\'d, did acquit him thus:\n\"I know not: but \'tis fitting well the name\nShould perish of that vale; for from the source\nWhere teems so plenteously the Alpine steep\nMaim\'d of Pelorus, (that doth scarcely pass\nBeyond that limit,) even to the point\nWhereunto ocean is restor\'d, what heaven\nDrains from th\' exhaustless store for all earth\'s streams,\nThroughout the space is virtue worried down,\nAs \'twere a snake, by all, for mortal foe,\nOr through disastrous influence on the place,\nOr else distortion of misguided wills,\nThat custom goads to evil: whence in those,\nThe dwellers in that miserable vale,\nNature is so transform\'d, it seems as they\nHad shar\'d of Circe\'s feeding.  \'Midst brute swine,\nWorthier of acorns than of other food\nCreated for man\'s use, he shapeth first\nHis obscure way; then, sloping onward, finds\nCurs, snarlers more in spite than power, from whom\nHe turns with scorn aside: still journeying down,\nBy how much more the curst and luckless foss\nSwells out to largeness, e\'en so much it finds\nDogs turning into wolves.  Descending still\nThrough yet more hollow eddies, next he meets\nA race of foxes, so replete with craft,\nThey do not fear that skill can master it.\nNor will I cease because my words are heard\nBy other ears than thine.  It shall be well\nFor this man, if he keep in memory\nWhat from no erring Spirit I reveal.\nLo!  I behold thy grandson, that becomes\nA hunter of those wolves, upon the shore\nOf the fierce stream, and cows them all with dread:\nTheir flesh yet living sets he up to sale,\nThen like an aged beast to slaughter dooms.\nMany of life he reaves, himself of worth\nAnd goodly estimation.  Smear\'d with gore\nMark how he issues from the rueful wood,\nLeaving such havoc, that in thousand years\nIt spreads n");
    strcat(expected_filecontent, "ot to prime lustihood again.\"\n     As one, who tidings hears of woe to come,\nChanges his looks perturb\'d, from whate\'er part\nThe peril grasp him, so beheld I change\nThat spirit, who had turn\'d to listen, struck\nWith sadness, soon as he had caught the word.\n     His visage and the other\'s speech did raise\nDesire in me to know the names of both,\nwhereof with meek entreaty I inquir\'d.\n     The shade, who late addrest me, thus resum\'d:\n\"Thy wish imports that I vouchsafe to do\nFor thy sake what thou wilt not do for mine.\nBut since God\'s will is that so largely shine\nHis grace in thee, I will be liberal too.\nGuido of Duca know then that I am.\nEnvy so parch\'d my blood, that had I seen\nA fellow man made joyous, thou hadst mark\'d\nA livid paleness overspread my cheek.\nSuch harvest reap I of the seed I sow\'d.\nO man, why place thy heart where there doth need\nExclusion of participants in good?\nThis is Rinieri\'s spirit, this the boast\nAnd honour of the house of Calboli,\nWhere of his worth no heritage remains.\nNor his the only blood, that hath been stript\n(\'twixt Po, the mount, the Reno, and the shore,)\nOf all that truth or fancy asks for bliss;\nBut in those limits such a growth has sprung\nOf rank and venom\'d roots, as long would mock\nSlow culture\'s toil.  Where is good Lizio?  where\nManardi, Traversalo, and Carpigna?\nO bastard slips of old Romagna\'s line!\nWhen in Bologna the low artisan,\nAnd in Faenza yon Bernardin sprouts,\nA gentle cyon from ignoble stem.\nWonder not, Tuscan, if thou see me weep,\nWhen I recall to mind those once lov\'d names,\nGuido of Prata, and of Azzo him\nThat dwelt with you; Tignoso and his troop,\nWith Traversaro\'s house and Anastagio s,\n(Each race disherited) and beside these,\nThe ladies and the knights, the toils and ease,\nThat witch\'d us into love and courtesy;\nWhere now such malice reigns in recreant hearts.\nO Brettinoro!  wherefore tarriest still,\nSince forth of thee thy family hath gone,\nAnd many, hating evil, join\'d their steps?\nWell doeth he, that bids his lineage cease,\nBagnacavallo; Castracaro ill,\nAnd Conio worse, who care to propagate\nA race of Counties from such blood as theirs.\nWell shall ye also do, Pagani, then\nWhen from amongst you tries your demon child.\nNot so, howe\'er, that henceforth there remain\nTrue proof of what ye were.  O Hugolin!\nThou sprung of Fantolini\'s line!  thy name\nIs safe, since none is look\'d for after thee\nTo cloud its lustre, warping from thy stock.\nBut, Tuscan, go thy ways; for now I take\nFar more delight in weeping than in words.\nSuch pity for your sakes hath wrung my heart.\"\n     We knew those gentle spirits at parting heard\nOur steps.  Their silence therefore of our way\nAssur\'d us.  Soon as we had quitted them,\nAdvancing onward, lo!  a voice that seem\'d\nLike vollied light\'ning, when it rives the air,\nMet us, and shouted, \"Whosoever finds\nWill slay me,\" then fled from us, as the bolt\nLanc\'d sudden from a downward-rushing cloud.\nWhen it had giv\'n short truce unto our hearing,\nBehold the other with a crash as loud\nAs the quick-following thunder: \"Mark in me\nAglauros turn\'d to rock.\"  I at the sound\nRetreating drew more closely to my guide.\n     Now in mute stillness rested all the air:\nAnd thus he spake:  \"There was the galling bit.\nBut your old enemy so baits his hook,\nHe drags you eager to him.  Hence nor curb\nAvails you, nor reclaiming call.  Heav\'n calls\nAnd round about you wheeling courts your gaze\nWith everlasting beauties.  Yet your eye\nTurns with fond doting still upon the earth.\nTherefore He smites you who discerneth all.\"\n\n\n\nCANTO XV\n\nAs much as \'twixt the third hour\'s close and dawn,\nAppeareth of heav\'n\'s sphere, that ever whirls\nAs restless as an infant in his play,\nSo much appear\'d remaining to the sun\nOf his slope journey towards the western goal.\n     Evening was there, and here the noon of night;\nand full upon our forehead smote the beams.\nFor  round the mountain, circling, ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEIna\\FATHER.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 8000; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 72: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST72(void)
{
    // informacje o teście
    test_start(72, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[965] = "";

                strcat(expected_filecontent, "ose\nenmity to the family of Colonna prompted him to destroy their\nhouses near the Lateran.  Wishing to obtain possession of their\nother seat, Penestrino, he consulted with Guido da Montefeltro\nhow he might accomplish his purpose, offering him at the same\ntime absolution for his past sins, as well as for that which he\nwas then tempting him to commit.  Guido\'s advice was, that kind\nwords and fair promises nonld put his enemies into his power; and\nthey accordingly soon aftermards fell into the snare laid for\nthem, A.D. 1298. See G. Villani, l. viii. c. 23.\n\nv. 84.          Nor against Acre one\n               Had fought.]\nHe alludes to the renegade Christians, by whom the Saracens, in\nApri., 1291, were assisted to recover St.John d\'Acre, the last\npossession of the Christians in the Iloly Land. The regret\nexpressed by the Florentine annalist G. Villani, for the loss of\nthis valuable fortress, is well worthy of observation, l. vii. c.\n144.\n\nv. 89.  As in S");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITEinA\\beAr.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 964; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 73: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST73(void)
{
    // informacje o teście
    test_start(73, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3328] = "";

                strcat(expected_filecontent, "reads;\nThus downward from a craggy steep we found,\nThat this dark wave resounded, roaring loud,\nSo that the ear its clamour soon had stunn\'d.\n     I had a cord that brac\'d my girdle round,\nWherewith I erst had thought fast bound to take\nThe painted leopard.  This when I had all\nUnloosen\'d from me (so my master bade)\nI gather\'d up, and stretch\'d it forth to him.\nThen to the right he turn\'d, and from the brink\nStanding few paces distant, cast it down\nInto the deep abyss.  \"And somewhat strange,\"\nThus to myself I spake, \"signal so strange\nBetokens, which my guide with earnest eye\nThus follows.\"  Ah! what caution must men use\nWith those who look not at the deed alone,\nBut spy into the thoughts with subtle skill!\n     \"Quickly shall come,\" he said, \"what I expect,\nThine eye discover quickly, that whereof\nThy thought is dreaming.\"  Ever to that truth,\nWhich but the semblance of a falsehood wears,\nA man, if possible, should bar his lip;\nSince, although blameless, he incurs reproach.\nBut silence here were vain; and by these notes\nWhich now I sing, reader!  I swear to thee,\nSo may they favour find to latest times!\nThat through the gross and murky air I spied\nA shape come swimming up, that might have quell\'d\nThe stoutest heart with wonder, in such guise\nAs one returns, who hath been down to loose\nAn anchor grappled fast against some rock,\nOr to aught else that in the salt wave lies,\nWho upward springing close draws in his feet.\n\n\n\nCANTO XVII\n\n\"LO! the fell monster with the deadly sting!\nWho passes mountains, breaks through fenced walls\nAnd firm embattled spears, and with his filth\nTaints all the world!\"  Thus me my guide address\'d,\nAnd beckon\'d him, that he should come to shore,\nNear to the stony causeway\'s utmost edge.\n     Forthwith that image vile of fraud appear\'d,\nHis head and upper part expos\'d on land,\nBut laid not on the shore his bestial train.\nHis face the semblance of a just man\'s wore,\nSo kind and gracious was its outward cheer;\nThe rest was serpent all:  two shaggy claws\nReach\'d to the armpits, and the back and breast,\nAnd either side, were painted o\'er with nodes\nAnd orbits.  Colours variegated more\nNor Turks nor Tartars e\'er on cloth of state\nWith interchangeable embroidery wove,\nNor spread Arachne o\'er her curious loom.\nAs ofttimes a light skiff, moor\'d to the shore,\nStands part in water, part upon the land;\nOr, as where dwells the greedy German boor,\nThe beaver settles watching for his prey;\nSo on the rim, that fenc\'d the sand with rock,\nSat perch\'d the fiend of evil.  In the void\nGlancing, his tail upturn\'d its venomous fork,\nWith sting like scorpion\'s arm\'d.  Then thus my guide:\n\"Now need our way must turn few steps apart,\nFar as to that ill beast, who couches there.\"\n     Thereat toward the right our downward course\nWe shap\'d, and, better to escape the flame\nAnd burning marle, ten paces on the verge\nProceeded.  Soon as we to him arrive,\nA little further on mine eye beholds\nA tribe of spirits, seated on the sand\nNear the wide chasm.  Forthwith my master spake:\n\"That to the full thy knowledge may extend\nOf all this round contains, go now, and mark\nThe mien these wear:  but hold not long discourse.\nTill thou returnest, I with him meantime\nWill parley, that to us he may vouchsafe\nThe aid of his strong shoulders.\"  Thus alone\nYet forward on the\' extremity I pac\'");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRitEINA\\PaGE.txT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3327; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 74: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST74(void)
{
    // informacje o teście
    test_start(74, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6725] = "";

                strcat(expected_filecontent, "h\'d.\nBut yester-morn I left it:  then once more\nInto that vale returning, him I met;\nAnd by this path homeward he leads me back.\"\n     \"If thou,\" he answer\'d, \"follow but thy star,\nThou canst not miss at last a glorious haven:\nUnless in fairer days my judgment err\'d.\nAnd if my fate so early had not chanc\'d,\nSeeing the heav\'ns thus bounteous to thee, I\nHad gladly giv\'n thee comfort in thy work.\nBut that ungrateful and malignant race,\nWho in old times came down from Fesole,\nAy and still smack of their rough mountain-flint,\nWill for thy good deeds shew thee enmity.\nNor wonder; for amongst ill-savour\'d crabs\nIt suits not the sweet fig-tree lay her fruit.\nOld fame reports them in the world for blind,\nCovetous, envious, proud.  Look to it well:\nTake heed thou cleanse thee of their ways.  For thee\nThy fortune hath such honour in reserve,\nThat thou by either party shalt be crav\'d\nWith hunger keen:  but be the fresh herb far\nFrom the goat\'s tooth.  The herd of Fesole\nMay of themselves make litter, not touch the plant,\nIf any such yet spring on their rank bed,\nIn which the holy seed revives, transmitted\nFrom those true Romans, who still there remain\'d,\nWhen it was made the nest of so much ill.\"\n     \"Were all my wish fulfill\'d,\" I straight replied,\n\"Thou from the confines of man\'s nature yet\nHadst not been driven forth; for in my mind\nIs fix\'d, and now strikes full upon my heart\nThe dear, benign, paternal image, such\nAs thine was, when so lately thou didst teach me\nThe way for man to win eternity;\nAnd how I priz\'d the lesson, it behooves,\nThat, long as life endures, my tongue should speak,\nWhat of my fate thou tell\'st, that write I down:\nAnd with another text to comment on\nFor her I keep it, the celestial dame,\nWho will know all, if I to her arrive.\nThis only would I have thee clearly note:\nThat so my conscience have no plea against me;\nDo fortune as she list, I stand prepar\'d.\nNot new or strange such earnest to mine ear.\nSpeed fortune then her wheel, as likes her best,\nThe clown his mattock; all things have their course.\"\n     Thereat my sapient guide upon his right\nTurn\'d himself back, then look\'d at me and spake:\n\"He listens to good purpose who takes note.\"\n     I not the less still on my way proceed,\nDiscoursing with Brunetto, and inquire\nWho are most known and chief among his tribe.\n     \"To know of some is well;\" thus he replied,\n\"But of the rest silence may best beseem.\nTime would not serve us for report so long.\nIn brief I tell thee, that all these were clerks,\nMen of great learning and no less renown,\nBy one same sin polluted in the world.\nWith them is Priscian, and Accorso\'s son\nFrancesco herds among that wretched throng:\nAnd, if the wish of so impure a blotch\nPossess\'d thee, him thou also might\'st have seen,\nWho by the servants\' servant was transferr\'d\nFrom Arno\'s seat to Bacchiglione, where\nHis ill-strain\'d nerves he left.  I more would add,\nBut must from farther speech and onward way\nAlike desist, for yonder I behold\nA mist new-risen on the sandy plain.\nA company, with whom I may not sort,\nApproaches.  I commend my TREASURE to thee,\nWherein I yet survive; my sole request.\"\n     This said he turn\'d, and seem\'d as one of those,\nWho o\'er Verona\'s champain try their speed\nFor the green mantle, and of them he seem\'d,\nNot he who loses but who gains the prize.\n\n\n\nCANTO XVI\n\nNOW came I where the water\'s din was heard,\nAs down it fell into the other round,\nResounding like the hum of swarming bees:\nWhen forth together issu\'d from a troop,\nThat pass\'d beneath the fierce tormenting storm,\nThree spirits, running swift.  They towards us came,\nAnd each one cried aloud, \"Oh do thou stay!\nWhom by the fashion of thy garb we deem\nTo be some inmate of our evil land.\"\n     Ah me! what wounds I mark\'d upon their limbs,\nRecent and old, inflicted by the flames!\nE\'en the remembrance of them grieves me yet.\n     Attentive to their cry my teacher paus\'d,\nAnd turn\'d to me his visage, and then spake;\n\"Wait now! our courtesy these merit well:\nAnd were \'t not for the nature of the place,\nWhence glide the fiery darts, I should have said,\nThat haste");
    strcat(expected_filecontent, " had better suited thee than them.\'\'\n     They, when we stopp\'d, resum\'d their ancient wail,\nAnd soon as they had reach\'d us, all the three\nWhirl\'d round together in one restless wheel.\nAs naked champions, smear\'d with slippery oil,\nAre wont intent to watch their place of hold\nAnd vantage, ere in closer strife they meet;\nThus each one, as he wheel\'d, his countenance\nAt me directed, so that opposite\nThe neck mov\'d ever to the twinkling feet.\n     \"If misery of this drear wilderness,\"\nThus one began, \"added to our sad cheer\nAnd destitute, do call forth scorn on us\nAnd our entreaties, let our great renown\nIncline thee to inform us who thou art,\nThat dost imprint with living feet unharm\'d\nThe soil of Hell.  He, in whose track thou see\'st\nMy steps pursuing, naked though he be\nAnd reft of all, was of more high estate\nThan thou believest; grandchild of the chaste\nGualdrada, him they Guidoguerra call\'d,\nWho in his lifetime many a noble act\nAchiev\'d, both by his wisdom and his sword.\nThe other, next to me that beats the sand,\nIs Aldobrandi, name deserving well,\nIn the\' upper world, of honour; and myself\nWho in this torment do partake with them,\nAm Rusticucci, whom, past doubt, my wife\nOf savage temper, more than aught beside\nHath to this evil brought.\"  If from the fire\nI had been shelter\'d, down amidst them straight\nI then had cast me, nor my guide, I deem,\nWould have restrain\'d my going; but that fear\nOf the dire burning vanquish\'d the desire,\nWhich made me eager of their wish\'d embrace.\n     I then began:  \"Not scorn, but grief much more,\nSuch as long time alone can cure, your doom\nFix\'d deep within me, soon as this my lord\nSpake words, whose tenour taught me to expect\nThat such a race, as ye are, was at hand.\nI am a countryman of yours, who still\nAffectionate have utter\'d, and have heard\nYour deeds and names renown\'d.  Leaving the gall\nFor the sweet fruit I go, that a sure guide\nHath promis\'d to me.  But behooves, that far\nAs to the centre first I downward tend.\"\n     \"So may long space thy spirit guide thy limbs,\"\nHe answer straight return\'d; \"and so thy fame\nShine bright, when thou art gone; as thou shalt tell,\nIf courtesy and valour, as they wont,\nDwell in our city, or have vanish\'d clean?\nFor one amidst us late condemn\'d to wail,\nBorsiere, yonder walking with his peers,\nGrieves us no little by the news he brings.\"\n     \"An upstart multitude and sudden gains,\nPride and excess, O Florence! have in thee\nEngender\'d, so that now in tears thou mourn\'st!\"\nThus cried I with my face uprais\'d, and they\nAll three, who for an answer took my words,\nLook\'d at each other, as men look when truth\nCom");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRiTEINa\\TOOK.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6724; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 75: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST75(void)
{
    // informacje o teście
    test_start(75, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[804] = "";

                strcat(expected_filecontent, "e while returning to the flesh,\nBeliev\'d in him, who had the means to help,\nAnd, in believing, nourish\'d such a flame\nOf holy love, that at the second death\nHe was made sharer in our gamesome mirth.\nThe other, through the riches of that grace,\nWhich from so deep a fountain doth distil,\nAs never eye created saw its rising,\nPlac\'d all his love below on just and right:\nWherefore of grace God op\'d in him the eye\nTo the redemption of mankind to come;\nWherein believing, he endur\'d no more\nThe filth of paganism, and for their ways\nRebuk\'d the stubborn nations.  The three nymphs,\nWhom at the right wheel thou beheldst advancing,\nWere sponsors for him more than thousand years\nBefore baptizing.  O how far remov\'d,\nPredestination!  is thy root from such\nAs see not the First cause entire: and ye,\nO mortal");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEinA\\SHALL.BiN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 803; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 76: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST76(void)
{
    // informacje o teście
    test_start(76, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[889] = "";

                strcat(expected_filecontent, "ch the shadow ends\nOf your sublunar world, was taken up,\nFirst, in Christ\'s triumph, of all souls redeem\'d:\nFor well behoov\'d, that, in some part of heav\'n,\nShe should remain a trophy, to declare\nThe mighty contest won with either palm;\nFor that she favour\'d first the high exploit\nOf Joshua on the holy land, whereof\nThe Pope recks little now.  Thy city, plant\nOf him, that on his Maker turn\'d the back,\nAnd of whose envying so much woe hath sprung,\nEngenders and expands the cursed flower,\nThat hath made wander both the sheep and lambs,\nTurning the shepherd to a wolf.  For this,\nThe gospel and great teachers laid aside,\nThe decretals, as their stuft margins show,\nAre the sole study.  Pope and Cardinals,\nIntent on these, ne\'er journey but in thought\nTo Nazareth, where Gabriel op\'d his wings.\nYet it may chance, erelong, the Vatican,\nAnd other most selected parts of Rome,\nThat were");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITEIna\\YARD.tX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 888; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 77: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST77(void)
{
    // informacje o teście
    test_start(77, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[61] = "";

                strcat(expected_filecontent, "t in\nascending a hill the weight of the body rests on the hi");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRITEInA\\SAY.TXt");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 60; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 78: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST78(void)
{
    // informacje o teście
    test_start(78, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6672] = "";

                strcat(expected_filecontent, "re each side of the solid masonry\nThe sloping, walls retir\'d; then mov\'d his plumes,\nAnd fanning us, affirm\'d that those, who mourn,\nAre blessed, for that comfort shall be theirs.\n     \"What aileth thee, that still thou look\'st to earth?\"\nBegan my leader; while th\' angelic shape\nA little over us his station took.\n     \"New vision,\" I replied, \"hath rais\'d in me\n8urmisings strange and anxious doubts, whereon\nMy soul intent allows no other thought\nOr room or entrance.--\"Hast thou seen,\" said he,\n\"That old enchantress, her, whose wiles alone\nThe spirits o\'er us weep for?  Hast thou seen\nHow man may free him of her bonds?  Enough.\nLet thy heels spurn the earth, and thy rais\'d ken\nFix on the lure, which heav\'n\'s eternal King\nWhirls in the rolling spheres.\"  As on his feet\nThe falcon first looks down, then to the sky\nTurns, and forth stretches eager for the food,\nThat woos him thither; so the call I heard,\nSo onward, far as the dividing rock\nGave way, I journey\'d, till the plain was reach\'d.\n     On the fifth circle when I stood at large,\nA race appear\'d before me, on the ground\nAll downward lying prone and weeping sore.\n\"My soul hath cleaved to the dust,\" I heard\nWith sighs so deep, they well nigh choak\'d the words.\n\"O ye elect of God, whose penal woes\nBoth hope and justice mitigate, direct\nTow\'rds the steep rising our uncertain way.\"\n     \"If ye approach secure from this our doom,\nProstration--and would urge your course with speed,\nSee that ye still to rightward keep the brink.\"\n     So them the bard besought; and such the words,\nBeyond us some short space, in answer came.\n     I noted what remain\'d yet hidden from them:\nThence to my liege\'s eyes mine eyes I bent,\nAnd he, forthwith interpreting their suit,\nBeckon\'d his glad assent. Free then to act,\nAs pleas\'d me, I drew near, and took my stand\nO`er that shade, whose words I late had mark\'d.\nAnd, \"Spirit!\"  I said, \"in whom repentant tears\nMature that blessed hour, when thou with God\nShalt find acceptance, for a while suspend\nFor me that mightier care.  Say who thou wast,\nWhy thus ye grovel on your bellies prone,\nAnd if in aught ye wish my service there,\nWhence living I am come.\"  He answering spake\n\"The cause why Heav\'n our back toward his cope\nReverses, shalt thou know: but me know first\nThe successor of Peter, and the name\nAnd title of my lineage from that stream,\nThat\' twixt Chiaveri and Siestri draws\nHis limpid waters through the lowly glen.\nA month and little more by proof I learnt,\nWith what a weight that robe of sov\'reignty\nUpon his shoulder rests, who from the mire\nWould guard it: that each other fardel seems\nBut feathers in the balance.  Late, alas!\nWas my conversion: but when I became\nRome\'s pastor, I discern\'d at once the dream\nAnd cozenage of life, saw that the heart\nRested not there, and yet no prouder height\nLur\'d on the climber: wherefore, of that life\nNo more enamour\'d, in my bosom love\nOf purer being kindled.  For till then\nI was a soul in misery, alienate\nFrom God, and covetous of all earthly things;\nNow, as thou seest, here punish\'d for my doting.\nSuch cleansing from the taint of avarice\nDo spirits converted need.  This mount inflicts\nNo direr penalty.  E\'en as our eyes\nFasten\'d below, nor e\'er to loftier clime\nWere lifted, thus hath justice level\'d us\nHere on the earth.  As avarice quench\'d our love\nOf good, without which is no working, thus\nHere justice holds us prison\'d, hand and foot\nChain\'d down and bound, while heaven\'s just Lord shall please.\nSo long to tarry motionless outstretch\'d.\"\n     My knees I stoop\'d, and would have spoke; but he,\nEre my beginning, by his ear perceiv\'d\nI did him reverence; and \"What cause,\" said he,\n\"Hath bow\'d thee thus!\"--\" Compunction,\" I rejoin\'d.\n\"And inward awe of your high dignity.\"\n     \"Up,\" he exclaim\'d, \"brother!  upon thy feet\nArise: err not: thy fellow servant I,\n(Thine and all others\') of one Sovran Power.\nIf thou hast ever mark\'d those holy sounds\nOf gospel truth, \'nor shall be given ill marriage,\'\nThou mayst discern the reasons of my speech.\nGo thy ways now; and linger here no more.\nThy tarrying is a let un");
    strcat(expected_filecontent, "to the tears,\nWith which I hasten that whereof thou spak\'st.\nI have on earth a kinswoman; her name\nAlagia, worthy in herself, so ill\nExample of our house corrupt her not:\nAnd she is all remaineth of me there.\"\n\n\n\nCANTO XX\n\nIll strives the will, \'gainst will more wise that strives\nHis pleasure therefore to mine own preferr\'d,\nI drew the sponge yet thirsty from the wave.\n     Onward I mov\'d: he also onward mov\'d,\nWho led me, coasting still, wherever place\nAlong the rock was vacant, as a man\nWalks near the battlements on narrow wall.\nFor those on th\' other part, who drop by drop\nWring out their all-infecting malady,\nToo closely press the verge.  Accurst be thou!\nInveterate wolf!  whose gorge ingluts more prey,\nThan every beast beside, yet is not fill\'d!\nSo bottomless thy maw!  --Ye spheres of heaven!\nTo whom there are, as seems, who attribute\nAll change in mortal state, when is the day\nOf his appearing, for whom fate reserves\nTo chase her hence?  --With wary steps and slow\nWe pass\'d; and I attentive to the shades,\nWhom piteously I heard lament and wail;\nAnd, \'midst the wailing, one before us heard\nCry out \"O blessed Virgin!\"  as a dame\nIn the sharp pangs of childbed; and \"How poor\nThou wast,\" it added, \"witness that low roof\nWhere thou didst lay thy sacred burden down.\nO good Fabricius!  thou didst virtue choose\nWith poverty, before great wealth with vice.\"\n     The words so pleas\'d me, that desire to know\nThe spirit, from whose lip they seem\'d to come,\nDid draw me onward.  Yet it spake the gift\nOf Nicholas, which on the maidens he\nBounteous bestow\'d, to save their youthful prime\nUnblemish\'d.  \"Spirit!  who dost speak of deeds\nSo worthy, tell me who thou was,\" I said,\n\"And why thou dost with single voice renew\nMemorial of such praise. That boon vouchsaf\'d\nHaply shall meet reward; if I return\nTo finish the Short pilgrimage of life,\nStill speeding to its close on restless wing.\"\n     \"I,\" answer\'d he, \"will tell thee, not for hell,\nWhich thence I look for; but that in thyself\nGrace so exceeding shines, before thy time\nOf mortal dissolution.  I was root\nOf that ill plant, whose shade such poison sheds\nO\'er all the Christian land, that seldom thence\nGood fruit is gather\'d.  Vengeance soon should come,\nHad Ghent and Douay, Lille and Bruges power;\nAnd vengeance I of heav\'n\'s great Judge implore.\nHugh Capet was I high: from me descend\nThe Philips and the Louis, of whom France\nNewly is govern\'d; born of one, who ply\'d\nThe slaughterer\'s trade at Paris.  When the race\nOf ancient kings had vanish\'d (all save one\nWrapt up in sable weeds) within ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITEINA\\DURInG.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6671; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 79: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST79(void)
{
    // informacje o teście
    test_start(79, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[978] = "";

                strcat(expected_filecontent, "\nv. 5.  Of that chill animal.]  The scorpion.\n\nv. 14.  Our minds.]  Compare Hell, Canto XXVI. 7.\n\nv. 18.  A golden-feathered eagle. ] Chaucer, in the house of\nFame at the conclusion of the first book and beginning of the\nsecond, represents himself carried up by the \"grim pawes\" of a\ngolden eagle. Much of his description is closely imitated from\nDante.\n\nv. 50.  Lucia.]  The enIightening, grace of heaven Hell, Canto\nII. 97.\n\nv. 85.  The lowest stair.]  By the white step is meant the\ndistinctness with which the conscience of the penitent reflects\nhis offences, by the burnt and cracked one, his contrition on,\ntheir account; and by that of porphyry, the fervour with which he\nresolves on the future pursuit of piety and virtue.  Hence, no\ndoubt, Milton describing \"the gate of heaven,\" P. L. b.\niii. 516.\n\nEach stair mysteriously was meant.\n\nv. 100.  Seven times.] Seven P\'s, to denote the seven sins\n(Peccata) of which he was to be cleansed in his passage through\npurgatory");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRiTEiNA\\FACE.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 977; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 80: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST80(void)
{
    // informacje o teście
    test_start(80, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[275] = "";

                strcat(expected_filecontent, ", one\nLords it, and bears his head aloft, for whom\nThe web is now a-warping.  Feltro too\nShall sorrow for its godless shepherd\'s fault,\nOf so deep stain, that never, for the like,\nWas Malta\'s bar unclos\'d.  Too large should be\nThe skillet, that would hold Ferrara\'s blood,\nA");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITeINA\\THING.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 274; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 81: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST81(void)
{
    // informacje o teście
    test_start(81, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[559] = "";

                strcat(expected_filecontent, "and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the we");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEiNA\\BoY.TxT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 558; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 82: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST82(void)
{
    // informacje o teście
    test_start(82, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[980] = "";

                strcat(expected_filecontent, "the\nlake, where it empties itself and forms the Mincius.\n\nv. 94.  Casalodi\'s madness.]  Alberto da Casalodi, who had got\npossession of Mantua, was persuaded by Pinamonte Buonacossi, that\nhe might ingratiate himself with the people by banishing to their\n\nown castles the nobles, who were obnoxious to them.  No sooner\nwas this done, than Pinamonte put himself at the head of the\npopulace, drove out Casalodi and his adherents, and obtained the\nsovereignty for himself.\n\nv. 111.  So sings my tragic strain.]\n        Suspensi Eurypilum scitatum oracula Phoebi\n        Mittimus.\n               Virg. Aeneid. ii. 14.\n\nv. 115.  Michael Scot.]  Sir Michael Scott, of Balwearie,\nastrologer to the Emperor Frederick II. lived in the thirteenth\ncentury.  For further particulars relating to this singular man,\nsee Warton\'s History of English Poetry, vol. i. diss. ii. and\nsect. ix.  p 292, and the Notes to Mr. Scott\'s \"Lay of the Last\nMinstrel,\" a  poem in which a happy use is made of th");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITeina\\MELODY.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 979; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 83: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST83(void)
{
    // informacje o teście
    test_start(83, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[699] = "";

                strcat(expected_filecontent, "ehold,\nAs would my speech discredit.\"  On all sides\nI heard sad plainings breathe, and none could see\nFrom whom they might have issu\'d.  In amaze\nFast bound I stood.  He, as it seem\'d, believ\'d,\nThat I had thought so many voices came\nFrom some amid those thickets close conceal\'d,\nAnd thus his speech resum\'d:  \"If thou lop off\nA single twig from one of those ill plants,\nThe thought thou hast conceiv\'d shall vanish quite.\"\n     Thereat a little stretching forth my hand,\nFrom a great wilding gather\'d I a branch,\nAnd straight the trunk exclaim\'d:  \"Why pluck\'st thou me?\"\nThen as the dark blood trickled down its side,\nThese words it added:  \"Wherefore tear\'st me thus?\nIs there no touch of mercy");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRiTEINA\\MEaT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 698; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 84: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST84(void)
{
    // informacje o teście
    test_start(84, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[703] = "";

                strcat(expected_filecontent, "is leader walks,\nLest he should err, or stumble unawares\nOn what might harm him, or perhaps destroy,\nI journey\'d through that bitter air and foul,\nStill list\'ning to my escort\'s warning voice,\n\"Look that from me thou part not.\"  Straight I heard\nVoices, and each one seem\'d to pray for peace,\nAnd for compassion, to the Lamb of God\nThat taketh sins away.  Their prelude still\nWas \"Agnus Dei,\" and through all the choir,\nOne voice, one measure ran, that perfect seem\'d\nThe concord of their song.  \"Are these I hear\nSpirits, O master?\"  I exclaim\'d; and he:\n\"Thou aim\'st aright: these loose the bonds of wrath.\"\n     \"Now who art thou, that through our smoke dost cleave?\nAnd speak\'st of us, as thou thys");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEINA\\suMMer.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 702; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 85: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST85(void)
{
    // informacje o teście
    test_start(85, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4393] = "";

                strcat(expected_filecontent, "in these murky settlings are we sad.\"\nSuch dolorous strain they gurgle in their throats.\nBut word distinct can utter none.\"  Our route\nThus compass\'d we, a segment widely stretch\'d\nBetween the dry embankment, and the core\nOf the loath\'d pool, turning meanwhile our eyes\nDownward on those who gulp\'d its muddy lees;\nNor stopp\'d, till to a tower\'s low base we came.\n\n\n\nCANTO VIII\n\nMY theme pursuing, I relate that ere\nWe reach\'d the lofty turret\'s base, our eyes\nIts height ascended, where two cressets hung\nWe mark\'d, and from afar another light\nReturn the signal, so remote, that scarce\nThe eye could catch its beam.  I turning round\nTo the deep source of knowledge, thus inquir\'d:\n\"Say what this means?  and what that other light\nIn answer set?  what agency doth this?\"\n     \"There on the filthy waters,\" he replied,\n\"E\'en now what next awaits us mayst thou see,\nIf the marsh-gender\'d fog conceal it not.\"\n     Never was arrow from the cord dismiss\'d,\nThat ran its way so nimbly through the air,\nAs a small bark, that through the waves I spied\nToward us coming, under the sole sway\nOf one that ferried it, who cried aloud:\n\"Art thou arriv\'d, fell spirit?\"--\"Phlegyas, Phlegyas,\nThis time thou criest in vain,\" my lord replied;\n\"No longer shalt thou have us, but while o\'er\nThe slimy pool we pass.\"  As one who hears\nOf some great wrong he hath sustain\'d, whereat\nInly he pines; so Phlegyas inly pin\'d\nIn his fierce ire.  My guide descending stepp\'d\nInto the skiff, and bade me enter next\nClose at his side; nor till my entrance seem\'d\nThe vessel freighted.  Soon as both embark\'d,\nCutting the waves, goes on the ancient prow,\nMore deeply than with others it is wont.\n     While we our course o\'er the dead channel held.\nOne drench\'d in mire before me came, and said;\n\"Who art thou, that thou comest ere thine hour?\"\n     I answer\'d: \"Though I come, I tarry not;\nBut who art thou, that art become so foul?\"\n     \"One, as thou seest, who mourn: \" he straight replied.\n     To which I thus: \" In mourning and in woe,\nCurs\'d spirit!  tarry thou. I know thee well,\nE\'en thus in filth disguis\'d.\"  Then stretch\'d he forth\nHands to the bark; whereof my teacher sage\nAware, thrusting him back: \"Away!  down there\nTo the\' other dogs!\"  then, with his arms my neck\nEncircling, kiss\'d my cheek, and spake: \"O soul\nJustly disdainful!  blest was she in whom\nThou was conceiv\'d!  He in the world was one\nFor arrogance noted; to his memory\nNo virtue lends its lustre; even so\nHere is his shadow furious.  There above\nHow many now hold themselves mighty kings\nWho here like swine shall wallow in the mire,\nLeaving behind them horrible dispraise!\"\n     I then: \"Master!  him fain would I behold\nWhelm\'d in these dregs, before we quit the lake.\"\n     He thus: \"Or ever to thy view the shore\nBe offer\'d, satisfied shall be that wish,\nWhich well deserves completion.\"  Scarce his words\nWere ended, when I saw the miry tribes\nSet on him with such violence, that yet\nFor that render I thanks to God and praise\n\"To Filippo Argenti:\" cried they all:\nAnd on himself the moody Florentine\nTurn\'d his avenging fangs.  Him here we left,\nNor speak I of him more.  But on mine ear\nSudden a sound of lamentation smote,\nWhereat mine eye unbarr\'d I sent abroad.\n     And thus the good instructor: \"Now, my son!\nDraws near the city, that of Dis is nam\'d,\nWith its grave denizens, a mighty throng.\"\n     I thus: \"The minarets already, Sir!\nThere certes in the valley I descry,\nGleaming vermilion, as if they from fire\nHad issu\'d.\"  He replied: \"Eternal fire,\nThat inward burns, shows them with ruddy flame\nIllum\'d; as in this nether hell thou seest.\"\n     We came within the fosses deep, that moat\nThis region comfortless.  The walls appear\'d\nAs they were fram\'d of iron.  We had made\nWide circuit, ere a place we reach\'d, where loud\nThe mariner cried vehement: \"Go forth!\nThe\' entrance is here!\"  Upon the gates I spied\nMore than a thousand, who of old from heaven\nWere hurl\'d.  With ireful gestures, \"Who is this,\"\nThey cried, \"that without death first felt, goes through\nThe regions of the dead?\"  My sapient guide\nMade sign th");
    strcat(expected_filecontent, "at he for secret parley wish\'d;\nWhereat their angry scorn abating, thus\nThey spake: \"Come thou alone; and let him go\nWho hath so hardily enter\'d this realm.\nAlone return he by his witless way;\nIf well he know it, let him prove.  For thee,\nHere shalt thou tarry, who through clime so dark\nHast been");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrItEina\\pROdUCE.bIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4392; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 86: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST86(void)
{
    // informacje o teście
    test_start(86, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "  loving, which of sight\nIs aftergrowth.  And of the seeing such\nThe meed, as unto each in due degree\nGrace and good-will their measure have assign\'d.\nThe other trine, that with still opening buds\nIn this eternal springtide blossom fair,\nFearless of bruising from the nightly ram,\nBreathe up in warbled melodies threefold\nHosannas blending ever, from the three\nTransmitted. hierarchy of gods, for aye\nRejoicing, dominations first, next then\nVirtues, and powers the third.  The next to whom\nAre princedoms and archangels, with glad round\nTo tread their festal ring; and last the band\nAngelical, disporting in their sphere.\nAll, as they circle in their orders, look\nAloft, and downward with such sway prevail,\nThat all with mutual impulse tend to God.\nThese once a mortal view beheld.  Desire\nIn Dionysius so intently wrought,\nThat he, as I have done rang\'d them; and nam\'d\nTheir orders, marshal\'d in his thought.  From him\nDissentient, one refus\'d his sacred read.\nBut soon as in this heav\'n his doubting eyes\nWere open\'d, Gregory at his error smil\'d\nNor marvel, that a denizen of earth\nShould scan such secret truth; for he had learnt\nBoth this and much beside of these our orbs,\nFrom an eye-witness to heav\'n\'s mysteries.\"\n\n\n\nCANTO XXIX\n\nNo longer than what time Latona\'s twins\nCover\'d of Libra and the fleecy star,\nTogether both, girding the\' horizon hang,\nIn even balance from the zenith pois\'d,\nTill from that verge, each, changing hemisphere,\nPart the nice level; e\'en so brief a space\nDid Beatrice\'s silence hold.  A smile\nBat painted on her cheek; and her fix\'d gaze\nBent on the point, at which my vision fail\'d:\nWhen thus her words resuming she began:\n\"I speak, nor what thou wouldst inquire demand;\nFor I have mark\'d it, where all time and place\nAre present.  Not for increase to himself\nOf good, which may not be increas\'d, but forth\nTo manifest his glory by its beams,\nInhabiting his own eternity,\nBeyond time\'s limit or what bound soe\'er\nTo circumscribe his being, as he will\'d,\nInto new natures, like unto himself,\nEternal Love unfolded.  Nor before,\nAs if in dull inaction torpid lay.\nFor not in process of before or aft\nUpon these waters mov\'d the Spirit of God.\nSimple and mix\'d, both form and substance, forth\nTo perfect being started, like three darts\nShot from a bow three-corded.  And as ray\nIn crystal, glass, and amber, shines entire,\nE\'en at the moment of its issuing; thus\nDid, from th\' eternal Sovran, beam entire\nHis threefold operation, at one act\nProduc\'d coeval.  Yet in order each\nCreated his due station knew: those highest,\nWho pure intelligence were made: mere power\nThe lowest: in the midst, bound with strict league,\nIntelligence and power, unsever\'d bond.\nLong tract of ages by the angels past,\nEre the creating of another world,\nDescrib\'d on Jerome\'s pages thou hast seen.\nBut that what I disclose to thee is true,\nThose penmen, whom the Holy Spirit mov\'d\nIn many a passage of their sacred book\nAttest; as thou by diligent search shalt find\nAnd reason in some sort discerns the same,\nWho scarce would grant the heav\'nly ministers\nOf their perfection void, so long a space.\nThus when and where these spirits of love were made,\nThou know\'st, and how: and knowing hast allay\'d\nThy thirst, which from the triple question rose.\nEre one had reckon\'d twenty, e\'en so soon\nPart of the angels fell: and in their fall\nConfusion to your elements ensued.\nThe others kept their station: and this task,\nWhereon thou lookst, began with such delight,\nThat they surcease not ever, day nor night,\nTheir circling.  Of that fatal lapse the cause\nWas the curst pride of him, whom thou hast seen\nPent with the world\'s incumbrance.  Those, whom here\nThou seest, were lowly to confess themselves\nOf his free bounty, who had made them apt\nFor ministries so high: therefore their views\nWere by enlight\'ning grace and their own merit\nExalted; so that in their will confirm\'d\nThey stand, nor feel to fall.  For do not doubt,\nBut to receive the grace, which heav\'n vouchsafes,\nIs meritorious, even as the soul\nWith prompt affection welcometh the guest.\nNow, without further help, if with");
    strcat(expected_filecontent, " good heed\nMy words thy mind have treasur\'d, thou henceforth\nThis consistory round about mayst scan,\nAnd gaze thy fill.  But since thou hast on earth\nHeard vain disputers, reasoners in the schools,\nCanvas the\' angelic nature, and dispute\nIts powers of apprehension, memory, choice;\nTherefore, \'t is well thou take from me the truth,\nPure and without disguise, which they below,\nEquivocating, darken and perplex.\n     \"Know thou, that, from the first, these substances,\nRejoicing in the countenance of God,\nHave held unceasingly their view, intent\nUpon the glorious vision, from the which\nNaught absent is nor hid: where then no change\nOf newness with succession interrupts,\nRemembrance there needs none to gather up\nDivided thought and images remote\n     \"So that men, thus at variance with the truth\nDream, though their eyes be open; reckless some\nOf error; others well aware they err,\nTo whom more guilt and shame are justly due.\nEach the known track of sage philosophy\nDeserts, and has a byway of his own:\nSo much the rest");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wrITEINA\\MEET.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 87: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST87(void)
{
    // informacje o teście
    test_start(87, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "aduca spoglia\n        Tu, Signor, me vestisti e tu mi spoglia:\n        Ben puoi\'l Regno me tor tu che me\'l desti.\nAnd by Maffei, in the Merope:\n               Tu disciogleste\n        Queste misere membra e tu le annodi.\n\nv. 79. In that fair region.]\n        Del bel paese la, dove\'l si suona.\nItaly as explained by Dante himself, in his treatise De Vulg.\nEloq. l. i. c. 8. \"Qui autem Si dicunt a praedictis finibus.\n(Januensiem) Oreintalem (Meridionalis Europae partem) tenent;\nvidelicet usque ad promontorium illud Italiae, qua sinus\nAdriatici maris incipit et Siciliam.\"\n\nv. 82.  Capraia and Gorgona.]  Small islands near the mouth of\nthe Arno.\n\nv. 94.  There very weeping suffers not to weep,]\n        Lo pianto stesso li pianger non lascia.\nSo Giusto de\'Conti, Bella Mano. Son. \"Quanto il ciel.\"\n        Che il troppo pianto a me pianger non lassa.\nv. 116.  The friar Albigero.]  Alberigo de\'Manfredi, of Faenza,\none of the Frati Godenti, Joyons Friars who having quarrelled\nwith some of his brotherhood, under pretence of wishing to be\nreconciled, invited them to a banquet, at the conclusion of which\nhe called for the fruit, a signal for the assassins to rush in\nand dispatch those whom he had marked for destruction.  Hence,\nadds Landino, it is said proverbially of one who has been\nstabbed, that he has had some of the friar Alberigo\'s fruit.\nThus Pulci, Morg. Magg. c. xxv.\n        Le frutte amare di frate Alberico.\n\nv. 123.  Ptolomea.]  This circle is named Ptolomea from Ptolemy,\nthe son of Abubus, by whom Simon and his sons were murdered, at a\ngreat banquet he had made for them. See Maccabees, ch xvi.\n\nv. 126.  The glazed tear-drops.]\n\n        -sorrow\'s eye, glazed with blinding tears.\n               Shakspeare, Rich. II. a. 2. s. 2.\n\nv. 136.  Branca Doria.]  The family of Doria was possessed of\ngreat influence in Genoa.  Branca is said to have murdered his\nfather-in-law, Michel Zanche, introduced in Canto XXII.\n\nv. 162  Romagna\'s darkest spirit.]  The friar Alberigo.\n\n\n\nCanto XXXIV.\n\nv. 6.  A wind-mill.]  The author of the Caliph Vathek, in the\nnotes to that tale, justly observes, that it is more than\nprobable that Don Quixote\'s mistake of the wind-mills for giants\nwas suggested to Cervantes by this simile.\n\nv. 37. Three faces.]  It can scarcely be doubted but that Milton\nderived his description of Satan in those lines,\n\n               Each passion dimm\'d his face\n        Thrice chang\'d with pale, ire, envy, and despair.\n               P. L. b. iv. 114.\nfrom this passage, coupled with the remark of Vellutello upon it:\n\n\"The first of these sins is anger which he signifies by the red\nface; the second, represented by that between pale and yellow is\nenvy and not, as others have said, avarice; and the third,\ndenoted by the black, is a melancholy humour that causes a man\'s\nthoughts to be dark and evil, and averse from all joy and\ntranquillity.\"\n\nv. 44. Sails.]\n               --His sail-broad vans\n        He spreads for flight.\n               Milton, P. L. b. ii. 927.\nCompare Spenser, F. Q. b. i. c. xi. st. 10;  Ben Jonson\'s Every\nMan out of his humour, v. 7; and Fletcher\'s Prophetess, a. 2. s.\n3.\n\nv. 46.  Like a bat.]  The description of an imaginary being, who\nis called Typhurgo, in the Zodiacus Vitae, has some touches very\nlike this of Dante\'s Lucifer.\n\n        Ingentem vidi regem ingentique sedentem\n        In solio, crines flammanti stemmate cinctum\n               ---utrinque patentes\n        Alae humeris magnae, quales vespertilionum\n        Membranis contextae amplis--\n        Nudus erat longis sed opertus corpora villis.\n               M. Palingenii, Zod. Vit. l. ix.\n        A mighty king I might discerne,\n               Plac\'d hie on lofty chaire,\n        His haire with fyry garland deckt\n               Puft up in fiendish wise.\n        x      x      x       x      x       x\n               Large wings on him did grow\n        Framde like the wings of flinder mice, &c.\n               Googe\'s Translation\n\nv. 61. Brutus.]  Landino struggles, but I fear in vain, to\nextricate Brutus from the unworthy lot which is here assigned\nhim.  ");
    strcat(expected_filecontent, "He maintains, that by Brutus and Cassius are not meant the\nindividuals known by those names, but any who put a lawful\nmonarch to death.  Yet if Caesar was such, the conspirators might\nbe regarded as deserving of their doom.\n\nv. 89.  Within one hour and half of noon.]  The poet uses the\nHebrew manner of computing the day, according to which the third\nhour answers to our twelve o\'clock at noon.\n\nv. 120.  By what of firm land on this side appears.]  The\nmountain of Purgatory.\n\nv.123.  The vaulted tomb.]  \"La tomba.\"  This word is used to\nexpress the whole depth of the infernal region.\n\n\n\nPURGATORY\n\n\nCANTO I\n\n\nO\'er better waves to speed her rapid course\nThe light bark of my genius lifts the sail,\nWell pleas\'d to leave so cruel sea behind;\nAnd of that second region will I sing,\nIn which the human spirit from sinful blot\nIs purg\'d, and for ascent to Heaven prepares.\n     Here, O ye hallow\'d Nine!  for in your train\nI follow, here the deadened strain revive;\nNor let Calliope refuse to sound\nA somewhat higher song, of that loud tone,\nWhich when the wretched birds of chattering note\nHad heard, they of forgiveness lost all hope.\n     Sweet hue of eastern sapphire, that was spread\nO\'er the serene aspect of the pure air,\nHigh up as the first circle, to mine eyes\nUnwonted joy renew\'d, soon as I \'scap\'d\nForth from the atmosphere of deadly gloom,\nThat had mine eyes and bosom fill\'d with grief.\nThe radiant planet, that to love invites,\nMade all the orient laugh, and veil\'d beneath\nThe Pisces\' light, that in his escort came.\n     To the right hand I turn\'d, and fix\'d my mind\nOn the\' other pole attentive, where I saw\nFour stars ne\'er seen before save by the ken\nOf our first parents.  Heaven of their rays\nSeem\'d joyous.  O thou northern site, bereft\nIndeed, and widow\'d, since of these depriv\'d!\n     As from this view I had desisted, straight\nTurning a little tow\'rds the other pole,\nThere from whence now the wain had disappear\'d,\nI saw an old man standing by my side\nAlone, so worthy of rev\'rence in his look,\nThat ne\'er from son to fa");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEINA\\ChiCk.biN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6144; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 88: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST88(void)
{
    // informacje o teście
    test_start(88, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[708] = "";

                strcat(expected_filecontent, "e.\n\nv. 39.  Many a noble act.]  Compare Tasso, G. L. c. i. st. 1.\n\nv. 42.  Aldobrandiu]  Tegghiaio Aldobrandi was of the noble\nfamily of Adimari, and much esteemed for his military talents.\nHe endeavored to dissuade the Florentines from the attack, which\nthey meditated against the Siennese, and the rejection of his\ncounsel occasioned the memorable defeat, which the former\nsustained at Montaperto, and the consequent banishment of the\nGuelfi from Florence.\n\nv. 45.  Rusticucci.]  Giacopo Rusticucci, a Florentine,\nremarkable for his opulence and the generosity of his spirit.\n\nv. 70.  Borsiere.]  Guglielmo Borsiere, another Florentine, whom\nBoccaccio, in a story which he relates of him, terms \"a man of\n");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEiNA\\TONE.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 707; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 89: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST89(void)
{
    // informacje o teście
    test_start(89, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[864] = "";

                strcat(expected_filecontent, "ng is\nCharles Martel crowned king of Hungary, and son of Charles 11\nking of Naples and Sicily, to which\ndominions dying in his father\'s lifetime, he did not succeed.\n\nv. 57.  Thou lov\'dst me well.]  Charles Martel might have been\nknown to our poet at Florence whither he came to meet his father\nin 1295, the year of his death.  The retinue and the habiliments\nof the young monarch are minutely described by G. Villani, who\nadds, that \"he remained more than twenty days in Florence,\nwaiting for his father King Charles and his brothers during which\ntime great honour was done him by the, Florentines and he showed\nno less love towards them, and he was much in favour with all.\"\n1.  viii. c. 13. His brother Robert, king of Naples, was the\nfriend of Petrarch.\n\nv. 60.  The left bank.]  Provence.\n\nv. 62.  That horn\nOf fair Ausonia.]\nThe kingdom of Naples.\n\nv. 68.  ");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\wRITEiNa\\cERTaIn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 863; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 90: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST90(void)
{
    // informacje o teście
    test_start(90, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6145] = "";

                strcat(expected_filecontent, "ttachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'d in thee?\nShakespeare, Richard II a. 5. s. 1.\n\nv. 89.  Justinian\'s hand.]  \"What avails it that Justinian\ndelivered thee from the Goths, and reformed thy laws, if thou art\nno longer under the control of his successors in the empire?\"\n\nv. 94.  That which God commands.]  He alludes to the precept-\n\"Render unto Caesar the things which are Caesar\'s.\"\n\nv. 98.  O German Albert!]  The Emperor Albert I. succeeded\nAdolphus in 1298, and was murdered in 1308.  See Par Canto XIX\n114 v. 103.  Thy successor.]  The successor of Albert was Henry\nof Luxembourg, by whose interposition in the affairs of Italy our\nPoet hoped to have been reinstated in his native city.\n\nv. 101.  Thy sire.]  The Emperor Rodolph, too intent on\nincreasing his power in Germany to give much of his thoughts to\nItaly, \"the garden of the empire.\"\n\nv. 107.  Capulets and Montagues.]  Our ears are so familiarized\nto the names of these rival families in the language of\nShakespeare, that I have used them instead of the \"Montecchi\" and\n\"Cappelletti.\"\n\nv. 108.  Philippeschi and Monaldi.] Two other rival families in\nOrvieto.\n\nv. 113.  What safety, Santafiore can supply.]  A place between\nPisa and Sienna.  What he alludes to is so doubtful, that it is\nnot certain whether we should not read \"come si cura\"--\" How\nSantafiore is governed.\" Perhaps the event related in the note to\nv. 58, Canto XI. may be pointed at.\n\nv. 127.  Marcellus.]\nUn Marcel diventa\nOgni villan che parteggiando viene.\nRepeated by Alamanni in his Coltivazione, 1. i.\n\nv. 51.  I sick wretch.]  Imitated by the Cardinal de Polignac in\nhis Anti-Lucretius, 1. i. 1052.\n\nCeu lectum peragrat membris languentibus aeger\nIn latus alterne faevum dextrumque recumbens\nNec javat:  inde oculos tollit resupinus in altum:\nNusquam inventa quies; semper quaesita:  quod illi\nPrimum in deliciis fuerat, mox torquet et angit:\nNec morburm sanat, nec fallit taedia morbi.\n\nCANTO VII\n\nv. 14.  Where one of mean estate might clasp his lord.]\nAriosto Orl.  F. c. xxiv. st. 19\n\nE l\'abbracciaro, ove il maggior s\'abbraccia\nCol capo nudo e col ginocchio chino.\n\nv. 31.  The three holy virtues.]  Faith, Hope and Charity.\n\nv. 32.  The red.]  Prudence, Justice, Fortitude, and Temperance.\n\nv. 72.  Fresh emeralds.]\nUnder foot the violet,\nCrocus, and hyacinth with rich inlay\nBroider\'d the ground, more colour\'d than with stone\nOf costliest emblem.\nMilton, P. L. b. iv. 793\n\nCompare Ariosto, Orl. F. c. xxxiv. st. 49.\n\nv. 79.  Salve Regina.]  The beginning of a prayer to the Virgin.\nIt is sufficient here to observe, that in similar instances I\nshall either preserve the original Latin words or translate them,\nas it may seem best to suit the purpose of the verse.\n\nv. 91.  The Emperor Rodolph.]  See the last Canto, v. 104.  He\ndied in 1291.\n\nv. 95.  That country.]  Bohemia.\n\nv. 97.  Ottocar.]  King of Bohemia, was killed in the battle of\nMarchfield, fought with Rodolph, August 26, 1278. Winceslaus II.\nHis son,who succeeded him in t");
    strcat(expected_filecontent, "he kingdom of Bohemia. died in\n1305. He is again taxed with luxury in the Paradise Canto XIX.\n123.\n\nv. 101.  That one with the nose deprest. ] Philip III of France,\nwho died in 1285, at Perpignan, in his retreat from Arragon.\n\nv. 102.  Him of gentle look.]  Henry of Naverre, father of Jane\nmarried to Philip IV of France, whom Dante calls \"mal di Francia\"\n-\" Gallia\'s bane.\"\n\nv. 110.  He so robust of limb.] Peter III called the Great,\nKing of Arragon, who died in 1285, leaving four sons, Alonzo,\nJames, Frederick and Peter. The two former succeeded him in the\nkingdom of Arragon, and Frederick in that of Sicily.\nSee G. Villani, 1. vii. c. 102. and Mariana, I. xiv. c. 9.\nHe is enumerated among the Provencal poets by Millot, Hist. Litt.\nDes Troubadours, t. iii. p. 150.\n\nv. 111.  Him of feature prominent.] \"Dal maschio naso\"-with the\nmasculine nose.\" Charles I. King of Naples, Count of Anjou, and\nbrother of St. Lonis.  He died in 1284. The annalist of Florence\nremarks, that \"there had been no sovereign of the house of\nFrance, since the time of Charlemagne, by whom Charles\nwas surpassed either in military renown, and prowess, or in the\nloftiness of his understanding.\"  G. Villani, 1. vii. c.  94.\nWe shall, however, find many of his actions severely reprobated\nin the twentieth Canto.\n\nv. 113.  That stripling.]  Either (as the old commentators\nsuppose) Alonzo III King of Arragon, the eldest son of Peter III\nwho died in 1291, at the age of 27, or, according to Venturi,\nPeter the youngest son. The former was a young prince of virtue\nsufficient to have justified the eulogium and the hopes of Dante.\n\nSee Mariana, 1. xiv. c. 14.\n\nv. 119.  Rarely.]\nFull well can the wise poet of Florence\nThat hight Dante, speaken in this sentence\nLo!  in such manner rime is Dantes tale.\nFull selde upriseth by his branches smale\nProwesse of man for God of his goodnesse\nWoll that we claim of him our gentlenesse:\nFor of our elders may we nothing claime\nBut temporal thing, that men may hurt and maime.\nChaucer, Wife of Bathe\'s Tale.\n\nCompare Homer, Od");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEINA\\AMOnG.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6144; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 91: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST91(void)
{
    // informacje o teście
    test_start(91, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5121] = "";

                strcat(expected_filecontent, "f a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit.  If of thee Charon complain,\nNow mayst thou know the import of his words.\"\n     This said, the gloomy region trembling shook\nSo terribly, that yet with clammy dews\nFear chills my brow.  The sad earth gave a blast,\nThat, lightening, shot forth a vermilion flame,\nWhich all my senses conquer\'d quite, and I\nDown dropp\'d, as one with sudden slumber seiz\'d.\n\n\n\nCANTO IV\n\nBROKE the deep slumber in my brain a crash\nOf heavy thunder, that I shook myself,\nAs one by main force rous\'d.  Risen upright,\nMy rested eyes I mov\'d around, and search\'d\nWith fixed ken to know what place it was,\nWherein I stood.  For certain on the brink\nI found me of the lamentable vale,\nThe dread abyss, that joins a thund\'rous sound\nOf plaints innumerable.  Dark and deep,\nAnd thick with clouds o\'erspread, mine eye in vain\nExplor\'d its bottom, nor could aught discern.\n     \"Now let us to the blind world there beneath\nDescend;\" the bard began all pale of look:\n\"I go the first, and thou shalt follow next.\"\n     Then I his alter\'d hue perceiving, thus:\n\"How may I speed, if thou yieldest to dread,\nWho still art wont to comfort me in doubt?\"\n     He then:  \"The anguish of that race below\nWith pity stains my cheek, which thou for fear\nMistakest.  Let us on.  Our length of way\nUrges to haste.\"  Onward, this said, he mov\'d;\nAnd ent\'ring led me with him on the bounds\nOf the first circle, that surrounds th\' abyss.\nHere, as mine ear could note, no plaint was heard\nExcept of sighs, that made th\' eternal air\nTremble, not caus\'d by tortures, but from grief\nFelt by those multitudes, many and vast,\nOf men, women, and infants.  Then to me\nThe gentle guide:  \"Inquir\'st thou not what spirits\nAre these, which thou beholdest?  Ere thou pass\nFarther, I would thou know,");
    strcat(expected_filecontent, " that these of sin\nWere blameless; and if aught they merited,\nIt profits not, since baptism was not theirs,\nThe portal to thy faith.  If they before\nThe Gospel liv\'d, they serv\'d not God aright;\nAnd among such am I. For these defects,\nAnd for no other evil, we are lost;\nOnly so far afflicted, that we live\nDesiring without hope.\"  So grief assail\'d\nMy heart at hearing this, for well I knew\nSuspended in that Limbo many a soul\nOf mighty worth.  \"O tell me, sire rever\'d!\nTell me, my master!\"  I began through wish\nOf full assurance in that holy faith,\nWhich vanquishes all error; \"say, did e\'er\nAny, or through his own or other\'s merit,\nCome forth from thence, whom afterward was blest?\"\n     Piercing the secret purport of my speech,\nHe answer\'d: \"I was new to that estate,\nWhen I beheld a puissant one arrive\nAmongst us, with victorious trophy crown\'d.\nHe forth the shade of our first parent drew,\nAbel his child, and Noah righteous man,\nOf Moses lawgiver for faith approv\'d,\nOf patriarch Abraham, and David king,\nIsrael w");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEInA\\eQUal.Tx");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5120; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 92: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST92(void)
{
    // informacje o teście
    test_start(92, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[4097] = "";

                strcat(expected_filecontent, "I dearly prize) if any soul\nOf Latium dwell among ye; and perchance\nThat soul may profit, if I learn so much.\"\n     \"My brother, we are each one citizens\nOf one true city.  Any thou wouldst say,\nWho lived a stranger in Italia\'s land.\"\n     So heard I answering, as appeal\'d, a voice\nThat onward came some space from whence I stood.\n     A spirit I noted, in whose look was mark\'d\nExpectance.  Ask ye how?  The chin was rais\'d\nAs in one reft of sight.  \"Spirit,\" said I,\n\"Who for thy rise are tutoring (if thou be\nThat which didst answer to me,) or by place\nOr name, disclose thyself, that I may know thee.\"\n     \"I was,\" it answer\'d, \"of Sienna:  here\nI cleanse away with these the evil life,\nSoliciting with tears that He, who is,\nVouchsafe him to us.  Though Sapia nam\'d\nIn sapience I excell\'d not, gladder far\nOf others\' hurt, than of the good befell me.\nThat thou mayst own I now deceive thee not,\nHear, if my folly were not as I speak it.\nWhen now my years slop\'d waning down the arch,\nIt so bechanc\'d, my fellow citizens\nNear Colle met their enemies in the field,\nAnd I pray\'d God to grant what He had will\'d.\nThere were they vanquish\'d, and betook themselves\nUnto the bitter passages of flight.\nI mark\'d the hunt, and waxing out of bounds\nIn gladness, lifted up my shameless brow,\nAnd like the merlin cheated by a gleam,\nCried, \"It is over.  Heav\'n!  I fear thee not.\"\nUpon my verge of life I wish\'d for peace\nWith God; nor repentance had supplied\nWhat I did lack of duty, were it not\nThe hermit Piero, touch\'d with charity,\nIn his devout orisons thought on me.\nBut who art thou that question\'st of our state,\nWho go\'st to my belief, with lids unclos\'d,\nAnd breathest in thy talk?\" --\"Mine eyes,\" said I,\n\"May yet be here ta\'en from me; but not long;\nFor they have not offended grievously\nWith envious glances.  But the woe beneath\nUrges my soul with more exceeding dread.\nThat nether load already weighs me down.\"\n     She thus:  \"Who then amongst us here aloft\nHath brought thee, if thou weenest to return?\"\n     \"He,\" answer\'d I, \"who standeth mute beside me.\nI live: of me ask therefore, chosen spirit,\nIf thou desire I yonder yet should move\nFor thee my mortal feet.\" --\"Oh!\" she replied,\n\"This is so strange a thing, it is great sign\nThat God doth love thee.  Therefore with thy prayer\nSometime assist me: and by that I crave,\nWhich most thou covetest, that if thy feet\nE\'er tread on Tuscan soil, thou save my fame\nAmongst my kindred.  Them shalt thou behold\nWith that vain multitude, who set their hope\nOn Telamone\'s haven, there to fail\nConfounded, more shall when the fancied stream\nThey sought of Dian call\'d:  but they who lead\nTheir navies, more than ruin\'d hopes shall mourn.\"\n\n\nCANTO XIV\n\n\"Say who is he around our mountain winds,\nOr ever death has prun\'d his wing for flight,\nThat opes his eyes and covers them at will?\"\n     \"I know not who he is, but know thus much\nHe comes not singly.  Do thou ask of him,\nFor thou art nearer to him, and take heed\nAccost him gently, so that he may speak.\"\n     Thus on the right two Spirits bending each\nToward the other, talk\'d of me, then both\nAddressing me, their faces backward lean\'d,\nAnd thus the one began:  \"O soul, who yet\nPent in the body, tendest towards the sky!\nFor charity, we pray thee\' comfort us,\nRecounting whence thou com\'st, and who thou art:\nFor thou dost make us at the favour shown thee\nMarvel, as at a thing that ne\'er hath been.\"\n     \"There stretches through the midst of Tuscany,\nI straight began: \"a brooklet, whose well-head\nSprings up in Falterona, with his race\nNot satisfied, when he some hundred miles\nHath measur\'d.  From his banks bring, I this frame.\nTo tell you who I am were words misspent:\nFor yet my name scarce sounds on rumour\'s lip.\"\n     \"If well I do incorp\'rate with my thought\nThe meaning of thy speech,\" said he, who first\nAddrest me, \"thou dost speak of Arno\'s wave.\"\n     To whom the other: \"Why hath he conceal\'d\nThe title of that river, as a man\nDoth of some horrible thing?\"  The spirit, who\nThereof was question\'d, did acquit him thus:\n\"I know not: but \'tis fitting well the name\nS");
    strcat(expected_filecontent, "h");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRItEina\\ENTER.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 4096; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 93: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST93(void)
{
    // informacje o teście
    test_start(93, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, "ing, when Syrinx warbled, (eyes that paid\nSo dearly for their watching,) then like painter,\nThat with a model paints, I might design\nThe manner of my falling into sleep.\nBut feign who will the slumber cunningly;\nI pass it by to when I wak\'d, and tell\nHow suddenly a flash of splendour rent\nThe curtain of my sleep, and one cries out:\n\"Arise, what dost thou?\"  As the chosen three,\nOn Tabor\'s mount, admitted to behold\nThe blossoming of that fair tree, whose fruit\nIs coveted of angels, and doth make\nPerpetual feast in heaven, to themselves\nReturning at the word, whence deeper sleeps\nWere broken, that they their tribe diminish\'d saw,\nBoth Moses and Elias gone, and chang\'d\nThe stole their master wore: thus to myself\nReturning, over me beheld I stand\nThe piteous one, who cross the stream had brought\nMy steps.  \"And where,\" all doubting, I exclaim\'d,\n\"Is Beatrice?\"--\"See her,\" she replied,\n\"Beneath the fresh leaf seated on its root.\nBehold th\' associate choir that circles her.\nThe others, with a melody more sweet\nAnd more profound, journeying to higher realms,\nUpon the Gryphon tend.\"  If there her words\nWere clos\'d, I know not; but mine eyes had now\nTa\'en view of her, by whom all other thoughts\nWere barr\'d admittance.  On the very ground\nAlone she sat, as she had there been left\nA guard upon the wain, which I beheld\nBound to the twyform beast.  The seven nymphs\nDid make themselves a cloister round about her,\nAnd in their hands upheld those lights secure\nFrom blast septentrion and the gusty south.\n     \"A little while thou shalt be forester here:\nAnd citizen shalt be forever with me,\nOf that true Rome, wherein Christ dwells a Roman\nTo profit the misguided world, keep now\nThine eyes upon the car; and what thou seest,\nTake heed thou write, returning to that place.\"\n     Thus Beatrice: at whose feet inclin\'d\nDevout, at her behest, my thought and eyes,\nI, as she bade, directed.  Never fire,\nWith so swift motion, forth a stormy cloud\nLeap\'d downward from the welkin\'s farthest bound,\nAs I beheld the bird of Jove descending\nPounce on the tree, and, as he rush\'d, the rind,\nDisparting crush beneath him, buds much more\nAnd leaflets.  On the car with all his might\nHe struck, whence, staggering like a ship, it reel\'d,\nAt random driv\'n, to starboard now, o\'ercome,\nAnd now to larboard, by the vaulting waves.\n     Next springing up into the chariot\'s womb\nA fox I saw, with hunger seeming pin\'d\nOf all good food.  But, for his ugly sins\nThe saintly maid rebuking him, away\nScamp\'ring he turn\'d, fast as his hide-bound corpse\nWould bear him.  Next, from whence before he came,\nI saw the eagle dart into the hull\nO\' th\' car, and leave it with his feathers lin\'d;\nAnd then a voice, like that which issues forth\nFrom heart with sorrow riv\'d, did issue forth\nFrom heav\'n, and, \"O poor bark of mine!\" it cried,\n\"How badly art thou freighted!\"  Then, it seem\'d,\nThat the earth open\'d between either wheel,\nAnd I beheld a dragon issue thence,\nThat through the chariot fix\'d his forked train;\nAnd like a wasp that draggeth back the sting,\nSo drawing forth his bale");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITEINA\\THERe");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 94: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST94(void)
{
    // informacje o teście
    test_start(94, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[6515] = "";

                strcat(expected_filecontent, "f\nWithin its tabernacle, and left dark\nThe Spaniard and the Indian, with the Jew.\nSuch fables Florence in her pulpit hears,\nBandied about more frequent, than the names\nOf Bindi and of Lapi in her streets.\nThe sheep, meanwhile, poor witless ones, return\nFrom pasture, fed with wind: and what avails\nFor their excuse, they do not see their harm?\nChrist said not to his first conventicle,\n\'Go forth and preach impostures to the world,\'\nBut gave them truth to build on; and the sound\nWas mighty on their lips; nor needed they,\nBeside the gospel, other spear or shield,\nTo aid them in their warfare for the faith.\nThe preacher now provides himself with store\nOf jests and gibes; and, so there be no lack\nOf laughter, while he vents them, his big cowl\nDistends, and he has won the meed he sought:\nCould but the vulgar catch a glimpse the while\nOf that dark bird which nestles in his hood,\nThey scarce would wait to hear the blessing said.\nWhich now the dotards hold in such esteem,\nThat every counterfeit, who spreads abroad\nThe hands of holy promise, finds a throng\nOf credulous fools beneath.  Saint Anthony\nFattens with this his swine, and others worse\nThan swine, who diet at his lazy board,\nPaying with unstamp\'d metal for their fare.\n     \"But (for we far have wander\'d) let us seek\nThe forward path again; so as the way\nBe shorten\'d with the time.  No mortal tongue\nNor thought of man hath ever reach\'d so far,\nThat of these natures he might count the tribes.\nWhat Daniel of their thousands hath reveal\'d\nWith finite number infinite conceals.\nThe fountain at whose source these drink their beams,\nWith light supplies them in as many modes,\nAs there are splendours, that it shines on: each\nAccording to the virtue it conceives,\nDiffering in love and sweet affection.\nLook then how lofty and how huge in breadth\nThe\' eternal might, which, broken and dispers\'d\nOver such countless mirrors, yet remains\nWhole in itself and one, as at the first.\"\n\n\n\nCANTO XXX\n\nNoon\'s fervid hour perchance six thousand miles\nFrom hence is distant; and the shadowy cone\nAlmost to level on our earth declines;\nWhen from the midmost of this blue abyss\nBy turns some star is to our vision lost.\nAnd straightway as the handmaid of the sun\nPuts forth her radiant brow, all, light by light,\nFade, and the spangled firmament shuts in,\nE\'en to the loveliest of the glittering throng.\nThus vanish\'d gradually from my sight\nThe triumph, which plays ever round the point,\nThat overcame me, seeming (for it did)\nEngirt by that it girdeth.  Wherefore love,\nWith loss of other object, forc\'d me bend\nMine eyes on Beatrice once again.\n     If all, that hitherto is told of her,\nWere in one praise concluded, \'t were too weak\nTo furnish out this turn.  Mine eyes did look\nOn beauty, such, as I believe in sooth,\nNot merely to exceed our human, but,\nThat save its Maker, none can to the full\nEnjoy it.  At this point o\'erpower\'d I fail,\nUnequal to my theme, as never bard\nOf buskin or of sock hath fail\'d before.\nFor, as the sun doth to the feeblest sight,\nE\'en so remembrance of that witching smile\nHath dispossess my spirit of itself.\nNot from that day, when on this earth I first\nBeheld her charms, up to that view of them,\nHave I with song applausive ever ceas\'d\nTo follow, but not follow them no more;\nMy course here bounded, as each artist\'s is,\nWhen it doth touch the limit of his skill.\n     She (such as I bequeath her to the bruit\nOf louder trump than mine, which hasteneth on,\nUrging its arduous matter to the close),\nHer words resum\'d, in gesture and in voice\nResembling one accustom\'d to command:\n\"Forth from the last corporeal are we come\nInto the heav\'n, that is unbodied light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradise; and one in that array,\nWhich in the final judgment thou shalt see.\"\n     As when the lightning, in a sudden spleen\nUnfolded, dashes from the blinding eyes\nThe visive spirits dazzled and bedimm\'d;\nSo, round about me, fulminating streams\nOf living radiance pl");
    strcat(expected_filecontent, "ay\'d, and left me swath\'d\nAnd veil\'d in dense impenetrable blaze.\nSuch weal is in the love, that stills this heav\'n;\nFor its own flame the torch this fitting ever!\n     No sooner to my list\'ning ear had come\nThe brief assurance, than I understood\nNew virtue into me infus\'d, and sight\nKindled afresh, with vigour to sustain\nExcess of light, however pure.  I look\'d;\nAnd in the likeness of a river saw\nLight flowing, from whose amber-seeming waves\nFlash\'d up effulgence, as they glided on\n\'Twixt banks, on either side, painted with spring,\nIncredible how fair; and, from the tide,\nThere ever and anon, outstarting, flew\nSparkles instinct with life; and in the flow\'rs\nDid set them, like to rubies chas\'d in gold;\nThen, as if drunk with odors, plung\'d again\nInto the wondrous flood; from which, as one\nRe\'enter\'d, still another rose.  \"The thirst\nOf knowledge high, whereby thou art inflam\'d,\nTo search the meaning of what here thou seest,\nThe more it warms thee, pleases me the more.\nBut first behooves thee of this water drink,\nOr ere that longing be allay\'d.\"  So spake\nThe day-star of mine eyes; then thus subjoin\'d:\n\"This stream, and these, forth issuing from its gulf,\nAnd diving back, a living topaz each,\nWith all this laughter on its bloomy shores,\nAre but a preface, shadowy of the truth\nThey emblem: not that, in themselves, the things\nAre crude; but on thy part is the defect,\nFor that thy views not yet aspire so high.\"\nNever did babe, that had outslept his wont,\nRush, with such eager straining, to the milk,\nAs I toward the water, bending me,\nTo make the better mirrors of mine eyes\nIn the refining wave; and, as the eaves\nOf mine eyelids did drink of it, forthwith\nSeem\'d it unto me turn\'d from length to round,\nThen as a troop of maskers, when they put\nTheir vizors off, look other than before,\nThe counterfeited semblance thrown aside;\nSo into greater jubilee were chang\'d\nThose flowers and sparkles, and distinct I saw\nBefore me either court of heav\'n displac\'d.\n     O prime enlightener!  thou who crav\'st me strength\nOn the high triumph of thy realm to gaze!\nGrant virtue now to utter what I kenn\'d,\n    There is in heav\'n a light, whose goodly shine\nMakes the Creator visible to all\nCreated, that in seeing him alone\nHave peace; and in a circle spreads so far,\nThat the circumference were too loose a zone\nTo girdle in the sun.  All is one beam,\nReflected from the summit of the first,\nThat moves, w");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WrITEiNA\\BeTWEEn.tXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 6514; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 95: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST95(void)
{
    // informacje o teście
    test_start(95, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7255] = "";

                strcat(expected_filecontent, "Fano,\nwere invited by Malatestino da Rimini to an entertainment on\npretence that he had some important business to transact with\nthem:  and, according to instructions given by him, they mere\ndrowned in their passage near Catolica, between Rimini and Fano.\n\nv. 85.  Focara\'s wind.] Focara is a mountain, from which a wind\nblows that is peculiarly dangerous to the navigators of that\ncoast.\n\nv. 94.  The doubt in Caesar\'s mind.]  Curio, whose speech\n(according to Lucan) determined Julius Caesar to proceed when he\nhad arrived at Rimini (the ancient Ariminum), and doubted whether\nhe should prosecute the civil war.\n        Tolle moras:  semper nocuit differre paratis\n               Pharsal, l. i. 281.\n\nv. 102.  Mosca.]  Buondelmonte was engaged to marry a lady of the\nAmidei family, but broke his promise and united himself to one of\nthe Donati.  This was so much resented by the former, that a\nmeeting of themselves and their kinsmen was held, to consider of\nthe best means of revenging the insult.  Mosca degli Uberti\npersuaded them to resolve on the assassination of Buondelmonte,\nexclaiming to them  \"the thing once done, there is an end.\"  The\ncounsel and its effects were the source of many terrible\ncalamities to the state of Florence.  \"This murder,\" says G.\nVillani, l. v. c. 38,  \"was the cause and beginning of the\naccursed Guelph and Ghibelline parties in Florence.\"  It happened\nin 1215.  See the Paradise, Canto XVI. 139.\n\nv. 111.  The boon companion.]\n        What stronger breastplate than a heart untainted?\nShakespeare, 2 Hen. VI. a. iii. s. 2.\n\nv. 160.  Bertrand.]  Bertrand de Born, Vicomte de Hautefort, near\nPerigueux in Guienne, who incited John to rebel against his\nfather, Henry II. of England.  Bertrand holds a distinguished\nplace among the Provencal poets.  He is quoted in Dante, \"De\nVulg. Eloq.\" l. ii. c. 2.  For the translation of some extracts\nfrom his poems, see Millot, Hist. Litteraire des Troubadors t. i.\np. 210; but the historical parts of that work are, I believe, not\nto be relied on.\n\nCANTO XXIX.\n\nv. 26.  Geri of Bello.]  A kinsman of the Poet\'s, who was\nmurdered by one of the Sacchetti family.  His being placed here,\nmay be considered as a proof that Dante was more impartial in the\nallotment of his punishments than has generally been supposed.\n\nv. 44.  As were the torment.]  It is very probable that these\nlines gave Milton the idea of his celebrated description:\n               Immediately a place\n        Before their eyes appear\'d, sad, noisome, dark,\n        A lasar-house it seem\'d, wherein were laid\n        Numbers of all diseas\'d, all maladies, &c.\n               P. L. b. xi. 477.\n\nv. 45.  Valdichiana.]  The valley through which passes the river\nChiana, bounded by Arezzo, Cortona, Montepulciano, and Chiusi. In\nthe heat of autumn it was formerly rendered unwholesome by the\nstagnation of the water, but has since been drained by the\nEmperor Leopold II.  The Chiana is mentioned as a remarkably\nsluggish stream, in the Paradise, Canto XIII. 21.\n\nv. 47.  Maremma\'s pestilent fen.]  See Note to Canto XXV. v. 18.\n\nv. 58.  In Aegina.] He alludes to the fable of the ants changed\ninto Myrmidons. Ovid, Met. 1. vii.\n\nv. 104.  Arezzo was my dwelling.]  Grifolino of Arezzo, who\npromised Albero, son of the Bishop of Sienna, that he would teach\nhim the art of flying; and because be did not keep his promise,\nAlbero prevailed on his father to have him burnt for a\nnecromancer.\n\nv. 117.\n               Was ever race\n        Light as Sienna\'s?]\nThe same imputation is again cast on the Siennese, Purg. Canto\nXIII. 141.\n\nv. 121.  Stricca.] This is said ironically.  Stricca, Niccolo\nSalimbeni, Caccia of Asciano, and Abbagliato, or Meo de\nFolcacchieri, belonged to a company of prodigal and luxurious\nyoung men in Sienna, called the \"brigata godereccia.\"  Niccolo\nwas the inventor of a new manner of using cloves in cookery, not\nvery well understood by the commentators, and which was termed\nthe  \"costuma ricca.\"\n\nv. 125.  In that garden.]  Sienna.\n\nv. 134.  Cappocchio\'s ghost.] Capocchio of Sienna, who is said to\nhave been a fellow-student o");
    strcat(expected_filecontent, "f Dante\'s in natural philosophy.\n\nCANTO XXX.\n\nv. 4.  Athamas.]  From Ovid, Metam. 1. iv.\n        Protinos Aelides, &c.\n\nv. 16.  Hecuba. See Euripedes, Hecuba; and Ovid, Metnm. l. xiii.\n\nv. 33.  Schicchi.]  Gianni Schicci, who was of the family of\nCavalcanti, possessed such a faculty of moulding his features to\nthe resemblance of others, that he was employed by Simon Donati\nto personate Buoso Donati, then recently deceased, and to make a\nwill, leaving Simon his heir; for which service he was\nrenumerated with a mare of extraordinary value, here called \"the\nlady of the herd.\"\n\nv. 39.  Myrrha.] See Ovid, Metam. l. x.\n\nv. 60. Adamo\'s woe.]  Adamo of Breschia, at the instigation of\nCuido Alessandro, and their brother Aghinulfo, lords of Romena,\ncoonterfeited the coin of Florence; for which crime he was burnt.\nLandino says, that in his time the peasants still pointed out a\npile of stones near Romena as the place of his execution.\n\nv. 64.  Casentino.] Romena is a part of Casentino.\n\nv. 77.  Branda\'s limpid spring.]  A fountain in Sienna.\n\nv. 88.  The florens with three carats of alloy.]  The floren was\na coin that ought to have had tmenty-four carats of pure gold.\nVillani relates, that it was first used at Florence in 1253, an\naera of great prosperity in the annals of the republic; before\nwhich time their most valuable coinage was of silver.  Hist. l.\nvi. c. 54.\n\nv. 98.  The false accuser.]  Potiphar\'s wife.\n\nCANTO XXXI.\n\nv. 1.  The very tongue.]\n        Vulnus in Herculeo quae quondam fecerat hoste\n        Vulneris auxilium Pellas hasta fuit.\n               Ovid, Rem. Amor. 47.\nThe same allusion was made by Bernard de Ventadour, a Provencal\npoet in the middle of the twelfth century: and Millot observes,\nthat it was a singular instance of erudition in a Troubadour.\nBut it is not impossible, as Warton remarks, (Hist. of Engl.\nPoetry, vol. ii. sec. x. p 215.) but that he might have been\nindebted for it to some of the early romances.\n\nIn Chaucer\'s Squier\'s Tale, a sword of similar quality is\nintroduced:\n        And other folk have wondred on the sweard,\n        That could so piercen through every thing;\n        And fell in speech of Telephus the king,\n        And of Achillcs for his queint spere,\n        For he couth with it both heale and dere.\nSo Shakspeare, Henry VI. p. ii. a. 5. s. 1.\n        Whose smile and frown like to Achilles\' spear\n        Is able with the change to kill and cure.\n\nv. 14. Orlando.l\n        When Charlemain with all his peerage fell\n               At Fontarabia\n               Milton, P. L. b. i. 586.\nSee Warton\'s Hist. of Eng. Poetrg, v. i. sect. iii. p. 132.\n\"This is the horn which Orlando won from the giant Jatmund, and\nwhich as Turpin and the Islandic bards report, was endued with\nmagical power, and might be heard at the distance of twenty\nmiles.\"  Charlemain and Orlando are introduced in the Paradise,\nCanto XVIII.\n\nv. 36.  Montereggnon.] A castle near Sienna.\n\nv. 105.  The fortunate vale.] The country near Carthage.  See\nLiv. Hist. l. xxx. and Lucan, Phars. l. iv. 590. Dante has kept\nthe latter of these writers in his eye throughout all this\npassage.\n\nv. 123.  Alcides.]  The combat be");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITeINa\\quaRT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7254; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 96: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST96(void)
{
    // informacje o teście
    test_start(96, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[547] = "";

                strcat(expected_filecontent, "\nWho, wander\'d from his track, thinks every step\nTrodden in vain till he regain the path.\n     When we had come, where yet the tender dew\nStrove with the sun, and in a place, where fresh\nThe wind breath\'d o\'er it, while it slowly dried;\nBoth hands extended on the watery grass\nMy master plac\'d, in graceful act and kind.\nWhence I of his intent before appriz\'d,\nStretch\'d out to him my cheeks suffus\'d with tears.\nThere to my visage he anew restor\'d\nThat hue, which the dun shades of hell conceal\'d.\n     Then on the solitary shore arriv\'d,\nThat n");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRitEINA\\SuDDEn");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 546; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 97: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST97(void)
{
    // informacje o teście
    test_start(97, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[3073] = "";

                strcat(expected_filecontent, " ye up\nUnto the summit of the scale, in time\nRemember ye my suff\'rings.\"  With such words\nHe disappear\'d in the refining flame.\n\n\n\nCANTO XXVII\n\nNow was the sun so station\'d, as when first\nHis early radiance quivers on the heights,\nWhere stream\'d his Maker\'s blood, while Libra hangs\nAbove Hesperian Ebro, and new fires\nMeridian flash on Ganges\' yellow tide.\n     So day was sinking, when the\' angel of God\nAppear\'d before us.  Joy was in his mien.\nForth of the flame he stood upon the brink,\nAnd with a voice, whose lively clearness far\nSurpass\'d our human, \"Blessed are the pure\nIn heart,\" he Sang:  then near him as we came,\n\"Go ye not further, holy spirits!\"  he cried,\n\"Ere the fire pierce you: enter in; and list\nAttentive to the song ye hear from thence.\"\n     I, when I heard his saying, was as one\nLaid in the grave.  My hands together clasp\'d,\nAnd upward stretching, on the fire I look\'d,\nAnd busy fancy conjur\'d up the forms\nErewhile beheld alive consum\'d in flames.\n     Th\' escorting spirits turn\'d with gentle looks\nToward me, and the Mantuan spake:  \"My son,\nHere torment thou mayst feel, but canst not death.\nRemember thee, remember thee, if I\nSafe e\'en on Geryon brought thee: now I come\nMore near to God, wilt thou not trust me now?\nOf this be sure: though in its womb that flame\nA thousand years contain\'d thee, from thy head\nNo hair should perish.  If thou doubt my truth,\nApproach, and with thy hands thy vesture\'s hem\nStretch forth, and for thyself confirm belief.\nLay now all fear, O lay all fear aside.\nTurn hither, and come onward undismay\'d.\"\nI still, though conscience urg\'d\' no step advanc\'d.\n     When still he saw me fix\'d and obstinate,\nSomewhat disturb\'d he cried:  \"Mark now, my son,\nFrom Beatrice thou art by this wall\nDivided.\"  As at Thisbe\'s name the eye\nOf Pyramus was open\'d (when life ebb\'d\nFast from his veins), and took one parting glance,\nWhile vermeil dyed the mulberry; thus I turn\'d\nTo my sage guide, relenting, when I heard\nThe name, that springs forever in my breast.\n     He shook his forehead; and, \"How long,\" he said,\n\"Linger we now?\"  then smil\'d, as one would smile\nUpon a child, that eyes the fruit and yields.\nInto the fire before me then he walk\'d;\nAnd Statius, who erewhile no little space\nHad parted us, he pray\'d to come behind.\n     I would have cast me into molten glass\nTo cool me, when I enter\'d; so intense\nRag\'d the conflagrant mass.  The sire belov\'d,\nTo comfort me, as he proceeded, still\nOf Beatrice talk\'d.  \"Her eyes,\" saith he,\n\"E\'en now I seem to view.\"  From the other side\nA voice, that sang, did guide us, and the voice\nFollowing, with heedful ear, we issued forth,\nThere where the path led upward.  \"Come,\" we heard,\n\"Come, blessed of my Father.\"  Such the sounds,\nThat hail\'d us from within a light, which shone\nSo radiant, I could not endure the view.\n\"The sun,\" it added, \"hastes: and evening comes.\nDelay not: ere the western sky is hung\nWith blackness, strive ye for the pass.\"  Our way\nUpright within the rock arose, and fac\'d\nSuch part of heav\'n, that from before my steps\nThe beams were s");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEiNA\\riCH.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 3072; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 98: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST98(void)
{
    // informacje o teście
    test_start(98, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[5352] = "";

                strcat(expected_filecontent, "ed more,\nAnd said:  \"Already satisfied, I rest\nFrom admiration deep, but now admire\nHow I above those lighter bodies rise.\"\n     Whence, after utt\'rance of a piteous sigh,\nShe tow\'rds me bent her eyes, with such a look,\nAs on her frenzied child a mother casts;\nThen thus began:  \"Among themselves all things\nHave order; and from hence the form, which makes\nThe universe resemble God.  In this\nThe higher creatures see the printed steps\nOf that eternal worth, which is the end\nWhither the line is drawn.  All natures lean,\nIn this their order, diversely, some more,\nSome less approaching to their primal source.\nThus they to different havens are mov\'d on\nThrough the vast sea of being, and each one\nWith instinct giv\'n, that bears it in its course;\nThis to the lunar sphere directs the fire,\nThis prompts the hearts of mortal animals,\nThis the brute earth together knits, and binds.\nNor only creatures, void of intellect,\nAre aim\'d at by this bow; hut even those,\nThat have intelligence and love, are pierc\'d.\nThat Providence, who so well orders all,\nWith her own light makes ever calm the heaven,\nIn which the substance, that hath greatest speed,\nIs turn\'d: and thither now, as to our seat\nPredestin\'d, we are carried by the force\nOf that strong cord, that never looses dart,\nBut at fair aim and glad.  Yet is it true,\nThat as ofttimes but ill accords the form\nTo the design of art, through sluggishness\nOf unreplying matter, so this course\nIs sometimes quitted by the creature, who\nHath power, directed thus, to bend elsewhere;\nAs from a cloud the fire is seen to fall,\nFrom its original impulse warp\'d, to earth,\nBy vicious fondness.  Thou no more admire\nThy soaring, (if I rightly deem,) than lapse\nOf torrent downwards from a mountain\'s height.\nThere would in thee for wonder be more cause,\nIf, free of hind\'rance, thou hadst fix\'d thyself\nBelow, like fire unmoving on the earth.\"\n     So said, she turn\'d toward the heav\'n her face.\n\n\n\nCANTO II\n\nAll ye, who in small bark have following sail\'d,\nEager to listen, on the advent\'rous track\nOf my proud keel, that singing cuts its way,\nBackward return with speed, and your own shores\nRevisit, nor put out to open sea,\nWhere losing me, perchance ye may remain\nBewilder\'d in deep maze.  The way I pass\nNe\'er yet was run: Minerva breathes the gale,\nApollo guides me, and another Nine\nTo my rapt sight the arctic beams reveal.\nYe other few, who have outstretch\'d the neck.\nTimely for food of angels, on which here\nThey live, yet never know satiety,\nThrough the deep brine ye fearless may put out\nYour vessel, marking, well the furrow broad\nBefore you in the wave, that on both sides\nEqual returns.  Those, glorious, who pass\'d o\'er\nTo Colchos, wonder\'d not as ye will do,\nWhen they saw Jason following the plough.\n     The increate perpetual thirst, that draws\nToward the realm of God\'s own form, bore us\nSwift almost as the heaven ye behold.\n     Beatrice upward gaz\'d, and I on her,\nAnd in such space as on the notch a dart\nIs plac\'d, then loosen\'d flies, I saw myself\nArriv\'d, where wond\'rous thing engag\'d my sight.\nWhence she, to whom no work of mine was hid,\nTurning to me, with aspect glad as fair,\nBespake me: \"Gratefully direct thy mind\nTo God, through whom to this first star we come.\"\n     Me seem\'d as if a cloud had cover\'d us,\nTranslucent, solid, firm, and polish\'d bright,\nLike adamant, which the sun\'s beam had smit\nWithin itself the ever-during pearl\nReceiv\'d us, as the wave a ray of light\nReceives, and rests unbroken.  If I then\nWas of corporeal frame, and it transcend\nOur weaker thought, how one dimension thus\nAnother could endure, which needs must be\nIf body enter body, how much more\nMust the desire inflame us to behold\nThat essence, which discovers by what means\nGod and our nature join\'d!  There will be seen\nThat which we hold through faith, not shown by proof,\nBut in itself intelligibly plain,\nE\'en as the truth that man at first believes.\n     I answered:  \"Lady!  I with thoughts devout,\nSuch as I best can frame, give thanks to Him,\nWho hath remov\'d me from the mortal world.\nBut tell, I pray thee, whence the gloo");
    strcat(expected_filecontent, "my spots\nUpon this body, which below on earth\nGive rise to talk of Cain in fabling quaint?\"\n     She somewhat smil\'d, then spake:  \"If mortals err\nIn their opinion, when the key of sense\nUnlocks not, surely wonder\'s weapon keen\nOught not to pierce thee; since thou find\'st, the wings\nOf reason to pursue the senses\' flight\nAre short.  But what thy own thought is, declare.\"\n     Then I:  \"What various here above appears,\nIs caus\'d, I deem, by bodies dense or rare.\"\n     She then resum\'d:  \"Thou certainly wilt see\nIn falsehood thy belief o\'erwhelm\'d, if well\nThou listen to the arguments, which I\nShall bring to face it.  The eighth sphere displays\nNumberless lights, the which in kind and size\nMay be remark\'d of different aspects;\nIf rare or dense of that were cause alone,\nOne single virtue then would be in all,\nAlike distributed, or more, or less.\nDifferent virtues needs must be the fruits\nOf formal principles, and these, save one,\nWill by thy reasoning be destroy\'d.  Beside,\nIf rarity were of that dusk the cause,\nWhich thou inquirest, either in some part\nThat planet must throughout be void, nor fed\nWith its own matter; or, as bodies share\nTheir fat and leanness, in like manner this\nMust in its volume change the leaves.  The first,\nIf it wer");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRITEINA\\bACk.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 5351; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 99: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST99(void)
{
    // informacje o teście
    test_start(99, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[320] = "";

                strcat(expected_filecontent, "of Charlemain, mentioned by\nArchbishop Turpin.  He is a common instance of treachery with the\npoets of the middle ages.\n        Trop son fol e mal pensant,\n        Pis valent que Guenelon.\n               Thibaut, roi de Navarre\n        O new Scariot, and new Ganilion,\n        O false dissembler, &c.\n               Cha");

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "\\WRiTeINA\\CHArgE.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 319; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 100: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST100(void)
{
    // informacje o teście
    test_start(100, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(7813, 1);
            char expected_filecontent[7814] = "";

            strcat(expected_filecontent, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "tHeN.bIn");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 390; ++i)
            {
                int res = file_read(filecontent + 20 * i, 20, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 20 * i, 20, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7813);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 7813);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 101: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST101(void)
{
    // informacje o teście
    test_start(101, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(4248, 1);
    char *filecontent1 = (char *)calloc(4098, 1);
    char *filecontent2 = (char *)calloc(674, 1);
    char *filecontent3 = (char *)calloc(7813, 1);
    char *filecontent4 = (char *)calloc(6333, 1);
    char *filecontent5 = (char *)calloc(6144, 1);
    char *filecontent6 = (char *)calloc(537, 1);

            char expected_filecontent0[4249] = "";
    char expected_filecontent1[4099] = "";
    char expected_filecontent2[675] = "";
    char expected_filecontent3[7814] = "";
    char expected_filecontent4[6334] = "";
    char expected_filecontent5[6145] = "";
    char expected_filecontent6[538] = "";

            strcat(expected_filecontent0, "s needed help\nOf vision to interpret.  As when breaks\nIn act to be discharg\'d, a cross-bow bent\nBeyond its pitch, both nerve and bow o\'erstretch\'d,\nThe flagging weapon feebly hits the mark;\nThus, tears and sighs forth gushing, did I burst\nBeneath the heavy load, and thus my voice\nWas slacken\'d on its way.  She straight began:\n\"When my desire invited thee to love\nThe good, which sets a bound to our aspirings,\nWhat bar of thwarting foss or linked chain\nDid meet thee, that thou so should\'st quit the hope\nOf further progress, or what bait of ease\nOr promise of allurement led thee on\nElsewhere, that thou elsewhere should\'st rather wait?\"\n     A bitter sigh I drew, then scarce found voice\nTo answer, hardly to these sounds my lips\nGave utterance, wailing:  \"Thy fair looks withdrawn,\nThings present, with deceitful pleasures, turn\'d\nMy steps aside.\"  She answering spake:  \"Hadst thou\nBeen silent, or denied what thou avow\'st,\nThou hadst not hid thy sin the more: such eye\nObserves it.  But whene\'er the sinner\'s cheek\nBreaks forth into the precious-streaming tears\nOf self-accusing, in our court the wheel\nOf justice doth run counter to the edge.\nHowe\'er that thou may\'st profit by thy shame\nFor errors past, and that henceforth more strength\nMay arm thee, when thou hear\'st the Siren-voice,\nLay thou aside the motive to this grief,\nAnd lend attentive ear, while I unfold\nHow opposite a way my buried flesh\nShould have impell\'d thee.  Never didst thou spy\nIn art or nature aught so passing sweet,\nAs were the limbs, that in their beauteous frame\nEnclos\'d me, and are scatter\'d now in dust.\nIf sweetest thing thus fail\'d thee with my death,\nWhat, afterward, of mortal should thy wish\nHave tempted?  When thou first hadst felt the dart\nOf perishable things, in my departing\nFor better realms, thy wing thou should\'st have prun\'d\nTo follow me, and never stoop\'d again\nTo \'bide a second blow for a slight girl,\nOr other gaud as transient and as vain.\nThe new and inexperienc\'d bird awaits,\nTwice it may be, or thrice, the fowler\'s aim;\nBut in the sight of one, whose plumes are full,\nIn vain the net is spread, the arrow wing\'d.\"\n     I stood, as children silent and asham\'d\nStand, list\'ning, with their eyes upon the earth,\nAcknowledging their fault and self-condemn\'d.\nAnd she resum\'d:  \"If, but to hear thus pains thee,\nRaise thou thy beard, and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in ");
    strcat(expected_filecontent0, "the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light");strcat(expected_filecontent1, " solid darkness stain\'d,\nLike to the sand that in the whirlwind flies.\n     I then, with error yet encompass\'d, cried:\n\"O master!  What is this I hear?  What race\nAre these, who seem so overcome with woe?\"\n     He thus to me: \"This miserable fate\nSuffer the wretched souls of those, who liv\'d\nWithout or praise or blame, with that ill band\nOf angels mix\'d, who nor rebellious prov\'d\nNor yet were true to God, but for themselves\nWere only.  From his bounds Heaven drove them forth,\nNot to impair his lustre, nor the depth\nOf Hell receives them, lest th\' accursed tribe\nShould glory thence with exultation vain.\"\n     I then: \"Master!  what doth aggrieve them thus,\nThat they lament so loud?\"  He straight replied:\n\"That will I tell thee briefly.  These of death\nNo hope may entertain: and their blind life\nSo meanly passes, that all other lots\nThey envy.  Fame of them the world hath none,\nNor suffers; mercy and justice scorn them both.\nSpeak not of them, but look, and pass them by.\"\n     And I, who straightway look\'d, beheld a flag,\nWhich whirling ran around so rapidly,\nThat it no pause obtain\'d: and following came\nSuch a long train of spirits, I should ne\'er\nHave thought, that death so many had despoil\'d.\n     When some of these I recogniz\'d, I saw\nAnd knew the shade of him, who to base fear\nYielding, abjur\'d his high estate.  Forthwith\nI understood for certain this the tribe\nOf those ill spirits both to God displeasing\nAnd to his foes.  These wretches, who ne\'er lived,\nWent on in nakedness, and sorely stung\nBy wasps and hornets, which bedew\'d their cheeks\nWith blood, that mix\'d with tears dropp\'d to their feet,\nAnd by disgustful worms was gather\'d there.\n     Then looking farther onwards I beheld\nA throng upon the shore of a great stream:\nWhereat I thus: \"Sir!  grant me now to know\nWhom here we view, and whence impell\'d they seem\nSo eager to pass o\'er, as I discern\nThrough the blear light?\"  He thus to me in few:\n\"This shalt thou know, soon as our steps arrive\nBeside the woeful tide of Acheron.\"\n     Then with eyes downward cast and fill\'d with shame,\nFearing my words offensive to his ear,\nTill we had reach\'d the river, I from speech\nAbstain\'d.  And lo!  toward us in a bark\nComes on an old man hoary white with eld,\nCrying, \"Woe to you wicked spirits!  hope not\nEver to see the sky again.  I come\nTo take you to the other shore across,\nInto eternal darkness, there to dwell\nIn fierce heat and in ice.  And thou, who there\nStandest, live spirit!  get thee hence, and leave\nThese who are dead.\"  But soon as he beheld\nI left them not, \"By other way,\" said he,\n\"By other haven shalt thou come to shore,\nNot by this passage; thee a nimbler boat\nMust carry.\"  Then to him thus spake my guide:\n\"Charon!  thyself torment not: so \'t is will\'d,\nWhere will and power are one: ask thou no more.\"\n     Straightway in silence fell the shaggy cheeks\nOf him the boatman o\'er the livid lake,\nAround whose eyes glar\'d wheeling flames.  Meanwhile\nThose spirits, faint and naked, color chang\'d,\nAnd gnash\'d their teeth, soon as the cruel words\nThey heard.  God and their parents they blasphem\'d,\nThe human kind, the place, the time, and seed\nThat did engender them and give them birth.\n     Then all together sorely wailing drew\nTo the curs\'d strand, that every man must pass\nWho fears not God.  Charon, demoniac form,\nWith eyes of burning coal, collects them all,\nBeck\'ning, and each, that lingers, with his oar\nStrikes.  As fall off the light autumnal leaves,\nOne still another following, till the bough\nStrews all its honours on the earth beneath;\nE\'en in like manner Adam\'s evil brood\nCast themselves one by one down from the shore,\nEach at a beck, as falcon at his call.\n     Thus go they over through the umber\'d wave,\nAnd ever they on the opposing bank\nBe landed, on this side another throng\nStill gathers.  \"Son,\" thus spake the courteous guide,\n\"Those, who die subject to the wrath of God,\nAll here together come from every clime,\nAnd to o\'erpass the river are not loth:\nFor so heaven\'s justice goads them on, that fear\nIs turn\'d into desire.  Hence ne\'er hath past\nGood spirit");
    strcat(expected_filecontent1, ".  ");strcat(expected_filecontent2, "Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should hard-favour\'d grief be lodg\'");strcat(expected_filecontent3, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent3, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");strcat(expected_filecontent4, "o my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few words I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld");
    strcat(expected_filecontent4, ".  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their w");strcat(expected_filecontent5, "m in their warfare for the faith.\nThe preacher now provides himself with store\nOf jests and gibes; and, so there be no lack\nOf laughter, while he vents them, his big cowl\nDistends, and he has won the meed he sought:\nCould but the vulgar catch a glimpse the while\nOf that dark bird which nestles in his hood,\nThey scarce would wait to hear the blessing said.\nWhich now the dotards hold in such esteem,\nThat every counterfeit, who spreads abroad\nThe hands of holy promise, finds a throng\nOf credulous fools beneath.  Saint Anthony\nFattens with this his swine, and others worse\nThan swine, who diet at his lazy board,\nPaying with unstamp\'d metal for their fare.\n     \"But (for we far have wander\'d) let us seek\nThe forward path again; so as the way\nBe shorten\'d with the time.  No mortal tongue\nNor thought of man hath ever reach\'d so far,\nThat of these natures he might count the tribes.\nWhat Daniel of their thousands hath reveal\'d\nWith finite number infinite conceals.\nThe fountain at whose source these drink their beams,\nWith light supplies them in as many modes,\nAs there are splendours, that it shines on: each\nAccording to the virtue it conceives,\nDiffering in love and sweet affection.\nLook then how lofty and how huge in breadth\nThe\' eternal might, which, broken and dispers\'d\nOver such countless mirrors, yet remains\nWhole in itself and one, as at the first.\"\n\n\n\nCANTO XXX\n\nNoon\'s fervid hour perchance six thousand miles\nFrom hence is distant; and the shadowy cone\nAlmost to level on our earth declines;\nWhen from the midmost of this blue abyss\nBy turns some star is to our vision lost.\nAnd straightway as the handmaid of the sun\nPuts forth her radiant brow, all, light by light,\nFade, and the spangled firmament shuts in,\nE\'en to the loveliest of the glittering throng.\nThus vanish\'d gradually from my sight\nThe triumph, which plays ever round the point,\nThat overcame me, seeming (for it did)\nEngirt by that it girdeth.  Wherefore love,\nWith loss of other object, forc\'d me bend\nMine eyes on Beatrice once again.\n     If all, that hitherto is told of her,\nWere in one praise concluded, \'t were too weak\nTo furnish out this turn.  Mine eyes did look\nOn beauty, such, as I believe in sooth,\nNot merely to exceed our human, but,\nThat save its Maker, none can to the full\nEnjoy it.  At this point o\'erpower\'d I fail,\nUnequal to my theme, as never bard\nOf buskin or of sock hath fail\'d before.\nFor, as the sun doth to the feeblest sight,\nE\'en so remembrance of that witching smile\nHath dispossess my spirit of itself.\nNot from that day, when on this earth I first\nBeheld her charms, up to that view of them,\nHave I with song applausive ever ceas\'d\nTo follow, but not follow them no more;\nMy course here bounded, as each artist\'s is,\nWhen it doth touch the limit of his skill.\n     She (such as I bequeath her to the bruit\nOf louder trump than mine, which hasteneth on,\nUrging its arduous matter to the close),\nHer words resum\'d, in gesture and in voice\nResembling one accustom\'d to command:\n\"Forth from the last corporeal are we come\nInto the heav\'n, that is unbodied light,\nLight intellectual replete with love,\nLove of true happiness replete with joy,\nJoy, that transcends all sweetness of delight.\nHere shalt thou look on either mighty host\nOf Paradise; and one in that array,\nWhich in the final judgment thou shalt see.\"\n     As when the lightning, in a sudden spleen\nUnfolded, dashes from the blinding eyes\nThe visive spirits dazzled and bedimm\'d;\nSo, round about me, fulminating streams\nOf living radiance play\'d, and left me swath\'d\nAnd veil\'d in dense impenetrable blaze.\nSuch weal is in the love, that stills this heav\'n;\nFor its own flame the torch this fitting ever!\n     No sooner to my list\'ning ear had come\nThe brief assurance, than I understood\nNew virtue into me infus\'d, and sight\nKindled afresh, with vigour to sustain\nExcess of light, however pure.  I look\'d;\nAnd in the likeness of a river saw\nLight flowing, from whose amber-seeming waves\nFlash\'d up effulgence, as they glided on\n\'Twixt banks, on either side, painted with spring,\nIncredible how fair; and, from the t");
    strcat(expected_filecontent5, "ide,\nThere ever and anon, outstarting, flew\nSparkles instinct with life; and in the flow\'rs\nDid set them, like to rubies chas\'d in gold;\nThen, as if drunk with odors, plung\'d again\nInto the wondrous flood; from which, as one\nRe\'enter\'d, still another rose.  \"The thirst\nOf knowledge high, whereby thou art inflam\'d,\nTo search the meaning of what here thou seest,\nThe more it warms thee, pleases me the more.\nBut first behooves thee of this water drink,\nOr ere that longing be allay\'d.\"  So spake\nThe day-star of mine eyes; then thus subjoin\'d:\n\"This stream, and these, forth issuing from its gulf,\nAnd diving back, a living topaz each,\nWith all this laughter on its bloomy shores,\nAre but a preface, shadowy of the truth\nThey emblem: not that, in themselves, the things\nAre crude; but on thy part is the defect,\nFor that thy views not yet aspire so high.\"\nNever did babe, that had outslept his wont,\nRush, with such eager straining, to the milk,\nAs I toward the water, bending me,\nTo make the better mirrors of mine eyes\nIn the refining wave; and, as the eaves\nOf mine eyelids did drink of it, forthwith\nSeem\'d it unto me turn\'d from length to round,\nThen as a troop of maskers, when they put\nTheir vizors off, look other than before,\nThe counterfeited semblance thrown aside;\nSo into greater jubilee were chang\'d\nThose flowers and sparkles, and distinct I saw\nBefore me either court of heav\'n displac\'d.\n     O prime enlightener!  thou who crav\'st me strength\nOn the high triumph of thy realm to gaze!\nGrant virtue now to utter what I kenn\'d,\n    There is in heav\'n a light, whose goodly shine\nMakes the Creator visible to all\nCreated, that in seeing him alone\nHave peace; and in a circle spreads so far,\nThat the circumference were too loose a zone\nTo girdle in the sun.  All is one beam,\nReflected from the summit of the first,\nThat moves, which being hence and vigour takes,\nAnd as some cliff, that from the bottom eyes\nIts image mirror\'d in the crystal flood,\nAs if \'t admire its brave appareling\nOf verdure and of flowers: so, round about,\nEye");strcat(expected_filecontent6, " evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLa");


            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "HigH");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "ALLOW.TX");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "SqUARE.Tx");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "THEN.bIn");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "ORDER.TXt");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "HaPPEN.tX");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "InsTrUME.TX");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 4248, file0);
                test_error(size0 == 4248, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4248 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 4248);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 4248);
            
                size_t size1 = file_read(filecontent1, 1, 4098, file1);
                test_error(size1 == 4098, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 4098 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 4098);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 4098);
            
                size_t size2 = file_read(filecontent2, 1, 674, file2);
                test_error(size2 == 674, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 674 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 674);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 674);
            
                size_t size3 = file_read(filecontent3, 1, 7813, file3);
                test_error(size3 == 7813, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7813 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 7813);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 7813);
            
                size_t size4 = file_read(filecontent4, 1, 6333, file4);
                test_error(size4 == 6333, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6333 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 6333);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 6333);
            
                size_t size5 = file_read(filecontent5, 1, 6144, file5);
                test_error(size5 == 6144, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 6144 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 6144);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 6144);
            
                size_t size6 = file_read(filecontent6, 1, 537, file6);
                test_error(size6 == 537, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 537 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 537);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 537);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 102: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST102(void)
{
    // informacje o teście
    test_start(102, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(7813, 1);
            char expected_filecontent[7814] = "";

            strcat(expected_filecontent, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "THEN.bIN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 4791, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[4791] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[4791], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 103: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST103(void)
{
    // informacje o teście
    test_start(103, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(4248, 1);
            char expected_filecontent[4249] = "";

            strcat(expected_filecontent, "s needed help\nOf vision to interpret.  As when breaks\nIn act to be discharg\'d, a cross-bow bent\nBeyond its pitch, both nerve and bow o\'erstretch\'d,\nThe flagging weapon feebly hits the mark;\nThus, tears and sighs forth gushing, did I burst\nBeneath the heavy load, and thus my voice\nWas slacken\'d on its way.  She straight began:\n\"When my desire invited thee to love\nThe good, which sets a bound to our aspirings,\nWhat bar of thwarting foss or linked chain\nDid meet thee, that thou so should\'st quit the hope\nOf further progress, or what bait of ease\nOr promise of allurement led thee on\nElsewhere, that thou elsewhere should\'st rather wait?\"\n     A bitter sigh I drew, then scarce found voice\nTo answer, hardly to these sounds my lips\nGave utterance, wailing:  \"Thy fair looks withdrawn,\nThings present, with deceitful pleasures, turn\'d\nMy steps aside.\"  She answering spake:  \"Hadst thou\nBeen silent, or denied what thou avow\'st,\nThou hadst not hid thy sin the more: such eye\nObserves it.  But whene\'er the sinner\'s cheek\nBreaks forth into the precious-streaming tears\nOf self-accusing, in our court the wheel\nOf justice doth run counter to the edge.\nHowe\'er that thou may\'st profit by thy shame\nFor errors past, and that henceforth more strength\nMay arm thee, when thou hear\'st the Siren-voice,\nLay thou aside the motive to this grief,\nAnd lend attentive ear, while I unfold\nHow opposite a way my buried flesh\nShould have impell\'d thee.  Never didst thou spy\nIn art or nature aught so passing sweet,\nAs were the limbs, that in their beauteous frame\nEnclos\'d me, and are scatter\'d now in dust.\nIf sweetest thing thus fail\'d thee with my death,\nWhat, afterward, of mortal should thy wish\nHave tempted?  When thou first hadst felt the dart\nOf perishable things, in my departing\nFor better realms, thy wing thou should\'st have prun\'d\nTo follow me, and never stoop\'d again\nTo \'bide a second blow for a slight girl,\nOr other gaud as transient and as vain.\nThe new and inexperienc\'d bird awaits,\nTwice it may be, or thrice, the fowler\'s aim;\nBut in the sight of one, whose plumes are full,\nIn vain the net is spread, the arrow wing\'d.\"\n     I stood, as children silent and asham\'d\nStand, list\'ning, with their eyes upon the earth,\nAcknowledging their fault and self-condemn\'d.\nAnd she resum\'d:  \"If, but to hear thus pains thee,\nRaise thou thy beard, and lo!  what sight shall do!\"\n     With less reluctance yields a sturdy holm,\nRent from its fibers by a blast, that blows\nFrom off the pole, or from Iarbas\' land,\nThan I at her behest my visage rais\'d:\nAnd thus the face denoting by the beard,\nI mark\'d the secret sting her words convey\'d.\n     No sooner lifted I mine aspect up,\nThan downward sunk that vision I beheld\nOf goodly creatures vanish; and mine eyes\nYet unassur\'d and wavering, bent their light\nOn Beatrice.  Towards the animal,\nWho joins two natures in one form, she turn\'d,\nAnd, even under shadow of her veil,\nAnd parted by the verdant rill, that flow\'d\nBetween, in loveliness appear\'d as much\nHer former self surpassing, as on earth\nAll others she surpass\'d.  Remorseful goads\nShot sudden through me.  Each thing else, the more\nIts love had late beguil\'d me, now the more\nI Was loathsome.  On my heart so keenly smote\nThe bitter consciousness, that on the ground\nO\'erpower\'d I fell: and what my state was then,\nShe knows who was the cause.  When now my strength\nFlow\'d back, returning outward from the heart,\nThe lady, whom alone I first had seen,\nI found above me.  \"Loose me not,\" she cried:\n\"Loose not thy hold;\" and lo!  had dragg\'d me high\nAs to my neck into the stream, while she,\nStill as she drew me after, swept along,\nSwift as a shuttle, bounding o\'er the wave.\n     The blessed shore approaching then was heard\nSo sweetly, \"Tu asperges me,\" that I\nMay not remember, much less tell the sound.\nThe beauteous dame, her arms expanding, clasp\'d\nMy temples, and immerg\'d me, where \'t was fit\nThe wave should drench me: and thence raising up,\nWithin the fourfold dance of lovely nymphs\nPresented me so lav\'d, and with their arm\nThey each did cover me.  \"Here are we nymphs,\nAnd in ");
    strcat(expected_filecontent, "the heav\'n are stars.  Or ever earth\nWas visited of Beatrice, we\nAppointed for her handmaids, tended on her.\nWe to her eyes will lead thee; but the light");

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HIGH");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -1928, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[2320] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[2320], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 104: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST104(void)
{
    // informacje o teście
    test_start(104, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(7813, 1);
            char expected_filecontent[7814] = "";

            strcat(expected_filecontent, "ce removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?");
    strcat(expected_filecontent, "\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment me more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in goi");

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "THen.BiN");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 3354, SEEK_SET);
            file_seek(file, 274, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[3628] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[3628], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 105: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST105(void)
{
    // informacje o teście
    test_start(105, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\AT\\TO\\mILLioN\\WILD\\eLECTRiC");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\aT\\tO\\mIlLION\\WiLD\\ElECTRIC) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 106: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST106(void)
{
    // informacje o teście
    test_start(106, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\PATTERN\\CrOP");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\PATTERN\\CrOP) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 107: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST107(void)
{
    // informacje o teście
    test_start(107, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\wRiTEinA\\PAPER\\DON'T");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\WRITEINa\\PAPER\\DON'T) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 108: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST108(void)
{
    // informacje o teście
    test_start(108, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\SIT\\ComPaNY\\mUCh\\LAW");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\SIT\\COmPANy\\MUCH\\LaW) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 109: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST109(void)
{
    // informacje o teście
    test_start(109, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\WRiTEINA\\biRd\\LIE\\GlASs");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\WrItEiNa\\BIrD\\LiE\\gLASS) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 110: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST110(void)
{
    // informacje o teście
    test_start(110, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\SiT\\STUDY\\DISTANT\\TOGETHeR");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\sIT\\sTUdY\\dIsTANT\\tOgEthER) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 111: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST111(void)
{
    // informacje o teście
    test_start(111, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\SIT\\if\\witH\\FIsH\\doN'T\\wHEeL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\sIt\\if\\WitH\\FiSH\\DON'T\\WheEL) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 112: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST112(void)
{
    // informacje o teście
    test_start(112, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\WRITEInA\\sTOnE\\BanK\\eNErGY\\TYpE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\WrITEINA\\StONE\\BanK\\enErgY\\tyPE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 113: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST113(void)
{
    // informacje o teście
    test_start(113, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\INseCT\\SlIP\\DeSIgN\\CooK");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\INSeCT\\sLIP\\DESiGn\\COOk) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 114: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST114(void)
{
    // informacje o teście
    test_start(114, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\WRITeinA\\fEEL\\SInG\\tAIl");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\WRITEINA\\FeeL\\SING\\TAIL) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 115: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST115(void)
{
    // informacje o teście
    test_start(115, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "\\WrIteINA\\fEeL\\NEIGHBOR\\TiNy");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (\\WRITEINA\\FEEL\\NEigHBOR\\tInY) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 116: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST116(void)
{
    // informacje o teście
    test_start(116, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SOfT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SoFT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 117: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST117(void)
{
    // informacje o teście
    test_start(117, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "LeArN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (leARn) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 118: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST118(void)
{
    // informacje o teście
    test_start(118, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PATTERN");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PaTTErN) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 119: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST119(void)
{
    // informacje o teście
    test_start(119, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "iNSECT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (INSECt) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 120: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST120(void)
{
    // informacje o teście
    test_start(120, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "AT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (AT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 121: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST121(void)
{
    // informacje o teście
    test_start(121, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "SIT");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (SiT) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 122: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST122(void)
{
    // informacje o teście
    test_start(122, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "WRITEINA");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (WRITEINA) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 123: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST123(void)
{
    // informacje o teście
    test_start(123, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "NOON");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie NOON, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 124: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST124(void)
{
    // informacje o teście
    test_start(124, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "NOOn");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 125: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST125(void)
{
    // informacje o teście
    test_start(125, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 126: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST126(void)
{
    // informacje o teście
    test_start(126, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 127: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST127(void)
{
    // informacje o teście
    test_start(127, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 128: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST128(void)
{
    // informacje o teście
    test_start(128, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "HIGH");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 129: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST129(void)
{
    // informacje o teście
    test_start(129, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[14] = { "HIGH", "ALLOW.TX", "SQUARE.TX", "THEN.BIN", "ORDER.TXT", "HAPPEN.TX", "INSTRUME.TX", "SOFT", "LEARN", "PATTERN", "INSECT", "AT", "SIT", "WRITEINA" };
            int found_names[14] = { 0 };

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 14; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 14; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 130: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST130(void)
{
    // informacje o teście
    test_start(130, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[69] = { "KNOW.BIN", "BE.BIN", "WEST.BIN", "SMILE.TX", "MINE.TX", "OLD.BIN", "INTEREST", "LEVEL.TXT", "PAIR", "COMMON", "LEG.TX", "HOUR.TXT", "YES", "THE", "NOUN.TXT", "HUNDRED.TXT", "COPY.TX", "PRETTY.TX", "SIMILAR.BIN", "STOP.TX", "GENERAL", "GLAD.BIN", "NORTH", "VOWEL.BIN", "NEXT.TXT", "CROSS", "SENSE.BIN", "NAME", "FATHER.TX", "BEAR.TX", "PAGE.TXT", "TOOK.TX", "SHALL.BIN", "YARD.TX", "SAY.TXT", "DURING.TXT", "FACE.BIN", "THING.TXT", "BOY.TXT", "MELODY.TXT", "MEAT", "SUMMER.TX", "PRODUCE.BIN", "MEET.BIN", "CHICK.BIN", "TONE.TX", "CERTAIN", "AMONG.TXT", "EQUAL.TX", "ENTER.TXT", "THERE", "BETWEEN.TXT", "QUART", "SUDDEN", "RICH.TX", "BACK.TX", "CHARGE.TXT", "UP", "FEEL", "DECIDE", "MAGNET", "STONE", "ELSE", "SLAVE", "SUFFIX", "BIRD", "PAPER", ".", ".." };
            int found_names[69] = { 0 };

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\wRITEINA");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 69; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 69; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 131: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST131(void)
{
    // informacje o teście
    test_start(131, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[12] = { "HOLD", "WEIGHT.BIN", "SOLVE", "WEEK", "POSE.TX", "FAT", "VERB", "HUGE", "ASK", "PICTURE", ".", ".." };
            int found_names[12] = { 0 };

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\LeARN\\..\\LeArN\\CLoSE\\SHOUlD\\OCEAN\\.\\DiViDe\\TRIANGLE");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 12; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 12; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 132: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST132(void)
{
    // informacje o teście
    test_start(132, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\sIT\\cReATe\\ShARE\\BELL\\FIeLD\\DECiMAl");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 133: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST133(void)
{
    // informacje o teście
    test_start(133, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\wriTEInA\\STONe\\BOTTOm\\BRIGHT\\ROCK\\DiFFIcUL.BIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 134: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST134(void)
{
    // informacje o teście
    test_start(134, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\WRITEINA\\ELsE\\STep\\PICK.Tx");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 135: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST135(void)
{
    // informacje o teście
    test_start(135, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\sOft\\ReACH\\woRLD");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 136: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST136(void)
{
    // informacje o teście
    test_start(136, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\InsECT\\SLIP\\DESiGN\\sIsTer\\AGo");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 137: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST137(void)
{
    // informacje o teście
    test_start(137, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\SIT\\cOMPAnY\\MuCh\\LAw\\HEAT\\GAS.Tx");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 138: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST138(void)
{
    // informacje o teście
    test_start(138, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\pATTERN\\cRoP\\DiE\\FLOwEr\\FAST\\LoNg\\EXACT");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 139: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST139(void)
{
    // informacje o teście
    test_start(139, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\WRItEiNA\\PAPER\\DON'T\\PrOPErTY\\BloCK.tX");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 140: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST140(void)
{
    // informacje o teście
    test_start(140, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\INSECT\\TRACK.bIN");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 141: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST141(void)
{
    // informacje o teście
    test_start(141, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\sIT\\IF\\NeIgHBoR\\TREE\\As\\CHaNCE\\INdusTRy");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 142: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST142(void)
{
    // informacje o teście
    test_start(142, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\AT\\TO\\MiLLiON\\WILD\\THOUgH\\cOUNTRy");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 143: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST143(void)
{
    // informacje o teście
    test_start(143, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\sOFT\\LEd");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 144: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST144(void)
{
    // informacje o teście
    test_start(144, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                        struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                        test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct volume_t* volume = fat_open(disk, 0);
                        test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        struct dir_t*  dir = dir_open(volume, "\\aT\\To\\miLLIoN\\WiLD\\WeaR.tX");
                        test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                        fat_close(volume);
                        disk_close(disk);

                        test_no_heap_leakage();
                        onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 145: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST145(void)
{
    // informacje o teście
    test_start(145, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HIGH");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 146: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST146(void)
{
    // informacje o teście
    test_start(146, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ALLOW.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 147: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST147(void)
{
    // informacje o teście
    test_start(147, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SQUArE.tx");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 148: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST148(void)
{
    // informacje o teście
    test_start(148, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "THEN.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 149: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST149(void)
{
    // informacje o teście
    test_start(149, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "ORder.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 150: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST150(void)
{
    // informacje o teście
    test_start(150, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "HAPPEn.tX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 151: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST151(void)
{
    // informacje o teście
    test_start(151, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "INSTRuMe.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 152: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST152(void)
{
    // informacje o teście
    test_start(152, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("doctor_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "arM");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_read
            UTEST30, // Sprawdzanie poprawności działania funkcji file_read
            UTEST31, // Sprawdzanie poprawności działania funkcji file_read
            UTEST32, // Sprawdzanie poprawności działania funkcji file_read
            UTEST33, // Sprawdzanie poprawności działania funkcji file_read
            UTEST34, // Sprawdzanie poprawności działania funkcji file_read
            UTEST35, // Sprawdzanie poprawności działania funkcji file_read
            UTEST36, // Sprawdzanie poprawności działania funkcji file_read
            UTEST37, // Sprawdzanie poprawności działania funkcji file_read
            UTEST38, // Sprawdzanie poprawności działania funkcji file_read
            UTEST39, // Sprawdzanie poprawności działania funkcji file_read
            UTEST40, // Sprawdzanie poprawności działania funkcji file_read
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji file_read
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji file_read
            UTEST47, // Sprawdzanie poprawności działania funkcji file_read
            UTEST48, // Sprawdzanie poprawności działania funkcji file_read
            UTEST49, // Sprawdzanie poprawności działania funkcji file_read
            UTEST50, // Sprawdzanie poprawności działania funkcji file_read
            UTEST51, // Sprawdzanie poprawności działania funkcji file_read
            UTEST52, // Sprawdzanie poprawności działania funkcji file_read
            UTEST53, // Sprawdzanie poprawności działania funkcji file_read
            UTEST54, // Sprawdzanie poprawności działania funkcji file_read
            UTEST55, // Sprawdzanie poprawności działania funkcji file_read
            UTEST56, // Sprawdzanie poprawności działania funkcji file_read
            UTEST57, // Sprawdzanie poprawności działania funkcji file_read
            UTEST58, // Sprawdzanie poprawności działania funkcji file_read
            UTEST59, // Sprawdzanie poprawności działania funkcji file_read
            UTEST60, // Sprawdzanie poprawności działania funkcji file_read
            UTEST61, // Sprawdzanie poprawności działania funkcji file_read
            UTEST62, // Sprawdzanie poprawności działania funkcji file_read
            UTEST63, // Sprawdzanie poprawności działania funkcji file_read
            UTEST64, // Sprawdzanie poprawności działania funkcji file_read
            UTEST65, // Sprawdzanie poprawności działania funkcji file_read
            UTEST66, // Sprawdzanie poprawności działania funkcji file_read
            UTEST67, // Sprawdzanie poprawności działania funkcji file_read
            UTEST68, // Sprawdzanie poprawności działania funkcji file_read
            UTEST69, // Sprawdzanie poprawności działania funkcji file_read
            UTEST70, // Sprawdzanie poprawności działania funkcji file_read
            UTEST71, // Sprawdzanie poprawności działania funkcji file_read
            UTEST72, // Sprawdzanie poprawności działania funkcji file_read
            UTEST73, // Sprawdzanie poprawności działania funkcji file_read
            UTEST74, // Sprawdzanie poprawności działania funkcji file_read
            UTEST75, // Sprawdzanie poprawności działania funkcji file_read
            UTEST76, // Sprawdzanie poprawności działania funkcji file_read
            UTEST77, // Sprawdzanie poprawności działania funkcji file_read
            UTEST78, // Sprawdzanie poprawności działania funkcji file_read
            UTEST79, // Sprawdzanie poprawności działania funkcji file_read
            UTEST80, // Sprawdzanie poprawności działania funkcji file_read
            UTEST81, // Sprawdzanie poprawności działania funkcji file_read
            UTEST82, // Sprawdzanie poprawności działania funkcji file_read
            UTEST83, // Sprawdzanie poprawności działania funkcji file_read
            UTEST84, // Sprawdzanie poprawności działania funkcji file_read
            UTEST85, // Sprawdzanie poprawności działania funkcji file_read
            UTEST86, // Sprawdzanie poprawności działania funkcji file_read
            UTEST87, // Sprawdzanie poprawności działania funkcji file_read
            UTEST88, // Sprawdzanie poprawności działania funkcji file_read
            UTEST89, // Sprawdzanie poprawności działania funkcji file_read
            UTEST90, // Sprawdzanie poprawności działania funkcji file_read
            UTEST91, // Sprawdzanie poprawności działania funkcji file_read
            UTEST92, // Sprawdzanie poprawności działania funkcji file_read
            UTEST93, // Sprawdzanie poprawności działania funkcji file_read
            UTEST94, // Sprawdzanie poprawności działania funkcji file_read
            UTEST95, // Sprawdzanie poprawności działania funkcji file_read
            UTEST96, // Sprawdzanie poprawności działania funkcji file_read
            UTEST97, // Sprawdzanie poprawności działania funkcji file_read
            UTEST98, // Sprawdzanie poprawności działania funkcji file_read
            UTEST99, // Sprawdzanie poprawności działania funkcji file_read
            UTEST100, // Sprawdzanie poprawności działania funkcji file_read
            UTEST101, // Sprawdzanie poprawności działania funkcji file_read
            UTEST102, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST103, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST104, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST105, // Sprawdzanie poprawności działania funkcji file_open
            UTEST106, // Sprawdzanie poprawności działania funkcji file_open
            UTEST107, // Sprawdzanie poprawności działania funkcji file_open
            UTEST108, // Sprawdzanie poprawności działania funkcji file_open
            UTEST109, // Sprawdzanie poprawności działania funkcji file_open
            UTEST110, // Sprawdzanie poprawności działania funkcji file_open
            UTEST111, // Sprawdzanie poprawności działania funkcji file_open
            UTEST112, // Sprawdzanie poprawności działania funkcji file_open
            UTEST113, // Sprawdzanie poprawności działania funkcji file_open
            UTEST114, // Sprawdzanie poprawności działania funkcji file_open
            UTEST115, // Sprawdzanie poprawności działania funkcji file_open
            UTEST116, // Sprawdzanie poprawności działania funkcji file_open
            UTEST117, // Sprawdzanie poprawności działania funkcji file_open
            UTEST118, // Sprawdzanie poprawności działania funkcji file_open
            UTEST119, // Sprawdzanie poprawności działania funkcji file_open
            UTEST120, // Sprawdzanie poprawności działania funkcji file_open
            UTEST121, // Sprawdzanie poprawności działania funkcji file_open
            UTEST122, // Sprawdzanie poprawności działania funkcji file_open
            UTEST123, // Sprawdzanie poprawności działania funkcji file_open
            UTEST124, // Sprawdzanie poprawności działania funkcji file_read
            UTEST125, // Sprawdzanie poprawności działania funkcji file_read
            UTEST126, // Sprawdzanie poprawności działania funkcji file_read
            UTEST127, // Sprawdzanie poprawności działania funkcji file_close
            UTEST128, // Sprawdzanie poprawności działania funkcji file_read
            UTEST129, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST130, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST131, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST132, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST133, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST134, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST135, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST136, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST137, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST138, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST139, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST140, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST141, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST142, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST143, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST144, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST145, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST146, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST147, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST148, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST149, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST150, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST151, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST152, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(152); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}