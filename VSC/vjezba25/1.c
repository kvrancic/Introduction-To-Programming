#include <ctype.h>
#include <stdio.h>

int main(void) {
   char adresa[] = "C:/Users/Karlo/OneDrive - fer.hr/1.semestar/UPRO/upro.txt";
   FILE *ulaz = fopen(adresa, "r");
   FILE *izlaz = fopen("izlaz.txt", "w");

   int c;
   while ((c = getc(ulaz)) != EOF) {
      putc(toupper(c), izlaz);
   }

   fclose(ulaz);
   fclose(izlaz);
   return 0;
}
