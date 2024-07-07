#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>
#include <windows.h>
#include <map>
#include <cstdlib> // voor stof

using namespace std;

bool benJeZeker(const string &vraag) {
    char antwoord;
    cout << vraag << " (j/n): ";
    cin >> antwoord;
    while (antwoord != 'j' && antwoord != 'n') {
        cout << "Ongeldige invoer. Voer in 'j' voor ja of 'n' voor nee: ";
        cin >> antwoord;
    }
    return antwoord == 'j';
}

struct Vak {
    string naam;
    float cijfer;
    int groep;
};

struct Direction {
    string name;
    map<int, string> subDirections;
};

bool isGeldigKeuze(int keuze, int min, int max) {
    return keuze >= min && keuze <= max;
}

void toonVakken(const vector<Vak> &vakken) {
    cout << "Lijst van vakken:" << endl;
    for (int i = 0; i < vakken.size(); ++i) {
        cout << i << ": " << vakken[i].naam << " (" << vakken[i].cijfer << ")" << endl;
    }
}

void voerCijfersInHandmatig(vector<Vak> &vakken, string &slbRating) {
    HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Hier de volgende commando's: " << endl;
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "t) Terug naar vorige vak" << endl;
    cout << "w) Wijzigen van een gekozen vak" << endl;
    cout << "r) Opnieuw invoeren van alle cijfers" << endl;
    cout << "m) Weer naar het HoofdMenu gaan" << endl;
    cout << "s) Sluiten van programma" << "\n";
    int i = 0;
    cout << endl;
    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN );
    cout << "Voer de cijfers in: " << endl;
    string input;

    while (i < vakken.size()) {
        SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << vakken[i].naam << ": ";
        cin >> input;

        if (input == "s") {
            if (benJeZeker("Weet u zeker dat u het programma wil sluiten?")) {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Programma sluiten. Goodbye!" << endl;
                exit(0);
                } else {
                    continue;
                }
            }

        if (input == "t") {
            if (i == 0) {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Kan niet terug naar een vorig vak. Dit is het eerste vak." << endl;
            } else {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                --i;
                cout << "Terug naar " << vakken[i].naam << "." << endl;
            }
            continue;
        }

        if (input == "m") {
            throw runtime_error("Restart");
        }

        if (input == "w") {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            toonVakken(vakken);
            int changeIndex;
            cout << "Voer het nummer van het vak in (0-" << vakken.size() - 1 << ") dat je wilt wijzigen: ";
            cin >> changeIndex;

            if (changeIndex >= 0 && changeIndex < vakken.size()) {
                cout << "Wijzig " << vakken[changeIndex].naam << ": ";
                cin >> input;
                try {
                    float newCijfer = stof(input);
                    if (newCijfer >= 1 && newCijfer <= 10) {
                        vakken[changeIndex].cijfer = newCijfer;
                        cout << vakken[changeIndex].naam << " is bijgewerkt naar " << vakken[changeIndex].cijfer << endl;
                    } else {
                        SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                        cout << "Ongeldige invoer. Voer een cijfer in tussen 1 en 10." << endl;
                    }
                } catch (invalid_argument&) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "Ongeldige invoer. Voer een cijfer in tussen 1 en 10." << endl;
                }
            } else {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Ongeldige index. Probeer opnieuw." << endl;
            }
            continue;
        }

        if (input == "r") {
            if (benJeZeker("Weet u zeker dat u alle cijfers opnieuw wilt invoeren?")) {
                i = 0;
                cout << "Alle cijfers worden opnieuw ingevoerd." << endl;
                continue;
            } else {
                cout << "Opnieuw invoeren geannuleerd." << endl;
            }
        }

        try {
            float cijfer = stof(input);
            if (cijfer >= 1 && cijfer <= 10) {
                vakken[i].cijfer = cijfer;
                ++i;
            } else {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Ongeldige invoer. Voer een cijfer in tussen 1 en 10." << endl;
            }
        } catch (invalid_argument&) {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
            cout << "Ongeldige invoer. Voer een cijfer in tussen 1 en 10." << endl;
        }
    }

