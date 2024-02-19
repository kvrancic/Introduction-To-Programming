#include <stdio.h>

int main(void) {
   int n;
   printf("Upisite n > ");
   scanf("%d", &n);

   FILE *izlaz = fopen("fibonacci.bin", "wb");
   unsigned int niz[n];

   for (int i = 0; i < n; i++) {
      niz[i] = 0;
   }

   niz[0] = 1;
   niz[1] = 1;
   niz[2] = 2;
   for (int i = 3; i < n; i++) {
      niz[i] = niz[i - 1] + niz[i - 2];
   }

   for (int i = 0; i < n; i++) {
      printf("%u\n", niz[i]);
   }
   fwrite(niz, sizeof(unsigned int), n, izlaz);
   fclose(izlaz);

   return 0;
}