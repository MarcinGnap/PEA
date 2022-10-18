#include "Menu.h"
#include <iostream>

int main() {
	Menu menu;

	std::cout << "Starting...\n";

	menu.OpenIni();
	std::cout << menu.sFilename << std::endl << menu.iRNumber << std::endl << menu.iOCost << std::endl;

	menu.OpenTxt(menu.sFilename);

	//while (menu.iNOfVertices != 0) {
	//	std::cout << "pentla";
	//}

	getchar();
	return 0;
}
