#include <stdio.h>

int main(void) {
   char niz[30];
   int i, nr = 0;
   char c;

   for (i = 0; i < 30 && (c = getc(stdin)) != '#'; i++) {
      if (c == '\n') {
         i--;
         nr++;
      } else {
         niz[i] = c;
      }
   }
   niz[i] = '\0';
   ungetc(c, stdin);

   printf("Novih redova je %d\n%s", nr, niz);

   return 0;
}