#pragma once
#include "student.h"
#include <memory>
#include <random>
#include <cstdlib>
#include <limits>

class Course {
    public:
        Course(const string newName);
        Course(const string newName, const Course& other);

        string getName();
        bool inscribeStudent(std::string name, int fileNumber);
        void unsuscribeStudent(const int fileNumber, float);
        bool isComplete();
        bool isInscribed(const int fileNumber);

        void print();
        
    private:
        const std::string name;
        vector<shared_ptr<Student>> students;
};