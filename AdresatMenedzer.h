#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer();
    int znajdzId();
    void wypiszWszystkichAdresatow(int idZalogowanegoUzytkownika);
    void dodajNowegoAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZPliku();
};
