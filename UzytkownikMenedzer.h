#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    }
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    bool czyZalogowanoUzytkownika();
    void wylogujUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
