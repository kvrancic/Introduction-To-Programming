#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double sinus(double x, unsigned long long int n);

int main(void) {
   double x;
   unsigned long long int n;
   printf("Upisite x i n ");
   scanf("%lf %llu", &x, &n);

   printf("sinus(%lf) = %lf\n", x, sinus(x, n));
   printf("sin(%lf) = %lf\nrazlika = %lf", x, sin(x), sin(x) - sinus(x, n));

   return 0;
}

double sinus(double x, unsigned long long int n) {
   double sinus = 0;
   unsigned long long int faktorijela = 1;
   int predznak = 1;
   for (int i = 1; i <= 2 * n - 1; i = i + 2) {
      faktorijela = 1;
      for (int j = 1; j <= i; j++) {
         faktorijela = faktorijela * j;
      }
      sinus = sinus + predznak * ((double)pow(x, i) / faktorijela);

      if (predznak == -1) {
         predznak = 1;
      } else {
         predznak = -1;
      }
   }

   return sinus;
}
