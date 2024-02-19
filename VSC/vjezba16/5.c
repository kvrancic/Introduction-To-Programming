#include <math.h>
#include <stdio.h>

void korijeni(unsigned int n, double *pa, double *pb, double *pc);

int main(void) {
   unsigned int n;
   double a, b, c;
   printf("Upisite nenegativni cijeli broj > ");
   scanf("%d", &n);

   int *p = &n;
   korijeni(n, &a, &b, &c);

   printf("Rezultati su:\n%.8lf\n%.8lf\n%.8lf", a, b, c);
}

void korijeni(unsigned int n, double *pa, double *pb, double *pc) {
   *pa = sqrt(n);
   *pb = pow(n, 1. / 3);
   *pc = pow(n, 0.2);

   return;
}