#include <stdio.h>

void kvadrat(int *matrica, int n) {
    for (int i = 0; i < n; i++) {
        // trazenje najmanje i najvece vrijednosti u retku, sablona
        int najmanji = *(matrica + i * n);
        int najveci = *(matrica + i * n);
        for (int j = 1; j < n; j++) { 
            if (najmanji > *(matrica + i * n + j)) {
                najmanji = *(matrica + i * n + j);
            } else if (najveci < *(matrica + i * n + j)) {
                najveci = *(matrica + i * n + j);
            }
        }
        // na svakoj poziciji u retku cija je vrijednost najveca ili najmanja
        // vrijednost matrice pretvoriti u 0
        for (int j = 0; j < n; j++) {
            if (najmanji == *(matrica + i * n + j) ||
                    najveci == *(matrica + i * n + j)) {
                *(matrica + i * n + j) = 0;
            }
        }
    }
}

int main(void) {
    int matrica[][4] = {
        {2, 1, 6, 7},
        {9, 5, 9, 5},
        {7, 2, 2, 4},
        {0, 2, 3, 6}
    };
    kvadrat(&matrica[0][0], 4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}