/* Omoguæiti korisniku unos dimenzije kvadratne matrice (2-D polja) realnih brojeva m × m, gdje je
3 < m < 16 te potom popunjavanje matrice. Pronaæi i na ekran ispisati element matrice iznad
sporedne dijagonale s najmanjom vrijednosti te element ispod glavne dijagonale s najveæom
vrijednosti. */

#include <stdio.h>

int main() {
    int m;
    do {
        scanf("%d", &m);
    } while (m < 3 || m > 9);

    int M[16][16];
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    printf("Matrica M: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    //provjera najmanjeg elementa iznad sporedne dijagonale M[i][m - 1 - i]
    int najmanja = M[0][0], najveca = M[0][0];
    for (int i = 0; i < m - 1; i++) {
        for (int j = m - i; j < m; j++) {
            if (M[i][j] < najmanja) {
                najmanja = M[i][j];
            }
        }
    }

    //provjera najveceg elementa ispod glavne dijagonale M[i][i]
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (M[i][j] > najveca) {
                najveca = M[i][j];
            }
        }
    }
    printf("Najveca: %d, a najmanja: %d", najveca, najmanja);

    return 0;
}