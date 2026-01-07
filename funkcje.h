#ifndef FUNKCJE_H
#define FUNKCJE_H

// Definicja stałych
#define MAX_BUFFER 128
#define MAX_REKORDOW 100

typedef struct {
    int id;
    char nazwa[50];
    float wartosc;
} Rekord;

// Deklaracje funkcji
void wyswietlMenu();
void dodajRekord(Rekord *baza, int *licznik);
void wyswietlWszystkie(const Rekord *baza, int licznik);

#endif
