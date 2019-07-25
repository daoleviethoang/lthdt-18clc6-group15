#ifndef _DELETESPACE_H_
#define _DELETESPACE_H_

#include <iostream>
using namespace std;

string DeleteSpace(string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == '\t') {
			str[i] = ' ';
		}
	}
	while (str[str.length() - 1] == ' ') {
		str.erase(str.length() - 1, 1);
	}
	while (str[0] == ' ')
		str.erase(0, 1);
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
		{
			str.erase(i, 1);
		}
	}
	return str;
}



#endif