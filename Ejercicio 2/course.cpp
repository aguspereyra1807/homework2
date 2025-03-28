#include "course.h"

Course::Course(const std::string name): name(name) {}

Course::Course(const std::string name, const Course& other): name(name), students(other.students) {}

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

    shared_ptr<Student> studentPtr = make_shared<Student>(name, fileNumber);
    students.push_back(studentPtr);
    return true;
}

void Course::unsuscribeStudent(const int fileNumber) {
    for (auto i = students.begin(); i != students.end(); ++i) { // iterador de <vector>
        if (i->get()->getFileNumber() == fileNumber) {
            students.erase(i);
            break; // sino queda un iterador inválido
        } 
    }
}

bool Course::isInscribed(const int fileNumber) {
    for (auto i = students.begin(); i < students.end(); ++i) {
        if (i->get()->getFileNumber() == fileNumber) return true;
    }
    return false;
}

void Course::print() {
    sort(students.begin(), students.end(), [](const shared_ptr<Student>& a, const shared_ptr<Student>& b) -> bool  {
        return *a < *b;
    }); 
    // lambda para referenciar los punteros y compararlos por el operador sobrecargado

    for (auto i = students.begin(); i < students.end(); ++i) {
        cout << **i << endl;
    }
}