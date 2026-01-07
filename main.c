#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main() {
    Rekord baza[MAX_REKORDOW];
    int licznik = 0;
    int wybor;

    printf("Uruchamianie systemu...\n");

    do {
        wyswietlMenu();
        if (scanf("%d", &wybor) != 1) {
            // Zabezpieczenie przed wpisaniem liter zamiast cyfr
            while(getchar() != '\n');
            wybor = 0;
        }

        switch (wybor) {
            case 1:
                dodajRekord(baza, &licznik);
                break;
            case 2:
                wyswietlWszystkie(baza, licznik);
                break;
            case 3:
                printf("Zamykanie...\n");
                break;
            default:
                printf("Nieznana opcja, sprobuj ponownie.\n");
        }
    } while (wybor != 3);

    return 0;
}
