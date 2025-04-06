#include "real.h"
#include "integer.h"
#include "complex.h"

int main() {

    cout << "\n- Creando los siguientes números: " << endl;
    auto integer1 = make_unique<Integer>(10);
    auto integer2 = make_unique<Integer>(-10);
    auto real1 = make_unique<Real>(5.5);
    auto real2 = make_unique<Real>(-5.5);
    auto complex1 = make_unique<Complex>(10.0, 5.0);
    auto complex2 = make_unique<Complex>(-10.0, -5.0);

    auto integerZero = make_unique<Integer>(0);

    cout << "integerZero -> ";
    integerZero->toString();
    cout << "integer1 -> ";
    integer1->toString();
    cout << "integer2 -> ";
    integer2->toString();
    cout << "real1 -> ";
    real1->toString();
    cout << "real2 -> ";
    real2->toString();
    cout << "complex1 -> ";
    complex1->toString();
    cout << "complex2 -> ";
    complex2->toString();

    unique_ptr<Number> resultInteger;
    unique_ptr<Number> resultReal;
    unique_ptr<Number> resultComplex;

    cout << "\n- OPERACIONES ENTRE MISMAS CLASES: \n" << endl;


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

    cout << "\n- OPERACIONES ENTRE DIFERENTES CLASES: " << endl;

    cout << "\n\tEntero | Real" << endl;
    
    cout << "integer1 + real1 = ";
    resultInteger = *integer1 + *real1;
    resultInteger->toString();
    cout << "integer1 - real1 = ";
    resultInteger = *integer1 - *real1;
    resultInteger->toString();
    cout << "integer1 * real1 = ";
    resultInteger = *integer1 * *real1;
    resultInteger->toString();
    cout << "integer1 / real1 = ";
    resultInteger = *integer1 / *real1;
    resultInteger->toString();

    cout << "\n\tEntero | Complejo" << endl;
    
    cout << "integer1 + complex1 = ";
    resultInteger = *integer1 + *complex1;
    resultInteger->toString();
    cout << "integer1 - complex1 = ";
    resultInteger = *integer1 - *complex1;
    resultInteger->toString();
    cout << "integer1 * complex1 = ";
    resultInteger = *integer1 * *complex1;
    resultInteger->toString();
    cout << "integer1 / complex1 = ";
    resultInteger = *integer1 / *complex1;
    resultInteger->toString();

    cout << "\n\tReal | Entero" << endl;
    
    cout << "real1 + integer1 = ";
    resultReal = *real1 + *integer1;
    resultReal->toString();
    cout << "real1 - integer1 = ";
    resultReal = *real1 - *integer1;
    resultReal->toString();
    cout << "real1 * integer1 = ";
    resultReal = *real1 * *integer1;
    resultReal->toString();
    cout << "real1 / integer1 = ";
    resultReal = *real1 / *integer1;
    resultReal->toString();

    cout << "\n\tReal | Complejo" << endl;
    
    cout << "real1 + complex1 = ";
    resultReal = *real1 + *complex1;
    resultReal->toString();
    cout << "real1 - complex1 = ";
    resultReal = *real1 - *complex1;
    resultReal->toString();
    cout << "real1 * complex1 = ";
    resultReal = *real1 * *complex1;
    resultReal->toString();
    cout << "real1 / complex1 = ";
    resultReal = *real1 / *complex1;
    resultReal->toString();

    cout << "\n\tComplejo | Entero" << endl;
    
    cout << "complex1 + integer1 = ";
    resultComplex = *complex1 + *integer1;
    resultComplex->toString();
    cout << "complex1 - integer1 = ";
    resultComplex = *complex1 - *integer1;
    resultComplex->toString();
    cout << "complex1 * integer1 = ";
    resultComplex = *complex1 * *integer1;
    resultComplex->toString();
    cout << "complex1 / integer1 = ";
    resultComplex = *complex1 / *integer1;
    resultComplex->toString();

    cout << "\n\tComplejo | Real" << endl;
    
    cout << "complex1 + real1 = ";
    resultComplex = *complex1 + *real1;
    resultComplex->toString();
    cout << "complex1 - real1 = ";
    resultComplex = *complex1 - *real1;
    resultComplex->toString();
    cout << "complex1 * real1 = ";
    resultComplex = *complex1 * *real1;
    resultComplex->toString();
    cout << "complex1 / real1 = ";
    resultComplex = *complex1 / *real1;
    resultComplex->toString();

    cout << "\n- DIVISIÓN POR CERO: \n" << endl;

    cout << "integer1 / integerZero = ";
    try {
        resultInteger = *integer1 / *integerZero;
        resultInteger->toString();
    } catch (runtime_error &e) {
        cerr << e.what() << endl; 
    }

    cout << "real1 / integerZero = ";
    try {
        resultReal = *real1 / *integerZero;
        resultReal->toString();
    } catch (runtime_error &e) {
        cerr << e.what() << endl; 
    }

    cout << "complex1 / integerZero = ";
    try {
        resultComplex = *complex1 / *integerZero;
        resultComplex->toString();
    } catch (runtime_error &e) {
        cerr << e.what() << endl; 
    }
    return 0;
}