// Functie voor SLB
    while (true) {
SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "SLB (O, V, G): ";
        string input;
        cin >> input;

               if (input == "t") {
            if (i == 0) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Kan niet terug naar een vorig vak. Dit is het eerste vak." << endl;
            } else {
                   SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                --i;
                cout << "Terug naar " << vakken[i].naam << "." << endl;
            }
            continue;
        }

        if (input == "s") {
            if (benJeZeker("Weet u zeker dat u het programma wil sluiten?")) {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Programma sluiten. Goodbye!" << endl;
                exit(0);
                } else {
                    continue;
                }
            }

        if (input == "m") {
            throw runtime_error("Restart");
        }

        if (input == "w") {
            toonVakken(vakken);
            int changeIndex;
            cout << "Voer het nummer van het vak in (0-" << vakken.size() - 1 << ") dat je wilt wijzigen: ";
            cin >> changeIndex;

                    if (input == "r") {
            if (benJeZeker("Weet u zeker dat u alle cijfers opnieuw wilt invoeren?")) {
                i = 0;
                cout << "Alle cijfers worden opnieuw ingevoerd." << endl;
                continue;
            } else {
                cout << "Opnieuw invoeren geannuleerd." << endl;
            }
        }

            if (changeIndex >= 0 && changeIndex < vakken.size()) {
                cout << "Wijzig " << vakken[changeIndex].naam << ": ";
                cin >> input;
                try {
                    float newCijfer = stof(input);
                    if (newCijfer >= 1 && newCijfer <= 10) {
                        vakken[changeIndex].cijfer = newCijfer;
                        cout << vakken[changeIndex].naam << " is bijgewerkt naar " << vakken[changeIndex].cijfer << endl;
                    } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "Ongeldige invoer. Voer een cijfer in tussen 1 en 10." << endl;
                    }
                } catch (invalid_argument&) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "Ongeldige invoer. Voer een cijfer in tussen 1 en 10." << endl;
                }
            } else {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Ongeldige index. Probeer opnieuw." << endl;
            }
            continue;
        }

        if (input == "O" || input == "o" || input == "V" || input == "v" || input == "G" || input == "g") {
            vakken.back().cijfer = input[0];
            slbRating = input;
            break;
        } else {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
            cout << "Ongeldige invoer. Voer alstublieft een geldige beoordeling in (O, V, G)." << endl;
        }
    }
}

