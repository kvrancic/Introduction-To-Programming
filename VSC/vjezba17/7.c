#include <stdio.h>

double zbroj2D(double *p, int m, int n) {
   double suma = 0;
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         suma += *(p + m * i + j);
      }
   }

   return suma;
}

int main(void) {
   int m, n, i, j;
   printf("Upisite dimenzije: ");
   scanf("%d %d", &m, &n);

   double matrica[m][n];

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
         scanf("%lf", &matrica[i][j]);
   }

   double *p = matrica[0];
   printf("Suma je: %lf", zbroj2D(p, m, n));

   return 0;
}