/*
* author: Matthias Guzmits
* date: 2017-09-21
* file: file_utility.h
*/

#ifndef FILE_UTILITY_H
#define FILE_UTILITY_H

#include <string>
#include <vector>

class LoadLevel {
public:
	// Constructors
	LoadLevel();
	LoadLevel( std::string filename );

	// read-function for files
	void read_level( std::string filename );

	//getter
	int get_xSize();
	int get_ySize();
	std::vector<std::string> get_levelArray();

private:
	// public variables to save data from lv file
	std::string m_level;
	int m_level_x_size;
	int m_level_y_size;
	std::vector<std::string> m_levelArray;
};

#endif
