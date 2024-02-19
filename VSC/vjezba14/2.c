#include <stdio.h>

int sumaznambroja(int i);
int sumaznamnizabrojeva(int n, int djeljivost);

int main(void) {
   int n;
   printf("Upisite broj n > ");
   scanf("%d", &n);
   printf("Suma S1: %d\n", sumaznamnizabrojeva(n, 0));
   printf("Suma S2: %d\n", sumaznamnizabrojeva(n, 1));

   return 0;
}

int sumaznamnizabrojeva(int n, int djeljivost) {
   int suma = 0;
   if (djeljivost == 0) {
      for (int i = 1; i <= n; i++) {
         if (i % 7 == 0)
            suma = suma + sumaznambroja(i);
      }
   } else {
      for (int i = 1; i <= n; i++) {
         if (i % 7 != 0)
            suma = suma + sumaznambroja(i);
      }
   }

   return suma;
}

int sumaznambroja(int i) {
   int suma = 0;
   while (i > 0) {
      suma = suma + i % 10;
      i = i / 10;
   }

   return suma;
}