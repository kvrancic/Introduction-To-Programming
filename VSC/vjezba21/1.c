#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
   srand((unsigned int)time(NULL));

   int brojac[3] = {};
   for (int i = 0; i < 1000; i++) {
      int x = rand() % 95 + 32;
      if (isdigit(x))
         brojac[1]++;
      else {
         if (toupper(x) >= 'A' && toupper(x) <= 'Z')
            brojac[0]++;
         else
            brojac[2]++;
      }
   }

   printf("Slova: %d\nZnamenke: %d\nOstali: %d", brojac[0], brojac[1],
          brojac[2]);
}