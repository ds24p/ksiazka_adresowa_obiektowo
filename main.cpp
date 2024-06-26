#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    ksiazkaAdresowa.wypiszWszystkichAdresatowZalogowanegoUzytkownika();
    ksiazkaAdresowa.dodajNowegoAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatowZalogowanegoUzytkownika();

    ksiazkaAdresowa.wylogujUzytkownika();

    return 0;
}
