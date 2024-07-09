#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    cout << "Rejestracja nowego uzytkownika" << endl;
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyZalogowanoUzytkownika())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodajNowegoAdresata()
{
    if (uzytkownikMenedzer.czyZalogowanoUzytkownika())
    {
        adresatMenedzer->dodajNowegoAdresata();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wypiszWszystkichAdresatowZalogowanegoUzytkownika()
{
    adresatMenedzer->wypiszWszystkichAdresatow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenedzer.czyZalogowanoUzytkownika();
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu()
{
    adresatMenedzer->wyszukajAdresataPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku()
{
    adresatMenedzer->wyszukajAdresataPoNazwisku();
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}
