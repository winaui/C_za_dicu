/* Napisati funkciju koja pretvara predani joj cijeli broj u binarni ekvivalent.
Funkcija vraæa binarni ekvivalent kao dekadski broj. Primjerice, za argument 29 funkcija
bi trebala vratiti 11101(10). Na kraju, na ekran ispisati povratnu vrijednost. */

#include <stdio.h>
#include <string.h>

void decimalno_u_binarno(int broj, char* binarni) {
    int i = 0;
    while (broj > 0) {
        binarni[i++] = (broj % 2) + '0';
        // '0' se dodaje da bi se int prebacio u char
        broj /= 2;
    }
    binarni[i] = '\0';  //kraj stringa

    //obrtanje stringa jer su brojevi uneseni "naopako"
    int len = strlen(binarni);
    for (int j = 0; j < len / 2; j++) {
        char temp = binarni[j];
        binarni[j] = binarni[len - j - 1];
        binarni[len - j - 1] = temp;
    }
}

int main() {
    int broj;
    char binarni[32];

    printf("Unesite broj: ");
    scanf("%d", &broj);

    decimalno_u_binarno(broj, binarni);
    printf("Binarni ekvivalent tog broja je: %s\n", binarni);

    return 0;
}
