#include <stdio.h>
#include <string.h>

typedef struct {
    int mb;
    char dvorana[10 + 1];
    float bodovi;
} bodovi_s;

void generateExample() { // nije dio rjesenja, ostavio sam ovo za znatizeljne
    char lines[][14] = {
        "550 19.3.2002",
        "343 23.2.2003",
        "12 1.12.2004",
        "17 17.8.2001"
    };
    bodovi_s b[] = {
        {11 , "D259"  , 12.0},
        {12 , "B2"    , 17.6},
        {13 , "D259"  , 14.7},
        {15 , "PCLAB2", 17.3},
        {343, "D270"  , 15.7},
        {345, "A102"  ,  9.4},
        {346, "A101"  , 10.0},
        {550, "D259"  , 16.9}
    };
    FILE *izlazStud = fopen("stud.txt", "w");
    for (int i = 0; i < 4; i++) {
        fprintf(izlazStud, "%s\n", lines[i]);
    }
    fclose(izlazStud);
    FILE *izlazBodovi = fopen("bodovi.bin", "wb");
    for (int i = 0; i < 8; i++) {
        fseek(izlazBodovi, (long)(b[i].mb - 1)*sizeof(bodovi_s), SEEK_SET);
        fwrite(b + i, sizeof(bodovi_s), 1, izlazBodovi);
    }
    fclose(izlazBodovi);
    
}

int main(void) {
    generateExample(); // nije dio rjesenja, cisto za testiranje
    bodovi_s b;
    FILE *bodovi_f = fopen("bodovi.bin", "r+b");
    // Izracun srednje vrijednosti svih bodova (zato idemo slijedno)
    int br = 0;
    float zbr = 0;
    while (fread(&b, sizeof(bodovi_s), 1, bodovi_f)) {
        if (b.mb) { // preskakanje praznih pozicija (kojima je mb == 0)
            br++;
            zbr += b.bodovi;
        };
    }
    float avg = zbr / br;
    // Opet idemo slijedno jer ne znamo na kojim su pozicijama oni cije bodove
    // treba mijenjati. Te pozicije nismo mogli zapisati u prvom prolazu jer
    // nismo znali koliko memorije je potrebno (koliko takvih ljudi ima)
    fseek(bodovi_f, 0L, SEEK_SET);
    while (fread(&b, sizeof(bodovi_s), 1, bodovi_f)) {
        if (b.mb && strcmp("D259", b.dvorana)) {
            b.bodovi = avg;
            // povratak poziciju iza da overwritamo ono sto smo sad citali:
            fseek(bodovi_f, -1L * sizeof(bodovi_s), SEEK_CUR);
            fwrite(&b, sizeof(bodovi_s), 1, bodovi_f);
            fflush(bodovi_f); // ne zaboraviti flush izmedju pisanja i citanja!
            // flush nakon pisanja, kuzis hhahah
        }
    }
    
    /* Provjera:
    fseek(bodovi_f, 0L, SEEK_SET);
    while (fread(&b, sizeof(bodovi_s), 1, bodovi_f)) {
        printf("%3d, %6s, %4.1f\n", b.mb, b.dvorana, b.bodovi);
    }
    */
    fclose(bodovi_f);
}