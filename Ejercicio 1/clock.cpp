#include "clock.h"

// Public Methods
int Clock::getHours() {
    return HHh;
}

int Clock::getMinutes() {
    return MMm;
}

int Clock::getSeconds() {
    return SSs;
}

string Clock::getIndicator() {
    return ind;
} 

void Clock::setHours(int h) {
    checkData(h);
    HHh = h;
}

void Clock::setMinutes(int m) {
    checkData(HHh, m);
    MMm = m;
}

void Clock::setSeconds(int s) {
    checkData(HHh, MMm, s);
    SSs = s;
}

void Clock::setIndicator(string indicator) {
    checkData(HHh, MMm, SSs, indicator);
    ind = indicator;
}

void Clock::print12format() {
    cout << setfill('0') << setw(2) << HHh << ":"
         << setfill('0') << setw(2) << MMm << ":"
         << setfill('0') << setw(2) << SSs << " "
         << ind << endl;
}

void Clock::print24format() {
    int hour = HHh;
    if (ind == "p.m.") hour = HHh + 12; 
    cout << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << MMm << ":"
         << setfill('0') << setw(2) << SSs << " "
         << "Hs" << endl;
}


// Private Methods
bool Clock::checkData(int hhs , int mms,int sss,string indicators) {
    if (hhs > 11 || hhs < 0 || mms > 59 || mms < 0 || sss > 59 || sss < 0 || (indicators != "a.m." && indicators != "p.m.")) {
        return false;
    }
    return true;
}

// Builders

Clock::Clock() {}

Clock::Clock(int hh) {
    if (!checkData(hh)) {
        throw invalid_argument("Invalid Argument");
    }
    HHh = hh;
}

Clock::Clock(int hh, int mm) {
    if (!checkData(hh,mm)) {
        throw invalid_argument("Invalid Argument");
    }
    HHh = hh;
    MMm = mm;
}

Clock::Clock(int hh, int mm, int ss) {
    if (!checkData(hh,mm,ss)) {
        throw invalid_argument("Invalid Argument");
    }
    HHh = hh;
    MMm = mm;
    SSs = ss;
}

Clock::Clock(int hh, int mm, int ss, string indicator) {
    if (!checkData(hh,mm,ss,indicator)) {
        throw invalid_argument("Invalid Argument");
    }
    HHh = hh;
    MMm = mm;
    SSs = ss;
    ind = indicator;
}
