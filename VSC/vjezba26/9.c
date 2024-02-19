#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand((unsigned int)time(NULL));
   FILE *izlaz = fopen("slucajni.bin", "wb");
   int i, br, n;

   for (int j = 0; j < 50; j++) {
      n = rand() % 7 + 2;
      fwrite(&n, sizeof(int), 1, izlaz);

      for (i = 0; i < n; i++) {
         br = rand() % 11 + 150;
         fwrite(&br, sizeof(int), 1, izlaz);
      }
   }
   fclose(izlaz);
   return 0;
}