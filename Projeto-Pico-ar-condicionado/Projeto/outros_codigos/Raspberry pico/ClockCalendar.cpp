#ifndef ClockCalendar_H
#define ClockCalendar_H
#include "Clock.cpp"
#include "Calendar.cpp"
#include <iostream>
using namespace std;

class ClockCalendar : public Clock, public Calendar {
    

public:
    ClockCalendar();
    void advance();
    void setClockCalendar(int, int, int, int, int, int);
    // int getClockCalendar();
};
ClockCalendar::ClockCalendar(): Clock (), Calendar (){
    hr = 0;
    min = 0;
    sec = 0;
    day = 1;
    mo = 1;
    yr = 2022;

}

void ClockCalendar::setClockCalendar(int dia, int mes, int ano, int hr, int mn, int sg){
    setCalendar(dia, mes, ano);
    setClock(hr, mn, sg);
    
}

void ClockCalendar::advance(){
    //bool wasPm = isPm;
    for(int i = 0; i <= 60; i++){
        Clock::advance();
    }
    Calendar::advance();
    
    }
    


#endif
