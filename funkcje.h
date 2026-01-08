#ifndef FUNKCJE_H
#define FUNKCJE_H

// --- DEFINICJE I STRUKTURY ---
#define MAX_REKORDOW 100
#define PLIK_DANE "baza.txt"

typedef struct {
    int id;
    char nazwa[50];
    float wartosc;
} Rekord;

// --- DEKLARACJE FUNKCJI ---
void wyswietlMenu();
void dodajRekord(Rekord *baza, int *licznik);
void wyswietlWszystkie(const Rekord *baza, int licznik);

// Nowe funkcje do plikow
void zapiszDoPliku(const Rekord *baza, int licznik);
void wczytajZPliku(Rekord *baza, int *licznik);

#endif
