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

// Pliki
void zapiszDoPliku(const Rekord *baza, int licznik);
void wczytajZPliku(Rekord *baza, int *licznik);

// Wyszukiwanie
void wyszukajPoID(const Rekord *baza, int licznik);
void wyszukajPoNazwie(const Rekord *baza, int licznik);

// Edycja, Usuwanie, Sortowanie
void usunRekord(Rekord *baza, int *licznik);
void edytujRekord(Rekord *baza, int licznik);
void sortujPoNazwie(Rekord *baza, int licznik);
void sortujPoWartosci(Rekord *baza, int licznik);

#endif
