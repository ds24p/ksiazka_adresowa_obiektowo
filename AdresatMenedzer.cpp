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
