#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vehicle {
   char registration[8 + 1];
   int weightKilos;
   int productionYear;
   _Bool isInUse;
};

int main(void) {
   FILE *ulaz = fopen("slova.bin", "rb");
   srand((unsigned int)time(NULL));

   char x, i;
   long random;
   for (i = 0; i < 40 && x != 'X'; i++) {
      random = (rand() % 62);
      fseek(ulaz, random, SEEK_SET);
      fread(&x, sizeof(char), 1, ulaz);
      printf("%c", x);
   }

   fclose(ulaz);
   return (0);
}