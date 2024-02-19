#include <stdio.h>
#include <math.h>

typedef struct {
    double X, Y;
} s_tocka;

double racUdaljenost(s_tocka *tocke, int n) {
    double sum = 0;
    for (int i = 1; i < n; i++, tocke++) {
        sum += sqrt(
            pow(tocke->X - (tocke + 1)->X, 2) +
            pow(tocke->Y - (tocke + 1)->Y, 2)
        );
    }
    return sum;
}

int main(void) {
    s_tocka tocke[] = {{2, 4}, {5, 0}, {0, 0}};
    printf("%.2lf", racUdaljenost(tocke, 3));
    
}