#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

public:
    int znajdzId();
    void wypiszWszystkichAdresatow();
    void dodajNowegoAdresata();
    void wczytajAdresatowZPliku();
};
