#pragma once
#include "number.h"

class Integer: public Number {
    public:
        Integer();
        Integer(long number);
        
        void toString() override;
        long getValue();

        unique_ptr<Number> operator + (const Number& other) override;
        unique_ptr<Number> operator - (const Number& other) override;
        unique_ptr<Number> operator * (const Number& other) override;
        unique_ptr<Number> operator / (const Number& other) override;
    
    protected:
        unique_ptr<Number> toInteger() const override;
        unique_ptr<Number> toReal() const override;
        unique_ptr<Number> toComplex() const override;

        friend class Real;
        friend class Complex;

    private:
        long value;
};