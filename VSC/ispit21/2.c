#include <stdio.h>

void ispisPodnizova(char *niz, char *pointer) {
   int razlika = pointer - niz;
   for (int i = 0; i <= razlika; i++) {
      printf("%c", *(pointer - i));
   }
   printf("\n");

   int j = 0;
   for (j = 0; *(niz + j) != '\0'; j++)
      ;

   for (int i = j - razlika; i >= 0; i--) {
      printf("%c", *(pointer + i));
   }

   return;
}

int main(void) {
   char niz[20] = "Abrazivni materijal";
   char *pointer = niz + 12;
   ispisPodnizova(niz, pointer);

   return 0;
}