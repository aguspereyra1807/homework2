#include "complex.h"
#include "real.h"
#include "integer.h"

Complex::Complex(): realComponent(0.0), imaginaryComponent(0.0) {}

Complex::Complex(double real, double imaginary): realComponent(real), imaginaryComponent(imaginary) {}


double Complex::getRealComponent() {
    return realComponent;
}

double Complex::getImaginaryComponent() {
    return imaginaryComponent;
}

void Complex::toString() {
    cout << realComponent << " + " << imaginaryComponent << "i" << endl;
}
unique_ptr<Number> Complex::toInteger() const {
    return make_unique<Integer>(static_cast<long>(realComponent));
}

unique_ptr<Number> Complex::toReal() const {
    return make_unique<Real>(realComponent);
}

unique_ptr<Number> Complex::toComplex() const {
    return make_unique<Complex>(realComponent, imaginaryComponent);
}

unique_ptr<Number> Complex::operator + (const Number& other) {
    auto otherNumber = other.toComplex();

    Complex* otherComplex = dynamic_cast<Complex*>(otherNumber.get());
    if (!otherComplex) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }
    double resultReal = this->realComponent + otherComplex->getRealComponent();
    double resultImaginary = this->imaginaryComponent + otherComplex->getImaginaryComponent();
    return make_unique<Number>(Complex(resultReal, resultImaginary));
}

unique_ptr<Number> Complex::operator - (const Number& other) {
    auto otherNumber = other.toComplex();

    Complex* otherComplex = dynamic_cast<Complex*>(otherNumber.get());
    if (!otherComplex) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    double resultReal = this->realComponent - otherComplex->getRealComponent();
    double resultImaginary = this->imaginaryComponent - otherComplex->getImaginaryComponent();
    return make_unique<Number>(Complex(resultReal, resultImaginary));
}

unique_ptr<Number> Complex::operator * (const Number& other) {
    auto otherNumber = other.toComplex();

    Complex* otherComplex = dynamic_cast<Complex*>(otherNumber.get());
    if (!otherComplex) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    double a = this->realComponent;
    double b = this->imaginaryComponent;
    double c = otherComplex->getRealComponent();
    double d = otherComplex->getImaginaryComponent();

    double resultReal = (a * c) - (b * d);

    double resultImaginary = (this->realComponent * otherComplex->getImaginaryComponent()) 
    + (this->imaginaryComponent * otherComplex->getRealComponent());

    return make_unique<Number>(Complex(resultReal, resultImaginary));
}

unique_ptr<Number> Complex::operator / (const Number& other) {
    auto otherNumber = other.toComplex();

    Complex* otherComplex = dynamic_cast<Complex*>(otherNumber.get());
    if (!otherComplex) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }
    double a = this->realComponent;
    double b = this->imaginaryComponent;
    double c = otherComplex->getRealComponent();
    double d = otherComplex->getImaginaryComponent();

    if (c == 0 && d == 0) {
        throw runtime_error("Error: División por cero");
        return nullptr;
    }
    
    double resultReal = (a*c + b*d) / (c*c + d*d);
    
    double resultImaginary = (b*c - a*d) / (c*c + d*d);
    
    return make_unique<Number>(Complex(resultReal, resultImaginary));
}