void toonVakkenEnVoerCijfersIn(vector<Vak> &vakken, string &slbRating) {
    voerCijfersInHandmatig(vakken, slbRating);
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het eerste jaar Elektrotechniek
bool controleerCijfers1eKlasElektro(const vector<Vak> &vakken, int maxBerekendeVijvenGroep45, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    int berekendeVijven = 0, berekendeVijvenGroep45 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
                if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 4) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 3 && vak.groep == 3) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep45++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 15 || somGroep3 < 30 || somGroep4 < 15 || somGroep5 < 10) return heeftNaderOnderzoek;
    if (berekendeVijvenGroep45 > maxBerekendeVijvenGroep45 || berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het tweede jaar Elektrotechniek
bool controleerCijfers2eKlasElektro(const vector<Vak> &vakken, int maxBerekendeVijvenGroep456, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0, somGroep6 = 0;
    int berekendeVijven = 0, berekendeVijvenGroep456 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {

                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 4) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 3 && vak.groep == 3) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5 || vak.groep == 6)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 4 || vak.groep == 5 || vak.groep == 6) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep456++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
            case 6: somGroep6 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 15 || somGroep3 < 20 || somGroep4 < 15 || somGroep5 < 15 || somGroep6 < 15) return heeftNaderOnderzoek;
    if (berekendeVijvenGroep456 > maxBerekendeVijvenGroep456 || berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het derde jaar Elektrotechniek Energie
bool controleerCijfers3eKlasElektroEnergie(const vector<Vak> &vakken, int maxBerekendeVijvenGroep345, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep345 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {

                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 3 || vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep345++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }

    if (somGroep1 < 20 || somGroep2 < 15 || somGroep3 < 25 || somGroep4 < 15 || somGroep5 < 15) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijvenGroep345 > maxBerekendeVijvenGroep345 || berekendeVijven > maxBerekendeVijven) return !vakkenNaderOnderzoek.empty();

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het derde jaar Elektrotechniek Info
bool controleerCijfers3eKlasElektroInfo(const vector<Vak> &vakken, int maxBerekendeVijvenGroep45, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep45 = 0;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
        // Controleer voor vakken in groep 1, 2, en 3
                if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false; // Student krijgt een NO
            }
        }
        // Controleer voor vakken in groep 4 en 5
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false; // Student krijgt een NO
            }
        }

        // Berekende vijven
        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep45++;
        }

        // Som van de cijfers in elke groep
        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }

    // Controleer of de som van de cijfers in elke groep voldoet aan de eisen
    if (somGroep1 < 20 || somGroep2 < 15 || somGroep3 < 25 || somGroep4 < 15 || somGroep5 < 15) return false;
    if (berekendeVijvenGroep45 > maxBerekendeVijvenGroep45 || berekendeVijven > maxBerekendeVijven) return false;

    // Student krijgt een NO als er vakken zijn die nader onderzoek vereisen
    return vakkenNaderOnderzoek.empty();
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het vierde jaar Elektrotechniek Energie.
bool controleerCijfers4eKlasElektroEnergie(const vector<Vak> &vakken, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0;
    int berekendeVijven = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
                if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer < 3 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer < 5 && (vak.groep == 3 || vak.groep == 4)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer < 5.5 && (vak.groep == 6)) {
            if (vak.cijfer + 2 >= 5.5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 35 || somGroep3 <= 16 || somGroep4 < 16.5) return heeftNaderOnderzoek;
    if (berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het vierde jaar Elektro Info.
bool controleerCijfers4eKlasElektroInfo(const vector<Vak> &vakken, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0;
    int berekendeVijven = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {

                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer < 3 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer < 5 && (vak.groep == 3 || vak.groep == 4)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer < 5.5 && (vak.groep == 6)) {
            if (vak.cijfer + 2 >= 5.5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 15 || somGroep3 <= 16 || somGroep4 < 16.5) return heeftNaderOnderzoek;
    if (berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het eerste jaar werktuigbouwkunde
bool controleerCijfers1eKlasWTB(const vector<Vak> &vakken, int maxBerekendeVijvenGroep45, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    int berekendeVijven = 0, berekendeVijvenGroep45 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 4) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 3 && vak.groep == 3) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep45++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 15 || somGroep3 < 30 || somGroep4 < 15 || somGroep5 < 10) return heeftNaderOnderzoek;
    if (berekendeVijvenGroep45 > maxBerekendeVijvenGroep45 || berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het tweede jaar Werktuigbouwkunde.
bool controleerCijfers2eKlasWTB(const vector<Vak> &vakken, int maxBerekendeVijvenGroep45, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    int berekendeVijven = 0, berekendeVijvenGroep45 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {

                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 4) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 3 && vak.groep == 3) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep45++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 11 || somGroep3 < 20 || somGroep4 < 20 || somGroep5 < 15) return heeftNaderOnderzoek;
    if (berekendeVijvenGroep45 > maxBerekendeVijvenGroep45 || berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het derde jaar Werktuigbouwkunde.
bool controleerCijfers3eKlasWTB(const vector<Vak> &vakken, int maxBerekendeVijvenGroep345, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep345 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 3 || vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep345++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }

    if (somGroep1 < 20 || somGroep2 < 10 || somGroep3 < 25 || somGroep4 < 20 || somGroep5 < 15) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijvenGroep345 > maxBerekendeVijvenGroep345 || berekendeVijven > maxBerekendeVijven) return !vakkenNaderOnderzoek.empty();

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het vierde jaar Werktuigbouwkunde.
bool controleerCijfers4eKlasWTB(const vector<Vak> &vakken, int maxBerekendeVijven, string &vakNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0;
    int berekendeVijven = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 3 && (vak.groep == 1 || vak.groep == 2)) {
            if (vak.cijfer + 2 >= 3) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 3 || vak.groep == 4)) {
            if (vak.cijfer + 2 >= 5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }
        if (vak.cijfer <= 5.5 && vak.groep == 6) {
            if (vak.cijfer + 2 >= 5.5) {
                vakNaderOnderzoek = vak.naam;
                heeftNaderOnderzoek = true;
            } else {
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;


        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 20 || somGroep3 < 20 || somGroep4 < 27.5) return heeftNaderOnderzoek;
    if (berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het eerste jaar Infrastructuur.
bool controleerCijfers1eKlasInfra(const vector<Vak> &vakken, int maxBerekendeVijvenGroep4, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0;
 float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep4 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 4) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep4++;
        }

        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
        }
    }

    if (somGroep1 < 10 || somGroep2 < 10 || somGroep3 < 30 || somGroep4 < 25) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijvenGroep4 > maxBerekendeVijvenGroep4 || berekendeVijven > maxBerekendeVijven) return !vakkenNaderOnderzoek.empty();

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het tweede jaar Infrastructuur.
bool controleerCijfers2eKlasInfra(const vector<Vak> &vakken, int maxBerekendeVijvenGroep345, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
 float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep345 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
            if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
                if (vak.cijfer < 5.5 && (vak.groep == 7)) {
                if (vak.cijfer + 2 >= 5.5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
        }
                }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 3 || vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep345++;
        }


        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }


    if (somGroep1 < 20 || somGroep2 < 20 || somGroep3 < 20 || somGroep4 < 10 || somGroep5 < 10) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijvenGroep345 > maxBerekendeVijvenGroep345 || berekendeVijven > maxBerekendeVijven) return !vakkenNaderOnderzoek.empty();
    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het derde jaar Infrastructuur Bouwkunde
bool controleerCijfers3eKlasInfraBouwkunde(const vector<Vak> &vakken, int maxBerekendeVijvenGroep345, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
 float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep345 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
            if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
                if (vak.cijfer <= 5.5 && (vak.groep == 7)) {
                if (vak.cijfer + 2 >= 5.5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
        }
                }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 3 || vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep345++;
        }


        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }


    if (somGroep1 < 20 || somGroep2 < 15 || somGroep3 < 15 || somGroep4 < 15 || somGroep5 < 15) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijvenGroep345 > maxBerekendeVijvenGroep345 || berekendeVijven > maxBerekendeVijven) return !vakkenNaderOnderzoek.empty();
    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het derde jaar Infrastructuur Weg en Water.
