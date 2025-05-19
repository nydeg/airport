#include "Level.h"
#include <fstream>
#include <string>

#include "Cilivian.h"
#include "Cargo.h"
#include "Military.h"

Level::Level(int levelNumber)
{
	string line;

	std::ifstream in("/Users/krllggnv/Documents/GitHub/airport/AirGame/levels/" + to_string(levelNumber) + ".txt");
	if (in.is_open())
	{
		//Taking off Aripalnes pasring
		getline(in, line);	
		int takingOffAirplanesCount = stoi(line);
		for (int i = 0; i < takingOffAirplanesCount; ++i) {
			getline(in, line);
			string bNum = "";
			string stata = "";
			string sDate = "";
			string addingLapsCount = "";

			//parsing information
			for (int i = 2; i < 5; ++i) {
				bNum += line[i];
			}
			stata = line[6];
			for (int i = 8; i < 24; ++i) {
				sDate += line[i];
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
				break;
			}
			case('O'): {
				Cargo* temp = new Cargo;
				break;
			}
			case('N'): {
				Civilian* temp = new Civilian;
				break;
			}
			default:
				cout << "OOOPS\n";
				break;
			}



			cout << "\n\t" << i << "\n";
		}


		/*
		while (std::getline(in, line)) {
			std::cout << line << std::endl;
		}
		*/
	}
	in.close();
}
