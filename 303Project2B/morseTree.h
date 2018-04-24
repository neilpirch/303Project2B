#pragma once
#include <map>
#include <fstream>
#include "Binary_Tree.h"
#include "BTNode.h"

using namespace std;

class morseTree : public Binary_Tree<char>
{
protected:
	//declare a root node
	//BTNode<char>* root;

public:
	
	// message decoder function
	string decode(string codedMessage);

	// tree builder
	morseTree buildTree(ifstream &file, morseTree tree);
};

