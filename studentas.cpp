#include "studentas.h"
#include <iostream>
#include <utility>

Studentas::Studentas()
    : Zmogus("Vardenis", "Pavardenis"), exam_(0), rez_(0.0), med_(0.0) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde,
                     const ProgramosVector<int>& paz, int exam,
                     double rez, double med)
    : Zmogus(vardas, pavarde), paz_(paz), exam_(exam), rez_(rez), med_(med) {}

Studentas::Studentas(const Studentas& other)
    : Zmogus(other.vardas_, other.pavarde_),
      paz_(other.paz_),
      exam_(other.exam_),
      rez_(other.rez_),
      med_(other.med_) {}

Studentas::Studentas(Studentas&& other) noexcept
    : Zmogus(std::move(other.vardas_), std::move(other.pavarde_)),
      paz_(std::move(other.paz_)),
      exam_(other.exam_),
      rez_(other.rez_),
      med_(other.med_) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
        paz_ = other.paz_;
        exam_ = other.exam_;
        rez_ = other.rez_;
        med_ = other.med_;
    }
    return *this;
}

Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
        paz_ = std::move(other.paz_);
        exam_ = other.exam_;
        rez_ = other.rez_;
        med_ = other.med_;
    }
    return *this;
}

Studentas::~Studentas() {}

std::string Studentas::vardas() const {
    return vardas_;
}

std::string Studentas::pavarde() const {
    return pavarde_;
}

const ProgramosVector<int>& Studentas::paz() const {
    return paz_;
}

int Studentas::exam() const {
    return exam_;
}

double Studentas::rez() const {
    return rez_;
}

double Studentas::med() const {
    return med_;
}

void Studentas::print() const {
    std::cout << *this << std::endl;
}

void Studentas::setVardas(const std::string& vardas) {
    vardas_ = vardas;
}

void Studentas::setPavarde(const std::string& pavarde) {
    pavarde_ = pavarde;
}

void Studentas::setExam(int exam) {
    exam_ = exam;
}

void Studentas::setRez(double rez) {
    rez_ = rez;
}

void Studentas::setMed(double med) {
    med_ = med;
}

void Studentas::addPaz(int paz) {
    paz_.push_back(paz);
}

void Studentas::clearPaz() {
    paz_.clear();
}

std::ostream& operator<<(std::ostream& out, const Studentas& s) {
    out << s.vardas_ << " " << s.pavarde_
        << " | Egz: " << s.exam_
        << " | Rez: " << s.rez_;
    return out;
}

std::istream& operator>>(std::istream& in, Studentas& s) {
    s.clearPaz();

    in >> s.vardas_ >> s.pavarde_;

    int paz;
    while (in >> paz) {
        s.paz_.push_back(paz);
    }

    in.clear();
    return in;
}
