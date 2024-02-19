#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void izbaciNR(char *niz) {
   while (*niz != '\0') {
      if (*niz == '\n' && *(niz + 1) == '\0')
         *niz == '\0';
      niz++;
   }

   return;
}

void genText(char *niz, int l, char *rezultat, int n) {
   int i = 0;
   for (i = 0; i < n; i++) {
      *(rezultat + i) = *(niz + rand() % l);
   }
   *rezultat = '\0';

   return;
}

int main(void) {
   char niz[60 + 1];
   fgets(niz, 60, stdin);
   izbaciNR(niz);

   int n, l;
   l = strlen(niz);
   printf("Kolko da je dug novi niz > ");
   scanf("%d", &n);
   static _Bool sjeme = 0;
   if (!sjeme) {
      srand((unsigned)time(NULL));
      sjeme = 1;
   }

   char rezultat[n];
   for (int i = 0; i < 3; i++) {
      genText(niz, l, rezultat, n);
      for (int j = 0; j < n; j++) {
         printf("%c", rezultat[j]);
      }
   }

   return 0;
}