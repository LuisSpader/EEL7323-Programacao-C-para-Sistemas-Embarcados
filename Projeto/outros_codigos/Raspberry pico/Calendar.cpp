#ifndef CALENDAR_CPP
#define CALENDAR_CPP
#include <iostream>
using namespace std;

class Calendar{
protected:
    int day, mo, yr;
public:
    Calendar();
    void setCalendar (int d, int m, int y);
    void getCalendar (int& d, int& m, int& y);
    void advance ();
};

Calendar::Calendar(){
    day = 1;
    mo = 1;
    yr = 2022;
    
}
void Calendar::setCalendar(int d,int m, int y){
    yr = y;
    mo = m;
    day = d;
}
void Calendar::getCalendar(int& d, int& m, int& y){
    y = yr;
    m = mo;
    d = day;
    //cout << day << "/" << mo << "/" << yr << endl;
}
void Calendar::advance(){
    
    day++;
        if(day >= 30){
            day = 1;
		    mo++;
            if(mo >= 12){
                mo = 1;
			    yr++;
            }
        }
    
}
#endif
//referencia altera diretamente a variavel