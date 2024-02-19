#include <stdio.h>

typedef struct {
   int jmbag;
   char ime[20];
   char prezime[20];
   int sifra;
   int ocjena;
} osoba;

typedef struct {
   int sifra;
   char ime[40];
   int ects;
   int brstud;
} predmet;

int main(void) {
   osoba ucenik = {0};
   predmet predmet = {0};
   FILE *ulaztxt = fopen("ocjene.txt", "r");
   FILE *ulazbin = fopen("predmeti1.bin", "rb");

   printf("Upisi sifru ucenika > ");
   int x;
   char subject[40];
   scanf("%d", &x);
   while (fscanf(ulaztxt, "%d %s %s %d %d", &ucenik.jmbag, &ucenik.ime,
                 &ucenik.prezime, &ucenik.sifra, &ucenik.ocjena) == 5) {
      if (ucenik.jmbag == x) {
         printf("%s %s je polozio/polozilla: \n", ucenik.ime, ucenik.prezime);
         fseek(ulazbin, (long)(predmet.sifra - 1001) * sizeof(predmet),
               SEEK_SET);
         fread(subject, sizeof(predmet.ime), 1, ulazbin);
         printf("%s", subject);
         printf(" (%d)\n", ucenik.ocjena);
      }
   }
}