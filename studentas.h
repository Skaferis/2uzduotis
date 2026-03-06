#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Asmuo {
    string vardas;
    string pavarde;
};

struct Studentas {
    string vardas = "Vardenis";
    string pavarde = "Pavardenis";
    vector<int> paz;
    int exam = 0;
    double rez = 0.0;
    double med = 0.0;
};

#endif // STUDENTAS_H