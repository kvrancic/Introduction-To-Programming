#include <stdio.h>

double *pokNaMax(double *niz, int n) {
   int i, j;
   double *max = niz;
   for (i = 0; i < n; i++) {
      if (*(niz + i * n + i) > *max)
         max = niz + i * n + i;
   }

   return max;
}

int main(void) {
   int n = 4;
   double niz[4][4] = {{-1., 2., 3., 9.},
                       {-9., 5., 3., -4.},
                       {7., 2., 2., 4.},
                       {1., 2., -3., 5.}};
   printf("Vrijednost najveceg clana na dijagonali je %lf",
          *(pokNaMax(&niz[0][0], n)));

   return 0;
}