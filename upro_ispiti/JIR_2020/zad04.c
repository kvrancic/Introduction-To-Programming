#include <stdio.h>

int brojiBajtove(unsigned long long broj, unsigned const char uzorak) {
    int br = 0;
    // shiftanje bajt po bajt i usporedba desnog bajta s uzorkom
    for (int i = 0; i++ < 8; broj >>= 8) {
        if ((broj & 0xFF) == uzorak) {
            br++;
        }
    }
    return br;
}

int main(void) {
    unsigned long long broj = 0xA132A1E7A131A1FF;
    unsigned char uzorak = 0xA1;
    printf("broj: %llX; uzorak: %hX; rezultat: %d\n",
        broj, uzorak, brojiBajtove(broj, uzorak));
    broj = 0xFF7294DFF37CA5FF;
    uzorak = 0xFF;
    printf("broj: %llX; uzorak: %hX; rezultat: %d\n",
        broj, uzorak, brojiBajtove(broj, uzorak));
}