#include "BruteForce.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

BruteForce::BruteForce()
{

}

BruteForce::~BruteForce()
{

}

int BruteForce::calculate(int ** iVertices, int iNOfVertices)
{
	int iTemp = 0;
	std::vector<int> vTowns;

	for (int i = 0; i < iNOfVertices; ++i) {
		if (i < iNOfVertices) {
			vTowns.push_back(i);
		}
	}

	iLowestCost = INT_MAX;
	do {
		int iCurrentWeigh = 0;
		int iTempVertex = iTemp;

		for (int j = 0; j < vTowns.size(); ++j) {
			iCurrentWeigh += iVertices[iTempVertex][vTowns[j]];
			iTempVertex = vTowns[j];
		}
		iCurrentWeigh += iVertices[iTempVertex][iTemp];

		if (iCurrentWeigh < iLowestCost)
		{
			iLowestCost = std::min(iLowestCost, iCurrentWeigh);
		}
	} while (next_permutation(vTowns.begin(), vTowns.end()));

	vTowns.clear();
	std::cout << "\n Min cost: " << iLowestCost << std::endl;

	return 0;
}