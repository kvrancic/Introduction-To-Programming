#include <math.h>
#include <stdio.h>

double itiClan(int i) {
   double izraz = 1 / (((double)(4 * i - 1)) * (4 * i + 1));

   return izraz;
}

double piKaoSumaReda(int n) {
   double suma = 0;
   for (int i = 1; i <= n; i++) {
      suma = suma + itiClan(i);
   }

   double pi = -(8 * suma - 4);

   return pi;
}

int main(void) {
   int n;
   printf("Upisi prirodni broj n >");
   scanf("%d", &n);

   printf("Pi pomocu sume reda > %lf\n", piKaoSumaReda(n));
   printf("Pi pomocu asin > %lf\n", 2 * asin(1.));
   printf("Razlika > %lf", piKaoSumaReda(n) - 2 * asin(1.));

   return 0;
}