#include "skaiciavimai.h"
#include <algorithm>

double skaiciuotiMediana(std::vector<int> paz) {

    std::sort(paz.begin(), paz.end());

    int n = paz.size();

    if (n == 0) {
        return 0;
    }

    if (n % 2 == 1) {
        return paz[n / 2];
    } 
    else {
        return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
    }
}

double skaiciuotiGalutini(int suma, int kiekis, int egzaminas) {

    if (kiekis > 0) {
        double vid = static_cast<double>(suma) / kiekis;
        return vid * 0.4 + egzaminas * 0.6;
    } 
    else {
        return egzaminas * 0.6;
    }
}