#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    char wyborMenuGlowne = '0';

    while (wyborMenuGlowne != '3')
    {
        MetodyPomocnicze::wyswietlMenuGlowne();
        wyborMenuGlowne = MetodyPomocnicze::wczytajZnak();

        switch (wyborMenuGlowne)
        {
        case '1':
            if(!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
            {
                ksiazkaAdresowa.logowanieUzytkownika();
                char wyborMenuUzytkownika = 0;

                while (wyborMenuUzytkownika != '9')
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
                        cout << "Nastapi wylogowanie uzytkownika o Id." << endl;
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
            else
            {
                cout << "Nieudane logowanie." << endl;
                system("pause");
            }
            break;
        case '2':
            ksiazkaAdresowa.rejestracjaUzytkownika();
            break;
        case '3':
            break;
        default:
            cout << "Wprowadziles znak nieobslugiwany przez menu programu. Sproboj ponownie." << endl;
            system("pause");
            break;
        }
    }

    cout << "Koncze program" << endl;

    return 0;
}
