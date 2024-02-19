#include <stdio.h>

typedef struct {
   int sifra;
   char naziv[30];
} tekstualna;

typedef struct {
   int sifra;
   char naziv[31];
   int ects;
} binarna;

int main(void) {
   tekstualna txt = {0};
   binarna bin = {0};
   FILE *ulazT = fopen("pred.txt", "r");
   FILE *ulazB = fopen("pred.txt", "rb");

   while (fscanf(ulazT, " %d %s", &txt.sifra, txt.naziv) == 2) {
      fseek(ulazB, 0L, SEEK_SET);
      while (fread(&bin, sizeof(binarna), 1, ulazB)) {
         if (bin.sifra == txt.sifra) {
            if (strcmp(bin.naziv, txt.naziv) != 0)
               printf("%4d %s\n", txt.sifra, txt.naziv);
         }
      }
   }

   flose(ulazB);
   fclose(ulazT);
   return 0;
}
