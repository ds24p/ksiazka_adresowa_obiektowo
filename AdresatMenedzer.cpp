#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajNowegoAdresata()
{
    Adresat nowyAdresat;

    nowyAdresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1));
    nowyAdresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie dodawanej osoby: ";
    nowyAdresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj nazwisko dodawanej osoby: ";
    nowyAdresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj numer telefonu dodawanej osoby: ";
    nowyAdresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj email dodawanej osoby: ";
    nowyAdresat.ustawEmail(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj adres pocztowy dodawanej osoby: ";
    nowyAdresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    adresaci.push_back(nowyAdresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(nowyAdresat))
    {
        cout << "Dodano nastepujaca osobe: " << endl << endl;
        nowyAdresat.wypiszAdresata();
    }
    else {
        cout << "Nie udalo sie dodac adresata" << endl;
    }

    system("pause");
}

void AdresatMenedzer::wypiszWszystkichAdresatow()
{
    for (size_t i = 0; i < adresaci.size(); i++)
    {
        adresaci[i].wypiszAdresata();
    }
}

void AdresatMenedzer::wyszukajAdresataPoImieniu()
{
    string szukaneImie;
    bool nieIstnieje = true;
    cout << "Podaj imie osoby/osob ktore chcesz znalezc: ";
    szukaneImie = MetodyPomocnicze::wczytajLinie();

    for (size_t i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzImie() == szukaneImie)
        {
            adresaci[i].wypiszAdresata();
            nieIstnieje = false;
        }
    }
    if (nieIstnieje)
    {
        cout << "W Twojej bazie przyjaciol nie istnieje osoba o podanym imieniu. "
             << endl
             << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyszukajAdresataPoNazwisku()
{
    string szukaneNazwisko;
    bool nieIstnieje = true;
    cout << "Podaj nazwisko osoby/osob ktore chcesz znalezc: ";
    szukaneNazwisko = MetodyPomocnicze::wczytajLinie();

    for (size_t i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzNazwisko() == szukaneNazwisko)
        {
            adresaci[i].wypiszAdresata();
            nieIstnieje = false;
        }
    }
    if (nieIstnieje)
    {
        cout << "W Twojej bazie przyjaciol nie istnieje osoba o podanym nazwisku. "
             << endl
             << endl;
    }
    system("pause");
}

void AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    bool nieIstnieje = true;

    cout << "Podaj id kontaktu, ktory chcesz usunac: " << endl;
    idUsuwanegoAdresata = MetodyPomocnicze::wczytajInt();

    for (size_t i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata)
        {
            nieIstnieje = false;
            cout << "Czy na pewno chcesz usunac kontakt o id: "<< idUsuwanegoAdresata << "? Potwierdz wybierajac 't' " << endl;
            char choice = MetodyPomocnicze::wczytajZnak();
            if(choice == 't')
            {
                cout << "Usuwam kontakt o id: " << idUsuwanegoAdresata << endl;
                plikZAdresatami.aktualizacjaPlikuZAdresatami(adresaci[i], 'd');
                adresaci.erase(adresaci.begin() + i);
            }
        }
    }
    if (nieIstnieje)
    {
        cout << "W Twojej bazie przyjaciol nie istnieje kontakt o podanym id. "
             << endl
             << endl;
    }
    system("pause");
}

void AdresatMenedzer::edytujAdresata()
{
    int idEdytowanegoAdresata = 0;
    bool nieIstnieje = true;

    cout << "Podaj id kontaktu, ktory chcesz edytowac: " << endl;
    idEdytowanegoAdresata = MetodyPomocnicze::wczytajInt();

    for (size_t i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            nieIstnieje = false;
            cout << "Edycja kontaktu o id: " << idEdytowanegoAdresata << endl;
            adresaci[i].edytujDaneAdresata();
            cout << "Dane kontaktu po edycji:" << endl;
            adresaci[i].wypiszAdresata();
            plikZAdresatami.aktualizacjaPlikuZAdresatami(adresaci[i], 'e');
        }
    }
    if (nieIstnieje)
    {
        cout << "W Twojej bazie przyjaciol nie istnieje kontakt o podanym id. Wybierz opcje: "
             << endl << "1. Ponowne wprowadzenie id" << endl
             << endl << "Dowolny znak. Powrot do menu glownego" << endl;
        int wybor = MetodyPomocnicze::wczytajZnak();
        if(wybor == '1')
        {
            edytujAdresata();
        }
    }
    system("pause");
}
