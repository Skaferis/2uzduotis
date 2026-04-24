#include "studentas.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== TEST START ===\n";

    // default constructor
    Studentas s1;
    std::cout << "Default: " << s1 << "\n";

    // parametrinis
    std::vector<int> paz = {8, 9, 10};
    Studentas s2("Jonas", "Jonaitis", paz, 9, 8.5, 9.0);
    std::cout << "Parametrinis: " << s2 << "\n";

    // COPY constructor
    Studentas s3(s2);
    std::cout << "Copy ctor: " << s3 << "\n";

    // MOVE constructor
    Studentas s4(std::move(s3));
    std::cout << "Move ctor: " << s4 << "\n";

    // COPY assignment
    Studentas s5;
    s5 = s2;
    std::cout << "Copy assign: " << s5 << "\n";

    // MOVE assignment
    Studentas s6;
    s6 = std::move(s5);
    std::cout << "Move assign: " << s6 << "\n";

    std::cout << "=== TEST END ===\n";

    return 0;
}