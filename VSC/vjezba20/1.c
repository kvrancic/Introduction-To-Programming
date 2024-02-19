#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   int n;
   do {
      printf("Upisite n > ");
      scanf("%d", &n);
   } while (n < 3 && n > 60);

   srand((unsigned int)time(NULL));
   for (int i = 0; i < n; i++)
      printf("%c", rand() % 26 + 65);
}
