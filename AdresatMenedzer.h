#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer(string NAZWAPLIKUZADRESATAMI):plikZAdresatami(NAZWAPLIKUZADRESATAMI){}
    int znajdzId();
    void wypiszWszystkichAdresatow(int idZalogowanegoUzytkownika);
    void dodajNowegoAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZPliku();
};

#endif
