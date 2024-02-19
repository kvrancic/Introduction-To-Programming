#include <stdio.h>

typedef struct studOcjene {
   char jmbag[10];
   int ocjene[10];
   int brOcjena;
} studOcjene;

float prosjek(studOcjene s) {
   int rez = 0;
   for (int i = 0; i < s.brOcjena; i++) {
      rez += s.ocjene[i];
   }
   return (float)rez / s.brOcjena;
}

int main(void) {
   studOcjene s1 = {"0036541994", {5, 5, 4, 4}, 4};
   studOcjene s2 = {"0036541994", {2, 3, 4}, 3};
   printf("%.1f %.1f\n", prosjek(s1), prosjek(s2));
   return 0;
}