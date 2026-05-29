#include <cassert>
#include <iostream>
#include <string>
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

void test_reserve() {
    Vector<int> v;

    v.reserve(10);

    assert(v.size() == 0);
    assert(v.capacity() >= 10);
    assert(v.empty());

    v.reserve(5);

    assert(v.capacity() >= 10);
}

void test_push_back_size_and_capacity() {
    Vector<int> v;

    v.push_back(1);
    assert(v.size() == 1);
    assert(v.capacity() >= 1);
    assert(!v.empty());

    v.push_back(2);
    v.push_back(3);

    assert(v.size() == 3);
    assert(v.capacity() >= 3);
}

void test_push_back_with_string() {
    Vector<std::string> words;
    std::string text = "labas";

    words.push_back(text);
    words.push_back(std::string("rytas"));

    assert(words.size() == 2);
    assert(words.capacity() >= 2);
}

void test_clear_after_push_back() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    const auto capacity_before_clear = v.capacity();

    v.clear();

    assert(v.size() == 0);
    assert(v.capacity() == capacity_before_clear);
    assert(v.empty());
}

int main() {
    test_empty_vector();
    test_clear_empty_vector();
    test_reserve();
    test_push_back_size_and_capacity();
    test_push_back_with_string();
    test_clear_after_push_back();

    std::cout << "3 etapas: reserve() ir push_back() veikia." << std::endl;

    return 0;
}
