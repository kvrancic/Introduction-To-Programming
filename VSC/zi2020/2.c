#include <stdio.h>
#include <string.h>

char *traziZnak(int n, char *niz1, char *niz2) {
   int i, j, brojac;
   for (i = 0; *(niz1 + i) != '\0'; i++) {
      brojac = 0;
      for (j = 0; *(niz2 + j) != '\0'; j++) {
         if (*(niz1 + i) == *(niz2 + j))
            brojac++;
      }

      if (brojac >= n)
         break;
   }

   return (niz1 + i);
}

int main(void) {
   char niz[40 + 1];
   fgets(niz, 40, stdin);

   char *x = traziZnak(3, niz, "BbaacacBacBc");
   printf("Rjesenje: %c", *x);
}