#pragma once
#include "number.h"

class Real: public Number {
    public:
        Real();
        Real(double number);
    
        void toString() override;
        double getValue();

        unique_ptr<Number> operator + (const Number& other) override;
        unique_ptr<Number> operator - (const Number& other) override;
        unique_ptr<Number> operator * (const Number& other) override;
        unique_ptr<Number> operator / (const Number& other) override;

    protected:
        unique_ptr<Number> toInteger() const override;
        unique_ptr<Number> toReal() const override;
        unique_ptr<Number> toComplex() const override;

        friend class Integer;
        friend class Complex;

    private:
        double value;
};