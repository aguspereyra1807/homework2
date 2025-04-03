#pragma once
#include "number.h"

class Complex: public Number {
    public:
        Complex();
        Complex(double real, double imaginary);

        void toString() override;
        double getRealComponent();
        double getImaginaryComponent();

        unique_ptr<Number> operator + (const Number& other) override;
        unique_ptr<Number> operator - (const Number& other) override;
        unique_ptr<Number> operator * (const Number& other) override;
        unique_ptr<Number> operator / (const Number& other) override;

    protected:
        unique_ptr<Number> toInteger() const override;
        unique_ptr<Number> toReal() const override;
        unique_ptr<Number> toComplex() const override;

        friend class Integer;
        friend class Real;

    private:
        double realComponent;
        double imaginaryComponent;
};