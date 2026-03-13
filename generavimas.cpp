#include <fstream>
#include <iomanip>
#include <random>
#include <stdexcept>
#include <string>

#include "generavimas.h"

void generuotiFaila(const std::string& failoPavadinimas, int studentuKiekis, int ndKiekis) {
    std::ofstream failas(failoPavadinimas);

    if (!failas.is_open()) {
        throw std::runtime_error("Nepavyko sukurti failo: " + failoPavadinimas);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> pazymys(1, 10);

    failas << std::left
           << std::setw(20) << "Vardas"
           << std::setw(20) << "Pavarde";

    for (int i = 1; i <= ndKiekis; i++) {
        failas << std::setw(8) << ("ND" + std::to_string(i));
    }

    failas << std::setw(8) << "Egz." << "\n";

    for (int i = 1; i <= studentuKiekis; i++) {
        failas << std::left
               << std::setw(20) << ("Vardas" + std::to_string(i))
               << std::setw(20) << ("Pavarde" + std::to_string(i));

        for (int j = 0; j < ndKiekis; j++) {
            failas << std::setw(8) << pazymys(gen);
        }

        failas << std::setw(8) << pazymys(gen) << "\n";
    }

    failas.close();
}