bool controleerCijfers3eKlasInfraWegenWater(const vector<Vak> &vakken, int maxBerekendeVijvenGroep345, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
    float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
 float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep345 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
            if (vak.cijfer <= 4 && (vak.groep == 1 || vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
                if (vak.cijfer < 5.5 && (vak.groep == 7)) {
                if (vak.cijfer + 2 >= 5.5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
        }
                }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

        if ((vak.groep == 3 || vak.groep == 4 || vak.groep == 5) && (cijfer == 5 || cijfer == 4 || cijfer == 3)) {
            berekendeVijvenGroep345++;
        }


        switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }


    if (somGroep1 < 20 || somGroep2 < 15 || somGroep3 < 15 || somGroep4 < 20 || somGroep5 < 15) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijvenGroep345 > maxBerekendeVijvenGroep345 || berekendeVijven > maxBerekendeVijven) return !vakkenNaderOnderzoek.empty();
    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het vierde jaar Infrastructuur Bouwkunde.
bool controleerCijfers4eKlasInfraBouwkunde(const vector<Vak> &vakken, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
     float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0, berekendeVijvenGroep345 = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }if (vak.cijfer < 3 && (vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 3) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

       switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }


    if (somGroep1 < 20 || somGroep2 < 10 || somGroep3 < 25 || somGroep4 < 20 || somGroep5 < 16.5) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

// Functie om te controleren of de cijfers voldoen aan de vereisten voor het vierde jaar Infrastructuur Weg en water.
bool controleerCijfers4eKlasInfraWegenWater(const vector<Vak> &vakken, int maxBerekendeVijven, vector<string> &vakkenNaderOnderzoek) {
     float somGroep1 = 0, somGroep2 = 0, somGroep3 = 0, somGroep4 = 0, somGroep5 = 0;
    float somWiskunde = 0, somNederlands = 0, somEngels = 0, somNatuurkunde = 0;
    int berekendeVijven = 0;
    bool heeftNaderOnderzoek = false;

    for (const auto &vak : vakken) {
        // Specifieke vakken in groep 1
        if (vak.naam == "Wiskunde") somWiskunde = vak.cijfer;
        if (vak.naam == "Nederlands") somNederlands = vak.cijfer;
        if (vak.naam == "Engels") somEngels = vak.cijfer;
        if (vak.naam == "Natuurkunde") somNatuurkunde = vak.cijfer;
    }

    float somGroepWNE = somWiskunde + somNederlands + somEngels + somNatuurkunde;

    if (somGroepWNE < 20 || (somNederlands + somEngels) < 10 || (somWiskunde + somNatuurkunde) < 10) {
        if (somWiskunde < 5) {
            vakkenNaderOnderzoek.push_back("Wiskunde");
        }
        if (somNederlands < 5) {
            vakkenNaderOnderzoek.push_back("Nederlands");
        }
        if (somEngels < 5) {
            vakkenNaderOnderzoek.push_back("Engels");
        }
        if (somNatuurkunde < 5) {
            vakkenNaderOnderzoek.push_back("Natuurkunde");
        }
    }

    for (const auto &vak : vakken) {
                    if (vak.cijfer <= 2) {
            return false; // Directe afwijzing voor een cijfer van 1 of 2
        }
        if (vak.cijfer <= 4 && (vak.groep == 1)) {
            if (vak.cijfer + 2 >= 4) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }if (vak.cijfer <= 3 && (vak.groep == 2 || vak.groep == 3)) {
            if (vak.cijfer + 2 >= 3) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }
        if (vak.cijfer <= 5 && (vak.groep == 4 || vak.groep == 5)) {
            if (vak.cijfer + 2 >= 5) {
                vakkenNaderOnderzoek.push_back(vak.naam);
                heeftNaderOnderzoek = true;
            } else {
                vakkenNaderOnderzoek.push_back(vak.naam);
                return false;
            }
        }

        float cijfer = vak.cijfer;
        if (cijfer == 5) berekendeVijven++;
        else if (cijfer == 4) berekendeVijven += 1.5;
        else if (cijfer == 3) berekendeVijven += 2;

       switch (vak.groep) {
            case 1: somGroep1 += cijfer; break;
            case 2: somGroep2 += cijfer; break;
            case 3: somGroep3 += cijfer; break;
            case 4: somGroep4 += cijfer; break;
            case 5: somGroep5 += cijfer; break;
        }
    }


    if (somGroep1 < 20 || somGroep2 < 15 || somGroep3 < 20 || somGroep4 < 20 || somGroep5 < 16.5) return !vakkenNaderOnderzoek.empty();
    if (berekendeVijven > maxBerekendeVijven) return heeftNaderOnderzoek;

    return true;
}

void verwerkStudent(map<int, string> &klassen, map<int, Direction> &richtingen, int &klas, int &richting, int &bijRichting) {
    system("cls");
    cout << "Welkom bij GradeMaster v1.0" << endl;
    cout << "Dit is een programma dat bepaalt of een student voldoet aan de eisen om naar het volgende leerjaar te gaan bij NATIN Nickerie." << endl;
    cout << "Gemaakt door Enser J., Shaw S. en Setrosetiko S. als afstudeerproject. @2024" << endl << endl;

    HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);

    system("title Grademaster");

    // Vraag naar welke Klas
    while (true) {
        SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "-------HoofdMenu------" << endl;
        SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);
        cout << "In welke klas zit de student?" << endl;
        SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        for (const auto &klasOptie : klassen) {
            cout << klasOptie.first << ") " << klasOptie.second << endl;
        }
        cout << endl;
        cout<< "Kies aub een klas: ";
         cin >> klas;


        if (isGeldigKeuze(klas, 1, klassen.size())) {
            break;
        } else {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
            cout << "Ongeldige keuze. Probeer opnieuw." << endl;
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << endl;

    // Vraag naar richting
    while (true) {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "-------Menu------" << endl;
        SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);
        cout << "In welke richting zit de student?" << endl;
        SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        for (const auto &richtingOptie : richtingen) {
            cout << richtingOptie.first << ") " << richtingOptie.second.name << endl;
        }
        cout << endl;
        cout<< "Kies aub een richting: ";
        cin >> richting;

        if (isGeldigKeuze(richting, 1, richtingen.size())) {
            break;
        } else {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
            cout << "Ongeldige keuze. Probeer opnieuw." << endl;
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << endl;

    if ((klas == 3 || klas == 4) && richtingen[richting].subDirections.size() > 0) {
        while (true) {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << "-------Menu------" << endl;
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_BLUE);
            cout << "Kies de bijrichting binnen " << richtingen[richting].name << ":" << endl;
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            for (const auto &bijRichtingOptie : richtingen[richting].subDirections) {
                cout << bijRichtingOptie.first << ") " << bijRichtingOptie.second << endl;
            }
            cout << endl;
            cout << "Kies aub een bijrichting: ";
            cin >> bijRichting;
            cout<< endl;

            if (isGeldigKeuze(bijRichting, 1,richtingen[richting].subDirections.size())) {
                break;
            } else {
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                cout << "Ongeldige keuze. Probeer opnieuw." << endl;
                SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

// Functie om het programma uit te voeren
void runProgram(map<int, string> &klassen, map<int, Direction> &richtingen, map<pair<int, int>, map<int, vector<Vak>>> &vakkenMap) {
    while (true) {
            HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
        try {
            int klas, richting, bijRichting;
            verwerkStudent(klassen, richtingen, klas, richting, bijRichting);

            // Haalt de lijst van vakken based on klas, richting, en bijRichting
            vector<Vak> &vakken = vakkenMap[{klas, richting}][bijRichting];
            string beoordelingSLB;
            toonVakkenEnVoerCijfersIn(vakken, beoordelingSLB);
            string vakNaderOnderzoek;

            // 1e klas electro
            if (klas == 1 && richting == 1 && bijRichting == 0) {
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers1eKlasElektro(vakken, 2, 5, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }

                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                         }
                         cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Praktijk Inleiding Electro en LO" << endl;

                }
            }
            // 2e klas electro
            else if (klas == 2 && richting == 1 && bijRichting == 0) {
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers2eKlasElektro(vakken, 3, 5, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }

                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                         }
                         cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Praktijk Info, Praktijk energie en LO" << endl;
                }
            }
            // 3e klas electro energie
            else if (klas == 3 && richting == 1 && bijRichting == 1) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers3eKlasElektroEnergie(vakken, 4, 5.5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }

                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 3e klas electro info
            else if (klas == 3 && richting == 1 && bijRichting == 2) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers3eKlasElektroInfo(vakken, 4, 5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 4e klas electro energie
            else if (klas == 4 && richting == 1 && bijRichting == 1) {
                string vakNaderOnderzoek;
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers4eKlasElektroEnergie(vakken, 4, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is geslaagd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet geslaagd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                        cout << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 4e klas electro info
            else if (klas == 4 && richting == 1 && bijRichting == 2) {
                string vakNaderOnderzoek;
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers4eKlasElektroInfo(vakken, 3, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is geslaagd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet geslaagd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                        cout << "De student kijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO"<< endl;
                    }
                }
            }
            // 1e klas wtb
            else if (klas == 1 && richting == 2 && bijRichting == 0) {
                string vakNaderOnderzoek;
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers1eKlasWTB(vakken, 2, 5, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                    }
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

                    cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Inleiding Werktuigbouwkunde en LO" << endl;
                }
            }
            // 2e klas wtb
            else if (klas == 2 && richting == 2 && bijRichting == 0) {
                string vakNaderOnderzoek;
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers2eKlasWTB(vakken, 2, 4.5, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                    }
                    cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Productietechnieken, Lassenpraktijk en LO" << endl;
                }
            }
            // 3e klas wtb
            else if (klas == 3 && richting == 2 && bijRichting == 0) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers3eKlasWTB(vakken, 4, 5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }

            }
            // 4e klas wtb
            else if (klas == 4 && richting == 2 && bijRichting == 0) {
                string vakNaderOnderzoek;
                bool heeftNaderOnderzoek = false;
                bool voldoetAanEisen = controleerCijfers4eKlasWTB(vakken, 4, vakNaderOnderzoek);
                if (!vakNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is geslaagd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet geslaagd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "Het vak dat in aanmerking komt voor nader onderzoek is: " << vakNaderOnderzoek << endl;
                    }
                }
            }
            // 1e klas infra
            else if (klas == 1 && richting == 3 && bijRichting == 0) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers1eKlasInfra(vakken, 2, 4, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 2e klas infra
            else if (klas == 2 && richting == 3 && bijRichting == 0) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers2eKlasInfra(vakken, 3, 4.5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 3e klas infra bouw
            else if (klas == 3 && richting == 3 && bijRichting == 1) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers3eKlasInfraBouwkunde(vakken, 3, 4.5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 3e klas infra weg en water
            else if (klas == 3 && richting == 3 && bijRichting == 2) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers3eKlasInfraWegenWater(vakken, 3.5, 5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is bevorderd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet bevorderd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 4e klas infra bouw
            else if (klas == 4 && richting == 3 && bijRichting == 1) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers4eKlasInfraBouwkunde(vakken, 5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is geslaagd." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet geslaagd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            // 4e klas infra weg en water
            else if (klas == 4 && richting == 3 && bijRichting == 2) {
                bool heeftNaderOnderzoek = false;
                vector<string> vakkenNaderOnderzoek;
                bool voldoetAanEisen = controleerCijfers4eKlasInfraWegenWater(vakken, 5, vakkenNaderOnderzoek);
                if (!vakkenNaderOnderzoek.empty()) {
                    heeftNaderOnderzoek = true;
                }
                if (voldoetAanEisen && !heeftNaderOnderzoek &&
                    (beoordelingSLB == "V" || beoordelingSLB == "v" || beoordelingSLB == "G" || beoordelingSLB == "g")) {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_GREEN);
                    cout << "De student heeft voldaan aan alle eisen." << endl;
                    cout << "De student is geslaagd ." << endl;
                } else {
                    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
                    cout << "De student heeft niet voldaan aan alle eisen." << endl;
                    cout << "De student is niet geslaagd." << endl;

                    if (heeftNaderOnderzoek) {
                        cout << "De vakken die in aanmerking komen voor nader onderzoek zijn: ";
                        for (const auto& vak : vakkenNaderOnderzoek) {
                        cout << vak << " ";
                    }
                        cout << endl << "De student krijgt geen NO voor de volgende vakken: SLB, Elektrometingen, Elektromontage en LO" << endl;
                    }
                }
            }
            else {
                cout << "Geen regels beschikbaar voor deze klas, richting en bijrichting combinatie." << endl;
            }

            break;
        } catch (const runtime_error &e) {
            if (string(e.what()) == "Restart") {
                cout << "Herstart het programma..." << endl;
                continue;
            } else {
                throw;
            }
        }
    }
}

int main() {
    HANDLE consolehwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    char userChoice;

    map<int, string> klassen = {
        {1, "1e klas"},
        {2, "2e klas"},
        {3, "3e klas"},
        {4, "4e klas"}
    };

    map<int, Direction> richtingen = {
        {1, {"Elektro", {{1, "Energie"}, {2, "Informatie"}}}},
        {2, {"WTB", {}}},
        {3, {"Infra", {{1, "Bouwkunde"}, {2, "Weg-en waterbouw"}}}}
    };

        map<pair<int, int>, map<int, vector<Vak>>> vakkenMap = {
//1e klas electro
{{1, 1}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 2}, {"Natuurkunde", 0, 2}, {"Scheikunde", 0, 2},
        {"Bedrijfskunde", 0, 3}, {"Lerenloopbaan", 0, 3}, {"Burgerschap", 0, 3},{"HSE",0, 3}, {"LO", 0, 3}, {"ICT", 0, 3},
        {"ElectriciteitsLeer", 0, 4}, {"Electronica", 0, 4}, {"Installatietechniek", 0, 4}, {"Technisch Tekenen", 0, 5},
        {" Praktijk Inleiding Electro", 0, 5}
    }}
}},
// 2e klas electro
{{2, 1}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 2}, {"Natuurkunde", 0, 2}, {"Scheikunde", 0, 2},
        {"Bedrijfskunde", 0, 3}, {"Lerenloopbaan", 0, 3}, {"Burgerschap", 0, 3}, {"LO", 0, 3},
        {"Electriciteitsleer", 0, 4}, {"Electronica", 0, 4}, {"Energie Overdracht", 0, 4},
        {"Installatietechniek", 0, 5}, {"Veiligheid", 0, 5}, {"Meetinstrumenten", 0, 5},
        {"Technisch Tekenen", 0, 6}, {"Praktijk Energie", 0, 6}, {"Praktijk Info", 0, 6}
    }}
}},
// 3e klas electro energie en info
{{3, 1}, {
    {1, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"LO", 0, 2}, {"Scheikunde", 0, 2},
        {"ICT", 0, 3},{"Telecommunicatie", 0, 3}, {"Meetinstrumenten", 0, 3}, {"Werktuigbouwkunde", 0, 3},
        {"Installatietechniek", 0, 3}, {"Digitaletechniek", 0, 3},
        {"Elektriciteitsleer", 0, 4}, {"Vermogens Elektronica", 0, 4}, {"Energie overdracht", 0, 4},
        {"Elektrische-Metingen", 0, 5}, {"Elektro-montage", 0, 5}, {"Technisch Tekenen", 0, 5}
    }}
