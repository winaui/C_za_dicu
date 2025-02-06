/* Ispisati na ekran sve pozitivne troznamenkaste brojeve cija je
zadnja znamenka djeljiva s 3. Na kraju, dodatno ispisati aritmeticku
sredinu ispisanih brojeva. */

#include <stdio.h>

int main() {

    int counter = 0, zbroj = 0;
    int i;

    printf("Brojevi kojima je zadnja znam. djeljiva s 3:\n");
    for (i = 100; i < 1000; i++) {
        if ((i % 10) != 0 && (i % 10) % 3 == 0) {
            counter++;
            zbroj += i;
            printf("%d\t", i);
        }
    }

    float aritmeticka = zbroj / counter;
    printf("\n\nAritmeticka sredina tih brojeva je: %.2f.", aritmeticka);

    return 0;
}