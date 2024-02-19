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
   _Bool pogodak = 0;

   while ((fscanf(ulaztxt, " %d %s %s %d %d", &sifst, ime, prezime, &sifpr,
                  &ocjena) == 5)) {
      if (meta == sifst) {
         if (pogodak == 0) {
            pogodak = 1;
            printf("%s %s je polozio/polozilla: \n", ime, prezime);
         }
         fseek(ulazbin, (sifpr - 1001L) * sizeof(predmet), SEEK_SET);
         fread(&predmet, sizeof(predmet), 1, ulazbin);
         if (sifpr == 0)
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