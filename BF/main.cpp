#include "Menu.h"
#include "BruteForce.h"
#include "timeMeasurement.h"
#include <iostream>
#include <chrono>

using namespace std;

int main() {
	Menu menu;
	BruteForce BF;
	timeMeasurement tM;

	std::cout << "Starting...\n";

	menu.OpenIni();
	std::cout << menu.sFilename << std::endl << menu.iRNumber << std::endl << menu.iOCost << std::endl;

	menu.OpenTxt(menu.sFilename);

	std::cout << "\t Calculating...\n";

	for (int n = 0; n < menu.iRNumber; ++n) {
		auto o1 = chrono::high_resolution_clock::now();
		
		BF.calculate(menu.iVertices, menu.iNOfVertices);
		
		auto o2 = chrono::high_resolution_clock::now();
		tM.tMOutcome(o1, o2);
	}
	std::cout << "\t Done...\n";

	getchar();
	return 0;
}
