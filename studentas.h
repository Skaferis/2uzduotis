#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> paz_;
    int exam_;
    double rez_;
    double med_;

public:
    // konstruktoriai / destruktorius
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde,
              const std::vector<int>& paz, int exam,
              double rez = 0.0, double med = 0.0);

    Studentas(const Studentas& other);
    Studentas(Studentas&& other) noexcept;
    Studentas& operator=(const Studentas& other);
    Studentas& operator=(Studentas&& other) noexcept;

    ~Studentas();

    // getteriai
    std::string vardas() const;
    std::string pavarde() const;
    const std::vector<int>& paz() const;
    int exam() const;
    double rez() const;
    double med() const;

    // setteriai
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setExam(int exam);
    void setRez(double rez);
    void setMed(double med);
    void addPaz(int paz);
    void clearPaz();

    friend std::istream& operator>>(std::istream& in, Studentas& s);
    friend std::ostream& operator<<(std::ostream& out, const Studentas& s);
};

struct Asmuo {
    std::string vardas;
    std::string pavarde;
};

#endif