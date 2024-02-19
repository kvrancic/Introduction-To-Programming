#include <stdio.h>
int main(void) {
   FILE *ulaz = fopen("cijeli.txt", "r");
   FILE *izlaz = fopen("realni.txt", "w");
   int broj;
   float realniBroj;
   broj = getc(ulaz);
   while (broj == 1) {
      realniBroj = broj * 0.5f;
      fprintf(izlaz, "%5.1f\n", realniBroj);
      broj = getc(ulaz);
   }
   fclose(ulaz);
   fclose(izlaz);
   return 0;
}
