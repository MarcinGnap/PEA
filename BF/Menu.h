#pragma once
#include <string>


class Menu {
public:
	int iRNumber;
	int iOCost;
	int iOptimalRouteSize;
	int *iOptimalRoute;
	std::string sFilename;

	int iNOfVertices;
	int **iVertices;
	int *bestPath;

	Menu();
	~Menu();
	bool OpenIni();
	int OpenTxt(std::string & sFilename);
};