#include "student.h"
#include "course.h"

// USAR TRY Y MANEJAR BAD_ALLOCS DE inscribeStudent

int main() {
    
    Course paradigmas("Paradigmas");
    cout << "Se ha creado el objeto curso 'paradigmas' con éxito" << endl;

    paradigmas.inscribeStudent("Pablo", 16525);

    return 0;
}