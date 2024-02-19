#include <stdio.h>
#include <string.h>

typedef struct {
   int sifra;
   char ime[40];
   int ects;
   int brstud;
} predmet;

int main(void) {
   predmet predmet = {0};
   FILE *ulaztxt = fopen("ocjene.txt", "r");
   FILE *ulazbin = fopen("predmeti1.bin", "rb");

   int meta;
   char ime[20], prezime[20], subject[40];
   int sifst, sifpr, ocjena;

   printf("Unesi sifru > ");
   scanf("%d", &meta);
   _Bool pogodak = 0, pogodak2 = 0;

   while ((fscanf(ulaztxt, " %d %s %s %d %d", &sifst, ime, prezime, &sifpr,
                  &ocjena) == 5)) {
      if (meta == sifst) {
         if (pogodak == 0) {
            pogodak = 1;
            printf("%s %s je polozio/polozilla: \n", ime, prezime);
         }
         fseek(ulazbin, 0L, SEEK_SET);
         while (fread(&predmet, sizeof(predmet), 1, ulazbin) == 1) {
            if (sifpr == predmet.sifra) {
               pogodak2 = 1;
            }
         }
         if (pogodak2 == 0)
            strcpy(predmet.ime, "?");
         printf("%s (%d)\n", predmet.ime, ocjena);
      }
   }

   if (!pogodak) {
      printf("Nema polozenih predmeta\n");
   }
   fclose(ulaztxt);
   fclose(ulazbin);
   return 0;
}