#include <ctype.h>
#include <stdio.h>

int brojiSamoglasnike(char *datapath) {
   FILE *ulaz = fopen(datapath, "r");

   int brojac = 0;
   int slovo;
   while ((slovo = fgetc(ulaz)) != EOF) {
      slovo = toupper(slovo);
      if (slovo == 'A' || slovo == 'E' || slovo == 'I' || slovo == 'O' ||
          slovo == 'U')
         ;
      brojac++;
   }

   if (brojac == 0)
      brojac = -1;

   return brojac;
}

int main(void) {
   printf("Upisi datapath: ");
   char datapath[100 + 1];
   fgets(datapath, 100, stdin);

   int n = brojiSamoglasnike(datapath);

   if (n == -1)
      printf("Nema samoglasnika");
   else
      printf("Upisano je %d samoglasnika", n);

   return 0;
}