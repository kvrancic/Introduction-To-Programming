#include <stdio.h>

typedef struct {
    char ime[20 + 1];
    char prezime[20 + 1];
    int godine;
    int sifraZanimanja;
} osoba;

typedef struct {
    int sifra;
    char naziv[20 + 1];
} zanimanje;

void generateExample() { // nije dio rjesenja, ostavio sam ovo za znatizeljne
    osoba o[] = { // provjeriti jesu li dobro prepisane godine
        {"Pero"   , "Peric"  , 55, 2},
        {"Ivo"    , "Ivic"   , 45, 3},
        {"Lujo"   , "Lujic"  , 22, 1},
        {"Vilibor", "Zvancic", 33, 2},
        {"Danko"  , "Dancic" , 75, 4}
    };
    
    zanimanje z[] = {
        {1, "stolar"     },
        {2, "znanstvenik"},
        {3, "kuhar"      },
        {4, "elektricar" },
        {5, "knjiznicar" }
    };
    FILE *izlazOsobe = fopen("osobe.bin", "wb");
    fwrite(o, sizeof(osoba), 5, izlazOsobe);
    fclose(izlazOsobe);
    FILE *izlazZanimanja = fopen("zanimanja.bin", "wb");
    fwrite(z, sizeof(zanimanje), 5, izlazZanimanja);
    fclose(izlazZanimanja);
}

int main(void) {
    generateExample(); // nije dio rjesenja, cisto da se vidi da radi
    FILE *ulazOsobe = fopen("osobe.bin", "rb");
    FILE *ulazZanimanja = fopen("zanimanja.bin", "rb");
    FILE *izlaz = fopen("izlaz.txt", "w");
    osoba o;
    zanimanje z;
    int cnt = 0, sum = 0;
    while (fread(&o, sizeof(osoba), 1, ulazOsobe)) {
        cnt++;
        sum += o.godine;
        // glavni dio zadatka: znati se pomaknuti u datoteci na zeljeni zapis
        fseek(
            ulazZanimanja,
            (long)(o.sifraZanimanja - 1)*sizeof(zanimanje),
            SEEK_SET
        );
        fread(&z, sizeof(zanimanje), 1, ulazZanimanja);
        fprintf(izlaz, "%s %s %s\n", o.ime, o.prezime, z.naziv);
    }
    fprintf(izlaz, "Prosjecna starost: %.0f", (float) sum/cnt);
    fclose(ulazOsobe);
    fclose(ulazZanimanja);
    fclose(izlaz);
    
    return 0;
}