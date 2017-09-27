/*
* author: Matthias Guzmits
* date: 2017-09-21
* file: controls.cpp
*/

#include <vector>
#include <string>
#include <iostream>
#include "controls.h"

Controls::Controls() {

}

Controls::Controls(std::vector<std::string> levelArray) {
	m_levelArray = levelArray;
}

void Controls::setLevel(std::vector<std::string> levelArray) {
	m_levelArray = levelArray;
}

void Controls::set_playerChar(char pChar) {
	m_pChar = pChar;
}

void Controls::set_gateChar(char gChar) {
	m_gChar = gChar;
}

std::pair<int, int> Controls::get_gatePos() {
	return m_gatePos;
}

std::pair<int, int> Controls::get_playerPos() {
	return m_playerPos;
}

void Controls::checkPosition() {
	for( int i = 0; i < m_levelArray.size(); i++ ) {
		for( int j = 0; j < m_levelArray[i].length(); j++) {
			if( m_levelArray[i][j] == m_pChar ) {
				m_playerPos = std::make_pair(i, j);
			} else if( m_levelArray[i][j] == m_gChar ) {
				m_gatePos = std::make_pair(i, j);
			}
		}
	}
}

bool Controls::doCollision(char key) {
	int x = m_playerPos.second;
	int y = m_playerPos.first;
	if( key == 'w' || key == 'W' ) {
		if( m_levelArray[y - 1][x] != '#' &&
			m_levelArray[y - 1][x] != '\0' ) {

			m_levelArray[y - 1][x] = 'P';
			m_levelArray[y][x] = ' ';
			m_playerPos = std::make_pair(--y, x);
		}
	} else if( key == 's' || key == 'S' ) {
		if( m_levelArray[y + 1][x] != '#' &&
			m_levelArray[y + 1][x] != '\0' ) {

			m_levelArray[y + 1][x] = 'P';
			m_levelArray[y][x] = ' ';
			m_playerPos = std::make_pair(++y, x);
		}
	} else if( key == 'a' || key == 'A' ) {
		if( m_levelArray[y][x - 1] != '#' &&
			m_levelArray[y][x - 1] != '\0' ) {

			m_levelArray[y][x - 1] = 'P';
			m_levelArray[y][x] = ' ';
			m_playerPos = std::make_pair(y, --x);
		}
	} else if( key == 'd' || key == 'D' ) {
		if( m_levelArray[y][x + 1] != '#' &&
			m_levelArray[y][x + 1] != '\0' ) {

			m_levelArray[y][x + 1] = 'P';
			m_levelArray[y][x] = ' ';
			m_playerPos = std::make_pair(y, ++x);
		}
	}
	if( m_playerPos.first == m_gatePos.first &&
		m_playerPos.second == m_gatePos.second ) {
		return false;
	} else {
		return true;
	}
}

void Controls::redraw() {
	for( int i = 0; i < m_levelArray.size(); i++ ) {
		std::cout << m_levelArray[i];
	}
}
