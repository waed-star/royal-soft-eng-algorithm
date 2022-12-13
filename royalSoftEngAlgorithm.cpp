#include "RoyalSoftEngAlgorithm.h"

#include <chrono>
using namespace std::chrono;


//Average case implementation: Time complexity O(n)
 // O(1)
RoyalSoftEngAlgorithm::RoyalSoftEngAlgorithm(std::string _filePath) {
	filePath = _filePath;
}

// O(1)
void RoyalSoftEngAlgorithm::addToSymbolPairs(std::string key, std::string value) {
	symbolPairs.insert(make_pair(key, value));
}

// O(1)
void RoyalSoftEngAlgorithm::addToOppositeSymbolPairs(std::string key, std::string value) {
	oppositeSymbolPairs.insert(make_pair(key, value));
}


void RoyalSoftEngAlgorithm::readFile() {
	try {
		std::fstream readFile;
		readFile.open(filePath);

		std::string currentLine;

		// O(n)
		while(std::getline(readFile, currentLine)) {
			int pos = currentLine.find(',');

			std::string firstSymbol = currentLine.substr(0, pos);
			std::string secondSymbol = currentLine.substr(pos + 1, currentLine.length() - pos);

			addToSymbolPairs(firstSymbol, secondSymbol);
			addToOppositeSymbolPairs(secondSymbol, firstSymbol);
		}
	} catch (std::exception const& e) {
		std::cout << "an error has occurred! " << e.what() << std::endl;
	}
}

void RoyalSoftEngAlgorithm::readFileForWorstCase() {
	try {
		std::fstream readFile;
		readFile.open(filePath);

		std::string currentLine;

		while(std::getline(readFile, currentLine)) {
			int pos = currentLine.find(',');

			std::string firstSymbol = currentLine.substr(0, pos);
			std::string secondSymbol = currentLine.substr(pos + 1, currentLine.length() - pos);

			symbolsPairsForWorstCase.insert( std::pair<std::string, std::string>(firstSymbol, secondSymbol));
			oppositeSymbolsPairsForWorstCase.insert( std::pair<std::string, std::string>(secondSymbol, firstSymbol));
		}
	} catch (std::exception const& e) {
		std::cout << "an error has occurred! " << e.what() << std::endl;
	}
}


void RoyalSoftEngAlgorithm::findMatchingSymbols() {
	std::unordered_map<std::string, std::string>::iterator it = symbolPairs.begin(); // O(1)

	results.push_front(symbolPairs.begin()->first); // O(1)
	results.push_back(symbolPairs.begin()->second); // O(1)

	while(symbolPairs.find(results.back()) != symbolPairs.end() || oppositeSymbolPairs.find(results.front()) != oppositeSymbolPairs.end()) {

		 // O(1)
		if (symbolPairs.find(results.back())  != symbolPairs.end())
			results.push_back(symbolPairs[results.back()]);  // O(1)

		 // O(1)
		if (oppositeSymbolPairs.find(results.front())  != oppositeSymbolPairs.end())
			results.push_front(oppositeSymbolPairs[results.front()]);  // O(1)
	}
}

void RoyalSoftEngAlgorithm::findMatchingSymbolsForWorstCase() {
	std::map<std::string, std::string>::iterator it = symbolsPairsForWorstCase.begin();

	results.push_front(symbolsPairsForWorstCase.begin()->first); // O(1)
	results.push_back(symbolsPairsForWorstCase.begin()->second); // O(1)

	while(symbolsPairsForWorstCase.find(results.back()) != symbolsPairsForWorstCase.end() || oppositeSymbolsPairsForWorstCase.find(results.front()) != oppositeSymbolsPairsForWorstCase.end()) {

		 // O(logn)
		if (symbolsPairsForWorstCase.find(results.back())  != symbolsPairsForWorstCase.end())
			results.push_back(symbolsPairsForWorstCase[results.back()]);  // O(1)

		// O(ogn)
		if (oppositeSymbolsPairsForWorstCase.find(results.front())  != oppositeSymbolsPairsForWorstCase.end())
			results.push_front(oppositeSymbolsPairsForWorstCase[results.front()]);  // O(1)
	}
}

void RoyalSoftEngAlgorithm::printOutResults() {
	std::list<std::string>::iterator it;
	for (it = results.begin(); it != results.end(); ++it)
		std::cout << *it << std::endl;
}


// Recursion implemenation
//void RoyalSoftEngAlgorithm::findMatchingSymbolsOnOneSide() {
//
//	if (symbolPairs.find(results.back())  != symbolPairs.end()) {
//		results.push_back(symbolPairs[results.back()]);
//		RoyalSoftEngAlgorithm::findMatchingSymbolsOnOneSide();
//	}
//
//}
//
//void RoyalSoftEngAlgorithm::findMatchingSymbolsOnOtherSide() {
//	if (oppositeSymbolPairs.find(results.front())  != oppositeSymbolPairs.end()) {
//		results.push_front(oppositeSymbolPairs[results.front()]);  // O(1)
//		RoyalSoftEngAlgorithm::findMatchingSymbolsOnOtherSide();
//	}
//
//}
//
//void RoyalSoftEngAlgorithm::findMatchingSymbols() {
//	std::unordered_map<std::string, std::string>::iterator it = symbolPairs.begin(); // O(1)
//
//	results.push_front(symbolPairs.begin()->first); // O(1)
//	results.push_back(symbolPairs.begin()->second); // O(1)
//
//	RoyalSoftEngAlgorithm::findMatchingSymbolsOnOneSide();
//	RoyalSoftEngAlgorithm::findMatchingSymbolsOnOtherSide();
//}
