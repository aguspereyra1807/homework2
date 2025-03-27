#include "course.h"

void Course::inscribeStudent(const std::string name, const int fileNumber) {
    Student new_student(name, fileNumber);
    students.push_back(new_student);
}

void Course::unsuscribeStudent(const int fileNumber) {
    for (auto i = students.begin(); i != students.end();  ++i) { // iterador de <vector>
        if (i->getFileNumber() == fileNumber) {
            students.erase(i);
        }
    }
}

