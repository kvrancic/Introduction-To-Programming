#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[15] = "student";
    char s2[4] = "aCl"; // nisam siguran da bas to pise, ali valjda da
    printf("%s", strcpy(&s1[8], s2));
}

