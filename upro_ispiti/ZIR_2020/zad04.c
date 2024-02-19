#include <stdio.h>

typedef struct {
    double x;
    double y;
} tocka;

void transponiraj(tocka *tocke, int n, int *resPos, int *resNeg) {
    // semanticki slicne povratne vrijednosti pa ih obije vracamo preko
    // pokazivaca
    *resPos = 0; // postavimo brojace na 0
    *resNeg = 0;
    for (int i = 0; i < n; i++, tocke++) {
        // transponiranje
        double temp = tocke->x;
        tocke->x = tocke->y;
        tocke->y = temp;
        // povecanje brojaca ako su obije negativne ili pozitivne
        if (tocke->x > 0 && tocke->y > 0) {
            (*resPos)++;
        } else if (tocke->x < 0 && tocke->y < 0) {
            (*resNeg)++;
        }
    }
}

int main(void) {
    tocka tocke[] = {
        {-1, -2}, {1, 2}, {-1, -5}, {30, -9}, {-20, 4}, {22, 9}  
    };
    int resPos, resNeg;
    transponiraj(tocke, 6, &resPos, &resNeg);
    for (int i = 0; i < 6; i++) {
        printf("(%.2lf, %.2lf) ", tocke[i].x, tocke[i].y);
    }
    printf("\n%d %d", resPos, resNeg);
    
    return 0;
}