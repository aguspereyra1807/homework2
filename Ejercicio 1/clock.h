#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstdlib> // Para el clear de consola
#include <limits>

using namespace std;

class Clock {
    public:
        // Constructores
        Clock();
        Clock(int hh);
        Clock(int hh, int mm);
        Clock(int hh, int mm, int ss);
        Clock(int hh, int mm, int ss, string indicator);
        
        // Métodos públicos
        int getHours();
        int getMinutes();
        int getSeconds();
        string getIndicator();
        void setHours(int h);
        void setMinutes(int m);
        void setSeconds(int s);
        void setIndicator(string indicator);
        void print12format();
        void print24format();
    private:
        bool checkData(int hhs = 0, int mms = 0,int sss = 0,string indicators = "a.m.");
        int HHh = 0, MMm = 0, SSs = 0;
        string ind = "a.m."; // No se si deberían ser públicos
};