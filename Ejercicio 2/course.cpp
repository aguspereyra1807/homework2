#include "course.h"

Course::Course(const std::string newName): name(newName) {}

Course::Course(const std::string newName, const Course& other): name(newName) {
    for (auto i = other.students.begin(); i != other.students.end(); ++i) { // Shallow copy de cada estudiante
        students.push_back(*i);
    }
}

string Course::getName() {
    return name;
}

bool Course::isComplete() {
    if (students.size() == 20) return true;
    return false;
}

// Si se pudo inscribir al estudiante devuelve true. Caso contrario false.
bool Course::inscribeStudent(const std::string name, const int fileNumber) {
    if (isComplete()) {
        cerr << "El curso está completo, no se pudo inscribir a " << name << endl;
        return false;
    }

    shared_ptr<Student> studentPtr = make_shared<Student>(name, fileNumber);
    students.push_back(studentPtr);
    return true;
}

void Course::unsuscribeStudent(const int fileNumber, float finalGrade) {
    for (auto i = students.begin(); i != students.end(); ++i) { // iterador de <vector>
        if (i->get()->getFileNumber() == fileNumber) {
            i->get()->completeCourse(name, finalGrade);
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