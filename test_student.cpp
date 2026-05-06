#include "studentas.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

int main() {
    std::cout << "=== STUDENTAS UNIT TEST START ===\n";

    Studentas s1;
    assert(s1.vardas() == "Vardenis");
    assert(s1.pavarde() == "Pavardenis");
    assert(s1.exam() == 0);

    std::vector<int> paz = {8, 9, 10};
    Studentas s2("Jonas", "Jonaitis", paz, 9, 8.5, 9.0);

    assert(s2.vardas() == "Jonas");
    assert(s2.pavarde() == "Jonaitis");
    assert(s2.exam() == 9);
    assert(s2.rez() == 8.5);
    assert(s2.med() == 9.0);

    Studentas s3(s2);
    assert(s3.vardas() == "Jonas");
    assert(s3.pavarde() == "Jonaitis");
    assert(s3.exam() == 9);

    Studentas s4(std::move(s3));
    assert(s4.vardas() == "Jonas");
    assert(s4.pavarde() == "Jonaitis");
    assert(s4.exam() == 9);

    Studentas s5;
    s5 = s2;
    assert(s5.vardas() == "Jonas");
    assert(s5.pavarde() == "Jonaitis");
    assert(s5.exam() == 9);

    Studentas s6;
    s6 = std::move(s5);
    assert(s6.vardas() == "Jonas");
    assert(s6.pavarde() == "Jonaitis");
    assert(s6.exam() == 9);

    s6.setVardas("Petras");
    s6.setPavarde("Petraitis");
    s6.setExam(10);
    s6.setRez(9.5);
    s6.setMed(9.0);

    assert(s6.vardas() == "Petras");
    assert(s6.pavarde() == "Petraitis");
    assert(s6.exam() == 10);
    assert(s6.rez() == 9.5);
    assert(s6.med() == 9.0);

    std::stringstream ss;
    ss << s6;
    assert(!ss.str().empty());

    std::cout << "Visi Studentas unit testai praejo sekmingai.\n";
    std::cout << "=== STUDENTAS UNIT TEST END ===\n";

    return 0;
}