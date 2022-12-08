#include "RoyalSoftEngAlgorithm.h"

#include <chrono>
using namespace std::chrono;

int main(int argc, char* argv[]) {
	auto start = high_resolution_clock::now();

	RoyalSoftEngAlgorithm symbols = RoyalSoftEngAlgorithm(argv[1]);
	symbols.readFile();
	symbols.findMatchingSymbols();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	symbols.printOutResults();


	std::cout << "duration: " << duration.count() << std::endl;

	return 0;
}

// Draft code

//argv[0] is the argument to start the program

//	std::string filepath = argv[1];
//
//	std::fstream readFile;
//	readFile.open(filepath);
//
//	std::string currentLine;
//
//	std::unordered_map<std::string, std::string> symbolPairs;
//	std::unordered_map<std::string, std::string> oppositeSymbolPairs;
//	list<string> results;
//
//	while(std::getline(readFile, currentLine)) {
//		int pos = currentLine.find(',');
//
//		std::string firstSymbol = currentLine.substr(0, pos);
//		std::string secondSymbol = currentLine.substr(pos + 1, currentLine.length() - pos);
//
//		symbolPairs.insert(make_pair(firstSymbol, secondSymbol));
//		oppositeSymbolPairs.insert(make_pair(secondSymbol, firstSymbol));
//	}
//
//	std::unordered_map<std::string, string>::iterator it = symbolPairs.begin();
////	while(it != symbolPairs.end()) {
////		std::cout<< it->first << " :: "<< it->second <<std::endl;
////		it++;
////	}
//
//	results.push_front(symbolPairs.begin()->first);
//	results.push_back(symbolPairs.begin()->second);
//	while(symbolPairs.find(results.back())  != symbolPairs.end() || oppositeSymbolPairs.find(results.front())  != oppositeSymbolPairs.end()) {
////		cout << symbolPairs[results.back()] << endl;
//		if (symbolPairs.find(results.back())  != symbolPairs.end())
//			results.push_back(symbolPairs[results.back()]);
//
//		if (oppositeSymbolPairs.find(results.front())  != oppositeSymbolPairs.end())
//			results.push_front(oppositeSymbolPairs[results.front()]);
//	}
//
////	results.push_front(symbolPairs.begin()->first);
////	while(oppositeSymbolPairs.find(results.front())  != oppositeSymbolPairs.end()) {
//////		cout << oppositeSymbolPairs[results.front()] << endl;
////
////		results.push_front(oppositeSymbolPairs[results.front()]);
////	}
////
////	std::cout << "-------------------------------------------" << std::endl;
////
////	std::unordered_map<std::string, string>::iterator itTwo = oppositeSymbolPairs.begin();
////	while(itTwo != oppositeSymbolPairs.end()) {
////		std::cout<< itTwo->first << " :: "<< itTwo->second <<std::endl;
////
////		itTwo++;
////	}
////	results.push_back(symbolPairs.begin()->first);
////	results.push_back(symbolPairs.begin()->second);
//
////	std::unordered_map<std::string, string>::iterator it = symbolPairs.begin();
////	while(it != symbolPairs.end())
////	{
////		results.push_back(it->first);
////		results.push_back(it->second);
////
////		try {
////
////			results.push_back(oppositeSymbolPairs.at(it->second));
////
////
////		} catch(const out_of_range &e)
////	    {
////	        cerr << "EoppositeSymbolPairsception at " << e.what() << endl;
////	    }
////
//////		std::cout<< oppositeSymbolPairs.at(it->first) << std::endl;
////
//////		results.push_back(oppositeSymbolPairs.at(it->first));
////
//////	    std::cout<< it->first << " :: "<< it->second <<std::endl;
////	    it++;
////	}
//
//
//	list<string>::iterator itForList;
//	for (itForList = results.begin(); itForList != results.end(); ++itForList)
//		cout << *itForList << std::endl;
//	cout << '\n';
