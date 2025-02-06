/* Napisati funkciju koja za predani joj cijeli broj racuna i vraca zbroj faktorijela znamenki.
Primjerice, za argument 234 funkcija bi trebala izracunati i vratiti
vrijednost 2! + 3! + 4! = 32. */

#include <stdio.h>

int faktorijel(int n) {
    if (n == 0 || n == 1) {
        return 1;
        //zatošto vrijedi 0! = 1 i 1! = 1
    }
    else {
        return n * faktorijel(n - 1);
    }
}

int zbrojFaktorijelZnamenki(int broj) {
    int zbroj = 0;

    while (broj > 0) {
        int znamenka = broj % 10;
        zbroj += faktorijel(znamenka);
        broj /= 10;
    }

    return zbroj;
}

int main() {
    int broj;

    printf("Unesite cijeli broj molim: ");
    scanf("%d", &broj);

    int fakt = zbrojFaktorijelZnamenki(broj);
    printf("\nFaktorijel tog broja je: %d", fakt);

    return 0;
}