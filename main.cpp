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


#include "studentas.h" // studentu struktūros aprašas
#include "skaiciavimai.h" // funkcijos skaičiavimams

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
        int sum = 0;

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

        A.med = skaiciuotiMediana(A.paz);

        cout << "Iveskite egzamino paz: ";
        cin >> A.exam;

        while (cin.fail()) {
            cout << "Iveskite egzamino paz, iveskite skaiciu: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> A.exam;
        }

        A.rez = skaiciuotiGalutini(sum, n, A.exam);

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
            << std::setw(8)  << "Rez" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;
        }
    }

    if (pasirinkimas == 2) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Med" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;
        }
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
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
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Rez" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.rez << endl;

        }
    }

    if (pasirinkimas == 2) {
        cout << "\n"
            << left
            << std::setw(12) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(8)  << "Med" << endl;

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(12) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2) << std::setw(8) << s.med << endl;
        }
    }

    if (pasirinkimas != 1 && pasirinkimas != 2) {
        cout << "Neteisingas pasirinkimas.\n";
    }

    return 0;
}

int skaitymas() {
    ifstream failas("kursiokai.txt");
    vector<Studentas> grupe;

    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo kursiokai.txt\n";
        return 0;
    }

    string eilute;
    getline(failas, eilute); // nusiskaityti pirma eilute (antraštę)
//    cout << headeris << endl; 
    stringstream info(eilute); // sukurti stringstream objektą iš antraštės
    string zodis; // laikinas kintamasis žodžiui iš stringstream

    int stulpsk;
    int sum;
    stulpsk = 0;

    while (info >> zodis) {
        stulpsk ++;
    }
    stulpsk = stulpsk - 3; 
//    cout << stulpsk << " namu darbu pazymiu\n" << endl;

    while (getline(failas, eilute)) {
        stringstream studentas(eilute);
        Studentas A;
        studentas >> A.vardas >> A.pavarde;

//        cout << endl;

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

    cout << "Rusiavimas pagal: 1-Varda, 2-Pavarde, 3-Galutinis(Vid), 4-Galutinis(Med): ";
    int r;
    cin >> r;

    while (cin.fail() || r < 1 || r > 4) {
        cout << "Iveskite 1..4: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> r;
    }

    if (r == 1) {
        sort(grupe.begin(), grupe.end(),
            [](const Studentas& a, const Studentas& b) {
                return a.vardas < b.vardas;
            });
    }
    else if (r == 2) {
        sort(grupe.begin(), grupe.end(),
            [](const Studentas& a, const Studentas& b) {
                return a.pavarde < b.pavarde;
            });
    }
    else if (r == 3) {
        sort(grupe.begin(), grupe.end(),
            [](const Studentas& a, const Studentas& b) {
                return a.rez > b.rez; // galutinis (vid.)
            });
    }
    else if (r == 4) {
        sort(grupe.begin(), grupe.end(),
            [](const Studentas& a, const Studentas& b) {
                return a.med > b.med; // galutinis (med.)
            });
    }

    cout << "Pasirinkite kur matyti rezultatus (1 - ekrane, 2 - faile): ";
    int isvedimas;
    cin >> isvedimas;

    while (cin.fail() || (isvedimas != 1 && isvedimas != 2)) {
        cout << "Iveskite 1 arba 2: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> isvedimas;
    }

    if (isvedimas == 1) {
        cout << left
            << std::setw(15) << "Vardas"
            << std::setw(15) << "Pavarde"
            << std::setw(18) << "Galutinis (Vid.)"
            << std::setw(18) << "Galutinis (Med.)"
            << "\n";

        cout << string(66, '-') << "\n";

        for (const Studentas& s : grupe) {
            cout << left
                << std::setw(15) << s.vardas
                << std::setw(15) << s.pavarde
                << std::fixed << std::setprecision(2)
                << std::setw(18) << s.rez
                << std::setw(18) << s.med
                << "\n";
        }
    }
    else if (isvedimas == 2) {

        ofstream isvestis("rezultatai.txt");

        if (!isvestis.is_open()) {
            cout << "Nepavyko sukurti rezultatai.txt\n";
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
    }

    return 0;
}

int main() {
    int pasirinkti;
    cout << "Irasyti ranka - 1, generuoti - 2, nuskaityti is failo - 3: ";
    cin >> pasirinkti;
    if (pasirinkti == 1) {
        return ranka();
    } else if (pasirinkti == 2) {
        return automatiskai();
    } else if (pasirinkti == 3) {
        return skaitymas();
    }
    else {
        cout << "Neteisingas pasirinkimas.\n";
        return 0;
    }
}