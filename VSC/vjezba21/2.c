#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void izbaciNR(char *niz) {
   while (*niz != '\0') {
      if (*niz == '\n' && *(niz + 1) == '\0')
         *niz = '\0';
      niz++;
   }
}

int brojpodnizova(char *niz1, char *niz2) {
   int brojac = 0;
   while (strstr(niz1, niz2) != NULL) {
      niz1 = strstr(niz1, niz2) + 1;
      brojac++;
   }

   return brojac;
}

int main(void) {
   char niz1[60 + 1], niz2[60 + 1];
   fgets(niz1, 60, stdin);
   fgets(niz2, 60, stdin);

   izbaciNR(niz1);
   izbaciNR(niz2);

   printf("Ima %d podnizov", brojpodnizova(niz1, niz2));

   return 0;
}