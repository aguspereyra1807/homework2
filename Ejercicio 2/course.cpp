#include "course.h"

Course::Course() {
    students = vector<Student>();
}

bool Course::isComplete() {
    if (students.size() == 20) return true;
    return false;
}

// Si se pudo inscribir al estudiante devuelve true. Caso contrario false
bool Course::inscribeStudent(const std::string name, const int fileNumber) {
    if (isComplete()) {
        cerr << "El curso está completo, no se pudo inscribir a " << name << endl;
        return false;
    }

    Student new_student(name, fileNumber);
    students.push_back(new_student);
    return true;
}

void Course::unsuscribeStudent(const int fileNumber) {
    for (auto i = students.begin(); i != students.end();  ++i) { // iterador de <vector>
        if (i->getFileNumber() == fileNumber) {
            students.erase(i);
        }
    }
}

bool Course::isInscribed(const int fileNumber) {
    for (auto i = students.begin(); i < students.end(); ++i) {
        if (i->getFileNumber() == fileNumber) return true;
    }
    return false;
}
