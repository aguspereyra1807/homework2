#include "student.h"
#include "course.h"

// USAR TRY Y MANEJAR BAD_ALLOCS DE inscribeStudent

int generateFileNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1000,9999);
    return dist(gen);
}

void pause() {
    cout << "[Enter] para continuar" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    
    vector<shared_ptr<Course>> courses;

    courses.push_back(make_shared<Course>("Paradigmas de la Programación"));
    courses.push_back(make_shared<Course>("Algoritmos y Estructuras de Datos"));
    courses.push_back(make_shared<Course>("Pensamiento Computacional"));

    int n1 = generateFileNumber();
    int n2 = generateFileNumber();
    int n3 = generateFileNumber();
    int n4 = generateFileNumber();
    
    for (auto i = courses.begin(); i != courses.end(); ++i) {
        try {
            i->get()->inscribeStudent("Tomás", n1);
            i->get()->inscribeStudent("Lucas", n2);
            i->get()->inscribeStudent("Rodrigo", n3);
            i->get()->inscribeStudent("Andrés", n4);
        } catch (const bad_alloc &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << "Se han creado los cursos 'Paradigmas de la Programación', 'Algoritmos y Estructuras de datos' y 'Pensamiento Computacional' "<< endl;
    pause();

    while (true) {
        system("clear");
        cout << "==============================================================\n"
             << "|| 1. Nuevo curso vacío  || 2. Nuevo curso a partir de otro ||\n"
             << "|| 3. Mostrar cursos     || 4. Operar sobre curso           ||\n"
             << "|| 5. exit               ||                                 ||\n"
             << "==============================================================\n" << endl;
        cout << "> ";
        int option;
        cin >> option;
        if (cin.fail()) {
            cout << "Comando desconocido" << endl;
            cin.clear();
            pause();
            continue;
        }
        switch (option) {
            case 1: { // Nuevo curso vacío
                cout << "Ingrese el nombre del curso: ";
                string name;
                getline(cin >> ws, name);
                courses.push_back(make_shared<Course>(name));
                cout << "\n Curso creado con éxito" << endl;
                pause();
                continue;

            } case 2: { // Nuevo curso a partir de otro
                
                cout << "Curso a copiar: " << endl;
                int i = 0;
                for (auto course : courses) {
                    cout << ++i << ". " << course->getName() << endl;
                }

                size_t indexToCopy;
                cin >> indexToCopy;
                if (cin.fail() || indexToCopy - 1 > courses.size()) {
                    cout << "Índice fuera de rango" << endl;
                    cin.clear();
                    pause();
                    continue;
                }
                
                shared_ptr<Course> toCopy = courses[indexToCopy-1];

                
                cout << "Ingrese el nombre del nuevo curso: ";
                string newCourseStr;
                getline(cin >> ws, newCourseStr);
                
                courses.push_back(make_shared<Course>(newCourseStr, *toCopy));
                cout << "Curso creado correctamente" << endl;
                pause();
                
                break;

            } case 3: { // Mostrar cursos

                
                for (auto i = courses.begin(); i != courses.end(); ++i) {
                    cout << "======================================================" << endl;
                    cout << i->get()->getName() << ":\n" << endl;
                    i->get()->print();
                    cout << "======================================================" << endl;
                }
                
                pause();
                break;

            } case 4: { // Operar sobre curso

                cout << "Curso a modificar: " << endl;
                int i = 0;
                for (auto course : courses) {
                    cout << ++i << ". " << course->getName() << endl;
                }

                size_t indexModify;
                cin >> indexModify;
                if (cin.fail() || indexModify - 1 > courses.size()) {
                    cout << "Índice fuera de rango" << endl;
                    cin.clear();
                    pause();
                    continue;
                }
                
                shared_ptr<Course> toModify = courses[indexModify-1];
                
                bool activeMenu = true;

                while (activeMenu) { // Menú operaciones
                    
                    system("clear");
                    cout << toModify->getName() << "\n" << endl;
                    cout << "==============================================================\n"
                         << "||  1. Inscribir Alumno    ||   2. Desinscribir Alumno      ||\n"
                         << "||  3. ¿Está inscripto?    ||   4. ¿Está completo el curso? ||\n"
                         << "||  5. Mostrar información ||   6. exit                     ||\n"
                         << "==============================================================" << endl;
                    cout << "> ";
                    int operation;
                    cin >> operation;

                    switch (operation) {

                        case 1: { // Inscribir Alumno

                            cout << "\nIngrese el nombre del alumno: ";
                            string studentName;
                            getline(cin >> ws, studentName);
                            toModify.get()->inscribeStudent(studentName, generateFileNumber());
                            pause();
                            break;

                        } case 2: { // Desinscribir Alumno

                            cout << "\nIngrese el numero de legajo del alumno: ";
                            int fileNumber;
                            cin >> fileNumber;
                            if (cin.fail()) {
                                cerr << "Input incorrecto" << endl;
                                cin.clear();
                                pause();
                                break;
                            }
                             if (!toModify.get()->isInscribed(fileNumber)) {
                                cerr << "El alumno no encontrado en " << toModify.get()->getName() << endl;
                                pause();
                                break;
                             }
                            cout<< "\nIngrese la nota final del alumno: ";
                            float finalGrade;
                            cin >> finalGrade;
                            if (cin.fail()) {
                                cerr << "Input incorrecto" << endl;
                                cin.clear();
                                pause();
                                break;
                            }
                            toModify.get()->unsuscribeStudent(fileNumber, finalGrade);
                            pause();
                            break;
            
                        } case 3: { // ¿Está inscripto?

                            cout << "\nIngrese el numero de legajo del alumno: ";
                            int fileNumber;
                            cin >> fileNumber;
                            if (toModify.get()->isInscribed(fileNumber)) cout << "\n El alumno está inscripto" << endl;
                            else cout << "\nEl alumno no está inscripto" << endl;
                            pause();
                            break;

                        } case 4: { // ¿Está completo el curso?

                            if (toModify.get()->isComplete()) cout << "\nEl curso está completo" << endl;
                            else cout << "\nEl curso no está completo" << endl;
                            pause();
                            break;

                        } case 5: { // Mostrar información

                            toModify.get()->print();
                            pause();
                            break;

                        } case 6: { // exit (del menú de operaciones)

                            activeMenu = false;
                            continue;

                        } default: {

                            cout << "Comando desconocido" << endl;
                            pause();
                            break;

                        }
                        
                    }
                }
                break;
            } case 5: { // exit

                return 0;

            } default: {
                cout << "Comando desconocido" << endl;
                pause();
                continue;
            }
        }
    }

    return 0;
}