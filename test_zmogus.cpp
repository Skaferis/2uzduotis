#include "studentas.h"
#include <iostream>
#include <type_traits>
#include <cassert>

int main() {
    std::cout << "=== ZMOGUS TEST START ===\n";

    static_assert(std::is_abstract<Zmogus>::value, "Zmogus turi buti abstrakti klase");
    static_assert(std::is_base_of<Zmogus, Studentas>::value, "Studentas turi paveldeti Zmogus klase");

    Studentas s;
    s.print();

    std::cout << "Zmogus klase yra abstrakti.\n";
    std::cout << "Studentas klase paveldi Zmogus klase.\n";

    std::cout << "=== ZMOGUS TEST END ===\n";
    return 0;
}