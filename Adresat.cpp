#include "Adresat.h"

void Adresat::wypiszAdresata()
{
    cout << "Numer id: " << id << endl;
    cout << "Imie: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Numer telefonu: " << numerTelefonu << endl;
    cout << "Email: " << email << endl;
    cout << "Adres: " << adres << endl << endl;
}

void Adresat::ustawIdUzytkownika(int noweIdUzytkownika)
{
    idUzytkownika = noweIdUzytkownika;
}

void Adresat::ustawId(int noweId)
{
    id = noweId;
}

void Adresat::ustawImie(string noweImie)
{
    imie = noweImie;
}

void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu)
{
    numerTelefonu = nowyNumerTelefonu;
}

void Adresat::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}

void Adresat::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}

int Adresat::pobierzIdUzytkownika()
{
    return idUzytkownika;
}

int Adresat::pobierzId()
{
    return id;
}

string Adresat::pobierzImie()
{
    return imie;
}

string Adresat::pobierzNazwisko()
{
    return nazwisko;
}

string Adresat::pobierzNumerTelefonu()
{
    return numerTelefonu;
}

string Adresat::pobierzEmail()
{
    return email;
}

string Adresat::pobierzAdres()
{
    return adres;
}

void Adresat::edytujDaneAdresata()
{
    char wybor = 0;
    while (wybor != '6')
    {
        MetodyPomocnicze::wyswietlMenuEdycjiAdresata();
        wybor = MetodyPomocnicze::wczytajZnak();

        switch (wybor)
        {
        case '1':
            cout << "Nowe imie: " << endl;
            ustawImie(MetodyPomocnicze::wczytajLinie());
            break;
        case '2':
            cout << "Nowe nazwisko: " << endl;
            ustawNazwisko(MetodyPomocnicze::wczytajLinie());
            break;
        case '3':
            cout << "Nowy numer telefonu: " << endl;
            ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
            break;
        case '4':
            cout << "Nowy adres email: " << endl;
            ustawEmail(MetodyPomocnicze::wczytajLinie());
            break;
        case '5':
            cout << "Nowy adres zamieszkania: " << endl;
            ustawAdres(MetodyPomocnicze::wczytajLinie());
            break;
        case '6':
            break;
        default:
            cout << "Wprowadziles znak nieobslugiwany przez menu programu. Sproboj ponownie." << endl;
            system("pause");
            break;
        }
    }
}
