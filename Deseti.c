#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Napišite C program koji æe omoguæiti unošenje imena, prezimena, prosjeka i 
datuma roðenja za n uèenika jednog razreda. Ispisati koji uèenik ima najbolji prosjek. 
(Uèenike upisati u polje od najviše 20 elemenata.) Pripazite na velièinu podatka za matièni 
broj te format zapisa datuma (toèke nakon dana, mjeseca i godine).  */

typedef struct ucenik {
    char ime[20];
    char prezime[30];
    float prosjek;
}UCENIK;

int main() {

    UCENIK ucenici[20];
    int i, n;

    printf("Unesite broj ucenika (maksimalno 20): ");
    do {
        scanf("%d", &n);
        getchar();
        if (n < 2 || n > 20) {
            printf("Krivi unos, ponovno molim: ");
        }
    } while (n < 2 || n > 20);

    for (i = 0; i < n; i++) {
        printf("Ime %d. ucenika: ", i + 1);
        fgets(ucenici[i].ime, 20, stdin);

        //sklanjanje '\n' znaka koji ostane od fgets-a
        size_t im = strlen(ucenici[i].ime);
        if (im > 0 && ucenici[i].ime[im - 1] == '\n') {
            ucenici[i].ime[--im] = '\0';
        }

        printf("Prezime %d. ucenika: ", i + 1);
        fgets(ucenici[i].prezime, 30, stdin);
        
        //sklanjanje '\n' znaka koji ostane od fgets-a
        size_t pr = strlen(ucenici[i].prezime);
            if (pr > 0 && ucenici[i].prezime[pr - 1] == '\n') {
                ucenici[i].prezime[--pr] = '\0';
            }

        printf("Prosjek %d. ucenika: ", i + 1);
        scanf("%f", &ucenici[i].prosjek);
        getchar();
    }

    float max_prosjek = 0;
    int max = 0;
    for (i = 0; i < n; i++) {
        if (ucenici[i].prosjek > max_prosjek) {
            max_prosjek = ucenici[i].prosjek;
            max = i;
        }
    }

    printf("Ucenik s max prosjekom je: %s %s, a prosjek im je: %.2f\n",
        ucenici[max].ime, ucenici[max].prezime, ucenici[max].prosjek);

    return 0;
}
