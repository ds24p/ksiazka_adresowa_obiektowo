#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static char wczytajZnak();
    static void wyswietlMenuGlowne();
    static void wyswietlMenuUzytkownika();
    static int wczytajInt();
    static void wyswietlMenuEdycjiAdresata();
};

#endif
