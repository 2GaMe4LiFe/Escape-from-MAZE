/*
* author: Matthias Guzmits
* date: 2017-09-21
* file: main.cpp
*/

#include <iostream>
#include <string>
#include "file_utility.h"
#include "controls.h"
#include "getch.h"

int main() {
	LoadLevel level1 = LoadLevel( "level1.lv" );
	
	Controls controller1 = Controls( (level1.get_levelArray()) );
	controller1.set_playerChar('P');
	controller1.set_gateChar('G');
	controller1.checkPosition();

	char inp;
	bool run = true;

	while( run ) {
		std::cout << "\033[2J\033[1;1H";
		controller1.redraw();
		inp = getch();
		run = controller1.doCollision(inp);
		if( run == false ) {
			std::cout << "\033[2J\033[1;1H";
			controller1.redraw();
		}
		if( inp == 'q')
			break;
	}

	//std::cout << controller1.get_gatePos().first << std::endl;
	return 0;
}
