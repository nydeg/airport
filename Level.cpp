#include "Level.h"
#include <fstream>
#include <string>
#include <algorithm>

#include "Cilivian.h"
#include "Cargo.h"
#include "Military.h"
#include "Date.h"
#include "Airstrip.h"


Level::Level(int levelNumber)
{
	string line;
	this->level_num = levelNumber;

	std::ifstream in("levels/" + to_string(levelNumber) + ".txt");
	if (in.is_open())
	{
		getline(in, line);	
		int AirplanesCount = stoi(line);
		countOfAirplanes = AirplanesCount;

		// Airstrips parsing
		getline(in, line);
		int AirstripsCount = stoi(line);
		for (int i = 0; i < AirstripsCount; ++i) {
			getline(in, line);
			int stX = 0;
			int stY = 0;
			int edX = 0;
			int edY = 0;

			//parse airstrips data
			int j = 0;
			string buff = "";
			int counter = 0;
			while (j < line.size()) {
				if (line[j] != ' ') {
					buff += line[j];
				}
				else {
					cout << "\n";
					switch (counter)
					{
						case(0): {
							stX = stoi(buff);
							buff = "";
							++counter;
							break;
						}
						case(1): {
							stY = stoi(buff);
							buff = "";
							++counter;
							break;
						}
						case(2): {
							edX = stoi(buff);
							buff = "";
							++counter;
							break;
						}
					}
				}
				++j;
			}
			edY = stoi(buff);

			//prepare airstrips data
			pair<int, int> st = { stX, stY };
			pair<int, int> ed = { edX, edY };

			Airstrip* airstripTMP = new Airstrip(st, ed);
			airstrips.push_back(airstripTMP);
			cout << "\n\t" << i + AirplanesCount << "\n";
		}

		//Airplanes parsing
		for (int i = 0; i < AirplanesCount; ++i) {
			getline(in, line);
			string bNum = "";
			string stata = "";
			string sDate = "";
			string addingLapsCount = "";

			//parsing information
			for (int j = 2; j < 5; ++j) {
				bNum += line[j];
			}
			stata = line[6];
			for (int k = 8; k < 24; ++k) {
				sDate += line[k];
			}
			addingLapsCount = line[25];

			//prepare information
			int boardNumber = stoi(bNum);
			Date fDate(sDate);
			int maxLaps = stoi(addingLapsCount);

			if (!(find(allBoardNumbers.begin(), allBoardNumbers.end(), boardNumber % 100) != allBoardNumbers.end())) {
				allBoardNumbers.push_back(boardNumber % 100);
			}

			switch (line[0])
			{
				case('Y'): {
					Military* temp = new Military(boardNumber, stata, fDate, maxLaps, this);
					temp->setType("military");
					airplanes.push_back(temp);
					break;
				}
				case('O'): {
					Cargo* temp = new Cargo(boardNumber, stata, fDate, maxLaps, this);
					temp->setType("cargo");
					airplanes.push_back(temp);
					break;
				}
				case('N'): {
					Civilian* temp = new Civilian(boardNumber, stata, fDate, maxLaps, this);
					temp->setType("civilian");
					airplanes.push_back(temp);
					break;
				}
				default:
					cout << "OOOPS\n";
				break;
			}



			cout << "\n\t" << i << "\n";
		}



	}
	in.close();

	initLapCoordinates();

}

Level::Level() {};

void Level::initLapCoordinates() {
	this->lapCoordinates.push_back({30, 30, "upper-left"});
	this->lapCoordinates.push_back({1480, 30, "upper-right"});
	this->lapCoordinates.push_back({1480, 870, "lower-right"});
	this->lapCoordinates.push_back({30, 870, "lower-left"});
}



bool CompareByDate(Airplane* ft, Airplane* sd)
{
	if (ft->getTimeOfAction() > sd->getTimeOfAction())
		return false;
	if (ft->getTimeOfAction() == sd->getTimeOfAction())
		if(ft->getBoardNumber() > sd->getBoardNumber())
			return false;
	return true;
}

void Level::scheduleSort()
{
	sort(airplanes.begin(), airplanes.end(), CompareByDate);
}

