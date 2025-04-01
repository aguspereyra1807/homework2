#pragma once
#include "student.h"
#include <memory>
#include <random>

class Course {
    public:
        Course(const string name);
        Course(const string name, const Course& other); // MODIFICAR A DEEP COPY

        bool inscribeStudent(std::string name, int fileNumber);
        void unsuscribeStudent(const int fileNumber);
        bool isComplete();
        bool isInscribed(const int fileNumber);

        void print();
        
    private:
        const std::string name;
        vector<shared_ptr<Student>> students;
};