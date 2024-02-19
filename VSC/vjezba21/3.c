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

   return;
}

int main(void) {
   char niz1[61];
   printf("Upisite 1. niz > ");
   fgets(niz1, 60, stdin);
   izbaciNR(niz1);

   char niz2[61];
   printf("Upisite 2. niz > ");
   fgets(niz2, 60, stdin);
   izbaciNR(niz2);

   char niz3[61];
   printf("Upisite 3. niz > ");
   fgets(niz3, 60, stdin);
   izbaciNR(niz3);

   char *pom;
   char *p1 = &niz1[0], *p2 = &niz2[0], *p3 = &niz3[0];
   if (strcmp(p1, p2) > 0) {
      pom = p1;
      p1 = p2;
      p2 = pom;
   }

   if (strcmp(p1, p3) > 0) {
      pom = p1;
      p1 = p3;
      p3 = pom;
   }

   if (strcmp(p2, p3) > 0) {
      pom = p2;
      p2 = p3;
      p3 = pom;
   }

   printf("%s\n%s\n%s\n", p1, p2, p3);
}