#pragma once
#include "student.h"

class Course {
    public:
        void inscribeStudent(std::string name, int fileNumber);
        void unsuscribeStudent(const int fileNumber);
    private:
        mutable vector<Student> students;
};