#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char genSlovo() {
   static int parnost = 1;
   char x;
   if (parnost % 2 == 0) {
      parnost++;
      x = rand() % ('Z' - 'A' + 1) + 'A';
   } else {
      parnost++;
      x = rand() % ('z' - 'a' + 1) + 'a';
   }

   return x;
}

int main(void) {
   srand((unsigned int)time(NULL));
   char niz[10 + 1];
   int i;
   for (i = 0; i < 10; i++) {
      niz[i] = genSlovo();
   }
   niz[i] = '\0';

   printf("%s", niz);
   return 0;
}