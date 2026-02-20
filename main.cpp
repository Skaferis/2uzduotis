#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
};

int main() {
    vector<Studentas> grupe;

    for (int ii = 0; ii < 2; ii++) {
        Studentas A;          // naujas studentas kiekvieną kartą
        int sum = 0;          // !!! labai svarbu

        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;

        cout << "Kiek bus pazymiu? ";
        int n = 0, temp = 0;
        cin >> n;

        A.paz.clear();
        A.paz.reserve(n);

        cout << "Iveskite pazymius: ";
        for (int i = 0; i < n; i++) {
            cin >> temp;
            A.paz.push_back(temp);
            sum += temp;
        }

        cout << "Iveskite egzamino paz: ";
        cin >> A.exam;

        if (n > 0) {
            double vid = static_cast<double>(sum) / n;
            A.rez = vid * 0.4 + A.exam * 0.6;
        } else {
            A.rez = A.exam * 0.6; // jei pažymių nėra
        }

        grupe.push_back(A);   // tik čia dedam į grupę
    }

    cout << "\n"
         << left
         << std::setw(12) << "Vardas"
         << std::setw(15) << "Pavarde"
         << std::setw(6)  << "Egz"
         << std::setw(8)  << "Rez"
         << "Pazymiai" << endl;

    for (const Studentas& s : grupe) {
        cout << left
             << std::setw(12) << s.vardas
             << std::setw(15) << s.pavarde
             << std::setw(6)  << s.exam
             << std::fixed << std::setprecision(2) << std::setw(8) << s.rez;

        for (int p : s.paz) cout << p << " ";
        cout << endl;
    }

    return 0;
}