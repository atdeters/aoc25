#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#ifndef PART
# define PART 1
#endif

#define STARTPOS 50

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./day01 <puzzle-input>" << std::endl;
		return 1;
	}

	std::ifstream input(av[1]);
	if (!input.good()) {
		std::cerr << "Could not open file: " << av[1] << std::endl;
		return 1;
	}

	if (PART != 1 && PART != 2) {
		std::cerr << "Invalid \"PART\" definition: " << PART << std::endl;
		return 1;
	}

	int zeroCounter = 0;
	int zeroCounterFr = 0;

	int currentPos = STARTPOS;
	std::string currentLine;
	while (std::getline(input, currentLine)) {
	
		if (currentLine.size() < 2
			|| (currentLine[0] != 'R' && currentLine[0] != 'L')) {
			continue;
		}
		
		char *currStr = static_cast<char *>(&currentLine[1]);
		int currentNb = std::atoi(currStr);

		if (currentLine[0] == 'R' && currentNb != -1) {
			switch (PART) {
				case 1:
					currentPos = (currentPos + currentNb) % 100;
					break;
				case 2:
					currentNb += currentPos;
					while (currentNb > 99) {
						currentNb -= 100;
						if (currentNb != 0)
							zeroCounterFr++;
					}
					currentPos = currentNb;
			}
		}
		else if (currentLine[0] == 'L' && currentNb != -1) {
			switch (PART) {
				case 1:
					currentPos = currentPos - (currentNb % 100);
					break;
				case 2:
					while (currentNb > 99) {
						currentNb -= 100;
						zeroCounterFr++;
					}
					if (currentPos != 0 && currentPos < currentNb) {
						zeroCounterFr++;
					}
					currentPos -= currentNb;
			}
			if (currentPos < 0) {
				currentPos = 100 + currentPos;
			}
		}
		if (currentPos == 0) {
			zeroCounter++;
			zeroCounterFr++;
		}
	}

	switch (PART) {
		case 1:
			std::cout << "The password is: " << zeroCounter << std::endl;
			break;
		case 2:
			std::cout << "The actual password is: " << zeroCounterFr << std::endl;

	}
}
