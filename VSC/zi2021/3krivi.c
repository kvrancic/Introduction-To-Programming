#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
   double x;
   double y;
} tocka;

void genTocka(tocka *koordinate, double *udaljenost) {
   static _Bool prva = 0;
   static tocka prosla;

   koordinate->x = (double)rand() / RAND_MAX * 10;
   koordinate->y = (double)rand() / RAND_MAX * 10;

   if (!prva) {
      *udaljenost = sqrt(pow(koordinate->x, 2) + pow(koordinate->y, 2));
      prva = 1;
   } else {
      *udaljenost = sqrt(pow(koordinate->x - prosla.x, 2) +
                         pow(koordinate->y - prosla.y, 2));
   }
   prosla.x = koordinate->x;
   prosla.y = koordinate->y;

   return;
}

int main(void) {
   srand((unsigned int)time(NULL));
   tocka koordinatereal = {0};
   tocka *koordinate = &koordinatereal;
   double realudaljenost = 0.;
   double *udaljenost = &realudaljenost;
   for (int i = 0; i < 6; i++) {
      genTocka(koordinate, udaljenost);
      printf("%6f %6f %6f\n", koordinatereal.x, koordinatereal.y,
             realudaljenost);
   }
}