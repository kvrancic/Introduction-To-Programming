#include <stdio.h>

int main(void) {
   FILE *ulaz = fopen("bodovi.txt", "r");
   float bodovi;
   float suma = 0.f;
   int brojac = 0;
   while (fscanf(ulaz, " %*u %*[^1234567890] %f", &bodovi) == 1) {
      brojac++;
      suma += bodovi;
   }

   float prosjek = suma / brojac;
   fseek(ulaz, 0L, SEEK_SET);
   char ime[20];
   char prezime[20];
   unsigned int jmbag;

   while (fscanf(ulaz, " %u %s %s %f", &jmbag, ime, prezime, &bodovi) == 4) {
      if (bodovi > prosjek) {
         printf("%u %s %s %f\n", jmbag, ime, prezime, bodovi);
      }
   }

   fclose(ulaz);
   return 0;
}