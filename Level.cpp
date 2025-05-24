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

	std::ifstream in("levels/" + to_string(levelNumber) + ".txt");
	if (in.is_open())
	{
		//Airplanes parsing
		getline(in, line);	
		int AirplanesCount = stoi(line);
		countOfAirplanes = AirplanesCount;
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

			switch (line[0])
			{
			case('Y'): {
				Military* temp = new Military(boardNumber, stata, fDate, maxLaps);
				airplanes.push_back(temp);
				break;
			}
			case('O'): {
				Cargo* temp = new Cargo(boardNumber, stata, fDate, maxLaps);
				airplanes.push_back(temp);
				break;
			}
			case('N'): {
				Civilian* temp = new Civilian(boardNumber, stata, fDate, maxLaps);
				airplanes.push_back(temp);
				break;
			}
			default:
				cout << "OOOPS\n";
				break;
			}



			cout << "\n\t" << i << "\n";
		}

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


	}
	in.close();
}

Level::Level() {};

void Level::initLapCoordinates() {
	this->lapCoordinates.push_back({10, 10, "upper-right"});
	this->lapCoordinates.push_back({0, 10, "upper-left"});
	this->lapCoordinates.push_back({0, 0, "lower-left"});
	this->lapCoordinates.push_back({10, 0, "lower-right"});
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

