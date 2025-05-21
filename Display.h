#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include "Airplane.h"
#include "Airstrip.h"
#include "Date.h"
#include "vector"

using namespace std;


class Display {
public:

    Display();
    Display(vector<Airplane*>* flights, vector<Airstrip*>* Airstrips);
    Display(Date curr, int fine, int score, vector<Airplane*>* flights, vector<Airstrip*>* Airstrips);

    void showingInfo(); // the info which will be showed on display.


    //setters
    void setCurrDate(Date tmp){currTime = tmp;};
    void setCurrFine(int tmp){currFine = tmp;}
    void setCurrScore(int tmp){currScore = tmp;}
    void setSchedule(vector<Airplane*>* tmp){ schedule = tmp;}
    void setAirstrips(vector<Airstrip*>* tmp){strips = tmp;}


    //access
    Date d_getCurrTime(){return currTime;}
    int getCurrFine(){return currFine;}
    int getCurrScore(){return currScore;}
    vector<Airplane*>* getSchedule(){return schedule;}
    vector<Airstrip*>* getAirstrips(){return strips;}


private:


    Date currTime;
    int currFine;
    int currScore;
    vector<Airplane*>* schedule;
    vector<Airstrip*>* strips;
    //approve
    //dismiss

};

#endif //DISPLAY_H