,{2, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"LO", 0, 2}, {"Scheikunde", 0, 2}, {"ICT", 0, 3},
        {"Telecommunicatie", 0, 3}, {"Meetinstrumenten", 0, 3}, {"Computertechniek", 0, 3},
        {"Installatietechniek", 0, 3}, {"Elektriciteitsleer", 0, 4}, {"Elektronica", 0, 4}, {"Digitaletechniek", 0, 4},
        {"Elektrische-Metingen", 0, 5}, {"Elektro-montage", 0, 5}, {"Technisch Tekenen", 0, 5}
    }}
}},
// 4e klas electro energie en info
{{4, 1}, {
    {1, {
        {"Wiskunde", 0, 1}, {"Bedrijfskunde", 0, 1}, {"ICT", 0, 2}, {"Telecommunicatie", 0, 2},
        {"Meetinstrumenten", 0, 2}, {"Computertechniek", 0, 2}, {"Installatietechniek", 0, 2}, {"Digitale techniek", 0, 2},
        {"Technologie", 0, 2}, {"Elektriciteitsleer", 0, 3}, {"Vermogens Electronica", 0, 3},
        {"Energieoverdracht", 0, 3}, {"Elektrische Metingen", 0, 4},
        {"Elektromontage", 0, 4}, {"Technisch Tekenen", 0, 4},
        {"Afstudeerproject", 0, 6}
    }}
,{2, {
        {"Wiskunde", 0, 1}, {"Bedrijfskunde", 0, 1},
        {"ICT", 0, 2}, {"Telecommunicatie", 0, 2}, {"Meetinstrumenten", 0, 2}, {"Computertechniek", 0, 2},
        {"Elektriciteitsleer", 0, 3}, {"Elektronica", 0, 3}, {"Digitaletechniek", 0, 3},
        {"Elektrische Metingen", 0, 4}, {"Elektromontage", 0, 4}, {"Technisch Tekenen", 0, 4},
        {"Afstudeerproject", 0, 6}
    }}
}},
// 1e klas wtb
{{1, 2}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 2}, {"Natuurkunde", 0, 2}, {"Scheikunde", 0, 2},
        {"Bedrijfskunde", 0, 3}, {"Lerenloopbaan", 0, 3}, {"Burgerschap", 0, 3},
        {"HSE", 0, 3}, {"LO", 0, 3}, {"ICT", 0, 3}, {"Materialen", 0, 4}, {"Productie Theorie/Techniek", 0, 4},
        {"Constructie Leer", 0, 4}, {"Tekenen", 0, 5}, {"Inleiding Werktuigbouwkunde", 0, 5}
    }}
}},
// 2e klas wtb
{{2, 2}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 2}, {"Natuurkunde", 0, 2},
        {"Bedrijfskunde", 0, 3}, {"Lerenloopbaan", 0, 3}, {"Burgerschap", 0, 3}, {"LO", 0, 3},
        {"Materialen", 0, 4}, {"Productie Theorie/Techniek", 0, 4}, {"Constructieleer", 0, 4}, {"Arbeidswerktuigen", 0, 4}, {"Veiligheid", 0, 4},
        {"Tekenen", 0, 5}, {"Productietechnieken Praktijk", 0, 5}, {"Lassen Praktijk", 0, 5}
    }}
}},
// 3e klas wtb
{{3, 2}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"LO", 0, 2}, {"Werktuigonderdelen", 0, 3}, {"Transportwerktuigen", 0, 3},
        {"Voertuigentechniek Theorie", 0, 3}, {"Koeltechniek Theorie", 0, 3}, {"Arbeidswerktuigen", 0, 3},
        {"Constructieleer", 0, 4}, {"Staalconstructie", 0, 4}, {"Veiligheid", 0, 4}, {"Onderhoudsmanagement", 0, 4},
        {"Tekenen", 0, 5}, {"Productietechnieken Praktijk", 0, 5}, {"Praktijk Materialen en Metingen", 0, 5}
    }}
}},
// 4e klas wtb
{{4, 2}, {
    {0, {
        {"Wiskunde", 0, 1}, {"Bedrijfskunde", 0, 1}, {"Regelen en Besturen", 0, 2},
        {"Elektrotechniek", 0, 2}, {"Voertuigentechniek Theorie", 0, 2}, {"Koeltechniek Theorie", 0, 2}, {"Werktuigonderdelen", 0, 3},
        {"Transportwerktuigen", 0, 3}, {"Staalconstructies", 0, 3}, {"Pnue & Hydr Theorie", 0, 3}, {"Tekenen", 0, 4},
        {"CNC praktijk", 0, 4}, {"Onderhoudsman.", 0, 4},
        {"Koeltechniek Praktijk", 0, 4}, {"Voertuigen praktijk", 0, 4},
        {"Afstudeerproject", 0, 6}
    }}
}},
// 1e klas infra
{{1, 3}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 2}, {"Natuurkunde", 0, 2},
        {"Bedrijfskunde", 0, 3}, {"Lerenloopbaan", 0, 3}, {"Burgerschap", 0, 3}, {"LO", 0, 3}, {"ICT", 0, 3}, {"HSE", 0, 3},
        {"Betontechnologie, Materialen en Grondwerken", 0, 4}, {"Inleiding Infrastructuur", 0, 4},
        {"Sterkteleer", 0, 4}, {"Tekenen", 0, 4}, {"Handvaardigheid", 0, 4}
    }}
}},
// 2e klas infra
{{2, 3}, {
    {0, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"Burgerschap", 0, 2}, {"Leren Loopbaan", 0, 2}, {"LO", 0, 2},
        {"Materialen", 0, 3}, {"Grondwerken", 0, 3}, {"Betontechnologie", 0, 3}, {"ICT", 0, 3},
        {"Sterkteleer", 0, 4}, {"Infrastructuur", 0, 4},
        {"Tekenen", 0, 5}, {"Houtbewerking", 0, 5},
        {"Beroepspraktijkvorming (snuffelstage)", 0, 7}
    }}
}},
// 3e klas infra bouw & weg en water
{{3, 3}, {
    {1, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"LO", 0, 2}, {"Leren Loopbaan", 0, 2},
        {"ICT", 0, 3}, {"Landmeten", 0, 3}, {"Bestekken en begroten", 0, 3},
        {"Sterkteleer", 0, 4}, {"Hout- en Staalconstructie", 0, 4}, {"Constructieleer", 0, 4},
        {"Tekenen", 0, 5}, {"Bouwkunde praktijk", 0, 5}, {"Beton en Metselwerk", 0, 5},
        {"Beroepspraktijkvorming (stage)", 0, 7}
    }}
