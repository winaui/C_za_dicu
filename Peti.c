/* Napisati funkciju koja predano joj polje realnih brojeva popunjava pseudo-slučajnim
brojevima iz [−2n, 2n] \ [−n, 0] (vrijednosti iz [−n, 0] nisu dozvoljene), gdje je n
veličina polja. U svrhu testiranja u funkciji main() dinamički zauzeti memoriju za
800 podataka tipa float. Iskoristiti dobiveno polje pri pozivu napisane funkcije i
naknadno ispisati elemente polja na ekran. */

#include <stdio.h>
#include <stdlib.h>

void popuniPseudoSlucajnimBrojevima(float* polje, int n) {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++){
        do{
            polje[i] = ((float)rand() / RAND_MAX) * (4 * n) - (2 * n);
        }
    }
}

int main(){
    float* polje;
    int velicinaPolja = 800;

    polje = (float*)malloc(velicinaPolja * sizeof(float));
    if (polje == NULL) {
        fprintf(stderr, "Greška pri alokaciji memorije.\n");
        return 1;
        }

    popuniPseudoSlucajnimBrojevima(polje, velicinaPolja);
    printf("Elementi polja:\n");
    for (int i = 0; i < velicinaPolja; i++) {
        printf("%.2f ", polje[i]);
    }
    printf("\n");

    free(polje);

    return 0;
    }
