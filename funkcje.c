#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void wyswietlMenu() {
    printf("\n--- MENU GLOWNE ---\n");
    printf("1. Dodaj nowy wpis\n");
    printf("2. Wyswietl baze danych\n");
    printf("3. Zakoncz program\n");
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
