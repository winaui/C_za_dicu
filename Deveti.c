/*   Napisati C program koji æe ponuditi uèitavanje 10 toèaka u trodimenzionalnom prostoru. Kreirati
strukturu tocka s tri realna èlana x, y, z. Dinamièki zauzeti memoriju za polje toèaka (u potpunosti
rukovati memorijom). Program treba pronaæi i ispisati indeks i koordinate najviše toèke. Najviša
toèka je onaj koja ima najveæu z koordinatu. Koristiti iskljuèivo pokazivaèku notaciju. Koristiti
typedef */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    float x;
    float y;
    float z;
} TOCKA;

int main() {

    int i;

    TOCKA* tocke;
    tocke = (TOCKA*)malloc(10 * sizeof(TOCKA));
    if (tocke == NULL) {
        printf("Greska pri alokaciji memorije.\n");
        return 1;
    }

    printf("Unesite koordinate tocaka:\n");
    for (i = 0; i < 10; i++) {
        printf("Tocka %d: ", i + 1);
        scanf("%f %f %f", &(tocke[i].x), &(tocke[i].y), &(tocke[i].z));
    }

    int max_indeks = 0;
    for (i = 1; i < 10; i++) {
        if (tocke[i].z > tocke[max_indeks].z) {
            max_indeks = i;
        }
    }

    printf("Najvislja tocka je tocka %d s koordinatama (%.2f, %.2f, %.2f).\n",
        max_indeks + 1, tocke[max_indeks].x, tocke[max_indeks].y, tocke[max_indeks].z);

    free(tocke);

    return 0;
}