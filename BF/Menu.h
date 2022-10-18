#pragma once
#include <string>


class Menu {
public:
	int iRNumber;
	int iOCost;
	std::string sFilename;

	int iNOfVertices;
	int **iVertices;

	Menu();
	~Menu();
	bool OpenIni();
	int OpenTxt(std::string & sFilename);

};

