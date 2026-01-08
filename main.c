#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main() {
    Rekord baza[MAX_REKORDOW];
    int licznik = 0;
    int wybor;

    // Automatyczne wczytanie danych na starcie
    wczytajZPliku(baza, &licznik);

    do {
        wyswietlMenu();
        if (scanf("%d", &wybor) != 1) {
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
                zapiszDoPliku(baza, licznik);
                break;
            case 4:
                wczytajZPliku(baza, &licznik);
                break;
            case 5:
                // Automatyczny zapis przy wyjsciu
                zapiszDoPliku(baza, licznik);
                printf("Zamykanie...\n");
                break;
            default:
                printf("Nieznana opcja.\n");
        }
    } while (wybor != 5);

    return 0;
}
