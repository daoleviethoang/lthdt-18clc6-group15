#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <io.h>
#include <time.h>
#include <vector>
using namespace std;
class PASSWORD
{
private:
	string User;
	string Pass;
public:
	PASSWORD()
	{
		User = "";
		Pass = "";
	}
	string getUser()
	{
		return User;
	}
	string getPass()
	{
		return Pass;
	}
	void createUser(string a)
	{
		User = a;
	}
	void createPass(string b)
	{
		Pass = b;
	}
};