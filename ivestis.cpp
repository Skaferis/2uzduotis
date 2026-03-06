#include "ivestis.h"
#include <cctype>
#include <iostream>

bool arTikRaides(const std::string& tekstas) {

    for (char c : tekstas) {
        if (!isalpha(c)) {
            return false;
        }
    }

    return true;
}

using std::cin;
using std::cout;

int ivestiSveika(const std::string& pranesimas) {

    int x;

    cout << pranesimas;
    cin >> x;

    while (cin.fail()) {
        cout << "Klaida. Iveskite skaiciu: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> x;
    }

    return x;
}