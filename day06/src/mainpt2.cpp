#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

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

	// === GET PUZZLE INPUT ===
	std::string currentLine;
	std::vector<std::string> lines;
	while (std::getline(file, currentLine)) {
		if (currentLine != "") {
			lines.push_back(currentLine);
		}
	}

	size_t fields = lines.size();

	// === FILL VEC WITH CORRECT ORDER ===
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

	// === CALCULATE THE ACTUAL RESULT ===
	long result = 0;
	size_t i = 0;
	while (i < newVec.size()) {

		// === CREATE CURRENT BLOCK TO CALCULATE ===
		size_t emptyLineCount = 0;
		std::vector<std::string> block;
		while (i < newVec.size() && emptyLineCount < fields) {
			if (newVec[i] != "") {
				block.push_back(newVec[i]);
				emptyLineCount = 0;
			}
			else {
				emptyLineCount++;
			}
			i++;
		}
	
		// === SORT BLOCK TO GET EXPR TO THE TOP ===
		std::sort(block.begin(), block.end());

		// === CALCULATE CURRENT BLOCK ===
		long blockRes = 0;
		char expr = 0;
		for (size_t j = 0; j < block.size(); j++) {
			if (expr == 0) {
				expr = block[j][0];
			}
			else if (blockRes == 0) {
				blockRes = std::atoi(block[j].c_str());
			}
			else if (expr == '+') {
				blockRes += std::atoi(block[j].c_str());
			}
			else if (expr == '*') {
				blockRes *= std::atoi(block[j].c_str());
			}
		}
		result += blockRes;
	}

	std::cout << "The actual result of the homework is \e[1m" <<  result << "\e[0m" <<  std::endl;
	file.close();
}
