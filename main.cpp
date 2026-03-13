#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <random>
#include <fstream> // failo skaitymas/rašymas
#include <sstream> // failo eilutės apdorojimas
#include <cctype> // isalpha
#include <stdexcept> // std::runtime_error

#include "studentas.h" // studentu struktūros aprašas
#include "skaiciavimai.h" // funkcijos skaičiavimams
#include "ivestis.h" // funkcijos įvesties validacijai
#include "isvestis.h" // funkcijos rezultatų spausdinimui
#include "generavimas.h" // funkcija generavimui

using std::left;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::ifstream;
using std::stringstream;
using std::ofstream;

int ranka() {
    int stud;
    vector<Studentas> grupe;

    stud = ivestiSveika("Kiek studentu grupeje? ");

    for (int ii = 0; ii < stud; ii++) {
        Studentas A;          // naujas studentas kiekvieną kartą
        int sum = 0;

        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;

        while (!arTikRaides(A.vardas) || !arTikRaides(A.pavarde)) {
            cout << "Bloga ivestis. Iveskite TIK RAIDES (vardas pavarde): ";
            cin >> A.vardas >> A.pavarde;
        }

        int n, temp;

        n = ivestiSveika("Kiek bus pazymiu? ");

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

        A.med = skaiciuotiMediana(A.paz);
        
        A.exam = ivestiSveika("Iveskite egzamino paz: ");

        A.rez = skaiciuotiGalutini(sum, n, A.exam);

        grupe.push_back(A);   // tik čia dedam į grupę
    }

    cout << "Ka norite matyti (1 - vidurkis, 2 - mediana)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        spausdinti(grupe, false);
    }

    if (pasirinkimas == 2) {
        spausdinti(grupe, true);
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}