,{2, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"LO", 0, 2}, {"Leren Loopbaan", 0, 2},
        {"ICT", 0, 3}, {"Landmeten", 0, 3}, {"Bestekken en begroten", 0, 3},
        {"Sterkteleer", 0, 4}, {"Waterbouwkunde", 0, 4}, {"Wegenbouwkunde", 0, 4}, {"Hout- en Staalconstructie", 0, 4},
        {"Tekenen", 0, 5}, {"Weg- en waterbouwkunde praktijk", 0, 5}, {"Beton en Metselwerk", 0, 5},
        {"Beroepspraktijkvorming (stage)", 0, 7}
    }}
}},
// 4e klas infra bouw & weg en water
{{4, 3}, {
    {1, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
        {"Bedrijfskunde", 0, 2}, {"Grondmechanica", 0, 2}, {"Beheer en onderhoud", 0, 3},
        {"Bouwfysica", 0, 3}, {"Landmeten", 0, 3}, {"Bestekken en Begroten", 0, 3},
        {"Architectuur geschiedenis", 0, 3},
        {"Sterkteleer", 0, 4}, {"Betonconstructie", 0, 4}, {"Constructieleer", 0, 4},
        {"Ontwerptechnieken", 0, 4},
        {"Tekenen", 0, 5}, {"Bouwkunde praktijk", 0, 5}, {"Laboratorium Onderzoek", 0, 5},
        {"Beroepspraktijkvorming (Afstudeerprojekt)", 0, 7}
    }}
,{2, {
        {"Nederlands", 0, 1}, {"Engels", 0, 1}, {"Wiskunde", 0, 1}, {"Natuurkunde", 0, 1},
            {"Bedrijfskunde", 0, 2}, {"Grondmechanica", 0, 2}, {"Hydraulica", 0, 2}, {"Beheer en onderhoud", 0, 3},
            {"Rioleringen", 0, 3}, {"Landmeten", 0, 3}, {"Bestekken en Begroten", 0, 3},
            {"Sterkteleer", 0, 4}, {"Betonconstructie", 0, 4},{"Civiele gezondheistechniek", 0, 4},
            {"Wegentechnologie", 0, 4},
            {"Tekenen", 0, 5}, {"Waterbouwkunde praktijk", 0, 5},{"Laboratorium Onderzoek", 0, 5},
            {"Beroepspraktijkvorming (Afstudeerprojekt)", 0, 7}}}}},
    };

    do {
        runProgram(klassen, richtingen, vakkenMap);

        SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << endl << "Wil u terug naar het hoofdmenu of het programma sluiten?";
        cout << endl << "m) Terug naar hoofdmenu";
        cout << endl << "s) Programma sluiten" << endl;
        cin >> userChoice;

        while (userChoice != 'm' && userChoice != 's') {
            SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
            cout << "Ongeldige invoer. Voer in 'm' om weer terug naar hoofdmenu of 's' om te sluiten: ";
            cin >> userChoice;
        }


        if (userChoice == 'm' && !benJeZeker("Weet u zeker dat u terug wilt naar het hoofdmenu?")) {
            userChoice = 's';
        }

        // Confirm the choice to close the program
        if (userChoice == 's' && !benJeZeker("Weet u zeker dat u het programma wilt sluiten?")) {
            userChoice = 'm';
        }

    } while (userChoice == 'm');

    SetConsoleTextAttribute(consolehwnd, FOREGROUND_RED);
    cout << "Programma sluiten. Goodbye!" << endl;
    return 0;
}
