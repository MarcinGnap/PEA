#include "timeMeasurement.h"

#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

void timeMeasurement::tMOutcome(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2)
{
	chrono::milliseconds time_span = chrono::duration_cast<chrono::milliseconds> (o2 - o1);
	cout << "\nWykonanie operacji zajelo " << time_span.count() << " milisekund." << endl;
}

long long timeMeasurement::tMShort(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2)
{
	chrono::milliseconds time_span = chrono::duration_cast<chrono::milliseconds> (o2 - o1);
	cout << "* " << time_span.count() << " milisekund" << endl;

	return time_span.count();
}

long long timeMeasurement::tMTest(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2)
{
	chrono::milliseconds time_span = chrono::duration_cast<chrono::milliseconds> (o2 - o1);

	return time_span.count();
}