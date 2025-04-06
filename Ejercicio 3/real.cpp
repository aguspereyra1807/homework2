#include "real.h"
#include "integer.h"
#include "complex.h"

Real::Real(): value(0.0) {}

Real::Real(double number): value(number) {}

double Real::getValue() {
    return value;
}

void Real::toString() {
    cout << value << endl;
}

unique_ptr<Number> Real::toInteger() const {
    return make_unique<Integer>(static_cast<long>(value));
}

unique_ptr<Number> Real::toReal() const {
    return make_unique<Real>(value);
}

unique_ptr<Number> Real::toComplex() const {
    return make_unique<Complex>(static_cast<double>(value), 0.0);
}

unique_ptr<Number> Real::operator + (const Number& other) {
    auto otherNumber = other.toReal();

    Real* otherReal = dynamic_cast<Real*>(otherNumber.get());
    if (!otherReal) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    double resultValue = this->value + otherReal->getValue();
    return make_unique<Real>(resultValue);
}

unique_ptr<Number> Real::operator - (const Number& other) {
    auto otherNumber = other.toReal();

    Real* otherReal = dynamic_cast<Real*>(otherNumber.get());
    if (!otherReal) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    double resultValue = this->value - otherReal->getValue();
    return make_unique<Real>(resultValue);
}

unique_ptr<Number> Real::operator * (const Number& other) {
    auto otherNumber = other.toReal();

    Real* otherReal = dynamic_cast<Real*>(otherNumber.get());
    if (!otherReal) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    double resultValue = this->value * otherReal->getValue();
    return make_unique<Real>(resultValue);
}

unique_ptr<Number> Real::operator / (const Number& other) {
    auto otherNumber = other.toReal();

    Real* otherReal = dynamic_cast<Real*>(otherNumber.get());
    if (!otherReal) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }
    if (otherReal->getValue() == 0.0) {
        throw runtime_error("Error: División por cero");
        return nullptr;
    }

    double resultValue = this->value / otherReal->getValue();
    return make_unique<Real>(resultValue);
}