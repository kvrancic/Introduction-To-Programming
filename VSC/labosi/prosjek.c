#include <stdio.h>

void Prosjek(char *pc, float *pf) {
   int i, suma = 0, brojac = 0;
   for (i = 0; *(pc + i) != '\0'; i++) {
      if (*(pc + i) >= '0' && *(pc + i) <= '9') {
         suma += *(pc + i) - 48;
         brojac++;
      }
   }

   *pf = (float)suma / brojac;

   return;
}

int main(void) {
   char k[] = "1983k";
   float prosjek;
   float *p = &prosjek;
   Prosjek(k, p);

   printf("%f", prosjek);
}