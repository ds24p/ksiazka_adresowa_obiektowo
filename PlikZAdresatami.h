#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;

public:
    vector <Adresat> wczytajAdresatowZPliku();
    Adresat pobierzDaneAdresata(string linia);
    void dopiszAdresataDoPliku(Adresat nowyAdresat);
};

#endif
