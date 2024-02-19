int brojiZnamenke(char *niz) {
   int i = 0, brojac = 0;
   for (i = 0; *(niz + i) != '\0'; i++) {
      if (isdigit(*(niz + i)))
         brojac++;
   }

   return brojac;
}