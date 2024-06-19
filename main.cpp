#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");

    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

   // ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wylogujUzytkownika();
    ksiazkaAdresowa.dodajNowegoAdresata();
    ksiazkaAdresowa.dodajNowegoAdresata();
    ksiazkaAdresowa.dodajNowegoAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
}
