#include <iostream>
#include "Date.h"
#include "Level.h"
int main()
{

    Level level_1(1);

    cout << "\n\n";

    for (int i = 0; i < level_1.getAirplanes().size(); ++i) {
        cout << "board nuber " << level_1.getAirplanes()[i]->getBoardNumber() << " will start at \n\t";
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
