#include "stdafx.h"
#include "morseMap.h"



morseMap::morseMap()
{
}

void morseMap::buildMap(ifstream& file)
{
	// read lines from text , and add to the map
	
	char ch;
	string str;

	while (file)
	{
		file >> ch >> str;
		ch = tolower(ch);
		codeMap[ch] = str;
	}
	file.close();
	return;
}

string morseMap::encode(string message)
{
	string result;
	cout << "Encoding message: " << message << endl;
	// read the message, compare to the morseMap, add codes and spaces to result
	for (int i=0; i<message.length(); i++)
	{
		char ch = tolower(message[i]);
		if (ch >= 'a' && ch <= 'z')
		{
			cout << ch << " = " << codeMap[ch] << endl;
			result += codeMap[ch] + ' ';
		}
		else if (ch == ' ')
		{
			result += '/';
		} 
		else
		{
			cout <<  "Letter not found in codeMap.";
		}
	}
	cout << "Encoded message: " << result << endl;
	return result;
}


