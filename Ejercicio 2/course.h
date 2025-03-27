#pragma once
#include "student.h"
#include <memory>

class Course {
    public:
        Course();

        bool inscribeStudent(std::string name, int fileNumber);
        void unsuscribeStudent(const int fileNumber);
        bool isComplete();
        bool isInscribed(const int fileNumber);

        
    private:
        vector<shared_ptr<Student>> students;
};