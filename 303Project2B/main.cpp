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
	ifstream treeData("morsetree.txt");

	myMap.buildMap(data);

	myTree = myTree.read_binary_tree(treeData);

	myTree.decode("-.. --."); 
	myTree.decode("... --- ..."); 
	myMap.encode("Hello World");


	system("pause");
	return 0;
}