int generavimas() {
    int ndKiekis;

    cout << "Kiek namu darbu pazymiu generuoti kiekvienam studentui? ";
    cin >> ndKiekis;

    while (cin.fail() || ndKiekis <= 0) {
        cout << "Iveskite teigiama skaiciu: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> ndKiekis;
    }

    vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};

    try {
        for (int kiekis : dydziai) {
            string failoPavadinimas = "studentai" + std::to_string(kiekis) + ".txt";
            generuotiFaila(failoPavadinimas, kiekis, ndKiekis);
            cout << "Sugeneruotas failas: " << failoPavadinimas << endl;
        }
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

int automatiskai() {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist10(1, 10); // 1..10

    int stud;
    vector<Studentas> grupe;

    vector<string> vardai_v = {"Jonas","Mantas","Tomas", "Petras", "Domas", "Lukas", "Simas", "Dainius", "Giedrius", "Rokas"};
    vector<string> pavardes_v = {"Kazlauskas","Petrauskas", "Jonauskas", "Domauskas", "Lukauskas", "Simanauskas", "Dainiauskas", "Giedriuskas", "Rokauskas", "Ievaskas"};

    vector<string> vardai_m = {"Ieva","Gabija", "Ugne", "Egle", "Aiste", "Rasa", "Indre", "Dovile", "Agniete", "Viktorija"};
    vector<string> pavardes_m = {"Kazlauskaite","Petrauskaite", "Jonauskaite", "Domauskaite", "Lukauskaite", "Simanauskaite", "Dainiauskaite", "Giedriuskaite", "Rokauskaite", "Ievaskaite"};

    vector<Asmuo> studentai;

    for (const auto& v : vardai_v) {
        for (const auto& p : pavardes_v) {
            studentai.push_back(Asmuo{v, p});
        }
    }

    for (const auto& v : vardai_m) {
        for (const auto& p : pavardes_m) {
            studentai.push_back(Asmuo{v, p});
        }
    }
    
    std::shuffle(studentai.begin(), studentai.end(), gen);

    stud = dist10(gen); // atsitiktinis studentų skaičius nuo 1 iki 10

    for (int ii = 0; ii < stud; ii++) {
        Studentas A;          // naujas studentas kiekvieną kartą
        int sum = 0;          // !!! labai svarbu pasižymėt kiekvieną kartą

        int temp;
        int n = dist10(gen); // atsitiktinis pažymių skaičius nuo 1 iki 10

        A.vardas  = studentai[ii].vardas;
        A.pavarde = studentai[ii].pavarde;
        
        for (int i = 0; i < n; i++) {
            temp = dist10(gen); // atsitiktinis pažymys nuo 1 iki 10
            A.paz.push_back(temp);
            sum += temp;
        }

        A.med = skaiciuotiMediana(A.paz);

        A.exam = dist10(gen); // atsitiktinis egzamino pažymys nuo 1 iki 10

        A.rez = skaiciuotiGalutini(sum, n, A.exam);

        grupe.push_back(A);   // čia dedam į grupę
    }

    cout << "Ka norite matyti (1 - vidurkis, 2 - mediana)? ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        spausdinti(grupe, false); // false - rodyti galutini (vidurkis)
    }

    if (pasirinkimas == 2) {
        spausdinti(grupe, true); // true - rodyti galutini (mediana)
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}

int skaitymas() {

    cout << "Iveskite nuskaitomo failo pavadinima (be .txt): ";
    string failoPavadinimas;    
    cin >> failoPavadinimas;

    ifstream failas(failoPavadinimas+".txt");
    vector<Studentas> grupe;
    vector<Studentas> vargsiukai;
    vector<Studentas> galvociai;

    try {
        if (!failas.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo");
        }
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    string eilute;
    getline(failas, eilute); // nusiskaityti pirma eilute (antraštę)
    stringstream info(eilute); // sukurti stringstream objektą iš antraštės
    string zodis; // laikinas kintamasis žodžiui iš stringstream

    int stulpsk;
    int sum;
    stulpsk = 0;

    while (info >> zodis) {
        stulpsk ++;
    }
    stulpsk = stulpsk - 3; 

    while (getline(failas, eilute)) {
        stringstream studentas(eilute);
        Studentas A;
        studentas >> A.vardas >> A.pavarde;

        sum = 0;
        for (int i = 0; i < stulpsk; i++) {
            int paz;
            studentas >> paz;
            A.paz.push_back(paz);
            sum += paz;
//            cout << "(" << i+1 << ") " << paz << " ";
        } 

//        cout << sum;
        studentas >> A.exam;

        A.rez = skaiciuotiGalutini(sum, stulpsk, A.exam);

        A.med = skaiciuotiMediana(A.paz);

        grupe.push_back(A);

    }

//    for (Studentas& s : grupe) {
//        cout << "Vardas: " << s.vardas << ", Pavarde: " << s.pavarde << ", Pazymiai: " << s.paz.size() << ", Egzamino pazymys: " << s.exam << ", Rezultatas: " << s.rez << ", Mediana: " << s.med << endl;
//    }

    for (Studentas& o : grupe) {
        if (o.rez < 5) {
            vargsiukai.push_back(o);
        }
        else {
            galvociai.push_back(o);
        }
    }

    ofstream isvestis(failoPavadinimas+"_rezultatai.txt");

    if (!isvestis.is_open()) {
        cout << failoPavadinimas << "_rezultatai.txt" << "nepavyko sukurti\n";
        return 0;
    }

    isvestis << left
        << std::setw(15) << "Vardas"
        << std::setw(15) << "Pavarde"
        << std::setw(18) << "Galutinis (Vid.)"
        << std::setw(18) << "Galutinis (Med.)"
        << "\n";

    isvestis << string(66, '-') << "\n";

    for (const Studentas& s : grupe) {

        isvestis << left
            << std::setw(15) << s.vardas
            << std::setw(15) << s.pavarde
            << std::fixed << std::setprecision(2)
            << std::setw(18) << s.rez
            << std::setw(18) << s.med
            << "\n";
    }

    isvestis.close();

    return 0;
}

int main() {

    int pasirinkti;

    while (true) {

        try {
            cout << "Irasyti ranka - 1, generuoti - 2, nuskaityti is failo - 3, generuoti failus - 4: ";
            cin >> pasirinkti;

            if (cin.fail()) {
                throw std::runtime_error("Neteisinga ivestis");
            }

            break; // jei ivestis gera - iseinam is ciklo
        }

        catch (const std::exception&) {
            cout << "Klaida: iveskite skaiciu.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    if (pasirinkti == 1) {
        return ranka();
    }
    else if (pasirinkti == 2) {
        return automatiskai();
    }
    else if (pasirinkti == 3) {
        return skaitymas();
    }
    else if (pasirinkti == 4) {
        return generavimas();
    }
    else {
        cout << "Neteisingas pasirinkimas.\n";
        return 0;
    }

}