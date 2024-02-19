#include <math.h>
#include <stdio.h>

int maks(int *px, int *py);

int main(void) {
   int x, y;
   printf("Upisi dva broja > ");
   scanf("%d %d", &x, &y);

   printf("Rezultat: %d", maks(&x, &y));
}

int maks(int *px, int *py) {
   int veci;
   if (*px > *py)
      veci = *px;
   else
      veci = *py;

   return veci;
}