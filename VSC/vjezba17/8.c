#include <stdio.h>

void transpKvad(int *mat, int n) {
   int pom;

   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         pom = *(mat + n * i + j);
         *(mat + n * i + j) = *(mat + n * j + i);
         *(mat + n * j + i) = pom;
      }
   }
}

int main(void) {
   int n, i, j;
   printf("Upisi red matrice > ");
   scanf("%d", &n);
   int matrica[n][n];

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &matrica[i][j]);
      }
   }

   transpKvad(matrica[0], n);

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("%5d", matrica[i][j]);
      }
      printf("\n");
   }

   return 0;
}