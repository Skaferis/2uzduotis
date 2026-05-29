#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include "Vector.h"

struct StudentTestData {
    std::string name;
    int grade;

    StudentTestData(const std::string& student_name, int student_grade)
        : name(student_name), grade(student_grade) {}
};

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

void test_copy_constructor() {
    Vector<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);

    Vector<int> copy(original);

    assert(copy.size() == original.size());
    assert(copy.capacity() >= copy.size());
    assert(copy[0] == 1);
    assert(copy[1] == 2);
    assert(copy[2] == 3);

    copy[0] = 100;

    assert(copy[0] == 100);
    assert(original[0] == 1);
}

void test_copy_assignment() {
    Vector<int> first;
    first.push_back(10);
    first.push_back(20);

    Vector<int> second;
    second.push_back(1);
    second.push_back(2);
    second.push_back(3);

    second = first;

    assert(second.size() == first.size());
    assert(second[0] == 10);
    assert(second[1] == 20);

    second[1] = 99;

    assert(second[1] == 99);
    assert(first[1] == 20);
}

void test_self_assignment() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(6);

    v = v;

    assert(v.size() == 2);
    assert(v[0] == 5);
    assert(v[1] == 6);
}

void test_copy_with_string() {
    Vector<std::string> words;
    words.push_back("vienas");
    words.push_back("du");

    Vector<std::string> copy = words;

    assert(copy.size() == 2);
    assert(copy[0] == "vienas");
    assert(copy[1] == "du");

    copy[0] = "pakeista";

    assert(copy[0] == "pakeista");
    assert(words[0] == "vienas");
}

void test_move_constructor() {
    Vector<int> original;
    original.push_back(11);
    original.push_back(22);

    const auto old_capacity = original.capacity();
    int* old_data = original.data();

    Vector<int> moved(std::move(original));

    assert(moved.size() == 2);
    assert(moved.capacity() == old_capacity);
    assert(moved.data() == old_data);
    assert(moved[0] == 11);
    assert(moved[1] == 22);

    assert(original.size() == 0);
    assert(original.capacity() == 0);
    assert(original.data() == nullptr);
}

void test_move_assignment() {
    Vector<std::string> source;
    source.push_back("labas");
    source.push_back("vakaras");

    const auto old_capacity = source.capacity();
    std::string* old_data = source.data();

    Vector<std::string> target;
    target.push_back("senas");

    target = std::move(source);

    assert(target.size() == 2);
    assert(target.capacity() == old_capacity);
    assert(target.data() == old_data);
    assert(target[0] == "labas");
    assert(target[1] == "vakaras");

    assert(source.size() == 0);
    assert(source.capacity() == 0);
    assert(source.data() == nullptr);
}


void test_begin_end_range_for() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int sum = 0;
    for (int value : v) {
        sum += value;
    }

    assert(sum == 6);
    assert(v.begin() == v.data());
    assert(v.end() == v.data() + v.size());
}

void test_iterators_modify_values() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto it = v.begin(); it != v.end(); ++it) {
        *it += 1;
    }

    assert(v[0] == 11);
    assert(v[1] == 21);
    assert(v[2] == 31);
}

void test_const_iterators() {
    Vector<int> v;
    v.push_back(4);
    v.push_back(5);

    const Vector<int>& const_v = v;

    int sum = 0;
    for (auto it = const_v.cbegin(); it != const_v.cend(); ++it) {
        sum += *it;
    }

    assert(sum == 9);
    assert(const_v.begin() == const_v.cbegin());
    assert(const_v.end() == const_v.cend());
}

void test_std_sort_with_iterators() {
    Vector<int> v;
    v.push_back(30);
    v.push_back(10);
    v.push_back(20);

    std::sort(v.begin(), v.end());

    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
}


void test_pop_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    const auto old_capacity = v.capacity();

    v.pop_back();

    assert(v.size() == 2);
    assert(v.capacity() == old_capacity);
    assert(v.back() == 20);

    v.pop_back();
    v.pop_back();

    assert(v.size() == 0);
    assert(v.capacity() == old_capacity);
    assert(v.empty());
}

void test_resize_smaller() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    const auto old_capacity = v.capacity();

    v.resize(2);

    assert(v.size() == 2);
    assert(v.capacity() == old_capacity);
    assert(v[0] == 1);
    assert(v[1] == 2);
}

void test_resize_larger_default_values() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(6);

    v.resize(5);

    assert(v.size() == 5);
    assert(v[0] == 5);
    assert(v[1] == 6);
    assert(v[2] == 0);
    assert(v[3] == 0);
    assert(v[4] == 0);
}

void test_resize_larger_with_value() {
    Vector<std::string> words;
    words.push_back("vienas");

    words.resize(3, std::string("naujas"));

    assert(words.size() == 3);
    assert(words[0] == "vienas");
    assert(words[1] == "naujas");
    assert(words[2] == "naujas");
}

void test_insert_middle() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);

    auto it = v.insert(v.begin() + 1, 2);

    assert(v.size() == 4);
    assert(*it == 2);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(v[3] == 4);
}

