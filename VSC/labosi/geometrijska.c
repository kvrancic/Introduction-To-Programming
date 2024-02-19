#include <stdio.h>

double geometrijska_sredina(int *matrica, int m, int n) {
   double avg;
   int suma;

   int i, j;
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
         suma += *(matrica + m * i + j);
   }

   avg = (double)suma / (n * m);
   return avg;
}

_Bool izracunaj(int *matrica, int m, int n, double *rezultat) {}
