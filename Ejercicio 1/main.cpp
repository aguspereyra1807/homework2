#include "clock.h"

int main() {
    // Test todas las funciones
    system("clear");
    cout << "===========================================\n"
    << "Test Constructores" << endl;
    cout << "===========================================\n";

    cout << "1) Vacío" << endl;
    Clock clock1;
    clock1.print12format();

    cout << "\n2) Sólo hora" << endl;
    Clock clock2(10);
    clock2.print12format();

    cout << "\n3) Hora y minutos" << endl;
    Clock clock3(10, 30);
    clock3.print12format();

    cout << "\n4) Hora, minutos y segundos" << endl;
    Clock clock4(10, 30, 45);
    clock4.print12format();

    cout << "\n3) Hora, minutos, segundos y 'a.m./p.m.'" << endl;
    Clock clock5(10, 30, 45, "p.m.");
    clock5.print12format();

    cout << endl;
    
    cout << "[Enter] para continuar" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");
    // Datos ingresados por el usuario
    Clock userclock;
    cout << "===========================================\n"
    << "Testeo de error + datos por consola" << endl;
    cout << "===========================================\n";

    int hh, mm, ss;
    string ind;

    cout << endl;

    while (true) {
        cout << "Ingrese las horas:\n>"; 
        cin >> hh;
        cout << "Ingrese los minutos:\n>"; 
        cin >> mm;
        cout << "Ingrese los segundos:\n>"; 
        cin >> ss;
        cout << "Ingrese 'a.m./p.m.':\n>"; 
        cin >> ind;
        try {
            userclock = Clock(hh,mm,ss,ind);
        } catch (const invalid_argument& e) {
            cout << "Error:" << e.what() << endl;
            cout << "Vuelva a intentar\n" << endl;
            continue;
        }
        break;
    }
    cout << "userclock creado correctamente " << endl;

    cout << "\nEnter para continuar" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); 

    while (true) {
        system("clear");
        cout << "Método:" << endl;
        cout << "==============================================\n"
             << "|| 1.get  ||  2.set ||  3.print  ||  4.exit ||\n"
             << "==============================================\n" << endl;
        
        cout << "> ";
        int option;
        cin >> option;
        system("clear");
        switch (option) {
            case 1:
                cout << "get()" << endl;
                cout << "===========================================================\n"
                    << "|| 1.Hours  ||  2.Minutes ||  3.Seconds  ||  4.Indicator ||\n"
                    << "===========================================================\n" << endl;
                cout << "> ";
                int get;
                cin >> get;
                switch (get) {
                    case 1:
                        cout << userclock.getHours() << endl;
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    case 2:
                        cout << userclock.getMinutes() << endl;
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    case 3:
                        cout << userclock.getSeconds() << endl;
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    case 4:
                        cout << userclock.getIndicator() << endl;
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    default:
                        cout << "Input inválido";
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                }
                break;
                
            case 2:
                cout << "set()" << endl;
                cout << "===========================================================\n"
                    << "|| 1.Hours  ||  2.Minutes ||  3.Seconds  ||  4.Indicator ||\n"
                    << "===========================================================\n" << endl;
                cout << "> ";
                int set;
                cin >> set;
                switch (set) {
                    case 1: {
                        int h;
                        cout << "Horas a setear: ";
                        cin >> h;
                        userclock.setHours(h);
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    }
                    case 2: {
                        int m;
                        cout << "Minutos a setear: ";
                        cin >> m;
                        userclock.setMinutes(m);
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    }
                    case 3: {
                        int s;
                        cout << "Segundos a setear: ";
                        cin >> s;
                        userclock.setSeconds(s);
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    }
                    case 4: {
                        string indInput;
                        cout << "'a.m./p.m.' : ";
                        cin >> indInput;
                        userclock.setIndicator(indInput);
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        break;
                    }
                    default:
                        cout << "Input inválido" << endl;
                        continue;
                }
                continue;
            case 3:
                cout << "print()" << endl;
                cout << "========================================\n"
                     << "|| 1.12HourFormat  ||  2.24HourFormat ||\n"
                     << "========================================\n" << endl;
                cout << "> ";
                int format;
                cin >> format;
                switch (format) {
                    case 1:
                        userclock.print12format();
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        continue;
                    case 2:
                        userclock.print24format();
                        cout << "[Enter] para continuar" << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                        continue;
                    default:
                        cout << "Input inválido" << endl;
                        break;
                    }
            case 4:
                return 0;
            
            default:
                cout << "Input inválido" << endl;
                cout << "[Enter] para continuar" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
    }
    return 0;
}