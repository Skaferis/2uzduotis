#include "studentas.h"

Studentas::Studentas()
    : vardas_("Vardenis"), pavarde_("Pavardenis"), exam_(0), rez_(0.0), med_(0.0) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde,
                     const std::vector<int>& paz, int exam,
                     double rez, double med)
    : vardas_(vardas), pavarde_(pavarde), paz_(paz), exam_(exam), rez_(rez), med_(med) {}

Studentas::~Studentas() {}

std::string Studentas::vardas() const {
    return vardas_;
}

std::string Studentas::pavarde() const {
    return pavarde_;
}

const std::vector<int>& Studentas::paz() const {
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