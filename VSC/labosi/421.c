#include <stdio.h>
#include <string.h>

#define f(a, b) a >> b

int main(void) {
   int i, x = 2, y = 5;

   for (i = 0; i < 3; i++) {
      printf(" %d ", f(x + y, i));
   }

   return 0;
}