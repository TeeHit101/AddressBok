#include <iostream>
#include <string>

using namespace std;


// Definiera struct f�r en kontakt
main
struct Kontakt {
    string namn;
    string telefon;
    string email;
    string Singel;
};


// Funktion f�r att l�gga till en kontakt i adressboken
void laggTillKontakt(Kontakt adressbok[], int& antalKontakter) {
    system("cls");
    cout << "\nL�gg till kontakt\n";

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
    cout << "Singel?:";
    getline(cin, adressbok[antalKontakter].Singel);
    antalKontakter++;
    cout << "Kontakten har lagts till.\n";
}

// Funktion f�r att visa alla kontakter i adressboken


void visaAdressbok(const Kontakt adressbok[], int antalKontakter) {
    // system("cls");
    cout << "\nAdressbok:\n";
    if (antalKontakter == 0) {
        cout << "Inga kontakter att visa.\n";
        return;
    }
    for (int i = 0; i < antalKontakter; ++i) {
        cout << "Namn: " << adressbok[i].namn << ", Telefon: " << adressbok[i].telefon << ", Email: " << adressbok[i].email << ", Singel: " << adressbok[i].Singel << endl;
    }
}

// Funktion f�r att redigera en kontakt i adressboken
void redigeraKontakt(Kontakt adressbok[], int antalKontakter) {
    // system("cls");
    string redigerNamn;
    cout << "\nAnge namnet p� kontakten du vill redigera: ";
    cout << "\nAnge namnet på kontakten du vill redigera: ";
    cin.ignore();
    getline(cin, redigerNamn);

    for (int i = 0; i < antalKontakter; ++i) {
        if (adressbok[i].namn == redigerNamn) {

            cout << "Ange det nya namnet f�r kontakten: ";
            getline(cin, adressbok[i].namn);
            cout << "Ange den nya telefonnumret f�r kontakten: ";
            getline(cin, adressbok[i].telefon);
            cout << "Ange den nya emailadressen f�r kontakten: ";

            cout << "Ange det nya namnet för kontakten: ";
            getline(cin, adressbok[i].namn);
            cout << "Ange det nya telefonnumret för kontakten: ";
            getline(cin, adressbok[i].telefon);
            cout << "Ange den nya emailadressen för kontakten: ";
            getline(cin, adressbok[i].email);
            cout << "Ange den nya singel statusen för kontakten";
            getline(cin, adressbok[i].Singel);
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
        cout << "\nV�lj ett alternativ:\n";
        cout << "1. L�gg till kontakt\n";
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
            cout << "\nOgiltigt val. F�rs�k igen.\n";
            cout << "\nOgiltigt val. Försök igen.\n";

        }
    }

    return 0;
}
