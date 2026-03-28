#include <iostream>
#include <iomanip>
#include <deque>
#include <list>
#include "isvestis.h"

using std::cout;
using std::left;

void spausdinti(const std::list<Studentas>& grupe, bool rodytiMediana) {

    cout << left
         << std::setw(12) << "Vardas"
         << std::setw(15) << "Pavarde";

    if (rodytiMediana)
        cout << std::setw(8) << "Med";
    else
        cout << std::setw(8) << "Rez";

    cout << "\n";

    for (const Studentas& s : grupe) {

        cout << left
             << std::setw(12) << s.vardas
             << std::setw(15) << s.pavarde
             << std::fixed << std::setprecision(2);

        if (rodytiMediana)
            cout << std::setw(8) << s.med;
        else
            cout << std::setw(8) << s.rez;

        cout << "\n";
    }
}