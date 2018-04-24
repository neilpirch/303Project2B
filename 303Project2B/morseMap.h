#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class morseMap
{
public:
	//default constructor
	morseMap();
	
	//Read the text file and populate the map
	void buildMap(ifstream& file);
	
	// read a message consisting of letters, compare to the map, build a string of morse code
	string encode(string message);

	// create a map to add letters and codes to
	map <char, string> codeMap;
};

