#include "student.h"

Student::Student(std::string name, const int fileNumber): name(name), fileNumber(fileNumber) {}

std::string Student::getName() const {
    return name;
}

int Student::getFileNumber() const {
    return fileNumber;
}

float Student::getFinalGrade(std::string subject) const{
    for (auto i = grades.begin(); i != grades.end(); ++i) { // iterador <vector>
        if (i->first == subject) return i->second;
    }
    return -1; // No encontrado
}

float Student::getAverageGrade() const {
    float average = 0.0;
    for (auto i = grades.begin(); i != grades.end(); ++i) { // iterador <vector>
        average += i->second;
    }
    return average;
}

bool Student::operator>(const Student& other) const {
    return this->name > other.name;
}

bool Student::operator<(const Student& other) const {
    return this->name < other.name;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << student.name << ": " << student.fileNumber;
    return os;
}