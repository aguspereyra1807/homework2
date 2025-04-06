#include "integer.h"
#include "real.h"
#include "complex.h"

Integer::Integer() : value(0) {}

Integer::Integer(long number): value(number) {}

long Integer::getValue() {
    return value;
}

void Integer::toString() {
    cout << value << endl;
}

unique_ptr<Number> Integer::toInteger() const {
    return make_unique<Integer>(value);
}

unique_ptr<Number> Integer::toReal() const {
    return make_unique<Real>(static_cast<double>(value));
}

unique_ptr<Number> Integer::toComplex() const {
    return make_unique<Complex>(static_cast<double>(value), 0.0);
}


unique_ptr<Number> Integer::operator + (const Number& other) {
    auto otherNumber = other.toInteger();

    Integer* otherInteger = dynamic_cast<Integer*>(otherNumber.get());
    if (!otherInteger) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    long resultValue = this->value + otherInteger->getValue();
    return make_unique<Integer>(resultValue);
}

unique_ptr<Number> Integer::operator - (const Number& other) {
    auto otherNumber = other.toInteger();

    Integer* otherInteger = dynamic_cast<Integer*>(otherNumber.get());
    if (!otherInteger) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    long resultValue = this->value - otherInteger->getValue();
    return make_unique<Integer>(resultValue);
}

unique_ptr<Number> Integer::operator * (const Number& other) {
    auto otherNumber = other.toInteger();

    Integer* otherInteger = dynamic_cast<Integer*>(otherNumber.get());
    if (!otherInteger) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }

    long resultValue = this->value * otherInteger->getValue();
    return make_unique<Integer>(resultValue);
}

unique_ptr<Number> Integer::operator / (const Number& other) {
    auto otherNumber = other.toInteger();

    Integer* otherInteger = dynamic_cast<Integer*>(otherNumber.get());
    if (!otherInteger) {
        throw runtime_error("No se pudo completar la operación");
        return nullptr;
    }
    if (otherInteger->getValue() == 0) {
        throw runtime_error("Error: División por cero");
        return nullptr;
    }

    long resultValue = static_cast<long>(this->value / otherInteger->getValue());
    return make_unique<Integer>(resultValue);
}