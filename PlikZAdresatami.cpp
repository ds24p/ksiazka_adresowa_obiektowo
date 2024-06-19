#include "PlikZAdresatami.h"

/*vector <Adresat> PlikZAdresatami::wczytajAdresatowZPliku()
{
    Adresat nowyAdresat;
    vector <Adresat> adresaci;
    fstream file;
    string linia = "";
    int numerLini = 1;
    file.open("persons.txt", ios::in | ios::app);

    if (!file.good())
    {
        cout << "Blad otwarcia pliku" << endl;
    }
    else
    {
        while (getline(file, linia))
        {
            nowyAdresat = splitLineIntoStructFields(linia);
            if (newPerson.userIdPerson == currentUserId)
            {
                friends.push_back(newPerson);
            }
            numerLini++;
        }
    }
    return adresaci;
}

Person splitLineIntoStructFields(string line)
{
    Person newPerson;
    char separator = '|';
    int i = 0;
    string helpWithId = "";
    string helpWithUserId = "";

    int fieldNumber = 0;
    while (line[i] != '\0')
    {
        if (line[i] != separator)
        {
            switch(fieldNumber)
            {
            case 0:
                helpWithId += line[i];
                break;
            case 1:
                helpWithUserId += line[i];
                break;
            case 2:
                newPerson.name += line[i];
                break;
            case 3:
                newPerson.surname += line[i];
                break;
            case 4:
                newPerson.telephoneNumber += line[i];
                break;
            case 5:
                newPerson.email += line[i];
                break;
            case 6:
                newPerson.adress += line[i];
                break;
            }
        }
        else
        {
            fieldNumber++;
        }
        i++;
    }
    newPerson.id = stoi(helpWithId);
    newPerson.userIdPerson = stoi(helpWithUserId);
    return newPerson;
}
*/
