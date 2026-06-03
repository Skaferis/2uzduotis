#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <iostream>
#include "vector.h"
#include "zmogus.h"

class Studentas : public Zmogus {
private:
    Vector<int> paz_;
    int exam_;
    double rez_;
    double med_;

public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde,
              const Vector<int>& paz, int exam,
              double rez = 0.0, double med = 0.0);

    Studentas(const Studentas& other);
    Studentas(Studentas&& other) noexcept;
    Studentas& operator=(const Studentas& other);
    Studentas& operator=(Studentas&& other) noexcept;
    ~Studentas();

    void print() const override;

    std::string vardas() const;
    std::string pavarde() const;
    const Vector<int>& paz() const;
    int exam() const;
    double rez() const;
    double med() const;

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
