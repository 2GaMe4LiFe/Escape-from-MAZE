/*
* author: Matthias Guzmits
* date: 2017-09-21
* file: file_utility.cpp
*/

#include <fstream>
#include <string>
#include <vector>
#include "file_utility.h"

LoadLevel::LoadLevel() {

}

LoadLevel::LoadLevel( std::string filename ) {
	read_level( filename );
}

int LoadLevel::get_xSize() {
	return m_level_x_size;
}

int LoadLevel::get_ySize() {
	return m_level_y_size;
}

std::vector<std::string> LoadLevel::get_levelArray() {
	return m_levelArray;
}

void LoadLevel::read_level( std::string filename ) {
	std::ifstream mylevel;
	std::string line;
	std::string level = "";
	int cnt = 0;
	int normSize;

	mylevel.open( filename.c_str() );

	if( !mylevel.good() ) {
		perror( filename.c_str() );
	}

	while( std::getline( mylevel, line) ) {
		if ( cnt == 0 )
			normSize = line.length();
		if ( line.length() != normSize )
			throw std::logic_error( "ERROR: Lines have not the same length" );
		if ( line[0] != '#' ) {
			throw std::logic_error( "ERROR: Begin of pattern is not valid" );
		}
		if ( line[normSize-1] != '#' )
			throw std::logic_error( "ERROR: End of pattern is not valid" );
		level += line + "\n";
		cnt++;
	}

	line = "";
	int i = 0;
	while( level[i] != '\0' ) {
		if( level[i] != '\n' ) {
			line += level[i];
		}
		else {
			m_levelArray.push_back( line + "\n" );
			line = "";
		}
		i++;
	}

	mylevel.close();
	m_level = level;
	m_level_x_size = level.length() / cnt;
	m_level_y_size = cnt;
}
