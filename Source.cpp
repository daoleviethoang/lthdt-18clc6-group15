#include <fstream>
#include "Employee.h"
using namespace std;
bool loadEmloyee(const char *path, string b)
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	Employee e;
	getline(fin, b, '\n');
	while (fin >> e.getNo())
	{
		fin.get();
		fin.getline(e.getLastn(), 101, ',');
		fin.getline(e.getN(), 101, ',');
		fin.getline(e.lastn, 101, ',');
		fin.getline(e.n, 10, ',');
		fin.getline(e.dob.getDay(), 5, '/');
		fin.getline(e.dob.getMonth(), 5, '/');
		fin.getline(e.dob.getYear(), 5, ',');
		fin.getline(e.gender, 5, ',');
		nodest *p = createNode(st);
		insertTail(l, p);
	}
	fin.close();
	return true;
}