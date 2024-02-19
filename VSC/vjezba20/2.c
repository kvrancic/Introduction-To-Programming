#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   int n[11] = {};
   srand((unsigned int)time(NULL));

   int i = 0, x;
   for (i = 0; i < 1000000; i++) {
      x = rand() % 11 + 50;
      for (int j = 0; j < 11; j++) {
         if (x - 50 == j) {
            n[j]++;
         }
      }
   }

   for (i = 0; i < 11; i++) {
      printf("%6d %d\n", i + 50, n[i]);
   }

   return 0;
}