void test_insert_begin_and_end() {
    Vector<int> v;
    v.push_back(20);
    v.push_back(30);

    auto first = v.insert(v.begin(), 10);
    auto last = v.insert(v.end(), 40);

    assert(v.size() == 4);
    assert(*first == 10);
    assert(*last == 40);
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);
    assert(v[3] == 40);
}

void test_insert_with_string() {
    Vector<std::string> words;
    words.push_back("vienas");
    words.push_back("trys");

    std::string word = "du";
    auto it = words.insert(words.begin() + 1, word);

    assert(words.size() == 3);
    assert(*it == "du");
    assert(words[0] == "vienas");
    assert(words[1] == "du");
    assert(words[2] == "trys");
}

void test_erase_middle() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    auto it = v.erase(v.begin() + 1);

    assert(v.size() == 3);
    assert(*it == 30);
    assert(v[0] == 10);
    assert(v[1] == 30);
    assert(v[2] == 40);
}

void test_erase_last() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    auto it = v.erase(v.end() - 1);

    assert(v.size() == 2);
    assert(it == v.end());
    assert(v[0] == 1);
    assert(v[1] == 2);
}

void test_erase_with_string() {
    Vector<std::string> words;
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");

    auto it = words.erase(words.begin());

    assert(words.size() == 2);
    assert(*it == "b");
    assert(words[0] == "b");
    assert(words[1] == "c");
}

void test_insert_count_middle() {
    Vector<int> v = {1, 4};

    auto it = v.insert(v.begin() + 1, 2, 2);

    assert(v.size() == 4);
    assert(*it == 2);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 2);
    assert(v[3] == 4);
}

void test_insert_count_begin_and_end() {
    Vector<std::string> words = {"b"};

    auto first = words.insert(words.begin(), 2, std::string("a"));

    assert(words.size() == 3);
    assert(*first == "a");
    assert(words[0] == "a");
    assert(words[1] == "a");
    assert(words[2] == "b");

    auto last = words.insert(words.end(), 1, std::string("c"));

    assert(words.size() == 4);
    assert(*last == "c");
    assert(words[0] == "a");
    assert(words[1] == "a");
    assert(words[2] == "b");
    assert(words[3] == "c");
}

void test_insert_count_zero() {
    Vector<int> v = {1, 2, 3};

    auto it = v.insert(v.begin() + 1, 0, 99);

    assert(v.size() == 3);
    assert(*it == 2);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void test_erase_range_middle() {
    Vector<int> v = {1, 2, 3, 4, 5};

    auto it = v.erase(v.begin() + 1, v.begin() + 4);

    assert(v.size() == 2);
    assert(*it == 5);
    assert(v[0] == 1);
    assert(v[1] == 5);
}

void test_erase_range_to_end() {
    Vector<int> v = {1, 2, 3, 4};

    auto it = v.erase(v.begin() + 2, v.end());

    assert(v.size() == 2);
    assert(it == v.end());
    assert(v[0] == 1);
    assert(v[1] == 2);
}

void test_erase_empty_range() {
    Vector<int> v = {1, 2, 3};

    auto it = v.erase(v.begin() + 1, v.begin() + 1);

    assert(v.size() == 3);
    assert(*it == 2);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void test_initializer_list_constructor() {
    Vector<int> v = {1, 2, 3, 4};

    assert(v.size() == 4);
    assert(v.capacity() >= 4);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(v[3] == 4);
}

void test_initializer_list_with_string() {
    Vector<std::string> words = {"vienas", "du", "trys"};

    assert(words.size() == 3);
    assert(words[0] == "vienas");
    assert(words[1] == "du");
    assert(words[2] == "trys");
}

void test_assign_count_value() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    v.assign(4, 9);

    assert(v.size() == 4);
    assert(v[0] == 9);
    assert(v[1] == 9);
    assert(v[2] == 9);
    assert(v[3] == 9);
}

void test_assign_initializer_list() {
    Vector<std::string> words;
    words.push_back("senas");

    words.assign({"a", "b", "c"});

    assert(words.size() == 3);
    assert(words[0] == "a");
    assert(words[1] == "b");
    assert(words[2] == "c");
}

void test_assign_empty_initializer_list() {
    Vector<int> v = {1, 2, 3};

    v.assign({});

    assert(v.size() == 0);
    assert(v.empty());
}


void test_equality_operators() {
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {1, 2, 3};
    Vector<int> c = {1, 2, 4};
    Vector<int> d = {1, 2};

    assert(a == b);
    assert(!(a != b));
    assert(a != c);
    assert(a != d);
}

void test_relational_operators() {
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {1, 2, 4};
    Vector<int> c = {1, 2, 3, 0};
    Vector<int> d = {1, 2, 3};

    assert(a < b);
    assert(a <= b);
    assert(b > a);
    assert(b >= a);

    assert(a < c);
    assert(c > a);

    assert(a <= d);
    assert(a >= d);
    assert(!(a < d));
    assert(!(a > d));
}

void test_comparison_with_strings() {
    Vector<std::string> a = {"a", "b"};
    Vector<std::string> b = {"a", "c"};
    Vector<std::string> c = {"a", "b"};

    assert(a == c);
    assert(a != b);
    assert(a < b);
    assert(b > a);
}

void test_member_swap() {
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {10, 20};

    int* a_data = a.data();
    int* b_data = b.data();
    const auto a_capacity = a.capacity();
    const auto b_capacity = b.capacity();

    a.swap(b);

    assert(a.size() == 2);
    assert(b.size() == 3);
    assert(a.data() == b_data);
    assert(b.data() == a_data);
    assert(a.capacity() == b_capacity);
    assert(b.capacity() == a_capacity);
    assert(a[0] == 10);
    assert(a[1] == 20);
    assert(b[0] == 1);
    assert(b[1] == 2);
    assert(b[2] == 3);
}

void test_non_member_swap() {
    Vector<std::string> a = {"vienas", "du"};
    Vector<std::string> b = {"trys"};

    swap(a, b);

    assert(a.size() == 1);
    assert(b.size() == 2);
    assert(a[0] == "trys");
    assert(b[0] == "vienas");
    assert(b[1] == "du");
}

void test_shrink_to_fit() {
    Vector<int> v;
    v.reserve(20);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    assert(v.capacity() >= 20);

    v.shrink_to_fit();

    assert(v.size() == 3);
    assert(v.capacity() == 3);
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void test_shrink_to_fit_empty_vector() {
    Vector<int> v;
    v.reserve(10);
    v.clear();

    assert(v.capacity() >= 10);

    v.shrink_to_fit();

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.data() == nullptr);
    assert(v.empty());
}


void test_count_constructor() {
    Vector<int> v(4);

    assert(v.size() == 4);
    assert(v.capacity() >= 4);
    assert(!v.empty());
    assert(v[0] == 0);
    assert(v[1] == 0);
    assert(v[2] == 0);
    assert(v[3] == 0);
}

void test_count_value_constructor() {
    Vector<int> v(5, 7);

    assert(v.size() == 5);
    assert(v.capacity() >= 5);
    assert(v[0] == 7);
    assert(v[1] == 7);
    assert(v[2] == 7);
    assert(v[3] == 7);
    assert(v[4] == 7);
}

void test_count_value_constructor_with_string() {
    Vector<std::string> words(3, std::string("testas"));

    assert(words.size() == 3);
    assert(words[0] == "testas");
    assert(words[1] == "testas");
    assert(words[2] == "testas");
}

void test_zero_count_constructor() {
    Vector<int> v(0);

    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty());
    assert(v.data() == nullptr);
}

