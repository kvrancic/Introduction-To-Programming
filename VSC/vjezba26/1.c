#include <stdio.h>
#define MAXLIN 7
int main(void) {
   char redak[MAXLIN];
   FILE *du = fopen("podaci.txt", "r");
   FILE *di = fopen("izlaz.txt", "w");
   while (fgets(redak, MAXLIN, du) != NULL) {
      fputs(redak, di);
   }
   fclose(du);
   fclose(di);
   return 0;
}