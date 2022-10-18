#include "Menu.h"
#include <fstream>
#include <iostream>

Menu::Menu() {
	iRNumber = 0;
	iOCost = 0;
	sFilename = " ";
}

Menu::~Menu() {
	if (iNOfVertices != 0) {
		for (int i = 0; i < iNOfVertices; i++)
			delete iVertices[i];
		delete[] iVertices;
		iVertices = NULL;
		iNOfVertices = 0;
	}
}

bool Menu::OpenIni() {
	std::ifstream ifFileini("config.ini", std::ios::in);
	if (ifFileini.good())
	{
		std::string sTemp;
		std::getline(ifFileini, sFilename);
		std::getline(ifFileini, sTemp);
		iRNumber = std::stoi(sTemp);
		sTemp = " ";
		std::getline(ifFileini, sTemp);
		iOCost = std::stoi(sTemp);

		ifFileini.close();

		return true;
	}
	return false;
}

int Menu::OpenTxt(std::string & sFilename) {
	std::fstream fFiletxt;
	fFiletxt.open(sFilename, std::ios::in);
	if (!fFiletxt.good())
	{
		this->sFilename = "Brak pliku";
		std::cout << "\nNie mozna wczytac pliku...";
		return 0;
	}

	if (iNOfVertices != 0)
	{
		for (int i = 0; i < iNOfVertices; ++i) {
			delete iVertices[i];
		}
		delete[] iVertices;
		iVertices = NULL;
		iNOfVertices = 0;
	}

	

	this->sFilename = sFilename;
	fFiletxt >> iNOfVertices;
	iVertices = new int *[iNOfVertices];
	int iLine = 0;

	for (int i = 0; i < iNOfVertices; ++i) {
		iVertices[i] = new int[iNOfVertices];
	}

	while (!fFiletxt.eof()) {
		for (int i = 0; i < iNOfVertices; ++i) {
			for (int j = 0; j < iNOfVertices; ++j) {
				fFiletxt >> iVertices[i][j];
			}
			iLine++;
		}
	}
	fFiletxt.close();

	if (iLine != iNOfVertices) {
		std::cout << "\nNiepoprawna ilosc danych...";
		this->sFilename = "Brak pliku";
		for (int i = 0; i < iNOfVertices; ++i) {
			delete iVertices[i];
		}
		delete[] iVertices;
		iVertices = NULL;
		iNOfVertices = 0;
		return 1;
	}
	std::cout << "\nWczytanie pliku przebieglo poprawnie";
	return 0;
}
