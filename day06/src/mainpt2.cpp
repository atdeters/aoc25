#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#define VERBOSE 1

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
	std::vector<std::string> lines;
	while (std::getline(file, currentLine)) {
		if (currentLine == "") {
			continue;
		}
		lines.push_back(currentLine);
	}

	size_t fields = lines.size();

	std::vector<std::string> newVec;
	for (size_t j = 0; j < lines[0].size(); j++) {
		std::string curr;
		std::string exprStr;
		for (size_t i = 0; i < lines.size(); i++) {
			char currCh = lines[i][lines[i].size() - 1 - j];
			if (isdigit(currCh)) {
				curr.push_back(currCh);
			}
			else if (currCh != ' '){
				curr.push_back(' ');
				curr.push_back(currCh);

			}
			else {
				curr.push_back(currCh);
			}
		}
		std::string s;
		std::stringstream ss(curr);
		while (std::getline(ss, s, ' ')) {
			newVec.push_back(s);
		}
	}

	long result = 0;
	size_t i = 0;
	while (i < newVec.size()) {
		size_t emptyLineCount = 0;
		std::vector<std::string> tmp;

		while (i < newVec.size() && emptyLineCount < fields) {
			if (newVec[i] != "") {
				tmp.push_back(newVec[i]);
				emptyLineCount = 0;
			}
			else {
				emptyLineCount++;
			}
			i++;
		}
		


		std::sort(tmp.begin(), tmp.end());


		bool tmpResSet = false;
		long tmpRes = 0;
		bool exprSet = false;
		char expr = 0;
		for (size_t j = 0; j < tmp.size(); j++) {
			if (!exprSet) {
				expr = tmp[j][0];
				exprSet = true;
				continue;
			}
			else if (!tmpResSet) {
				tmpRes = std::atoi(tmp[j].c_str());
				tmpResSet = true;
				continue;
			}
			if (expr == '+') {
				tmpRes += std::atoi(tmp[j].c_str());
			}
			else if (expr == '*') {
				tmpRes *= std::atoi(tmp[j].c_str());
			}
		}
		result += tmpRes;
	}

	std::cout << "The actual result of the homework is \e[1m" <<  result << "\e[0m" <<  std::endl;


	file.close();
}
