#include <ctype.h>
#include <stdio.h>

int main(void) {
   FILE *izlaz = fopen("slova.bin", "wb");

   char i = 0;
   for (i = 65; i <= 125; i++) {
      if (isalpha(i)) {
         fwrite(&i, sizeof(char), 1, izlaz);
      }
   }

   for (i = '0'; i <= '9'; i++) {
      fwrite(&i, sizeof(char), 1, izlaz);
   }

   fclose(izlaz);
   return 0;
}