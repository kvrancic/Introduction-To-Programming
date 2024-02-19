#include <stdio.h>

int sumaparnih(int x, int y);

int main(void) {
   int x, y;
   do {
      printf("Upisite dva prirodna broja > ");
      scanf("%d %d", &x, &y);
   } while (!(y > x && x > 0 && y > 0 && x < 100 && y < 100));

   int suma = sumaparnih(x, y);

   if (suma == 0)
      printf("Nema parnih znamenaka");
   else
      printf("Suma prnih znamenaka iznosi: %d", suma);

   return 0;
}

int sumaparnih(int x, int y) {
   int suma = 0;
   for (int i = x + 1; i < y; i++) {
      if (i % 2 == 0)
         suma = suma + i % 10;

      if (i > 9 && (i / 10) % 2 == 0)
         suma = suma + i / 10;
   }

   return suma;
}