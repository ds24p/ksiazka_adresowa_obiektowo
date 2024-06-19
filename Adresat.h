#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <string>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
public:
    void wypiszAdresata();
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawId(int noweId);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);
    int pobierzIdUzytkownika();
    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};

#endif
