#include <stdio.h>

void genPrim(int *p, int dgr, int n) {
   int i, j, brojac = 0;
   _Bool prim = 1;
   for (i = dgr; brojac < n; i++) {
      for (j = 2; j < i; j++) {
         if (i % j == 0) {
            prim = 0;
         }
      }
      if (prim == 1) {
         *(p + brojac) = i;
         brojac++;
      }
      prim = 1;
   }

   return;
}

int main(void) {
   int dgr, n;
   printf("Upisite donju granicu i broj prim brojeva > ");
   scanf("%d %d", &dgr, &n);

   int niz[n];
   int *p = niz;

   genPrim(p, dgr, n);

   for (int i = 0; i < n; i++)
      printf("%7d\n", niz[i]);

   return 0;
}