#include "Vector.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct BenchmarkResult {
    double seconds;
    std::size_t reallocations;
    std::size_t final_size;
    std::size_t final_capacity;
};

template <typename Container>
BenchmarkResult measure_push_back(std::size_t size) {
    Container values;
    std::size_t reallocations = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (std::size_t i = 1; i <= size; ++i) {
        if (values.capacity() == values.size()) {
            ++reallocations;
        }
        values.push_back(static_cast<int>(i));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return {duration.count(), reallocations, values.size(), values.capacity()};
}

void print_result_row(std::size_t size,
                      const BenchmarkResult& std_result,
                      const BenchmarkResult& custom_result) {
    std::cout << std::left
              << std::setw(14) << size
              << std::setw(18) << std_result.seconds
              << std::setw(22) << std_result.reallocations
              << std::setw(18) << custom_result.seconds
              << std::setw(22) << custom_result.reallocations
              << '\n';
}

int main(int argc, char* argv[]) {
    std::vector<std::size_t> sizes = {
        10000,
        100000,
        1000000,
        10000000,
        100000000
    };

    if (argc > 1 && std::string(argv[1]) == "quick") {
        sizes = {10000, 100000, 1000000};
        std::cout << "Greitas testavimo rezimas: naudojami tik mazesni dydziai.\n";
    }

    std::cout << std::fixed << std::setprecision(6);

    std::cout << std::left
              << std::setw(14) << "Dydis"
              << std::setw(18) << "std::vector(s)"
              << std::setw(22) << "std perskirstymai"
              << std::setw(18) << "Vector(s)"
              << std::setw(22) << "Vector perskirstymai"
              << '\n';

    std::cout << std::string(94, '-') << '\n';

    for (std::size_t size : sizes) {
        BenchmarkResult std_result = measure_push_back<std::vector<int>>(size);
        BenchmarkResult custom_result = measure_push_back<Vector<int>>(size);

        print_result_row(size, std_result, custom_result);
    }

    return 0;
}
