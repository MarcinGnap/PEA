#include "Menu.h"
#include "BruteForce.h"
#include "timeMeasurement.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main() {
	Menu menu;
	BruteForce BF;
	timeMeasurement tM;
	std::fstream outputFile;
	int iAvgTime = 0;

	outputFile.open("results.csv", std::ios::out);

	outputFile << "Nazwa pliku" << ", ";
	outputFile << "Powtórzenia algorytmu" << ", ";
	outputFile << "Optymalny koszt" << ", ";
	outputFile << "Optymalna œcie¿ka" << ", ";
	outputFile << "Otrzymany koszt" << ", ";
	outputFile << "Œredni czas wykonania [ms]" << "\n";

	cout << "Starting...\n";

	menu.OpenIni();
	cout << menu.sFilename << endl << menu.iRNumber << endl << menu.iOCost << endl;

	outputFile << menu.sFilename << ", ";
	outputFile << menu.iRNumber << ", ";
	outputFile << menu.iOCost << ", ";
	for (int i = 0; i < menu.iOptimalRouteSize; i++) {
		outputFile << menu.iOptimalRoute[i] << " ";
	}
	outputFile << ", ";
	delete[] menu.iOptimalRoute;


	menu.OpenTxt(menu.sFilename);

	cout << "\t Calculating...\n";

	for (int n = 0; n < menu.iRNumber; ++n) {
		auto o1 = chrono::high_resolution_clock::now();
		
		BF.calculate(menu.iVertices, menu.iNOfVertices);
		
		auto o2 = chrono::high_resolution_clock::now();
		tM.tMOutcome(o1, o2);
		iAvgTime = iAvgTime + tM.tMTest(o1, o2);
	}
	iAvgTime = iAvgTime / menu.iRNumber;
	outputFile << BF.iLowestCost << ", ";
	outputFile << iAvgTime << "\n";
	cout << "Sredni czas wykonywania algorytmu: " << iAvgTime << endl;
	cout << "\t Done...\n";

	getchar();
	return 0;
}
