#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <string>

using namespace std;

class Dispatcher {
public:
    // getters
    int getLastLevel() { return this->lastLevel; }
    int getBestScore() { return this->bestScore; }
    string getName() { return this->name; }
    int getLosesNumber() { return this->losesNumber; }
    int getCurrentScore() { return this->currentScore; }

    //setters
    void setLastLevel(int level) { this->lastLevel = level; }
    void setBestScore(int score) { this->bestScore = score; }
    void setCurrentScore(int score) { this->currentScore = score; }
    void setLosesNumber(int loses) { this->losesNumber = loses; }

private:
    int lastLevel;
    int bestScore;
    int currentScore;
    string name;
    int losesNumber;
};

#endif //DISPATCHER_H
