#include "real.h"
#include "integer.h"
#include "complex.h"

int main() {

    cout << "\n- Creando los siguientes números: " << endl;
    auto integer1 = make_unique<Integer>(10);
    auto integer2 = make_unique<Integer>(-10);
    auto real1 = make_unique<Real>(5.5);
    auto real2 = make_unique<Real>(-5.5);
    auto complex1 = make_unique<Complex>(20.0, 5.0);
    auto complex2 = make_unique<Complex>(-20.0, -5.0);

    auto integerZero = make_unique<Integer>(0);

    cout << "\nintegerZero -> ";
    integerZero->toString();
    cout << "\ninteger1 -> ";
    integer1->toString();
    cout << "\ninteger2 -> ";
    integer2->toString();
    cout << "\nreal1 -> ";
    real1->toString();
    cout << "\nreal2 -> ";
    real2->toString();
    cout << "\ncomplex1 -> ";
    complex1->toString();
    cout << "\ncomplex2 -> ";
    complex2->toString();


    cout << "\n- OPERACIONES ENTRE MISMAS CLASES: " << endl;

    unique_ptr<Number> resultInteger;
    unique_ptr<Number> resultReal;
    unique_ptr<Number> resultComplex;

    cout << "integer1 + integer2 = ";
    resultInteger = *integer1 + *integer2;
    resultInteger->toString();

    cout << "integer1 - integer2 = ";
    resultInteger = *integer1 - *integer2;
    resultInteger->toString();

    cout << "integer1 * integer2 = ";
    resultInteger = *integer1 * *integer2;
    resultInteger->toString();

    cout << "integer1 / integer2 = ";
    resultInteger = *integer1 / *integer2;
    resultInteger->toString();

    cout << "integer1 / integerZero = ";
    try {
        resultInteger = *integer1 / *integerZero;
        resultInteger->toString();
    } catch (runtime_error &e) {
        cerr << e.what() << endl; 
    }

    cout << endl;

    cout << "real1 + real2 = ";
    resultReal = *real1 + *real2;
    resultReal->toString();

    cout << "real1 - real2 = ";
    resultReal = *real1 - *real2;
    resultReal->toString();

    cout << "real1 * real2 = ";
    resultReal = *real1 * *real2;
    resultReal->toString();

    cout << "real1 / real2 = ";
    resultReal = *real1 / *real2;
    resultReal->toString();

    cout << "real1 / integerZero = ";
    try {
        resultReal = *real1 / *integerZero;
        resultReal->toString();
    } catch (runtime_error &e) {
        cerr << e.what() << endl; 
    }

    cout << endl;

    cout << "complex1 + complex2 = ";
    resultComplex = *complex1 + *complex2;
    resultComplex->toString();

    cout << "complex1 - complex2 = ";
    resultComplex = *complex1 - *complex2;
    resultComplex->toString();

    cout << "complex1 * complex2 = ";
    resultComplex = *complex1 * *complex2;
    resultComplex->toString();

    cout << "complex1 / complex2 = ";
    resultComplex = *complex1 / *complex2;
    resultComplex->toString();

    cout << "complex1 / integerZero = ";
    try {
        resultComplex = *complex1 / *integerZero;
        resultComplex->toString();
    } catch (runtime_error &e) {
        cerr << e.what() << endl; 
    }

    cout << "\n- OPERACIONES ENTRE DIFERENTES CLASES: " << endl;
    
    return 0;
}