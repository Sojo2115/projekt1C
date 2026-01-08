#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void wyswietlMenu() {
    printf("\n--- MENU GLOWNE ---\n");
    printf("1. Dodaj nowy wpis\n");
    printf("2. Wyswietl baze danych\n");
    printf("3. Zapisz do pliku\n");
    printf("4. Wczytaj z pliku\n");
    printf("5. Zakoncz program\n");
    printf("Twoj wybor: ");
}

void dodajRekord(Rekord *baza, int *licznik) {
    if (*licznik >= MAX_REKORDOW) {
        printf("[BLAD] Baza jest pelna!\n");
        return;
    }
    
    printf("\n--- DODAWANIE ---\n");
    printf("Podaj ID: ");
    scanf("%d", &baza[*licznik].id);
    
    printf("Podaj Nazwe: ");
    scanf("%s", baza[*licznik].nazwa);
    
    printf("Podaj Wartosc: ");
    scanf("%f", &baza[*licznik].wartosc);
    
    (*licznik)++;
    printf("[SUKCES] Rekord dodany.\n");
}

void wyswietlWszystkie(const Rekord *baza, int licznik) {
    if (licznik == 0) {
        printf("[INFO] Baza jest pusta.\n");
        return;
    }
    
    printf("\n--- LISTA REKORDOW ---\n");
    printf("ID | NAZWA | WARTOSC\n");
    for (int i = 0; i < licznik; i++) {
        printf("%d | %s | %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
    }
}

void zapiszDoPliku(const Rekord *baza, int licznik) {
    FILE *plik = fopen(PLIK_DANE, "w");
    if (plik == NULL) {
        printf("[BLAD] Nie mozna otworzyc pliku do zapisu!\n");
        return;
    }

    // Zapisujemy ilosc rekordow jako pierwsza liczbe
    fprintf(plik, "%d\n", licznik);

    for (int i = 0; i < licznik; i++) {
        fprintf(plik, "%d %s %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
    }

    fclose(plik);
    printf("[SUKCES] Dane zapisane do pliku %s.\n", PLIK_DANE);
}

void wczytajZPliku(Rekord *baza, int *licznik) {
    FILE *plik = fopen(PLIK_DANE, "r");
    if (plik == NULL) {
        printf("[INFO] Brak pliku z danymi lub blad odczytu.\n");
        return;
    }

    // Wczytujemy liczbe rekordow
    fscanf(plik, "%d", licznik);

    for (int i = 0; i < *licznik; i++) {
        fscanf(plik, "%d %s %f", &baza[i].id, baza[i].nazwa, &baza[i].wartosc);
    }

    fclose(plik);
    printf("[SUKCES] Wczytano %d rekordow z pliku.\n", *licznik);
}
