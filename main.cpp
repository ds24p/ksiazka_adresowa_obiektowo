#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

   // ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wylogujUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.dodajNowegoAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
}
