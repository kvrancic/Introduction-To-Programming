#include <stdio.h>

void sort1D(int *p, _Bool silazno, int dimenzija) {
   int i, j, pom;

   if (silazno == 0) {
      for (i = 0; i < dimenzija; i++) {
         for (j = i + 1; j < dimenzija; j++) {
            if (*(p + j) < *(p + i)) {
               pom = *(p + j);
               *(p + j) = *(p + i);
               *(p + i) = pom;
            }
         }
      }
   } else {
      for (i = 0; i < dimenzija; i++) {
         for (j = i + 1; j < dimenzija; j++) {
            if (*(p + j) > *(p + i)) {
               pom = *(p + j);
               *(p + j) = *(p + i);
               *(p + i) = pom;
            }
         }
      }
   }
}

int main(void) {
   char smjer;
   printf("Upisite smjer poretka (S-silazno) > ");
   scanf("%c", &smjer);
   _Bool silazno = 0;

   if (smjer == 'S')
      silazno = 1;

   int dimenzija;
   printf("Upisite dimenziju > ");
   scanf("%d", &dimenzija);

   int niz[dimenzija];
   printf("Upisite clanove > ");
   for (int i = 0; i < dimenzija; i++)
      scanf("%d", &niz[i]);

   int *p = niz;
   sort1D(p, silazno, dimenzija);

   for (int i = 0; i < dimenzija; i++)
      printf("%d ", niz[i]);

   return 0;
}