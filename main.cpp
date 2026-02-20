#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

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

int main() {
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
        int sum = 0;          // !!! labai svarbu

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
//            << std::setw(6)  << "Egz"
            << std::setw(8)  << "Rez" << endl;
//            << "Pazymiai" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
//                << std::setw(6)  << s.exam
                << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;

/*            for (int p : s.paz) cout << p << " ";
            cout << endl;*/
        }
    }

    if (pasirinkimas == 2) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
//            << std::setw(6)  << "Egz"
            << std::setw(8)  << "Med" << endl;
//            << "Pazymiai" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
//                << std::setw(6)  << s.exam
                << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;

/*            for (int p : s.paz) cout << p << " ";
            cout << endl;*/
        }
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}