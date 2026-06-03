#include <iomanip>
#include <iostream>
#include <string>
#include "isvestis.h"

using std::cout;
using std::left;

void spausdinti(const ProgramosVector<Studentas>& grupe, bool rodytiMediana) {
    cout << left
         << std::setw(15) << "Vardas"
         << std::setw(15) << "Pavarde";

    if (rodytiMediana)
        cout << std::setw(20) << "Galutinis (Med.)";
    else
        cout << std::setw(20) << "Galutinis (Vid.)";

    cout << "\n";
    cout << std::string(50, '-') << "\n";

    for (const Studentas& s : grupe) {
        cout << left
             << std::setw(15) << s.vardas()
             << std::setw(15) << s.pavarde()
             << std::fixed << std::setprecision(2);

        if (rodytiMediana)
            cout << std::setw(20) << s.med();
        else
            cout << std::setw(20) << s.rez();

        cout << "\n";
    }
}
