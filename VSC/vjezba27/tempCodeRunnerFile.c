#include <stdio.h>
typedef struct {
   int sifra;
   char ime[40];
   int ects;
   int brstud;
} predmet;

int main(void) {
   FILE *ulaz = fopen("predmeti1.bin", "rb");

   predmet predmet = {0};
   while (fread(&predmet, sizeof(predmet), 1, ulaz) == 1) {
      printf("%d, %s, polozilo %d\n", predmet.sifra, predmet.ime,
             predmet.brstud);
   }

   fclose(ulaz);
   return 0;
}