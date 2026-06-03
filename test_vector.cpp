#include "vector.h"

#include <cassert>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>

int main() {
    Vector<int> v;
    assert(v.empty());
    assert(v.size() == 0);

    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
    }

    assert(v.size() == 5);
    assert(v.front() == 1);
    assert(v.back() == 5);
    assert(v[2] == 3);

    v.at(0) = 10;
    assert(v[0] == 10);

    bool exception_thrown = false;
    try {
        (void)v.at(100);
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }
    assert(exception_thrown);

    v.insert(v.begin() + 1, 20);
    assert(v.size() == 6);
    assert(v[1] == 20);

    v.erase(v.begin() + 1);
    assert(v.size() == 5);
    assert(v[1] == 2);

    v.resize(7, 9);
    assert(v.size() == 7);
    assert(v[5] == 9 && v[6] == 9);

    v.pop_back();
    assert(v.size() == 6);

    Vector<int> copy = v;
    assert(copy == v);

    Vector<int> moved = std::move(copy);
    assert(moved.size() == 6);

    Vector<int> init{1, 2, 3};
    assert(init.size() == 3);
    assert(init[0] == 1 && init[2] == 3);

    Vector<std::string> words;
    words.emplace_back("labas");
    words.push_back("rytas");
    assert(words.size() == 2);
    assert(words[0] == "labas");
    assert(words[1] == "rytas");

    int sum = std::accumulate(v.begin(), v.end(), 0);
    assert(sum == 10 + 2 + 3 + 4 + 5 + 9);

    std::cout << "Visi Vector testai praejo sekmingai.\n";
    return 0;
}
