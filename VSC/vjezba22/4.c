#include <stdio.h>

int main(void) {
   char c;
   while ((c = getc(stdin)) != EOF) {
      putc(c, stdout);
   }
   return 0;
}