#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#define VERBOSE 0

int main( int ac, char **av ) {

	if (ac != 2) {
		std::cerr << "Usage: ./day06 <puzzle-input>" << std::endl;
		return 1;
	}

	std::fstream file(av[1]);
	if (!file.good()) {
		std::cerr << "Could not open file: " << av[1] << std::endl;
		return 1;
	}

	std::string currentLine;
	std::vector<std::vector<std::string> > lines;
	size_t counter = 0;
	size_t vecLen = 0;
	while (std::getline(file, currentLine)) {
		if (currentLine == "") {
			continue;
		}
		std::vector<std::string> vec;
		std::string s;
		std::stringstream ss(currentLine);
		while (std::getline(ss, s, ' ')) {
			if (s != "") {
				vec.push_back(s);
			}
		}
		if (counter == 0) {
			vecLen = vec.size();
		}
		else if (vecLen != vec.size()) {
			std::cerr << "Cannot calculate unevenly sized lines input" << std::endl;
			file.close();
			return 1;
		}
		lines.push_back(vec);
		counter++;
	}

	long res = 0;
	char expr;
	for (size_t i = 0; i < vecLen; i++) {
		long tmp = std::atoi(lines[lines.size()-2][i].c_str());
		expr = lines[lines.size()-1][i][0];
		for (size_t j = 2; j < lines.size(); j++) {
			if (VERBOSE) {
				std::cout << lines[lines.size()-1-j][i] << " " << expr << " ";
			}
			if (expr == '+') {
				tmp += std::atoi(lines[lines.size()-1-j][i].c_str());
			}
			else if (expr == '*') {
				tmp *= std::atoi(lines[lines.size()-1-j][i].c_str());
			}
		}
		res += tmp;
		if (VERBOSE) {
			std::cout << "= " << tmp <<  std::endl;
		}
	}
	file.close();
	std::cout << "The result of the homework is \e[1m" << res << "\e[0m" << std::endl;
}
