#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main() {
    Rekord baza[MAX_REKORDOW];
    int licznik = 0;
    int wybor;

    wczytajZPliku(baza, &licznik);

    do {
        wyswietlMenu();
        if (scanf("%d", &wybor) != 1) {
            while(getchar() != '\n');
            wybor = -1;
        }

        switch (wybor) {
            case 1: dodajRekord(baza, &licznik); break;
            case 2: wyswietlWszystkie(baza, licznik); break;
            case 3: zapiszDoPliku(baza, licznik); break;
            case 4: wczytajZPliku(baza, &licznik); break;
            case 5: wyszukajPoID(baza, licznik); break;
            case 6: wyszukajPoNazwie(baza, licznik); break;
            case 7: edytujRekord(baza, licznik); break;
            case 8: usunRekord(baza, &licznik); break;
            case 9: sortujPoNazwie(baza, licznik); break;
            case 10: sortujPoWartosci(baza, licznik); break;
            case 0: 
                zapiszDoPliku(baza, licznik);
                printf("Koniec.\n"); 
                break;
            default: printf("Zla opcja.\n");
        }
    } while (wybor != 0);

    return 0;
}
