#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
   double x;
   double y;
} tocka;

void genTocka(tocka *koordinate, double *udaljenost) {
   static tocka prosla = {0., 0.};

   koordinate->x = (double)rand() / RAND_MAX * 10.;
   koordinate->y = (double)rand() / RAND_MAX * 10.;
   *udaljenost = sqrt(pow(koordinate->x - prosla.x, 2.) +
                      pow(koordinate->y - prosla.y, 2.));
   prosla = *koordinate;

   return;
}

int main(void) {
   srand((unsigned int)time(NULL));

   tocka koordinate;
   double udaljenost;
   for (int i = 0; i < 6; i++) {
      genTocka(&koordinate, &udaljenost);
      printf("%6f %6f %6f\n", koordinate.x, koordinate.y, udaljenost);
   }
}
