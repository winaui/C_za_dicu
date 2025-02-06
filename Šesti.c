/* Napisati funkciju koja elemente predanog joj polja cijelih brojeva mijenja na sljedeći
način: elemente manje od aritmetičke sredine svih elemenata polja zamjenjuje s
tom istom aritmetičkom sredinom. Korak izračuna aritmetičke sredine elemenata
polja izdvojiti u zasebnu funkciju. U svrhu testiranja u funkciji main() omogućiti
korisniku unos 3 < n ≤ 16 elemenata u polje cijelih brojeva. Iskorisiti popunjeno
polje u pozivu napisane funkcije te ispisati izmijenjeno polje na ekran. Koristiti
isključivo pokazivačku notaciju za pristup elementima polja. */

#include <stdio.h>

float aritmetickaSredina(int* polje, int n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
        suma += polje[i];
    }

    return (float)suma / n;
}

void zamijeniElemente(int* polje, int n) {
    float avg = aritmetickaSredina(polje, n);

    for (int i = 0; i < n; i++) {
        if (polje[i] < avg) {
            polje[i] = (int)avg;
        }
    }
}

int main() {
    int n;

    do {
        printf("Unesite broj elemenata (3 < n <= 16): ");
        scanf("%d", &n);
    } while (n <= 3 || n > 16);

    int polje[16];

    printf("Unesite %d cijelih brojeva:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &polje[i]);
    }

    zamijeniElemente(polje, n);

    printf("Izmijenjeno polje:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", polje[i]);
    }
    printf("\n");

    return 0;
}