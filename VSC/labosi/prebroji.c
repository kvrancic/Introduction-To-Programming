#include <stdio.h>

int prebroji(char *niz1, char *niz2) {
   int i, j, rezultat = 0;
   for (i = 0; *(niz1 + i) != '\0'; i++) {
      for (j = 0; *(niz2 + j) != '\0'; j++) {
         if (*(niz1 + i) == *(niz2 + j))
            rezultat++;
      }
   }

   return rezultat;
}

int main(void) {
   char niz1[50], niz2[50];
   fgets(niz1, 49 + 1, stdin);
   fgets(niz2, 49 + 1, stdin);
   printf("%d", prebroji(niz1, niz2));

   return 0;
}