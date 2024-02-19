#include "fibonacci.h"

static int x = 1;
static int y = 1;
static int new = 1;
static int brojac = 0;

void resetFibonacci() {
   x = 1;
   y = 1;
   new = 1;
   brojac = 0;
   return;
}

int getNextFibonacci() {
   if (brojac < 2) {
      new = 1;
   } else {
      x = y;
      y = new;
      new = x + y;
   }
   brojac++;
   printf("%d", new);

   return new;
}