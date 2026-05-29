#include "Vector.h"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    Vector<int> skaiciai;

    assert(skaiciai.size() == 0);
    assert(skaiciai.capacity() == 0);
    assert(skaiciai.empty());

    Vector<std::string> tekstai;

    assert(tekstai.size() == 0);
    assert(tekstai.capacity() == 0);
    assert(tekstai.empty());

    std::cout << "1 etapas: Vector karkasas veikia.\n";
    return 0;
}
