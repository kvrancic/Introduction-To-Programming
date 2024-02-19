#include <stdio.h>
#include <string.h>

int main(void) {
   char ime[60], zanr[20];
   int godina;

   FILE *ulaz = fopen("filmovi.txt", "r");
   FILE *drama = fopen("drama.txt", "w");
   FILE *komedija = fopen("komedija.txt", "w");
   FILE *sf = fopen("sf.txt", "w");

   while (fscanf(ulaz, " %[^|]|%[^|]|%d", ime, zanr, &godina) == 3) {
      if (strcmp(zanr, "drama") == 0) {
         fprintf(drama, "%s, %d\n", ime, godina);
      }
      if (strcmp(zanr, "komedija") == 0) {
         fprintf(komedija, "%s, %d\n", ime, godina);
      }
      if (strcmp(zanr, "SF") == 0) {
         fprintf(sf, "%s, %d\n", ime, godina);
      }
   }

   fclose(ulaz);
   fclose(drama);
   fclose(komedija);
   fclose(sf);
}