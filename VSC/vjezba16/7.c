#include <math.h>
#include <stdio.h>

void poredaj(double *pa, double *pb, double *pc);

int main(void) {
   double a, b, c;
   printf("Upisite 3 realna broja > ");
   scanf("%lf %lf %lf", &a, &b, &c);

   poredaj(&a, &b, &c);
   printf("%lf %lf %lf", a, b, c);
}

void poredaj(double *pa, double *pb, double *pc) {
   double pom;

   if (*pb < *pa) {
      pom = *pa;
      *pa = *pb;
      *pb = pom;
   }

   if (*pc < *pa) {
      pom = *pa;
      *pa = *pc;
      *pc = pom;
   }

   if (*pc < *pb) {
      pom = *pc;
      *pc = *pb;
      *pb = pom;
   }

   return;
}