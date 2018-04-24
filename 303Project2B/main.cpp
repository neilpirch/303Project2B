// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "morseTree.h"
#include "morseMap.h"
#include <map>
#include <iostream>

using namespace std;



int main()
{
	morseTree myTree;
	morseMap myMap;
	ifstream data("morse.txt");

	myMap.buildMap(data);

	//need to get this function and its parameters figured out
	myTree.buildTree(data, myTree);

	//myTree.decode("-.. --."); //need to get pointers and references worked out this should return "ac"
	myMap.encode("Hello World");  


	system("pause");
	return 0;
}
