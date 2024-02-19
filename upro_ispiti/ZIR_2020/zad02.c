#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *slucajni(char *niz, int n) {
    // osigurati da se inicijalizacija dogodi samo jednom
    static _Bool inicijaliziran = 0;
    if (!inicijaliziran) {
        srand((unsigned int) time(NULL));
        inicijaliziran = 1;
        // rand(); Slaba rasprsenost prvog gen. broja na Windowsima? Ovo pomaze
    }
    return (int) ((double) rand() / (RAND_MAX + 1U) * n) + niz;
}

int main(void) {
    char niz[] = "Krivotvoritelji diploma";
    char *start = slucajni(niz, 24);
    char *stop = slucajni(niz, 24);
    if (stop - start < 2) {
        printf("Nema znakova");
        return 0;
    }
    for (start++; start < stop; start++) {
        printf("%c", *start);
    }
    return 0;
}