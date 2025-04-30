/* Deklarirati strukturu stan koja ima èlanove: površina, cijena, adresa, energetski razred, klima
ureðaj [1/0]. Omoguæiti korisniku unos podataka za željeni broj stanova (max. 20) u polje struktura.
Ponavljati unos dokle god je željeni broj manji od 2, a veæi od 20. Ispisati podatke o svim unesenim
stanovima kod kojih je cijena po kvadratu manja od 900 eura i sve stanove kojima je cijena veæa od
1100 eura po kvadratu, a nemaju klima ureðaj.
Ako nema takvih stanova ispisati tekst: „Niti jedan stan ne odgovara kriterijima.“, a ako ima takvih
stanova ispisati ih u formatu „adresa, cijena“ za svaki takav stan u novi red.   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float povrsina;
    float cijena;
    char adresa[100];
    char energetski_razred;
    int klima_uredaj;
} STAN;

int main() {
    STAN stanovi[20];
    int n;

    do {
        printf("Unesite broj stanova (2-20): ");
        scanf("%d", &n);
    } while (n < 2 || n > 20);

    for (int i = 0; i < n; i++) {
        printf("Unos podataka za stan %d:\n", i + 1);
        printf("Povrsina (m^2): ");
        scanf("%f", &stanovi[i].povrsina);
        printf("Cijena (€): ");
        scanf("%f", &stanovi[i].cijena);
        printf("Adresa: ");
        getchar(); // uklanja zaostali newline od scanf-a
        fgets(stanovi[i].adresa, 100, stdin);
        stanovi[i].adresa[strcspn(stanovi[i].adresa, "\n")] = 0; // uklanja newline iz adrese
        printf("Energetski razred (A-F): ");
        scanf(" %c", &stanovi[i].energetski_razred);
        printf("Ima li klima uredaj? (1 - Da, 0 - Ne): ");
        scanf("%d", &stanovi[i].klima_uredaj);
    }

    int postoji_jeftin = 0, postoji_skup = 0;

    printf("\nStanovi s cijenom po kvadratu manjom od 900 €/m^2:\n");
    for (int i = 0; i < n; i++) {
        if ((stanovi[i].cijena / stanovi[i].povrsina) < 900) {
            printf("%s, %.2f €\n", stanovi[i].adresa, stanovi[i].cijena);
            postoji_jeftin = 1;
        }
    }
    if (!postoji_jeftin) {
        printf("Niti jedan stan ne odgovara kriterijima.\n");
    }

    printf("\nStanovi s cijenom po kvadratu veæom od 1100 €/m^2 i bez klima ureðaja:\n");
    for (int i = 0; i < n; i++) {
        if ((stanovi[i].cijena / stanovi[i].povrsina) > 1100 && stanovi[i].klima_uredaj == 0) {
            printf("%s, %.2f €\n", stanovi[i].adresa, stanovi[i].cijena);
            postoji_skup = 1;
        }
    }
    if (!postoji_skup) {
        printf("Niti jedan stan ne odgovara kriterijima.\n");
    }

    return 0;
}
