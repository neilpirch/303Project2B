#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include "BTNode.h"

using namespace std;

class morseTree 
{
protected:
	//declare a root node
	BTNode<char>* root;

public:
	// default constructor
	morseTree() :root(NULL) {}

	// parameterized constructor
	morseTree(const char &ch):root(new BTNode<char>(ch)){}

	// message decoder function
	string decode(string codedMessage);

	// tree builder
	morseTree read_binary_tree(istream& in);
	//Binary_Tree<Item_Type> read_binary_tree(std::vector<std::string>& text, int& i);

};

