#include <stdio.h>

typedef struct {
   int sifra;
   char ime[40];
   int ects;
   int brstud;
} predmet;

int main(void) {
   predmet predmet = {0};

   FILE *ulaz = fopen("predmeti.txt", "r");
   FILE *izlaz1 = fopen("predmeti1.bin", "wb");
   FILE *izlaz2 = fopen("predmeti2.bin", "wb");

   while (fscanf(ulaz, " %d %[^\n]", &predmet.sifra, predmet.ime) == 2) {
      fwrite(&predmet, sizeof(predmet), 1, izlaz1);

      fseek(izlaz2, (predmet.sifra - 1001L) * sizeof(predmet), SEEK_SET);
      fwrite(&predmet, sizeof(predmet), 1, izlaz2);
   }

   fclose(ulaz);
   fclose(izlaz1);
   fclose(izlaz2);
   return 0;
}