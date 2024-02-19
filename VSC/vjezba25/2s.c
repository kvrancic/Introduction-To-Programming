#include <ctype.h>
#include <stdio.h>

int brojiSamoglasnike(char *path) {
   FILE *ulaz = fopen(path, "r");
   int c, brojac = 0;

   if (ulaz == NULL) {
      brojac = -1;
   } else {
      while ((c = getc(ulaz)) != EOF) {
         c = toupper(c);
         if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            brojac++;
         }
      }
   }

   fclose(ulaz);

   return brojac;
}

void izbaciNR(char *path) {
   while ((*path) != '\0') {
      if (*path == '\n' && *(path + 1) == '\0')
         *path = '\0';
      path++;
   }
}

int main(void) {
   char path[150];
   printf("Upisite path > ");
   fgets(path, 150, stdin);
   izbaciNR(path);

   int n = brojiSamoglasnike(path);
   if (n == -1) {
      printf("Nije uspjelo otvaranje datoteke %s", path);
   } else {
      printf("Broj samoglasnika u datoteci %s je %d", path, n);
   }
}