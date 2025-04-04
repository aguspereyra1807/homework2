#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Student {
    public:
        Student(const std::string name, int fileNumber);

        std::string getName() const; // const -> no modifica atributos
        int getFileNumber() const;
        float getFinalGrade(std::string subject) const;
        float getAverageGrade() const;
        void completeCourse(string subject, float finalGrade);

        bool operator>(const Student& other) const;
        bool operator<(const Student& other) const;
        friend ostream& operator<<(ostream& os, const Student& student);

    private:
        const std::string name;
        const int fileNumber; // atributo no modificable
        mutable vector<pair<std::string,float>> grades; // Vector de pares <CURSO,NOTA_FINAL>, mutable
};