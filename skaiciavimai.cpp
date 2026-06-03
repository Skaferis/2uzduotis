#include "skaiciavimai.h"
#include <algorithm>

double skaiciuotiMediana(ProgramosVector<int> paz) {
    std::sort(paz.begin(), paz.end());

    int n = static_cast<int>(paz.size());

    if (n == 0) {
        return 0;
    }

    if (n % 2 == 1) {
        return paz[n / 2];
    }

    return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
}

double skaiciuotiGalutini(int suma, int kiekis, int egzaminas) {
    if (kiekis > 0) {
        double vid = static_cast<double>(suma) / kiekis;
        return vid * 0.4 + egzaminas * 0.6;
    }

    return egzaminas * 0.6;
}

double skaiciuotiGalutiniMed(ProgramosVector<int> paz, int egzaminas) {
    double mediana = skaiciuotiMediana(paz);
    return mediana * 0.4 + egzaminas * 0.6;
}
