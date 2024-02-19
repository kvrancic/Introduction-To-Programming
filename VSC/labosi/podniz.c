#include <stdio.h>

int najduljiUzlazniPodniz(int *niz, int N) {
   int i, brojac = 0, max = 0;
   for (i = 1; i < N; i++) {
      if (*(niz + i) > *(niz + i - 1)) {
         brojac++;
      } else {
         if (brojac > max)
            max = brojac;

         brojac = 0;
      }
   }
}