
#include <string>

using namespace std;

class Number {
    public:
        // // Métodos. Modifican
        // virtual void add(Number& other) = 0; 
        // virtual void subtract(Number& other) = 0;
        // virtual void multiplicate(Number& other) = 0;

        // // ó

        // // Sobrecarga de operadores modificando el primer número (this).
        // virtual void operator+(const Number& other) = 0;
        // virtual void operator-(const Number& other) = 0;
        // virtual void operator*(const Number& other) = 0;

        // Sobrecarga de operadores con retorno.
        virtual Number* operator+(const Number& other) = 0; // Creo la clase numero a retornar adentro
        virtual Number* operator-(const Number& other) = 0;
        virtual Number* operator*(const Number& other) = 0;

        virtual void toString() = 0;
};