#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
   int brojac = 0;
   char niz[40];
   while (strlen(fgets(niz, 40, stdin)) >= 10) {
      for (int i = 0; niz[i] != '\0'; i++) {
         if (isdigit(niz[i]))
            brojac++;
      }
   }

   printf("Broj znamenki: %d", brojac);
}