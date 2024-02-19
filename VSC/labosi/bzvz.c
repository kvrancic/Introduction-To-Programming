#include <stdio.h>

int main(void) {
   int n[2][3] = {2, 3, 4, 5};
   int *p = &n[1][0];
   *(p + 2) = *p + *(p + 2);

   printf("%d", *(p + 2));
}