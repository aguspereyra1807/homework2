#pragma once
#include <string>
#include <stdexcept>
#include <memory>
#include <iostream>

using namespace std;

class Number {
    public:
        virtual unique_ptr<Number> operator + (const Number& other) = 0; 
        virtual unique_ptr<Number> operator - (const Number& other) = 0;
        virtual unique_ptr<Number> operator * (const Number& other) = 0;
        virtual unique_ptr<Number> operator / (const Number& other) = 0;
        
        virtual void toString() = 0;
        
        virtual ~Number() = default;

    protected:
        virtual unique_ptr<Number> toInteger() const = 0;
        virtual unique_ptr<Number> toReal() const = 0;
        virtual unique_ptr<Number> toComplex() const = 0;

        friend class Integer;
        friend class Real;
        friend class Complex;

};