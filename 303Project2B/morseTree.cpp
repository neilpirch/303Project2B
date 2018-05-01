#include "stdafx.h"
#include "morseTree.h"






string morseTree::decode(string codedMessage)
{
	string result;
	cout << "Decoding message: " << codedMessage << endl;

	BTNode<char>* currentNode = root;

	for (int i = 0; i < codedMessage.length(); i++)
	{
		if (codedMessage[i] == '.')
		{
			currentNode = currentNode->left;
			
			if (currentNode == NULL)
			{
				return "Invalid Code";
			}
		}
		else if (codedMessage[i] == '-')
		{
			currentNode = currentNode->right;

			if (currentNode == NULL)
			{
				return "Invalid Code";
			}
		}
		else
		{
			char ch = currentNode->data;

			result += ch;

			currentNode = root;
		}
	}
	char ch = currentNode->data;
	result += ch;

	cout << "Decoded message: " << result << endl << endl;

	return result;
}

morseTree morseTree::read_binary_tree(istream& file)
{
	char letter;
	string code;

	morseTree myTree(0);

	BTNode<char>**bnode;

	while (file)
	{
		file >> letter >> code;

		bnode = &myTree.root;

		for (int i = 0; i < code.length(); i++)
		{
			if (code[i] == '.')
			{
				bnode = &(*bnode)->left;
			}
			else
			{
				bnode = &(*bnode)->right;
			}

		}
		*bnode = new BTNode<char>(letter);

	}
	return myTree;
}
