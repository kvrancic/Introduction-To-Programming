#include <stdio.h>

int main(void) {
   int m = 1080033280;
   void *p1;
   p1 = &m;
   printf("%f\n", *(float *)p1);

   return 0;
}