CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
OPTFLAGS = -O2

COMMON = studentas.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp

.PHONY: all test benchmark run clean

all: vector test_vector benchmark_vector

vector: main_vector.cpp $(COMMON)
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) main_vector.cpp $(COMMON) -o vector

test_vector: test_vector.cpp vector.h
	$(CXX) $(CXXFLAGS) test_vector.cpp -o test_vector

benchmark_vector: benchmark_vector.cpp vector.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) benchmark_vector.cpp -o benchmark_vector

test: test_vector
	./test_vector

benchmark: benchmark_vector
	./benchmark_vector quick

run: vector
	./vector

clean:
	rm -f vector.exe vector test_vector.exe test_vector benchmark_vector.exe benchmark_vector
