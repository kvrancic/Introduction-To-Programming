#include <stdio.h>

int main(void) {
   FILE *ulaz = fopen("slucajni.bin", "rb");

   int broj;
   int n, br;
   while (fread(&broj, sizeof(int), 1, ulaz) == 1) {
      printf("%d ", broj);
      br++;
      if (br == n) {
         printf("\n");
      }
      if (broj >= 2 && broj <= 8) {
         n = broj;
         br = 0;
      }
   }

   fclose(ulaz);
}