/*  Napisati C program koji æe od korisnika tražiti unos cijelog broja n te u datoteku naziva suma.txt
upisati sumu njegovih znamenaka. Za traženje sume znamenaka broja koristiti rekurziju.  */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int funkcija(int x) {
    if (x == 0) {
        return x;
    }
    else {
        return x % 10 + funkcija(x / 10);
    }
}


int main(void) {

    int x;
    printf("Unesite viseznamenkasti broj: ");
    scanf("%d", &x);

    FILE* pFile = fopen("suma.txt", "w");
    int rezultat = funkcija(x);
    fprintf(pFile, "%d", rezultat);
    printf("Suma znamenki je: %d", rezultat);

    return 0;
}