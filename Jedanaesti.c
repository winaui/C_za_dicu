/* Napišite C program koji za unos broja izmeðu 1 i 12 ispisuje pripadajuæi mjesec slovima, a ukoliko
je unesen broj veæi od 12 ili manji od 1, ispisuje se „Nekorektan broj mjeseca". Za inicijalizaciju
imena mjeseci koristiti polje pokazivaèa.   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    char* mjeseci[12] = { "Sijecanj", "Veljaca", "Ozujak" , "Travanj", "Svibanj", "Lipanj", "Srpanj", "Kolovoz",
"Rujan", "Listopad", "Studeni", "Prosinac" };
    int n;

    printf("Unesite broj mjeseca: ");
    do {
        scanf("%d", &n);
        if (n < 1 || n > 12) {
            printf("Taj mjesec ne postoji!! Molim unesite drugi broj: ");
        }
    } while (n < 1 || n > 12);

    printf("Mjesec je: %s.", mjeseci[n - 1]);

    return 0;
}

