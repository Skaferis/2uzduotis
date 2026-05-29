#include <cassert>
#include <iostream>
#include <stdexcept>
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

void test_push_back_values() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
}

void test_push_back_with_string() {
    Vector<std::string> words;
    std::string text = "labas";

    words.push_back(text);
    words.push_back(std::string("rytas"));

    assert(words.size() == 2);
    assert(words.capacity() >= 2);
    assert(words[0] == "labas");
    assert(words[1] == "rytas");
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

void test_at() {
    Vector<int> v;

    v.push_back(100);
    v.push_back(200);

    assert(v.at(0) == 100);
    assert(v.at(1) == 200);

    bool exception_thrown = false;

    try {
        v.at(2);
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }

    assert(exception_thrown);
}

void test_front_back_data() {
    Vector<int> v;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    assert(v.front() == 5);
    assert(v.back() == 15);
    assert(v.data() != nullptr);
    assert(v.data()[1] == 10);

    v.front() = 1;
    v.back() = 99;

    assert(v[0] == 1);
    assert(v[2] == 99);
}

void test_const_access() {
    Vector<int> v;

    v.push_back(7);
    v.push_back(8);

    const Vector<int>& const_v = v;

    assert(const_v[0] == 7);
    assert(const_v.at(1) == 8);
    assert(const_v.front() == 7);
    assert(const_v.back() == 8);
    assert(const_v.data() != nullptr);
}

int main() {
    test_empty_vector();
    test_clear_empty_vector();
    test_reserve();
    test_push_back_size_and_capacity();
    test_push_back_values();
    test_push_back_with_string();
    test_clear_after_push_back();
    test_at();
    test_front_back_data();
    test_const_access();

    std::cout << "4 etapas: elementu pasiekimo funkcijos veikia." << std::endl;

    return 0;
}
