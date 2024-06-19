#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZPliku()
{
    Adresat nowyAdresat;
    vector <Adresat> adresaci;
    fstream file;
    string linia = "";
    int numerLini = 1;
    file.open("persons.txt", ios::in | ios::app);

    if (!file.good())
    {
        cout << "Blad otwarcia pliku" << endl;
    }
    else
    {
        while (getline(file, linia))
        {
            nowyAdresat = pobierzDaneAdresata(linia);
            adresaci.push_back(nowyAdresat);
        }
    }
    return adresaci;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string linia)
{
    Adresat nowyAdresat;
    return nowyAdresat;
}

