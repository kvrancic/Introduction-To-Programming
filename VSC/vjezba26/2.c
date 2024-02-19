#include <stdio.h>

int main(void) {
   float c;
   FILE *ulaz = fopen("brojevi.txt", "r");
   float suma = 0;
   int br = 0;
   _Bool ucitan = 0;
   while ((fscanf(ulaz, "%f", &c)) == 1) {
      ucitan = 1;
      suma += c;
      br++;
   }

   if (ucitan) {
      printf("%f", suma / br);
   } else {
      printf("Nisi nista ucita majmune");
   }

   return 0;
}