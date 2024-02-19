unsigned long long factorial(unsigned int n) {
   unsigned long long faktorijela = 1;
   for (int i = 2; i <= n; i++)
      faktorijela = faktorijela * i;

   return faktorijela;
}

_Bool maclaurin_exp(double x, unsigned int n, double *e) {
   double rezultat = 0, suma = 0;

   for (int i = 0; i <= n; i++) {
      rezultat = (1 / factorial(n)) * pow(x, i);
      suma = suma + rezultat;
   }

   *e = suma;
   _Bool izlaz;

   if (n >= 0 && n <= 15) {
      izlaz = 1;
      *e = suma;
   } else {
      izlaz = 0;
      *e = 0;
   }

   return izlaz;
}