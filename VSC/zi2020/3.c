#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
   _Bool istinitost;
   double broj;
} varijabla;

varijabla gen() {
   double n;
   static _Bool inicijaliziran = 0;
   static varijabla X = {0};

   if (inicijaliziran == 0) {
      X.istinitost = 0;
      srand((unsigned int)time(NULL));
      inicijaliziran = 1;
      X.broj = rand() / (RAND_MAX + 1U) * 9 + 1;
   } else {
      n = rand() / (RAND_MAX + 1U) * 9 + 1;
      if (n > X.broj) {
         X.istinitost = 1;
      }
   }

   n = X.broj;
   return X;
}