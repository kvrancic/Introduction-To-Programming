#include "fibonacci.h"
#include <stdio.h>

int main(void) {
   int n;
   do {
      printf("Upisi cijeli broj ");
      scanf("%d", &n);
      if (n > 0) {
         resetFibonacci;
         for (int i = 0; i < n; i++)
            printf("%d\n", getNextFibonacci);
      }
   } while (n != 0);

   return 0;
}
