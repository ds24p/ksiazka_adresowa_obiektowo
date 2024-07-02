#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownika(int ID_ZALOGOWANEGO_UZYTKOWNIKA)
{
    Adresat nowyAdresat;
    vector <Adresat> adresaci;
    fstream file;
    string linia = "";
    int numerLini = 1;
    file.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in | ios::app);

    if (!file.good())
    {
        cout << "Blad otwarcia pliku" << endl;
    }
    else
    {
        while (getline(file, linia))
        {
            nowyAdresat = pobierzDaneAdresata(linia);
            idOstatniegoAdresata = nowyAdresat.pobierzId();
            if (nowyAdresat.pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA)
            {
               adresaci.push_back(nowyAdresat);
            }
        }
    }
    return adresaci;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string linia)
{
    Adresat nowyAdresat;
    char separator = '|';
    int i = 0;
    string pomocZId, pomocZUserId, imie, nazwisko, numerTelefonu, email, adres = "";

    int numerPola = 0;
    while (linia[i] != '\0')
    {
        if (linia[i] != separator)
        {
            switch(numerPola)
            {
            case 0:
                pomocZId += linia[i];
                break;
            case 1:
                pomocZUserId += linia[i];
                break;
            case 2:
                imie += linia[i];
                break;
            case 3:
                nazwisko += linia[i];
                break;
            case 4:
                numerTelefonu += linia[i];
                break;
            case 5:
                email += linia[i];
                break;
            case 6:
                adres += linia[i];
                break;
            }
        }
        else
        {
            numerPola++;
        }
        i++;
    }
    nowyAdresat.ustawId(stoi(pomocZId));
    nowyAdresat.ustawIdUzytkownika(stoi(pomocZUserId));
    nowyAdresat.ustawImie(imie);
    nowyAdresat.ustawNazwisko(nazwisko);
    nowyAdresat.ustawAdres(adres);
    nowyAdresat.ustawNumerTelefonu(numerTelefonu);
    nowyAdresat.ustawEmail(email);
    return nowyAdresat;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat nowyAdresat)
{
    fstream plik;
    plik.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::app);

    if (!plik.good())
    {
        cout << "Blad otwarcia pliku wyjsciowego" << endl;
        return false;
    }
    else
    {
        plik << nowyAdresat.pobierzId() << "|";
        plik << nowyAdresat.pobierzIdUzytkownika() << "|";
        plik << nowyAdresat.pobierzImie() << "|";
        plik << nowyAdresat.pobierzNazwisko() << "|";
        plik << nowyAdresat.pobierzNumerTelefonu() << "|";
        plik << nowyAdresat.pobierzEmail() << "|";
        plik << nowyAdresat.pobierzAdres() << "|" << endl;
    }

    plik.close();
    idOstatniegoAdresata++;
    return true;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}
