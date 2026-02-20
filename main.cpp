#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <random>
#include <cctype>

using std::left;
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Studentas {
    string vardas = "Vardenis";
    string pavarde = "Pavardenis";

    int* paz = nullptr;   // C dinaminis masyvas
    int paz_kiekis = 0;   // kiek pazymiu

    int exam = 0;
    double rez = 0.0;
    double med = 0.0;
};

int ranka() {
    int stud;
    cout << "Kiek studentu grupeje? ";
    cin >> stud;

    while (cin.fail()) {
        cout << "Kiek studentu grupeje, iveskite skaiciu: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> stud;
    }

    Studentas* grupe = new Studentas[stud];

    for (int ii = 0; ii < stud; ii++) {
        Studentas& A = grupe[ii];
        int sum = 0;

        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;

        bool gerai = false;
        while (!gerai) {
            gerai = true;

            if (A.vardas.empty() || A.pavarde.empty()) gerai = false;

            // tikrinam varda
            for (unsigned char c : A.vardas) {
                if (!std::isalpha(c)) { gerai = false; break; }
            }
            // tikrinam pavarde
            for (unsigned char c : A.pavarde) {
                if (!std::isalpha(c)) { gerai = false; break; }
            }

            if (!gerai) {
                cout << "Bloga ivestis. Iveskite TIK RAIDES (vardas pavarde): ";
                cin >> A.vardas >> A.pavarde;
            }
        }

        cout << "Kiek bus pazymiu? ";
        int n;
        cin >> n;

        while (cin.fail()) {
            cout << "Kiek bus pazymiu, iveskite skaiciu: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> n;
        }

        A.paz_kiekis = n;

        if (n > 0) {
            A.paz = new int[n];

            cout << "Iveskite pazymius: ";
            for (int i = 0; i < n; i++) {
                int temp;
                cin >> temp;

                while (cin.fail()) {
                    cout << "Iveskite pazymi, iveskite skaiciu: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cin >> temp;
                }

                A.paz[i] = temp;
                sum += temp;
            }

            std::sort(A.paz, A.paz + n);

            if (n % 2 == 1) A.med = A.paz[n / 2];
            else A.med = (A.paz[n / 2 - 1] + A.paz[n / 2]) / 2.0;

        } else {
            A.paz = nullptr;
            A.med = 0.0;
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
            A.rez = A.exam * 0.6;
        }
    }

    cout << "Ka norite matyti (1 - vidurkis, 2 - mediana)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        cout << "\n" << left
             << std::setw(12) << "Vardas"
             << std::setw(15) << "Pavarde"
             << std::setw(8)  << "Rez" << endl;

        for (int i = 0; i < stud; i++) {
            const Studentas& s = grupe[i];
            cout << left
                 << std::setw(12) << s.vardas
                 << std::setw(15) << s.pavarde
                 << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;
        }
    } else if (pasirinkimas == 2) {
        cout << "\n" << left
             << std::setw(12) << "Vardas"
             << std::setw(15) << "Pavarde"
             << std::setw(8)  << "Med" << endl;

        for (int i = 0; i < stud; i++) {
            const Studentas& s = grupe[i];
            cout << left
                 << std::setw(12) << s.vardas
                 << std::setw(15) << s.pavarde
                 << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;
        }
    } else {
        cout << "Neteisingas pasirinkimas.\n";
    }

    for (int i = 0; i < stud; i++) {
        delete[] grupe[i].paz;
        grupe[i].paz = nullptr;
    }
    delete[] grupe;

    return 0;
}

int automatiskai() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist10(1, 10);

    const int V = 10;

    const string vardai_v[V]   = {"Jonas","Mantas","Tomas","Petras","Domas","Lukas","Simas","Dainius","Giedrius","Rokas"};
    const string pavardes_v[V] = {"Kazlauskas","Petrauskas","Jonauskas","Domauskas","Lukauskas","Simanauskas","Dainiauskas","Giedriuskas","Rokauskas","Ievaskas"};

    const string vardai_m[V]   = {"Ieva","Gabija","Ugne","Egle","Aiste","Rasa","Indre","Dovile","Agniete","Viktorija"};
    const string pavardes_m[V] = {"Kazlauskaite","Petrauskaite","Jonauskaite","Domauskaite","Lukauskaite","Simanauskaite","Dainiauskaite","Giedriuskaite","Rokauskaite","Ievaskaite"};

    // kombinacijos: 200
    const int KOMBI = 200;
    std::pair<string,string>* studentai = new std::pair<string,string>[KOMBI];

    int idx = 0;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            studentai[idx++] = {vardai_v[i], pavardes_v[j]};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            studentai[idx++] = {vardai_m[i], pavardes_m[j]};

    std::shuffle(studentai, studentai + KOMBI, gen);

    int stud = dist10(gen);
    Studentas* grupe = new Studentas[stud];

    for (int ii = 0; ii < stud; ii++) {
        Studentas& A = grupe[ii];
        int sum = 0;

        int n = dist10(gen);
        A.paz_kiekis = n;
        A.paz = new int[n];

        A.vardas  = studentai[ii].first;
        A.pavarde = studentai[ii].second;

        for (int i = 0; i < n; i++) {
            A.paz[i] = dist10(gen);
            sum += A.paz[i];
        }

        std::sort(A.paz, A.paz + n);

        if (n % 2 == 1) A.med = A.paz[n / 2];
        else A.med = (A.paz[n / 2 - 1] + A.paz[n / 2]) / 2.0;

        A.exam = dist10(gen);

        double vid = static_cast<double>(sum) / n;
        A.rez = vid * 0.4 + A.exam * 0.6;
    }

    cout << "Ka norite matyti (1 - vidurkis, 2 - mediana)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        cout << "\n" << left
             << std::setw(12) << "Vardas"
             << std::setw(15) << "Pavarde"
             << std::setw(8)  << "Rez" << endl;

        for (int i = 0; i < stud; i++) {
            const Studentas& s = grupe[i];
            cout << left
                 << std::setw(12) << s.vardas
                 << std::setw(15) << s.pavarde
                 << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;
        }
    } else if (pasirinkimas == 2) {
        cout << "\n" << left
             << std::setw(12) << "Vardas"
             << std::setw(15) << "Pavarde"
             << std::setw(8)  << "Med" << endl;

        for (int i = 0; i < stud; i++) {
            const Studentas& s = grupe[i];
            cout << left
                 << std::setw(12) << s.vardas
                 << std::setw(15) << s.pavarde
                 << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;
        }
    } else {
        cout << "Neteisingas pasirinkimas.\n";
    }

    for (int i = 0; i < stud; i++) {
        delete[] grupe[i].paz;
        grupe[i].paz = nullptr;
    }
    delete[] grupe;
    delete[] studentai;

    return 0;
}

int main() {
    int pasirinkti;
    cout << "Irasyti ranka - 1, generuoti faila - 2: ";
    cin >> pasirinkti;

    if (pasirinkti == 1) return ranka();
    if (pasirinkti == 2) return automatiskai();

    cout << "Neteisingas pasirinkimas.\n";
    return 0;
}