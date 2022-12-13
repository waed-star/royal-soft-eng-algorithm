#include "RoyalSoftEngAlgorithm.h"

#include <chrono>
using namespace std::chrono;

#include <map>
#include <utility>
#include <list>

int main(int argc, char* argv[]) {
	auto start = high_resolution_clock::now();

	RoyalSoftEngAlgorithm symbols = RoyalSoftEngAlgorithm(argv[1]);
	symbols.readFile();
	symbols.findMatchingSymbols();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	symbols.printOutResults();

	std::cout << "duration: " << duration.count() << std::endl;

	/*
	 * Please comment the above code before testing for worst case scenario
	 * This is because they both use the results std::list structure to
	 * save results
	 */
//	auto start = high_resolution_clock::now();
//
//	RoyalSoftEngAlgorithm symbols = RoyalSoftEngAlgorithm(argv[1]);
//	symbols.readFileForWorstCase();
//	symbols.findMatchingSymbolsForWorstCase();
//	auto stop = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>(stop - start);
//
//	symbols.printOutResults();
//
//	std::cout << "duration: " << duration.count() << std::endl;

	return 0;
}
