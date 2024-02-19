#include "zad03a.h"

_Bool jestPrimBroj(int broj) {
    // eliminacija parnih brojeva i onih manjih od 2
    if (broj < 2 || broj % 2 == 0) { 
        return broj == 2;
    }
    // ako broj nema djelitelja izmedju 3 i sqrt(broj), prost je
    for (int i = 3; i * i <= broj; i += 2) {
        if (broj % i == 0) {
            return 0;
        }
    }
    return 1;
}