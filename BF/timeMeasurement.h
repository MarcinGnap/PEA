#pragma once
#include <chrono>

using namespace std;

class timeMeasurement
{
public:
	void tMOutcome(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2);
	long long tMShort(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2);
	long long tMTest(chrono::high_resolution_clock::time_point o1, chrono::high_resolution_clock::time_point o2);
};