#include <stdio.h>

int main(void) {
   int n;
   printf("Upisi cijeli broj n > ");
   scanf("%d", &n);

   FILE *ulaz = fopen("fibonacci.bin", "rb");
   int broj;
   for (int i = 0; i < n; i++) {
      fread(&broj, sizeof(int), 1, ulaz);
      printf("%d\n", broj);
   }

   fclose(ulaz);
   return 0;
}