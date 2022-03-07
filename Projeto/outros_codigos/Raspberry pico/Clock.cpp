#include <iostream>
#include "Calendar.cpp"
using namespace std;

class Clock{
protected:
   
    int hr, min, sec; 
    
public:
    Clock();
    void setClock(int h, int m, int s);
    void getClock(int& h, int& m, int& s);
    void advance ();
};    
Clock::Clock(){
    
    
}
void Clock::setClock(int h, int m, int s){
    hr = h;
    min = m;
    sec = s;
    
} 
void Clock::getClock(int& h, int& m, int& s){
    h = hr;
    m = min;
    s = sec;
    //cout << hr << ":" << min << ":" << sec << endl;
    
}

void Clock::advance(){
        sec++;
        if(sec >= 60){
            sec = 0;
            min++;
            if(min >= 60){
                min = 0;
                hr++;
                if(hr >= 24){
                    hr = 0;
                    
                    
                }
                /*if(isPm && hr >= 12){//passou  da meia noite, virou o dia
                    hr = 0;
                    isPm = !isPm;// muda para AM
                }else
                    if(!isPm && hr >= 12){
                        
                        isPm = !isPm;
                    }*/
            }
        }
        //sleep_ms(1000);
}
