#include "student.h"
#include "course.h"

int main() {
    Course course("Paradigmas");
    course.inscribeStudent("agus", 1232);
    course.inscribeStudent("zaa", 1532);
    course.inscribeStudent("hhhh", 1533);

    course.print();

    cout << course.isInscribed(1532) << endl;

    course.unsuscribeStudent(1532);

    cout << course.isInscribed(1532) << endl;
    
    cout << "=========================" << endl;


    Course mate("Matemática", course);

    course.print();
    cout << "=========================" << endl;
    mate.print();

    return 0;
}