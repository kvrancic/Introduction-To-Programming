#include <stdio.h>
#define N 40
int main(void) {
   int a_i_minus2, a_i_minus1 = 1, a_i = 1;
   FILE *tok = fopen("fibonacci.bin", "wb");
   for (int i = 1; i <= N; ++i) {
      if (i > 2) {
         a_i_minus2 = a_i_minus1;
         a_i_minus1 = a_i;
         a_i = a_i_minus1 + a_i_minus2;
      }
      fwrite(&a_i, sizeof(a_i), 1, tok);
   }
   fclose(tok);
   return 0;
}
