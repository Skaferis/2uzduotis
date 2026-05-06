CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

COMMON = studentas.cpp skaiciavimai.cpp ivestis.cpp isvesti.cpp generavimas.cpp

all: vector deque list

vector:
	$(CXX) $(CXXFLAGS) main_vector.cpp $(COMMON) -o vector

deque:
	$(CXX) $(CXXFLAGS) main_deque.cpp $(COMMON) -o deque

list:
	$(CXX) $(CXXFLAGS) main_list.cpp $(COMMON) -o list

clean:
	del /Q vector.exe deque.exe list.exe 2>nul || rm -f vector deque list vector.exe deque.exe list.exe