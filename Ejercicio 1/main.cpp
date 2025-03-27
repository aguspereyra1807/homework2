#include "clock.h"

int main() {
    // Test todas las funciones
    cout << "===========================================\n"
    << "Constructores" << endl;

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

    cout << endl
    << "===========================================\n"
    << "Modificaciones" << endl;
    cout << "clock1.print12format(): ";
    clock1.print12format();
    cout << "clock1.setHours(8)\nclock1.setMinutes(50)\nclock1.setSeconds(15)\nclock1.setIndicator('p.m.')" << endl;
    clock1.setHours(8);
    clock1.setMinutes(50);
    clock1.setSeconds(15);
    clock1.setIndicator("p.m.");
    cout << "clock1.getHours() = " << clock1.getHours() << endl;
    cout << "clock1.getMinutes() = " << clock1.getMinutes()  << endl;
    cout << "clock1.getSeconds() = " << clock1.getSeconds()  << endl;
    cout << "clock1.getSeconds() = " << clock1.getIndicator()  << endl;
    cout << "\nclock1.print12format(): ";
    clock1.print12format();
    cout << "\nclock1.print24format(): ";
    clock1.print24format();
    
    // Datos ingresados por el usuario
    Clock userclock;
    cout << "===========================================\n"
    << "Testeo de error + datos por consola" << endl;
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
            Clock userclock(hh,mm,ss,ind);
        } catch (const invalid_argument& e) {
            cout << "Error:" << e.what() << endl;
            cout << "Vuelva a intentar\n" << endl;
            continue;
        }
        break;
    }
    cout << "userclock creado correctamente " << endl;
}