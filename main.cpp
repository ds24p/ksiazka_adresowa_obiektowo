#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    char wyborMenuGlowne = '0';
    char wyborMenuUzytkownika = '0';

    while(true)
    {
        if(!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            MetodyPomocnicze::wyswietlMenuGlowne();
            wyborMenuGlowne = MetodyPomocnicze::wczytajZnak();
            switch (wyborMenuGlowne)
            {
            case '1':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '3':
                cout << "Koncze program" << endl;
                exit(0);
                break;
            default:
                cout << "Wprowadziles znak nieobslugiwany przez menu programu. Sproboj ponownie." << endl;
                system("pause");
                break;
            }
        }
        else
        {
            MetodyPomocnicze::wyswietlMenuUzytkownika();
            wyborMenuUzytkownika = MetodyPomocnicze::wczytajZnak();

            switch (wyborMenuUzytkownika)
            {
            case '1':
                ksiazkaAdresowa.dodajNowegoAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresataPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresataPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wypiszWszystkichAdresatowZalogowanegoUzytkownika();
                system("pause");
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '9':
                cout << "Nastapi wylogowanie uzytkownika" << endl;
                ksiazkaAdresowa.wylogujUzytkownika();
                system("pause");
                break;
            default:
                cout << "Wprowadziles znak nieobslugiwany przez menu programu. Sproboj ponownie." << endl;
                system("pause");
                break;
            }
        }

    }

return 0;
}
