#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <random>
#include <fstream> // failo skaitymas/rašymas
#include <sstream> // failo eilutės apdorojimas
#include <cctype> // isalpha

using std::left;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Studentas {
    string vardas = "Vardenis";
    string pavarde = "Pavardenis";
    vector<int> paz;
    int exam = 0;
    double rez = 0.0;
    double med = 0.0;
};

int ranka() {
    int stud;
    vector<Studentas> grupe;
    cout << "Kiek studentu grupeje? ";
    cin >> stud;


    while (cin.fail()) {
        cout << "Kiek studentu grupeje, iveskite skaiciu: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> stud;
    }

    for (int ii = 0; ii < stud; ii++) {
        Studentas A;          // naujas studentas kiekvieną kartą
        int sum = 0;

        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;

        bool gerai = false;

        while (!gerai) {
            gerai = true;

            // tikrinam varda
            for (char c : A.vardas) {
                if (!isalpha(c)) {
                    gerai = false;  
                    break;
                }
            }

            // tikrinam pavarde
            for (char c : A.pavarde) {
                if (!isalpha(c)) {
                    gerai = false;
                    break;
                }
            }

            if (!gerai) {
                cout << "Bloga ivestis. Iveskite TIK RAIDES (vardas pavarde): ";
                cin >> A.vardas >> A.pavarde;
            }
        }

        cout << "Kiek bus pazymiu? ";
        int n, temp;
        cin >> n;

        while (cin.fail()) {
            cout << "Kiek bus pazymiu, iveskite skaiciu: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> n;
        }

        cout << "Iveskite pazymius: ";
        
        for (int i = 0; i < n; i++) {
            cin >> temp;
            while (cin.fail()) {
                cout << "Iveskite pazymius, iveskite skaiciu: ";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> temp;
            }
            A.paz.push_back(temp);
            sum += temp;
        }

        sort(A.paz.begin(), A.paz.end());

        if (n > 0) {
            if (n % 2 == 1) {
                A.med = A.paz[n / 2];
            } else {
                A.med = (A.paz[n / 2 - 1] + A.paz[n / 2]) / 2.0;
            }
        }

        cout << "Iveskite egzamino paz: ";
        cin >> A.exam;

        while (cin.fail()) {
            cout << "Iveskite egzamino paz, iveskite skaiciu: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> A.exam;
        }

        if (n > 0) {
            double vid = static_cast<double>(sum) / n;
            A.rez = vid * 0.4 + A.exam * 0.6;
        } else {
            A.rez = A.exam * 0.6; // jei pažymių nėra
        }

        grupe.push_back(A);   // tik čia dedam į grupę
    }

    cout << "Ka norite matyti (1 - vidurkis, 2 - mediana)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Rez" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;
        }
    }

    if (pasirinkimas == 2) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Med" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;
        }
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}

int automatiskai() {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist10(1, 10); // 1..10

    int stud;
    vector<Studentas> grupe;

    vector<string> vardai_v = {"Jonas","Mantas","Tomas", "Petras", "Domas", "Lukas", "Simas", "Dainius", "Giedrius", "Rokas"};
    vector<string> pavardes_v = {"Kazlauskas","Petrauskas", "Jonauskas", "Domauskas", "Lukauskas", "Simanauskas", "Dainiauskas", "Giedriuskas", "Rokauskas", "Ievaskas"};

    vector<string> vardai_m = {"Ieva","Gabija", "Ugne", "Egle", "Aiste", "Rasa", "Indre", "Dovile", "Agniete", "Viktorija"};
    vector<string> pavardes_m = {"Kazlauskaite","Petrauskaite", "Jonauskaite", "Domauskaite", "Lukauskaite", "Simanauskaite", "Dainiauskaite", "Giedriuskaite", "Rokauskaite", "Ievaskaite"};

    vector<std::pair<string,string>> studentai;

    for (const auto& v : vardai_v) {
        for (const auto& p : pavardes_v) {
            studentai.push_back({v, p});
        }
    }

    for (const auto& v : vardai_m) {
        for (const auto& p : pavardes_m) {
            studentai.push_back({v, p});
        }
    }
    
    std::shuffle(studentai.begin(), studentai.end(), gen);

    stud = dist10(gen); // atsitiktinis studentų skaičius nuo 1 iki 10

    for (int ii = 0; ii < stud; ii++) {
        Studentas A;          // naujas studentas kiekvieną kartą
        int sum = 0;          // !!! labai svarbu pasižymėt kiekvieną kartą

        int temp;
        int n = dist10(gen); // atsitiktinis pažymių skaičius nuo 1 iki 10

        A.vardas  = studentai[ii].first;
        A.pavarde = studentai[ii].second;
        
        for (int i = 0; i < n; i++) {
            temp = dist10(gen); // atsitiktinis pažymys nuo 1 iki 10
            A.paz.push_back(temp);
            sum += temp;
        }

        sort(A.paz.begin(), A.paz.end());

        if (n > 0) {
            if (n % 2 == 1) {
                A.med = A.paz[n / 2];
            } else {
                A.med = (A.paz[n / 2 - 1] + A.paz[n / 2]) / 2.0;
            }
        }

        A.exam = dist10(gen); // atsitiktinis egzamino pažymys nuo 1 iki 10

        if (n > 0) {
            double vid = static_cast<double>(sum) / n;
            A.rez = vid * 0.4 + A.exam * 0.6;
        } else {
            A.rez = A.exam * 0.6; // jei pažymių nėra
        }

        grupe.push_back(A);   // čia dedam į grupę
    }

    cout << "Ka norite matyti (1 - vidurkis, 2 - mediana)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Rez" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;

        }
    }

    if (pasirinkimas == 2) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Med" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;
        }
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}

int skaitymas() {
    return 0;
}

int main() {
    int pasirinkti;
    cout << "Irasyti ranka - 1, generuoti - 2, nuskaityti is failo - 3: ";
    cin >> pasirinkti;
    if (pasirinkti == 1) {
        return ranka();
    } else if (pasirinkti == 2) {
        return automatiskai();
    } else if (pasirinkti == 3) {
        return skaitymas();
    }
    else {
        cout << "Neteisingas pasirinkimas.\n";
        return 0;
    }
}