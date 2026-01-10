#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"

void wyswietlMenu() {
    printf("\n=== SYSTEM BAZY DANYCH ===\n");
    printf("1. Dodaj wpis\n");
    printf("2. Wyswietl wszystko\n");
    printf("3. Zapisz do pliku\n");
    printf("4. Wczytaj z pliku\n");
    printf("5. Szukaj (ID)\n");
    printf("6. Szukaj (Nazwa)\n");
    printf("7. Edytuj wpis\n");
    printf("8. Usun wpis\n");
    printf("9. Sortuj (Nazwa)\n");
    printf("10. Sortuj (Wartosc)\n");
    printf("0. Wyjscie\n");
    printf("Wybor: ");
}

void dodajRekord(Rekord *baza, int *licznik) {
    if (*licznik >= MAX_REKORDOW) {
        printf("[BLAD] Baza pelna!\n");
        return;
    }
    printf("ID: "); scanf("%d", &baza[*licznik].id);
    printf("Nazwa: "); scanf("%s", baza[*licznik].nazwa);
    printf("Wartosc: "); scanf("%f", &baza[*licznik].wartosc);
    (*licznik)++;
    printf("[OK] Dodano.\n");
}

void wyswietlWszystkie(const Rekord *baza, int licznik) {
    if (licznik == 0) { printf("[INFO] Pusto.\n"); return; }
    printf("\nID | NAZWA | WARTOSC\n");
    printf("----------------------\n");
    for (int i = 0; i < licznik; i++) {
        printf("%d | %s | %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
    }
}

void zapiszDoPliku(const Rekord *baza, int licznik) {
    FILE *f = fopen(PLIK_DANE, "w");
    if (!f) return;
    fprintf(f, "%d\n", licznik);
    for (int i = 0; i < licznik; i++) 
        fprintf(f, "%d %s %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
    fclose(f);
    printf("[OK] Zapisano.\n");
}

void wczytajZPliku(Rekord *baza, int *licznik) {
    FILE *f = fopen(PLIK_DANE, "r");
    if (!f) return;
    fscanf(f, "%d", licznik);
    for (int i = 0; i < *licznik; i++) 
        fscanf(f, "%d %s %f", &baza[i].id, baza[i].nazwa, &baza[i].wartosc);
    fclose(f);
}

void wyszukajPoID(const Rekord *baza, int licznik) {
    int id; printf("Podaj ID: "); scanf("%d", &id);
    for(int i=0; i<licznik; i++) {
        if(baza[i].id == id) {
            printf("ZNALEZIONO: %s (%.2f)\n", baza[i].nazwa, baza[i].wartosc);
            return;
        }
    }
    printf("Brak rekordu.\n");
}

void wyszukajPoNazwie(const Rekord *baza, int licznik) {
    char s[50]; printf("Podaj nazwe: "); scanf("%s", s);
    for(int i=0; i<licznik; i++) {
        if(strstr(baza[i].nazwa, s))
            printf("%d | %s | %.2f\n", baza[i].id, baza[i].nazwa, baza[i].wartosc);
    }
}


void usunRekord(Rekord *baza, int *licznik) {
    int id, found = -1;
    printf("Podaj ID do usuniecia: "); scanf("%d", &id);
    
    // 1. Szukamy indeksu
    for (int i = 0; i < *licznik; i++) {
        if (baza[i].id == id) { found = i; break; }
    }
    
    if (found == -1) { printf("[BLAD] Nie ma takiego ID.\n"); return; }

    // 2. Przesuwamy reszte tablicy w lewo (zasypujemy dziure)
    for (int i = found; i < *licznik - 1; i++) {
        baza[i] = baza[i+1];
    }
    
    (*licznik)--;
    printf("[OK] Usunieto rekord ID %d.\n", id);
}

void edytujRekord(Rekord *baza, int licznik) {
    int id;
    printf("Podaj ID do edycji: "); scanf("%d", &id);
    
    for (int i = 0; i < licznik; i++) {
        if (baza[i].id == id) {
            printf("Stara nazwa: %s. Nowa: ", baza[i].nazwa);
            scanf("%s", baza[i].nazwa);
            printf("Stara wartosc: %.2f. Nowa: ", baza[i].wartosc);
            scanf("%f", &baza[i].wartosc);
            printf("[OK] Zaktualizowano.\n");
            return;
        }
    }
    printf("[BLAD] Nie znaleziono ID.\n");
}

void sortujPoNazwie(Rekord *baza, int licznik) {
    // Sortowanie babelkowe
    for (int i = 0; i < licznik - 1; i++) {
        for (int j = 0; j < licznik - 1 - i; j++) {
            if (strcmp(baza[j].nazwa, baza[j+1].nazwa) > 0) {
                Rekord temp = baza[j];
                baza[j] = baza[j+1];
                baza[j+1] = temp;
            }
        }
    }
    printf("[OK] Posortowano alfabetycznie.\n");
    wyswietlWszystkie(baza, licznik);
}

void sortujPoWartosci(Rekord *baza, int licznik) {
    for (int i = 0; i < licznik - 1; i++) {
        for (int j = 0; j < licznik - 1 - i; j++) {
            if (baza[j].wartosc > baza[j+1].wartosc) { // Tu zmieniamy warunek
                Rekord temp = baza[j];
                baza[j] = baza[j+1];
                baza[j+1] = temp;
            }
        }
    }
    printf("[OK] Posortowano wedlug wartosci.\n");
    wyswietlWszystkie(baza, licznik);
}
