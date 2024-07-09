#include "MetodyPomocnicze.h"


string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie()
{
    string input;
    getline(cin, input);
    return input;
}

char MetodyPomocnicze::wczytajZnak()
{
    string ciagZnakow = "";
    char inputChar = (0);

    while(true)
    {
        ciagZnakow = wczytajLinie();

        if (ciagZnakow.length() == 1)
        {
            inputChar = ciagZnakow[0];
            break;
        }
        cout << "To nie jest pojedynczy znak, sproboj ponownie." << endl;
    }

    return inputChar;
}

void MetodyPomocnicze::wyswietlMenuGlowne()
{
    system("cls");
    cout << "--------------------LOGIN-MENU-------------------" << endl;
    cout << "Wybierz odpowiednia opcje:" << endl;
    cout << "1. Logowanie" << endl;
    cout << "2. Rejestracja" << endl;
    cout << "3. Zamknij program" << endl;
}

void MetodyPomocnicze::wyswietlMenuUzytkownika()
{
    system("cls");
    cout << "-----------------------MENU---------------------" << endl;
    cout << "Wybierz opcje z menu: " << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl wszystkich adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
}

int MetodyPomocnicze::wczytajInt()
{
    string input;
    int liczba;

    while(true)
    {
        getline(cin, input);

        stringstream myStream(input);

        if (myStream >> liczba)
        {
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie" << endl;
    }
    return liczba;
}
