#include <stdio.h>

void premjesti(char *src, char *dst) {
   int i, j, brojac = 0;
   for (i = 0; *(src + i) != '\0'; i++) {
      if (*(src + i) >= 48 && *(src + i) <= 57) {
         *(dst + brojac) == *(src + i);
         brojac++;

         for (j = i; *(src + j) != '\0'; j++) {
            *(src + j) = *(src + j + 1);
         }
      }
   }
}