#include "stdafx.h"
#include "morseTree.h"






string morseTree::decode(string codedMessage)
{
	string result;
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
	return result;
}

morseTree morseTree::buildTree(ifstream& file, morseTree tree)
{
	char letter = '0';
	string code;

	//morseTree myTree(const char& letter);

	BTNode<char>**bnode;

	while (file)
	{
		file >> letter >> code;

		bnode = &tree.root;

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
	file.close();
	return tree;
}
