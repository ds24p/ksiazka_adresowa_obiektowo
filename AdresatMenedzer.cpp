#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat nowyAdresat;

    nowyAdresat.ustawId(znajdzId());
    nowyAdresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

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
    plikZAdresatami.dopiszAdresataDoPliku(nowyAdresat);

    cout << "Dodano nastepujaca osobe: " << endl << endl;
    nowyAdresat.wypiszAdresata();

    system("pause");
}

int AdresatMenedzer::znajdzId()
{
    fstream file;
    string nazwaPlikuZAdresatami = plikZAdresatami.pobierzNazwaPlikuZAdresatami();
    file.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    int i = 0;
    int idKontaktu = 0;
    string linia = "";
    while (getline(file, linia))
    {
        i = 0;
        string pomocZId = "";
        idKontaktu = 0;
        while (linia[i] != '|')
        {
            pomocZId += linia[i];
            i++;
        }
        idKontaktu = stoi(pomocZId);
    }
    return idKontaktu + 1;
}

void AdresatMenedzer::wypiszWszystkichAdresatow(int idZalogowanegoUzytkownika)
{
    for (size_t i = 0; i < adresaci.size(); i++)
    {
        if(idZalogowanegoUzytkownika == adresaci[i].pobierzIdUzytkownika())
        {
            adresaci[i].wypiszAdresata();
        }
    }
}

void AdresatMenedzer::wczytajAdresatowZPliku()
{
   adresaci = plikZAdresatami.wczytajAdresatowZPliku();
}
