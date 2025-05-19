#include <iostream>
#include "Date.h"
#include "Level.h"
int main()
{

    Level level_1(2);

    cout << "\n\n";

    level_1.scheduleSort();

    for (int i = 0; i < level_1.getAirplanes().size(); ++i) {
        cout << "board number " << level_1.getAirplanes()[i]->getBoardNumber() << " will start at \n\t";
        level_1.getAirplanes()[i]->getTimeOfAction().printDate();
        cout << "\n";
    }

    /*
    Date currDate;
    Date cD;

    currDate = currDate + 30;
    currDate.printDate();

    int raz = currDate - cD;
    cout << "\nThis is ZADERJKA IN MINUTES --> " << raz << "\n";
    */
//    std::cout << "Hello World!\n";
}
