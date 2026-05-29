#include <cassert>
#include <iostream>
#include "Vector.h"

void test_empty_vector() {
    Vector<int> v;

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty());
}

void test_clear_empty_vector() {
    Vector<int> v;

    v.clear();

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty());
}

void test_different_types() {
    Vector<int> numbers;
    Vector<double> decimals;

    assert(numbers.empty());
    assert(decimals.empty());
}

int main() {
    test_empty_vector();
    test_clear_empty_vector();
    test_different_types();

    std::cout << "2 etapas: Vector destruktorius ir clear() veikia." << std::endl;

    return 0;
}
