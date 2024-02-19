#include <stdio.h>

typedef struct {
   int bitovi;
   int bajtovi;
} x;

x brojiBitove(unsigned int n) {
   x bit = {0};
   int i, brojac;
   for (i = 0; i < 32; i++) {
      if (i % 8 == 0)
         brojac == 0;

      if ((n & 0x1 << i) > 0) {
         bit.bitovi++;
         brojac++;
      }

      if (brojac == 8)
         bit.bajtovi++;
   }

   return bit;
}

int main(void) {
   unsigned int b;
   int rez1, rez2;
   scanf("%u", &b);
   brojiBitove(b, &rez1, &rez2);
   printf("%u -> %d, %d\n", b, rez1, rez2);
   return 0;
}
