#include <stdio.h>

typedef struct {
   int sifra;
   char rijec[20 + 1];
} binarni;

int main(void) {
   binarni bin = {0};
   FILE *ulazT = fopen("recenice.txt", "r");
   FILE *ulazB = fopen("rijeci.bin", "rb");

   int sifraT;
   int n;
   while (fscanf(ulazT, " %d", &n) == 1) {
      for (int i = 0; i < n; i++) {
         fscanf(ulazT, ",%d", &sifraT);
         fseek(ulazB, 0L, SEEK_SET);
         while (fread(&bin, sizeof(binarni), 1, ulazB) == 1) {
            if (bin.sifra == sifraT) {
               printf("%s ", bin.rijec);
               break;
            }
         }
      }
      printf("\n");
   }

   return 0;
}