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