void test_emplace_back_with_string() {
    Vector<std::string> words;
    words.reserve(2);

    std::string& first = words.emplace_back("labas");
    assert(first == "labas");

    words.emplace_back(5, 'x');

    assert(words.size() == 2);
    assert(words[0] == "labas");
    assert(words[1] == "xxxxx");
}

void test_emplace_back_with_custom_type() {
    Vector<StudentTestData> students;

    StudentTestData& inserted = students.emplace_back("Jonas", 9);

    assert(students.size() == 1);
    assert(inserted.name == "Jonas");
    assert(inserted.grade == 9);
    assert(students[0].name == "Jonas");
    assert(students[0].grade == 9);
}

int main() {
    test_empty_vector();
    test_count_constructor();
    test_count_value_constructor();
    test_count_value_constructor_with_string();
    test_zero_count_constructor();
    test_emplace_back_with_string();
    test_emplace_back_with_custom_type();
    test_clear_empty_vector();
    test_reserve();
    test_push_back_size_and_capacity();
    test_push_back_values();
    test_push_back_with_string();
    test_clear_after_push_back();
    test_at();
    test_front_back_data();
    test_const_access();
    test_copy_constructor();
    test_copy_assignment();
    test_self_assignment();
    test_copy_with_string();
    test_move_constructor();
    test_move_assignment();

    test_begin_end_range_for();
    test_iterators_modify_values();
    test_const_iterators();
    test_std_sort_with_iterators();

    test_pop_back();
    test_resize_smaller();
    test_resize_larger_default_values();
    test_resize_larger_with_value();

    test_insert_middle();
    test_insert_begin_and_end();
    test_insert_with_string();
    test_erase_middle();
    test_erase_last();
    test_erase_with_string();
    test_insert_count_middle();
    test_insert_count_begin_and_end();
    test_insert_count_zero();
    test_erase_range_middle();
    test_erase_range_to_end();
    test_erase_empty_range();

    test_initializer_list_constructor();
    test_initializer_list_with_string();
    test_assign_count_value();
    test_assign_initializer_list();
    test_assign_empty_initializer_list();

    test_equality_operators();
    test_relational_operators();
    test_comparison_with_strings();

    test_member_swap();
    test_non_member_swap();
    test_shrink_to_fit();
    test_shrink_to_fit_empty_vector();

    std::cout << "15 etapas: insert(count) ir erase(range) veikia." << std::endl;

    return 0;
}
