#include <stdio.h>
#include "zad03a.h"
#include "zad03b.h"

int main(void) {
    int broj;
    scanf("%d", &broj);
    while(jestPrimBroj(broj)) {
        printf("Jest prim broj\n");
        scanf("%d", &broj);
    }
    printf("Nije prim broj\n");
    return 0;
}