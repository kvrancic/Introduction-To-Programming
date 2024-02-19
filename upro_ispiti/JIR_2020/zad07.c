#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rezultat = 1, vrijednost;
    scanf("%d", &vrijednost);
    
    switch (vrijednost) {
        case 0:
            rezultat = 0;
            break;
        case 1:
        case 2:
        case 3:
        case 9:
            rezultat += 7;
            break;
        case 7:
        case 10:
            rezultat += 10;
        default:
            rezultat += 5;
    }
    
    printf("%d", rezultat);
    
    rezultat = 1;
    // pocetak rjesenja:
    if (vrijednost == 0) {
        rezultat = 0;
    } else if (vrijednost > 0 && vrijednost < 4 || vrijednost == 9) {
        rezultat += 7;
    } else {
        if (vrijednost == 7 || vrijednost == 10) {
            rezultat += 10;
        }
        rezultat += 5;
    }
    // kraj rjesenja
    printf(" %d", rezultat);ž
    
    // Svaki else-if obuhvaca sve slucajeve izmedju dvije break naredbe
}
