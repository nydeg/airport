#include "Level.h"
#include <fstream>
#include <string>

Level::Level(int levelNumber)
{
	string line;

	std::ifstream in("levels/" + to_string(levelNumber) + ".txt");
	if (in.is_open())
	{
		while (std::getline(in, line)) {
			std::cout << line << std::endl;
		}
	}
	in.close();
}
