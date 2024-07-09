#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA);
    Adresat pobierzDaneAdresata(string linia);
    bool dopiszAdresataDoPliku(Adresat nowyAdresat);
    int pobierzIdOstatniegoAdresata();
    void usunAdresataZPliku(int idAdresata);
    void edytujAdresataWPliku(Adresat adresat);
    void aktualizacjaPlikuZAdresatami(Adresat aktualizowanyAdresat, char tryb);
};

#endif
