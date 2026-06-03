CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
OPTFLAGS = -O2

COMMON = studentas.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp

.PHONY: all test benchmark run run_std clean

all: vector std_vector test_vector benchmark_vector test_student_custom test_student_std

vector: main_vector.cpp $(COMMON) vector.h programos_vector.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -DNUOSAVAS_VECTOR main_vector.cpp $(COMMON) -o vector

std_vector: main_vector.cpp $(COMMON) programos_vector.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) main_vector.cpp $(COMMON) -o std_vector

test_vector: test_vector.cpp vector.h
	$(CXX) $(CXXFLAGS) test_vector.cpp -o test_vector

test_student_custom: test_student.cpp studentas.cpp vector.h programos_vector.h zmogus.h
	$(CXX) $(CXXFLAGS) -DNUOSAVAS_VECTOR test_student.cpp studentas.cpp -o test_student_custom

test_student_std: test_student.cpp studentas.cpp programos_vector.h zmogus.h
	$(CXX) $(CXXFLAGS) test_student.cpp studentas.cpp -o test_student_std

benchmark_vector: benchmark_vector.cpp vector.h
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) benchmark_vector.cpp -o benchmark_vector

test: test_vector test_student_custom test_student_std
	./test_vector
	./test_student_custom
	./test_student_std

benchmark: benchmark_vector
	./benchmark_vector quick

run: vector
	./vector

run_std: std_vector
	./std_vector

clean:
	rm -f vector.exe vector std_vector.exe std_vector test_vector.exe test_vector benchmark_vector.exe benchmark_vector test_student_custom.exe test_student_custom test_student_std.exe test_student_std
