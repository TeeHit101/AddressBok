#include <iostream>
#include <string>

using namespace std;

struct Kontakt {
    string namn;
    string telefon;
    string email;
};

void laggTillKontakt(Kontakt adressbok[], int& antalKontakter, int maxKontakter) {
    if (antalKontakter >= maxKontakter) {
        cout << "Adressboken är full. Kan inte lägga till fler kontakter.\n";
        return;
    }
    // system("cls"); // Ta bort eller kommentera om du inte är på Windows
    cout << "\nLägg till kontakt\n";
    cout << "Namn: ";
    cin.ignore();
    getline(cin, adressbok[antalKontakter].namn);
    cout << "Telefon: ";
    getline(cin, adressbok[antalKontakter].telefon);
    cout << "Email: ";
    getline(cin, adressbok[antalKontakter].email);
    antalKontakter++;
    cout << "Kontakten har lagts till.\n";
}

void visaAdressbok(const Kontakt adressbok[], int antalKontakter) {
    // system("cls");
    cout << "\nAdressbok:\n";
    if (antalKontakter == 0) {
        cout << "Inga kontakter att visa.\n";
        return;
    }
    for (int i = 0; i < antalKontakter; ++i) {
        cout << "Namn: " << adressbok[i].namn << ", Telefon: " << adressbok[i].telefon << ", Email: " << adressbok[i].email << endl;
    }
}

void redigeraKontakt(Kontakt adressbok[], int antalKontakter) {
    // system("cls");
    string redigerNamn;
    cout << "\nAnge namnet på kontakten du vill redigera: ";
    cin.ignore();
    getline(cin, redigerNamn);

    for (int i = 0; i < antalKontakter; ++i) {
        if (adressbok[i].namn == redigerNamn) {
            cout << "Ange det nya namnet för kontakten: ";
            getline(cin, adressbok[i].namn);
            cout << "Ange det nya telefonnumret för kontakten: ";
            getline(cin, adressbok[i].telefon);
            cout << "Ange den nya emailadressen för kontakten: ";
            getline(cin, adressbok[i].email);
            cout << "Kontakten '" << redigerNamn << "' har redigerats.\n";
            return;
        }
    }
    cout << "Kontakten '" << redigerNamn << "' hittades inte.\n";
}

int main() {
    setlocale(LC_ALL, "Swedish");

    const int MAX_KONTAKTER = 100;
    Kontakt adressbok[MAX_KONTAKTER];
    int antalKontakter = 0;

    bool fortsatt = true;
    while (fortsatt) {
        cout << "\nVälj ett alternativ:\n";
        cout << "1. Lägg till kontakt\n";
        cout << "2. Visa adressbok\n";
        cout << "3. Redigera kontakt\n";
        cout << "4. Avsluta programmet\n";
        cout << "Ange ditt val: ";
        int val;
        cin >> val;
        cin.ignore(); // Viktig!! Ignorera ny rad efter cin >>

        switch (val) {
        case 1:
            laggTillKontakt(adressbok, antalKontakter, MAX_KONTAKTER);
            break;
        case 2:
            visaAdressbok(adressbok, antalKontakter);
            break;
        case 3:
            redigeraKontakt(adressbok, antalKontakter);
            break;
        case 4:
            cout << "\nAvslutar programmet.\n";
            fortsatt = false;
            break;
        default:
            cout << "\nOgiltigt val. Försök igen.\n";
        }
    }

    return 0;
}
