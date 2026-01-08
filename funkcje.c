#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "funkcje.h"

void wyswietlMenu() {
    printf("\n--- MENU GLOWNE ---\n");
    printf("1. Dodaj nowy wpis\n");
    printf("2. Wyswietl baze danych\n");
    printf("3. Zapisz do pliku\n");
    printf("4. Wczytaj z pliku\n");
    printf("5. Wyszukaj po ID\n");
    printf("6. Wyszukaj po Nazwie\n");
    printf("0. Zakoncz program\n"); // Zmienilem wyjscie na 0
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

    fprintf(plik, "%d\n", licznik);
    for (int i = 0; i < licznik; i++) {
        fprintf(plik, "%d %s %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
    }
    fclose(plik);
    printf("[SUKCES] Dane zapisane.\n");
}

void wczytajZPliku(Rekord *baza, int *licznik) {
    FILE *plik = fopen(PLIK_DANE, "r");
    if (plik == NULL) {
        return; // Brak pliku to nie blad na starcie
    }

    fscanf(plik, "%d", licznik);
    for (int i = 0; i < *licznik; i++) {
        fscanf(plik, "%d %s %f", &baza[i].id, baza[i].nazwa, &baza[i].wartosc);
    }
    fclose(plik);
}

// --- NOWE FUNKCJE WYSZUKIWANIA ---

void wyszukajPoID(const Rekord *baza, int licznik) {
    int szukaneId;
    int znaleziono = 0;
    
    printf("Podaj ID do znalezienia: ");
    scanf("%d", &szukaneId);

    printf("\n--- WYNIKI WYSZUKIWANIA (ID: %d) ---\n", szukaneId);
    for (int i = 0; i < licznik; i++) {
        if (baza[i].id == szukaneId) {
            printf("%d | %s | %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
            znaleziono = 1;
        }
    }

    if (!znaleziono) printf("Nie znaleziono rekordu o takim ID.\n");
}

void wyszukajPoNazwie(const Rekord *baza, int licznik) {
    char szukanaNazwa[50];
    int znaleziono = 0;

    printf("Podaj fragment nazwy: ");
    scanf("%s", szukanaNazwa);

    printf("\n--- WYNIKI WYSZUKIWANIA (Nazwa: %s) ---\n", szukanaNazwa);
    for (int i = 0; i < licznik; i++) {
        // strstr sprawdza, czy szukanaNazwa zawiera sie w baza[i].nazwa
        if (strstr(baza[i].nazwa, szukanaNazwa) != NULL) {
            printf("%d | %s | %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
            znaleziono = 1;
        }
    }

    if (!znaleziono) printf("Nie znaleziono pasujacych rekordow.\n");
}
