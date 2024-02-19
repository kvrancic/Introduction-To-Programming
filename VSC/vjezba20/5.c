#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gadjajPolje(int *polje, int m, int n, int x) {
   static _Bool inicijaliziran = 0;

   if (!inicijaliziran) {
      inicijaliziran = 1;
      for (int i = 0; i < m * n; i++)
         *(polje + i) = 0;
   }

   for (int i = 0; i < x; i++)
      (*(polje + (rand() % m) * n + rand() % n))++;

   return;
}

int main(void) {
   srand((unsigned int)time(NULL));

   int m, n;
   m = rand() % 6 + 5;
   n = rand() % 11 + 10;
   printf("Upisite broj hitaca > ");
   int x;
   scanf("%d", &x);

   int polje[m][n];

   gadjajPolje(&polje[0][0], m, n, x);

   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
         printf("%6d", polje[i][j]);
      printf("\n");
   }

   return 0;
}