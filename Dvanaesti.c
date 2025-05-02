/* Napisati C program koji æe omoguæiti zauzimanje memorije za dvodimenzionalno polje cjelobrojnih vrijednosti tipa short duljine m redova 
i stupaca. Unutar dvodimenzionalnog polja potrebno je ispod sporedne dijagonale pronaæi najveæi parni broj i tim parnim brojem prepisati sve
vrijednosti iznad sporedne dijagonale. Ispisati novonastalo dvodimenzionalno polje. Popuniti dvodimenzionalno polje pseudo - sluèajnim 
vrijednostima, kao i varijablu m. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

short** zauzimanjeMatrice(int m) {
    short** matrica = (short**)malloc(m * sizeof(short*));
    for (int i = 0; i < m; i++) {
        *(matrica + i) = (short*)malloc(m * sizeof(short));
    }
    return matrica;
}

void brisanjeMatrice(int m, short** matrica) {
    for (int i = 0; i < m; i++) {
        free(*(matrica + i));
    }
    free(matrica);
}

void popunjavanjeMatrice(int m, short** matrica) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            *(*(matrica + i) + j) = rand() % 2101 - 1550;
        }
    }
}

void ispisMatrice(int m, short** matrica) {
    printf("Matrica:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d ", *(*(matrica + i) + j));
        }
        printf("\n");
    }
}

short najveciParniBroj(int m, short** matrica) {
    short max_parni = -1551;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j < m - 1) {
                if (*(*(matrica + i) + j) % 2 == 0) {
                    if (*(*(matrica + i) + j) > max_parni) {
                        max_parni = *(*(matrica + i) + j);
                    }
                }
            }
        }
    }
    return max_parni;
}

void novaMatrica(int m, short** matrica, short max_parni) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j > m - 1) {
                *(*(matrica + i) + j) = max_parni;
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int m = rand() % (8 - 3 + 1) + 3;
    printf("--> m nam je: %d\n", m);

    short** polje2d = zauzimanjeMatrice(m);

    popunjavanjeMatrice(m, polje2d);
    ispisMatrice(m, polje2d);

    short max_parni = najveciParniBroj(m, polje2d);

    novaMatrica(m, polje2d, max_parni);
    printf("\nNovo polje je:\n");
    ispisMatrice(m, polje2d);

    brisanjeMatrice(m, polje2d);

    return 0;
}
