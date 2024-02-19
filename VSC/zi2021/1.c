#include <stdio.h>

typedef struct {
   int sifra;
   char ime[30 + 1];
} potrosaci;

int main(void) {
   FILE *ulazT = fopen("potrosnja.txt", "r");
   FILE *ulazB = fopen("potrosac.bin", "r");

   potrosaci bin = {0};
   int sifra, mjesec, dan, godina;
   float kolicina;
   while (fscanf(ulazT, "%d %d.%d.%d. %f", sifra, dan, mjesec, godina,
                 kolicina) == 5) {
      if ((mjesec == 7 || mjesec == 8) && godina == 2020 && bin.ime[0] == 'J') {
         fseek(ulazB, (long)(sifra - 1) * sizeof(potrosaci), SEEK_SET);
         fread(&bin, sizeof(bin), 1, ulazB);
         printf("%6d %7.2f kWh %d.%d.%d. %s\n", sifra, kolicina, dan, mjesec,
                godina, bin.ime);
      }
   }

   fclose(ulazT);
   fclose(ulazB);

   return 0;
}
