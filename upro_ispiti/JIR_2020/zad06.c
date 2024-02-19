#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned int) time(NULL));
    int rezultat = (int)(rand() * 1.0 / (RAND_MAX + 1U) * 30000 + 1);
    printf("%d", rezultat);
}
