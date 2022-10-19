#pragma once

class BruteForce
{
public:
	int iLowestCost;

	BruteForce();
	~BruteForce();

	int calculate(int **iVertices, int iNOfVertices);
};