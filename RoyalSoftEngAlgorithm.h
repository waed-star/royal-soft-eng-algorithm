#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <string>
#include <list>
#include <utility>

class RoyalSoftEngAlgorithm {
	private:
		std::string filePath;
		std::unordered_map<std::string, std::string> symbolPairs;
		std::unordered_map<std::string, std::string> oppositeSymbolPairs;
		std::map<std::string, std::string> symbolsPairsForWorstCase;
		std::map<std::string, std::string> oppositeSymbolsPairsForWorstCase;
		void addToSymbolPairs(std::string, std::string);
		void addToOppositeSymbolPairs(std::string, std::string);
//		void findMatchingSymbolsOnOneSide(); // Recursion
//		void findMatchingSymbolsOnOtherSide(); // Recursion

	public:
		std::list<std::string> results;
		RoyalSoftEngAlgorithm(std::string filePath);
		void readFile();
		void readFileForWorstCase();
		void findMatchingSymbols();
		void findMatchingSymbolsForWorstCase();
		void printOutResults();
};


