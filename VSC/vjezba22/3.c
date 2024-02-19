#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
   char s1[80], s2[80];
   int c;
   int i = 0;

   while ((c = getchar()) != 'X') {
      s1[i++] = c;
   }
   s1[i] = '\0';
   i = 0;
   while ((c = getchar()) != 'Y') {
      s2[i++] = c;
   }
   s2[i] = '\0';

   fputs(s1, stdout);
   fputs(s2, stdout);
}