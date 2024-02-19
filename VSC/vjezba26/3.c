#include <stdio.h>
#include <string.h>

int main(void) {
   FILE *ulaz = fopen("osobe.txt", "r");

   char ime[20], prezime[20];
   int godina, broj;
   while (fscanf(ulaz, "%d %s %s %*d.%*d.%d", &broj, ime, prezime, &godina) ==
          4) {
      if (strstr(ime, "na") != NULL || godina == 1987)
         printf("%d %s %s\n", broj, ime, prezime);
   }

   fclose(ulaz);
   return 0;
}