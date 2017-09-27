/*
* author: Matthias Guzmits
* date: 2017-09-21
* file: controls.h
*/

#ifndef CONTROLS_H
#define CONTROLS_H

#include <vector>
#include <string>

class Controls {
public:
	Controls();
	Controls(std::vector<std::string> levelArray);

	// setter
	void setLevel(std::vector<std::string> levelArray);
	void set_playerChar(char pChar);
	void set_gateChar(char gChar);

	//getter
	std::pair<int, int> get_gatePos();
	std::pair<int, int> get_playerPos();

	// gamelogic
	void checkPosition();
	bool doCollision(char key);

	void redraw();
private:
	std::vector<std::string> m_levelArray;
	char m_pChar;
	char m_gChar;
	std::pair<int, int> m_playerPos;
	std::pair<int, int> m_gatePos;
};

#endif
