#include <stdio.h>

int main(void) {
   FILE *ulaz = fopen("mjerenja.txt", "r");
   float temperatura;
   float suma = 0.f;

   int dan, brojmjerenja;
   while (fscanf(ulaz, "#%3d#%2d", &dan, &brojmjerenja) == 2) {
      suma = 0.f;
      for (int i = 0; i < brojmjerenja; i++) {
         fscanf(ulaz, "#%*d#%f", &temperatura);
         suma += temperatura;
      }
      fscanf(ulaz, "\n");
      printf("Dan= %d, Broj mjerenja= %d, Prosjek= %.2f\n", dan, brojmjerenja,
             suma / brojmjerenja);
   }

   fclose(ulaz);

   return 0;
}