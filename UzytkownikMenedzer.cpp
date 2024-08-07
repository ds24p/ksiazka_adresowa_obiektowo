#include "UzytkownikMenedzer.h"


void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    haslo = MetodyPomocnicze::wczytajLinie();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}


void UzytkownikMenedzer::logowanieUzytkownika()
{
    string login, haslo = "";
    bool czyZalogowano = false;

    int proba = 3;
    cout << "Podaj nazwe uzytkownika: ";
    login = MetodyPomocnicze::wczytajLinie();

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            while(proba > 0)
            {
                cout << "Podaj haslo uzytkownika: ";
                haslo = MetodyPomocnicze::wczytajLinie();
                if(uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    czyZalogowano = true;
                    cout << "Zalogowano." << endl;
                    break;
                }
                else
                {
                    proba--;
                    cout << "Niepoprawne haslo. " << "Pozostalo " << proba << " prob." << endl;
                }
            }
        }
    }
    if(!czyZalogowano)
    {
        cout << endl << "Nie dnaleziono uzytkownika. Sproboj ponownie." << endl;
    }
    system("pause");
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            break;
        }
    }

    plikZUzytkownikami.aktualizujPlikZUzytkownikami(uzytkownicy);
    cout << "Haslo zostalo zmienione" << endl;
    system("pause");
}

bool UzytkownikMenedzer::czyZalogowanoUzytkownika()
{
    if(idZalogowanegoUzytkownika > 0)
    {
        return true;
    }
    return false;
}

void UzytkownikMenedzer::wylogujUzytkownika()
{
    if(!czyZalogowanoUzytkownika())
    {
        cout << "Zaden uzytkownik nie jest zalogowany" << endl;
    }
    else
    {
        idZalogowanegoUzytkownika = 0;
        cout << "Wylogowano" << endl;
    }
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
