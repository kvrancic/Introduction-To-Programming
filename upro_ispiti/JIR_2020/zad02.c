#include <stdio.h>
#define N 5

int brojBodovaTima(int *matrix, int n, int team) {
    int sum = 0;
    for (int opponent = 0; opponent < n; opponent++) {
        if (opponent == team) {
            continue;
        }
        int teamGoals = *(matrix + team * n + opponent);
        int opponentGoals = *(matrix + opponent * n + team);
        // printf("Us: %2d - Them: %2d\n", teamGoals, opponentGoals);
        if (teamGoals > opponentGoals) {
            sum += 2;
        } else if (teamGoals == opponentGoals) {
            sum += 1;
        }
    }
    // printf("Bodovi: %2d\n\n", sum); za provjeru
    return sum;
}

int main(void) {
    int matrix[N][N] = {
        {0 , 29, 12, 34, 5 },
        {13, 0 , 24, 7 , 3 },
        {4 , 32, 0 , 5 , 23},
        {29, 10, 17, 0 , 34},
        {15, 23, 26, 31, 0 },
    };
    
    // trazenje maksimuma (i minimuma), uvijek ovako izgleda:
    int maxI = 0, maxVal = brojBodovaTima(&matrix[0][0], N, 0);
    for (int i = 1; i < N; i++) {
        int newVal = brojBodovaTima(&matrix[0][0], N, i);
        if (newVal > maxVal) { // koristi >= ako ti treba s NAJVECIM indeksom
            maxI = i;
            maxVal = newVal;
        }
    }
    printf("%d", maxI);
    
}
