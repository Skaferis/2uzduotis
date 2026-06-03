#include "studentas.h"
#include <iostream>
#include <utility>

int main() {
    std::cout << "=== TEST START ===\n";

    Studentas s1;
    std::cout << "Default: " << s1 << "\n";

    ProgramosVector<int> paz = {8, 9, 10};
    Studentas s2("Jonas", "Jonaitis", paz, 9, 8.5, 9.0);
    std::cout << "Parametrinis: " << s2 << "\n";

    Studentas s3(s2);
    std::cout << "Copy ctor: " << s3 << "\n";

    Studentas s4(std::move(s3));
    std::cout << "Move ctor: " << s4 << "\n";

    Studentas s5;
    s5 = s2;
    std::cout << "Copy assign: " << s5 << "\n";

    Studentas s6;
    s6 = std::move(s5);
    std::cout << "Move assign: " << s6 << "\n";

    std::cout << "Pazymiu kiekis: " << s6.paz().size() << "\n";
    std::cout << "=== TEST END ===\n";

    return 0;
}
