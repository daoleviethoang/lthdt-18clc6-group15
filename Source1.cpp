#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <io.h>
#include <time.h>
//#include "sha256.h"
using namespace std;
struct date {
	char day[100];
	char month[100];
	char year[100];
};
struct student {
	int no;
	char id[100];
	char lastname[100];
	char firstname[100];
	char sex[100];
	date birth;
};
struct timef {
	int hour;
	int minute;
};
struct date1 {
	int day;
	int month;
	int year;
};
struct lecturer
{
	char name[50];
	char user[20];
	char pass[100];
	char mail[50];
};
struct nodelt
{
	lecturer data;
	nodelt *next;
};
struct listlt
{

	nodelt *head;
	nodelt *tail;
};
struct nodest
{
	student data;
	nodest *next;
};
struct liststcr
{
	nodest *head;
	nodest *tail;
};
struct course
{
	int no;
	char id[100];
	char name[100];
	char classn[100];
	char lecture[100];
	date1 start;
	date1 end;
	char day[100];
	timef start1;
	timef end1;
	char room[100];
	//listst *lstcr;
};
struct password
{
	int no;
	char id[100];
	char user[100];
	char pass[100];
};
struct nodepw
{
	password data;
	nodepw *next;
};
struct listpw
{
	nodepw *head;
	nodepw *tail;
};
struct listst
{
	nodest *head;
	nodest *tail;
};
struct nodecr
{
	course data;
	nodecr *next;
};
struct att {
	char id[100];
	int w1;
	int w2;
	int w3;
	int w4;
	int w5;
	int w6;
	int w7;
	int w8;
	int w9;
	int w10;
	int w11;
};
struct att1 {
	char id[100];
	int w1;
	int w2;
	int w3;
	int w4;
	int w5;
	int w6;
	int w7;
	int w8;
	int w9;
	int w10;
};
struct score
{
	int ID;
	int midterm;
	int final;
	int lab;
	int bonus;
};
struct nodesb
{
	score data;
	nodesb *next;
};
struct listsb
{
	nodesb *head;
	nodesb *tail;
};
nodesb *createNode(score x)
{
	nodesb *p = new nodesb;
	p->next = NULL;
	p->data = x;
	return p;
}
struct nodeat
{
	att data;
	nodeat*next;
};
struct listat
{
	nodeat *head;
	nodeat *tail;
};
nodeat*createnodeat(att x)
{
	nodeat *p = new nodeat;
	p->next = NULL;
	p->data = x;
	return p;
}
struct nodeat1
{
	att1 data;
	nodeat1*next;
};
struct listat1
{
	nodeat1 *head;
	nodeat1 *tail;
};
nodeat1*createnodeat(att1 x)
{
	nodeat1 *p = new nodeat1;
	p->next = NULL;
	p->data = x;
	return p;
}
struct listcr
{
	nodecr *head;
	nodecr *tail;
};
struct nameall
{
	char name[100];
};
struct savenameall
{
	char savename[100];
};
struct nodeallstsave
{
	savenameall data;
	nodeallstsave *next;
};
struct nodeallst
{
	nameall data;
	nodeallst *next;
};
struct listallst
{
	nodeallst *head;
	nodeallst *tail;
};
struct listallstsave
{
	nodeallstsave *head;
	nodeallstsave *tail;
};
void init(listallst &l)
{
	l.head = l.tail = NULL;
}
void init(listpw &l)
{
	l.head = l.tail = NULL;
}
void init(listst &l)
{
	l.head = l.tail = NULL;
}
void init(listcr &l)
{
	l.head = l.tail = NULL;
}
void init(listallstsave &l)
{
	l.head = l.tail = NULL;
}
void init(listlt &l)
{
	l.head = l.tail = NULL;
}
void init(listsb &l)
{
	l.head = l.tail = NULL;
}
nodelt * createNode(lecturer x)
{
	nodelt *p = new nodelt;
	p->next = NULL;
	p->data = x;
	return p;
}
nodeallst *createNode(nameall x)
{
	nodeallst *p = new nodeallst;
	p->next = NULL;
	p->data = x;
	return p;
}
nodeallstsave *createNode(savenameall x)
{
	nodeallstsave *p = new nodeallstsave;
	p->next = NULL;
	p->data = x;
	return p;
}
nodepw *createNode(password x)
{
	nodepw *p = new nodepw;
	p->next = NULL;
	p->data = x;
	return p;
}
nodest *createNode(student x)
{
	nodest *p = new nodest;
	p->next = NULL;
	p->data = x;
	return p;
}
nodecr *createNode(course x)
{
	nodecr *p = new nodecr;
	p->next = NULL;
	p->data = x;
	return p;
}
void insertTail(listsb &l, nodesb *p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void insertTail(listlt &l, nodelt *p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void insertTail(listallst &l, nodeallst *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void insertTail(listallstsave &l, nodeallstsave *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void insertTail(listst &lst, nodest *p)
{
	if (lst.head == NULL)
	{
		lst.head = lst.tail = p;
	}
	else
	{
		lst.tail->next = p;
		lst.tail = p;
	}
}
void insertTail(listcr &l, nodecr *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void insertTail(liststcr &l, nodest *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
int login(char y[]);
void outputClass(listallst &last);
void menu();/////////////////////
void coursemenu();
void staffmenu();

void insertTail(listpw &l, nodepw *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
bool loadPassword(const char *path, listpw &l, char b[])
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	init(l);
	password pw;
	fin.getline(b, 200, '\n');
	while (fin >> pw.no)
	{
		fin.get();
		fin.getline(pw.id, 15, ',');
		fin.getline(pw.user, 15, ',');
		fin.getline(pw.pass, 100, '\n');
		nodepw *p = createNode(pw);
		insertTail(l, p);
	}
	fin.close();
	return true;
}
bool saveTeacher(const char*file, listlt &llt)
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << "Name, User, Password, Email" << endl;
	for (nodelt*p = llt.head; p != NULL; p = p->next)
	{
		lecturer lt = p->data;
		if (lt.user < 0) break;
		fout << lt.name << "," << lt.user << "," << lt.pass << "," << lt.mail << endl;
	}
	fout.close();
	return true;
}
bool savePassword(const char *path, listpw &l)
{
	ofstream fout;
	fout.open(path);
	if (fout.fail())
		return false;
	fout << "no, id, user, pass" << endl;
	for (nodepw *p = l.head; p != NULL; p = p->next)
	{
		password pw = p->data;
		if (pw.no < 0) break;
		fout << pw.no << "," << pw.id << "," << pw.user << "," << pw.pass << endl;
	}
	fout.close();
	return true;
}
bool loadAllStudent(listallst &last)
{
	ifstream fin;
	fin.open("AllStudents.csv");
	if (fin.fail())
		return false;
	nameall nall;
	init(last);
	while (fin.getline(nall.name, 30, '\n'))
	{
		nodeallst *p = createNode(nall);
		insertTail(last, p);
	}
	fin.close();
	return true;
}
bool loadAllStudentSave(listallstsave &lasts)
{
	ifstream fin;
	fin.open("SaveAllStudent.csv");
	if (fin.fail())
		return false;
	savenameall sna;
	init(lasts);
	while (fin.getline(sna.savename, 30, '\n'))
	{
		nodeallstsave *p = createNode(sna);
		insertTail(lasts, p);
	}
	fin.close();
	return true;
}
bool loadStudent(nodeallst*t, listst &lst)
{
	ifstream fin;
	fin.open(t->data.name);
	if (fin.fail())
		return false;
	char b[100];
	init(lst);
	student st;
	fin.getline(b, 50, '\n');
	while (fin >> st.no)
	{
		fin.get();
		fin.getline(st.id, 9, ',');
		fin.getline(st.lastname, 101, ',');
		fin.getline(st.firstname, 101, ',');
		fin.getline(st.sex, 10, ',');
		fin.getline(st.birth.month, 5, '/');
		fin.getline(st.birth.day, 5, '/');
		fin.getline(st.birth.year, 5, '\n');
		nodest *p = createNode(st);
		insertTail(lst, p);
	}
	fin.close();
	return true;
}
bool saveStudent(nodeallstsave *t, listst &lst)
{
	ofstream fout;
	fout.open(t->data.savename);
	if (fout.fail())
		return false;
	fout << "No,Student ID,Lastname,Firstname,Gender,DoB" << endl;
	for (nodest *p = lst.head; p != NULL; p = p->next)
	{
		student st = p->data;
		if (st.no < 0) break;
		fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
	}
	fout.close();
	return true;
}
bool loadall(listst*&lst, listallst &last, listallstsave &lasts)
{
	loadAllStudent(last);
	ifstream fin;
	fin.open("SaveAllStudent.csv");
	if (!fin.is_open() && loadAllStudent(last) == false)
		return false;
	char load[300];
	char save[100];
	nameall x;
	int i = 0;
	loadAllStudentSave(lasts);
	nodeallstsave *t = lasts.head;
	for (nodeallst *p = last.head; p != NULL; p = p->next)
	{
		loadStudent(p, lst[i]);
		saveStudent(t, lst[i]);
		t = t->next;
		i++;
	}
	fin.close();
	return true;
}
bool saveStudentAll(listallst &last)
{
	ofstream fout;
	fout.open("AllStudents.csv");
	if (fout.fail())
		return false;
	for (nodeallst *p = last.head; p != NULL; p = p->next)
	{
		fout << p->data.name << endl;
	}
	fout.close();
	return true;
}
bool saveSaveStudentAll(listallstsave &lasts)
{
	ofstream fout;
	fout.open("SaveAllStudent.csv");
	if (fout.fail())
		return false;
	for (nodeallstsave *p = lasts.head; p != NULL; p = p->next)
	{
		fout << p->data.savename << endl;
	}
	fout.close();
	return true;
}
bool loadCourse(const char *path, listcr &lcr, char b[])
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	course cr;
	fin.getline(b, 200, '\n');
	lcr.head = lcr.tail = NULL;
	while (fin >> cr.no)
	{
		fin.get();
		fin.getline(cr.id, 10, ',');
		fin.getline(cr.name, 100, ',');
		fin.getline(cr.classn, 7, ',');
		fin.getline(cr.lecture, 100, ',');
		fin >> cr.start.day;
		fin.ignore();
		fin >> cr.start.month;
		fin.ignore();
		fin >> cr.start.year;
		fin.ignore();
		fin >> cr.end.day;
		fin.ignore();
		fin >> cr.end.month;
		fin.ignore();
		fin >> cr.end.year;
		fin.ignore();
		fin.getline(cr.day, 100, ',');
		fin >> cr.start1.hour;
		fin.ignore();
		fin >> cr.start1.minute;
		fin.ignore();
		fin >> cr.end1.hour;
		fin.ignore();
		fin >> cr.end1.minute;
		fin.ignore();
		fin.getline(cr.room, 10, '\n');
		nodecr *p = createNode(cr);
		insertTail(lcr, p);
	}
	fin.close();
	return true;
}

bool saveCourse(const char *path, listcr &l, char b[])
{
	ofstream fout;
	fout.open(path);

	if (fout.fail())
		return false;

	int i = 0;
	fout << b << endl;
	for (nodecr *p = l.head; p != NULL; p = p->next)
	{
		course cr = p->data;
		if (cr.no < 0) break;
		fout << cr.no << "," << cr.id << "," << cr.name << "," << cr.classn << "," << cr.lecture << "," << cr.start.day << "/" << cr.start.month << "/" << cr.start.year << ',' << cr.end.day << "/" << cr.end.month << "/" << cr.end.year << ',' << cr.day << ',' << cr.start1.hour << ':' << cr.start1.minute << ',' << cr.end1.hour << ':' << cr.end1.minute << ',' << cr.room << endl;
	}
	fout.close();
	return true;
}
void addnewstudent(listst &lst, int i)
{
	listpw lpw;
	char tt[200];
	loadPassword("Password.csv", lpw, tt);
	student st;
	cout << "Add new student to a class" << endl;
	st.no = lst.tail->data.no + 1;
	cout << "Enter ID: ";
	cin >> st.id;
	cin.get();
	cout << "Enter Lastname: ";
	cin.getline(st.lastname, '/n');
	cout << "Enter Firstname: ";
	cin >> st.firstname;
	do
	{
		cout << "Enter gender(Male/Female): ";
		cin >> st.sex;
	} while ((strcmp(st.sex, "Male") != 0 && strcmp(st.sex, "Female") != 0) && cout << "You can only enter Male/Female");
	cout << "Enter day of DOB: ";
	cin >> st.birth.day;
	cout << "Enter month of DOB: ";
	cin >> st.birth.month;
	cout << "Enter year of DOB: ";
	cin >> st.birth.year;
	nodest*p = createNode(st);
	insertTail(lst, p);

	password pa;
	pa.no = st.no;
	strcpy(pa.id, st.id);
	strcpy(pa.user, st.id);
	strcpy(pa.pass, st.birth.day);
	strcat(pa.pass, st.birth.month);
	strcat(pa.pass, st.birth.year);
	nodepw*pw = createNode(pa);
	insertTail(lpw, pw);
	savePassword("Password.csv", lpw);
}
void importClass(listallst &last, listst &lst, listallstsave &lasts)
{
	listpw lpw;
	char tt[200];
	loadPassword("Password.csv", lpw, tt);
	nameall a;
	savenameall b;
	char c[100];
	cout << "Enter name import class (Ex: 18CLC1Student.csv): ";
	cin >> a.name;
	cout << "Enter name save import class (Ex: 18CLC1Student.csv): ";
	cin >> b.savename;
	int check = 0;
	for (nodeallst *m = last.head; m != NULL; m = m->next)
	{

		if (strcmp(m->data.name, a.name) == 0)
		{
			check = 1;
			break;
		}
	}
	if (check == 1)
	{
		cout << "Class already exists, do you want to add another class? (yes/no): ";
		cin >> c;
		if (strcmp("yes", c) == 0)
			importClass(last, lst, lasts);
		else return;
	}
	else
	{
		nodeallst *p = createNode(a);
		insertTail(last, p);
		saveStudentAll(last);
		nodeallstsave *t = createNode(b);
		insertTail(lasts, t);
		saveSaveStudentAll(lasts);
		int h = loadStudent(last.tail, lst);
		int k = saveStudent(lasts.tail, lst);
		for (nodest *z = lst.head; z != NULL; z = z->next)
		{
			password pa;
			pa.no = z->data.no;
			strcpy(pa.id, z->data.id);
			strcpy(pa.user, z->data.id);
			strcpy(pa.pass, z->data.birth.day);
			strcat(pa.pass, z->data.birth.month);
			strcat(pa.pass, z->data.birth.year);
			nodepw*pw = createNode(pa);
			insertTail(lpw, pw);
		}
		savePassword("Password.csv", lpw);
		if (h == true && k == true)
		{
			cout << "Import new class successfull !!!" << endl;
		}
		else cout << "Import new class not successfull !!!" << endl;
		char d[100];
		cout << "Do you want to import more ??? (yes/no): ";
		cin >> d;
		if (strcmp("yes", d) == 0)
			importClass(last, lst, lasts);
		else return;
	}
}
void inputpassword(char password[])
{
	int i = 0;
	for (char c; (c = _getch());)
	{
		if (c == '\n' || c == '\r')
		{
			cout << "\n";
			break;
		}
		else if (c == '\b')
		{
			cout << "\b \b";
			if (i != 0)
				password[i - 1] = NULL;
			i++;
		}
		else if (c == -32)
		{
			_getch();
		}
		else if (isprint(c))
		{
			cout << '*';
			password[i++] = c;
		}
	}
	password[i] = NULL;
}
bool editstudent(listst &lst, char ID[])
{
	int check;
	char temp[100];
	nodest* head = lst.head;
	nodest*current = head;
	while (current != lst.tail)
	{
		if (strcmp(current->data.id, ID) == 0)
		{
			do
			{
				cout << "Please input the one you want to edit: " << endl;
				cout << "1. Edit Student ID" << endl;
				cout << "2. Edit Lastname" << endl;
				cout << "3. Edit Firstname" << endl;
				cout << "4. Edit Gender" << endl;
				cout << "5. Edit D.O.B" << endl;
				cout << "6. Done" << endl;
				cin >> check;
				switch (check)
				{
				case 1:
				{
					cout << "Input new Student ID: ";
					cin >> temp;
					strcpy(current->data.id, temp);
					cout << "DONE" << endl;
					break;
				}
				case 2:
				{
					cin.get();
					cout << "Enter new Lastname: ";
					cin.getline(temp, '/n');
					strcpy(current->data.lastname, temp);
					cout << "DONE" << endl;
					break;
				}
				case 3:
				{
					cout << "Enter new Firstname: ";
					cin >> temp;
					strcpy(current->data.firstname, temp);
					cout << "DONE" << endl;
					break;
				}
				case 4:
				{
					do
					{
						cout << "Enter new gender(Male/Female): ";
						cin >> temp;
					} while ((strcmp(temp, "Male") != 0 && strcmp(temp, "Female") != 0) && cout << "Error!! Please try again!" << endl);
					strcpy(current->data.sex, temp);
					cout << "DONE" << endl;
					break;
				}
				case 5:
				{
					cout << "Enter new day of D.O.B:";
					cin >> temp;
					strcpy(current->data.birth.day, temp);
					cout << "Enter new month of D.O.B:";
					cin >> temp;
					strcpy(current->data.birth.month, temp);
					cout << "Enter new year of D.O.B:";
					cin >> temp;
					strcpy(current->data.birth.year, temp);
					cout << "DONE" << endl;
					break;
				}
				case 6:
				{
					break;
				}
				default: cout << "You can only input from 1 to 6" << endl;
				}
			} while (check != 6);
			return true;
		}
		current = current->next;
	}
}
void outputClass(listallst &last)
{
	ifstream fin;
	fin.open("AllStudents.csv");
	if (fin.fail())
		return;
	nameall nall;
	int i = 1;
	init(last);
	while (fin.getline(nall.name, 30, '\n'))
	{
		nodeallst *p = createNode(nall);
		insertTail(last, p);
		cout << " " << i << " : " << nall.name << endl;
		i++;
	}
	fin.close();
	return;
}
int listn()
{
	ifstream fin;
	fin.open("AllStudents.csv");
	char a[100];
	int n = 0;
	while (fin.getline(a, 30, '\n'))
	{
		n++;
	}
	return n;
}
void moveStudent(listst*&lst, listallstsave &lasts)
{
	char ID[10];
	int flag = 0;
	int check = 0;
	int check1 = 0;
	char a[10];
	do
	{
		cout << "Input the student ID you want to remove: ";
		cin >> ID;
		for (int i = 0; i < listn(); i++)
		{
			for (nodest *p = lst[i].head; p != NULL; p = p->next)
			{
				if (strcmp(lst[i].head->data.id, ID) == 0)
				{
					check = i;
					check1 = 1;
					cout << "Yeahh, Had found student with ID " << ID << " in the class " << i + 1 << "" << endl;
					cout << "Do you want to remove ??? (yes/no): ";
					cin >> a;
					if (strcmp(a, "yes") == 0)
					{
						lst[i].head = lst[i].head->next;
						while (p->next != NULL)
						{
							p->next->data.no -= 1;
							p = p->next;
						}
						flag = 1;
						break;
					}
					else break;
				}
				if (p->next != NULL)
				{
					if (strcmp(p->next->data.id, ID) == 0)
					{
						check = i;
						check1 = 1;
						cout << "Yeahh, Had found student with ID " << ID << " in the class " << i + 1 << "" << endl;
						cout << "Do you want to remove ??? (yes/no): ";
						cin >> a;
						if (strcmp(a, "yes") == 0)
						{
							p->next = p->next->next;
							while (p->next != NULL)
							{
								p->next->data.no -= 1;
								p = p->next;
							}
							flag = 1;
							break;
						}
						else break;
					}
				}
				else
				{
					if (flag != 1)
					{
						flag = 0;
						check1 = 0;
					}
				}
			}
			if (flag == 1) break;
		}
		if (check1 == 0)
		{
			cout << "Can't find student with ID " << ID << " in the class!" << endl;
		}
	} while (flag == 0);
	int index = 0;
	for (nodeallstsave *t = lasts.head; t != NULL; t = t->next)
	{
		if (index == check)
		{
			saveStudent(t, lst[check]);
		}
		index++;
	}
}
void changeStudent(listst*&lst, listallst &last, listallstsave &lasts, int &cla, int &cla1)
{
	char ID[10];
	int flag = 0;
	nodest*temp = new nodest;
	do
	{
		do
		{
			outputClass(last);
			cout << "Enter the class A (1 -> " << listn() << "): ";
			cin >> cla;
		} while (cla > listn() && cla < 1 && cout << "We only have " << listn() << " classes!" << endl);
		cout << "Input the student ID you want to move to another class: ";
		cin >> ID;
		int i = cla - 1;
		for (nodest *p = lst[i].head; p != NULL; p = p->next)
		{
			if (strcmp(lst[i].head->data.id, ID) == 0)
			{
				cout << "Found student with ID " << ID << " in the class!" << endl;
				temp = lst[i].head;
				lst[i].head = lst[i].head->next;
				while (p->next != NULL)
				{
					p->next->data.no -= 1;
					p = p->next;
				}
				flag = 1;
				break;
			}
			if (p->next != NULL)
			{
				if (strcmp(p->next->data.id, ID) == 0)
				{
					cout << "Found student with ID " << ID << " in the class!" << endl;
					temp = p->next;
					p->next = p->next->next;
					while (p->next != NULL)
					{
						p->next->data.no -= 1;
						p = p->next;
					}
					flag = 1;
					break;
				}
			}
			else
			{
				if (flag != 1)
				{
					cout << "Can't find student with ID " << ID << " in the class!" << endl;
					flag = 0;
				}
			}
		}
	} while (flag == 0);
	do
	{
		do
		{
			cout << "Enter the class B (1 -> " << listn() << "): ";
			cin >> cla1;
		} while (cla1 > listn() && cla1 < 1 && cout << "We only have " << listn() << " classes!" << endl);
	} while ((cla1 == cla) && cout << "Opps, Please not enter 2 class same " << endl);
	temp->data.no = lst[cla1 - 1].tail->data.no + 1;
	temp->next = NULL;
	insertTail(lst[cla1 - 1], temp);
	int index = 0;
	for (nodeallstsave *t = lasts.head; t != NULL; t = t->next)
	{
		index++;
		if (index == cla)
		{
			saveStudent(t, lst[cla - 1]);
		}
		if (index == cla1)
		{
			saveStudent(t, lst[cla1 - 1]);
		}
	}
}
void viewClassandList(listallst &last, listst *&lst)
{
	outputClass(last);
	char a[10];
	int b = 0;
	char c[10];
	int index = 0;
	cout << "Do you want to view list of students in a class??? (yes/no): ";
	cin >> a;
	if (strcmp(a, "yes") == 0)
	{
		cout << "Choose a class to see: ";
		cin >> b;
		for (nodeallst *p = last.head; p != NULL; p = p->next)
		{
			index++;
			if (index == b)
			{
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "        No        |      StudentID     |                          Name                        |          Sex        |                                        Birthday" << endl;
				for (nodest *p = lst[b - 1].head; p != NULL; p = p->next)
					cout << p->data.no << "|" << p->data.id << "|" << p->data.lastname << " " << p->data.firstname << "|" << p->data.sex << "|" << p->data.birth.month << "/" << p->data.birth.day << "/" << p->data.birth.year << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
	}
	else return;
}
bool Create(const char *path)
{
	if (!CreateDirectory(path, NULL))
		return false;
	else return true;
}
void CreateAll()
{
	Create("2018 - 2019");
	Create("2018 - 2019/Semester 1");
	Create("2018 - 2019/Semester 2");
	Create("2018 - 2019/Semester 3");
}
bool loadsemester(const string path, listcr &lcr, char b[], course *&cr, int ii)
{
	ifstream fin;
	fin.open(path);
	if (fin.fail())
		return false;
	cr = new course[200];
	ii = 0;
	init(lcr);
	fin.getline(b, 200, '\n');
	while (fin >> cr[ii].no)
	{
		fin.get();
		fin.getline(cr[ii].id, 10, ',');
		fin.getline(cr[ii].name, 100, ',');
		fin.getline(cr[ii].classn, 7, ',');
		fin.getline(cr[ii].lecture, 100, ',');
		fin >> cr[ii].start.day;
		fin.ignore();
		fin >> cr[ii].start.month;
		fin.ignore();
		fin >> cr[ii].start.year;
		fin.ignore();
		fin >> cr[ii].end.day;
		fin.ignore();
		fin >> cr[ii].end.month;
		fin.ignore();
		fin >> cr[ii].end.year;
		fin.ignore();
		fin.getline(cr[ii].day, 100, ',');
		fin >> cr[ii].start1.hour;
		fin.ignore();
		fin >> cr[ii].start1.minute;
		fin.ignore();
		fin >> cr[ii].end1.hour;
		fin.ignore();
		fin >> cr[ii].end1.minute;
		fin.ignore();
		fin.getline(cr[ii].room, 10, '\n');
		nodecr *p = createNode(cr[ii]);
		insertTail(lcr, p);
		ii++;
	}
	fin.close();
	return true;
}
bool savesemester(const string path, listcr &lcr, char b[])
{
	ofstream fout;
	fout.open(path);
	int i = 0;
	if (fout.fail())
		return false;
	fout << b << endl;
	for (nodecr *p = lcr.head; p != NULL; p = p->next)
	{
		course cr = p->data;
		if (cr.no < 0) break;
		fout << cr.no << "," << cr.id << "," << cr.name << "," << cr.classn << "," << cr.lecture << "," << cr.start.month << "/" << cr.start.day << "/" << cr.start.year << ',' << cr.end.month << "/" << cr.end.day << "/" << cr.end.year << ',' << cr.day << ',' << cr.start1.hour << ':' << cr.start1.minute << ',' << cr.end1.hour << ':' << cr.end1.minute << ',' << cr.room << endl;
	}
	fout.close();
	return true;
}
bool semester(course *&cr, listcr *&lcr, course *&crr)
{
	char b[200];
	int h, k;
	int check = 0;
	int ii = 0;
	int master = 0;
	string a[3] = { "2018 - 2019/Semester 1/courseS1.csv", "2018 - 2019/Semester 2/courseS2.csv", "2018 - 2019/Semester 3/courseS3.csv" };
	for (int i = 0; i < 2; i++)
	{
		h = loadsemester(a[i], lcr[i], b, cr, ii);
		for (int cri = 0; cri < lcr[i].tail->data.no; cri++)
		{
			crr[master] = cr[cri];
			master++;
		}
		k = savesemester(a[i], lcr[i], b);
	}
	if (h == true && k == true)
		return true;
	else return false;
}
void viewsemester(course *&cr, listcr *&lcr, course *&crr)
{
	semester(cr, lcr, crr);
	cout << "------| SCHOLASTIC 2018 - 2019 |------" << endl;
	cout << "1: Semester 1" << endl;
	cout << "2: Semester 2" << endl;
	cout << "3: Semester 3" << endl;
}
void course1menu(listcr *&lcr, int i, course *&cr, course *&crr)
{
	cout << "Create/update/delete/view academic years (2018 - 2019) & semesters" << endl;
	cout << "1: Create" << endl;
	cout << "2: Update" << endl;
	cout << "3: Delete" << endl;
	cout << "4: View academic years (2018 - 2019) & semesters" << endl;
	cout << "5: Back" << endl;
	int s;
	cout << "Let's choose request you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		CreateAll();
		cout << "Create academic years (2018 - 2019) & semesters successfull" << endl;
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		system("cls");
		viewsemester(cr, lcr, crr);
		break;
	}
	case 5:
	{
		break;
	}
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		course1menu(lcr, i, cr, crr);
		break;
	}
	}
}
bool importcourse(listcr &lcr, char a[])
{
	ofstream fout;
	ofstream fout1;
	ofstream fout2;
	fout.open("2018 - 2019/Semester 1/courseS1.csv");
	fout1.open("2018 - 2019/Semester 2/courseS2.csv");
	fout2.open("2018 - 2019/Semester 3/courseS3.csv");
	if (fout.fail() && fout1.fail() && fout2.fail())
		return false;
	int check = 0;
	int number1 = 1;
	int number2 = 1;
	int number3 = 1;
	fout << a << endl;
	fout1 << a << endl;
	fout2 << a << endl;
	for (nodecr *p = lcr.head; p != NULL; p = p->next)
	{
		course cr = p->data;
		if (cr.start.day > 1 && cr.start.month == 9 && cr.start.year == 2018 && cr.end.day < 30 && cr.end.month == 11 && cr.end.year == 2018)
		{
			if (cr.no < 0) break;
			cr.no = number1;
			fout << cr.no << "," << cr.id << "," << cr.name << "," << cr.classn << "," << cr.lecture << "," << cr.start.month << "/" << cr.start.day << "/" << cr.start.year << ',' << cr.end.month << "/" << cr.end.day << "/" << cr.end.year << ',' << cr.day << ',' << cr.start1.hour << ':' << cr.start1.minute << ',' << cr.end1.hour << ':' << cr.end1.minute << ',' << cr.room << endl;
			number1++;
		}
		else if (cr.start.day > 1 && cr.start.month == 1 && cr.start.year == 2019 && cr.end.day < 30 && cr.end.month == 4 && cr.end.year == 2019)
		{
			if (cr.no < 0) break;
			cr.no = number2;
			fout1 << cr.no << "," << cr.id << "," << cr.name << "," << cr.classn << "," << cr.lecture << "," << cr.start.month << "/" << cr.start.day << "/" << cr.start.year << ',' << cr.end.month << "/" << cr.end.day << "/" << cr.end.year << ',' << cr.day << ',' << cr.start1.hour << ':' << cr.start1.minute << ',' << cr.end1.hour << ':' << cr.end1.minute << ',' << cr.room << endl;
			number2++;
		}
		else
		{
			if (cr.no < 0) break;
			cr.no = number3;
			fout2 << cr.no << "," << cr.id << "," << cr.name << "," << cr.classn << "," << cr.lecture << "," << cr.start.month << "/" << cr.start.day << "/" << cr.start.year << ',' << cr.end.month << "/" << cr.end.day << "/" << cr.end.year << ',' << cr.day << ',' << cr.start1.hour << ':' << cr.start1.minute << ',' << cr.end1.hour << ':' << cr.end1.minute << ',' << cr.room << endl;
			number3++;
		}
	}
	fout.close();
	return true;
}
void addnewcourse(listcr &lcr)
{
	course cr;
	cout << "Add new course" << endl;
	cr.no = lcr.tail->data.no + 1;
	cout << "Enter Course ID: ";
	cin >> cr.id;
	cin.get();
	cout << "Enter Course Name: ";
	cin.getline(cr.name, '/n');
	cout << "Enter Class of Course: ";
	cin >> cr.classn;
	cout << "Enter Lecture Account: ";
	cin >> cr.lecture;
	cout << "Enter Day of Start Date: ";
	cin >> cr.start.day;
	cout << "Enter Month of Start Date: ";
	cin >> cr.start.month;
	cout << "Enter Year of Start Date: ";
	cin >> cr.start.year;
	cout << "Enter Day of End Date: ";
	cin >> cr.end.day;
	cout << "Enter Month of End Date: ";
	cin >> cr.end.month;
	cout << "Enter Year of End Date: ";
	cin >> cr.end.year;
	cout << "Enter the Day of Week the course take: ";
	cin >> cr.day;
	cout << "Enter the Start Hour: ";
	cin >> cr.start1.hour;
	cout << "Enter the Start Minute: ";
	cin >> cr.start1.minute;
	cout << "Enter the End Hour: ";
	cin >> cr.end1.hour;
	cout << "Enter the End Minute: ";
	cin >> cr.end1.minute;
	cout << "Enter the room of the Course: ";
	cin >> cr.room;
	nodecr *p = createNode(cr);
	insertTail(lcr, p);
}
//
bool editCourses(listcr &lcr, char ID[], char Class[], char Date[], int h, int m)
{
	int check;
	char temp[100];
	int x, y, z;
	nodecr* head = lcr.head;
	nodecr*current = head;
	while (current != lcr.tail)
	{
		if (strcmp(current->data.id, ID) == 0 && strcmp(current->data.classn, Class) == 0 && strcmp(current->data.day, Date) == 0 && current->data.start1.hour == h && current->data.start1.minute == m)
		{
			do
			{
				cout << "Please input the one you want to edit: " << endl;
				cout << "1. Edit Course ID" << endl;
				cout << "2. Edit Course Name" << endl;
				cout << "3. Edit Class" << endl;
				cout << "4. Edit LecturerAccount" << endl;
				cout << "5. Edit Start Date" << endl;
				cout << "6. Edit End Date" << endl;
				cout << "7. Edit Day of Week" << endl;
				cout << "8. Edit Start Hour:Minute" << endl;
				cout << "9. Edit End Hour:Minute" << endl;
				cout << "10. Edit Room" << endl;
				cout << "11. BACK" << endl;
				cin >> check;
				switch (check)
				{
				case 1:
					cout << "Enter Course ID : ";
					cin >> temp;
					strcpy(current->data.id, temp);
					cout << "DONE" << endl;
					break;
				case 2:
					cout << "Enter Course Name : ";
					cin.getline(temp, '\n');
					strcpy(current->data.name, temp);
					cout << "DONE" << endl;
					break;
				case 3:
					cout << "Enter Class : ";
					cin >> temp;
					strcpy(current->data.classn, temp);
					cout << "DONE" << endl;
					break;
				case 4:
					cout << "Enter Lecturer Name : ";
					cin >> temp;
					strcpy(current->data.lecture, temp);
					cout << "DONE" << endl;
					break;
				case 5:
					cout << "Edit Start Date" << endl;
					cout << "Day : ";
					do
					{
						cin >> x;
						if (x < 1 || x > 31) cout << "Please re-enter" << endl;
					} while (x < 1 || x > 31);
					current->data.start.day = x;
					cout << "Month : ";
					do
					{
						cin >> y;
						if (y < 1 || y > 12) cout << "Please re-enter" << endl;
					} while (y < 1 || y > 12);
					current->data.start.month = y;
					cout << "Year : ";
					cin >> z;
					current->data.start.year = z;
					cout << "DONE" << endl;
					break;
				case 6:
					cout << "Enter Day of Week : ";
					cin >> temp;
					strcpy(current->data.day, temp);
					cout << "DONE" << endl;
					break;
				case 7:
					cout << "Edit End Date" << endl;
					cout << "Day : ";
					do
					{
						cin >> x;
						if (x < 1 || x > 31) cout << "Please re-enter" << endl;
					} while (x < 1 || x > 31);
					current->data.end.day = x;
					cout << "Month : ";
					do
					{
						cin >> y;
						if (y < 1 || y > 12) cout << "Please re-enter" << endl;
					} while (y < 1 || y > 12);
					current->data.end.month = y;
					cout << "Year : ";
					cin >> z;
					current->data.end.year = z;
					cout << "DONE" << endl;
					break;
				case 8:
					cout << "Edit Start Hour:Minute" << endl;
					cout << "Hour : ";
					do
					{
						cin >> x;
						if (x < 1 || x>24) cout << "Please re-enter" << endl;
					} while (x < 1 || x>24);
					current->data.start1.hour = x;
					cout << "Minute : ";
					do
					{
						cin >> y;
						if (y < 1 || y > 60) cout << "Please re-enter" << endl;
					} while (y < 1 || y > 60);
					current->data.start1.minute = y;
					cout << "DONE" << endl;
					break;
				case 9:
					cout << "End Hour:Minute" << endl;
					cout << "Hour : ";
					do
					{
						cin >> x;
						if (x < 1 || x>24) cout << "Please re-enter" << endl;
					} while (x < 1 || x>24);
					current->data.end1.hour = x;
					cout << "Minute : ";
					do
					{
						cin >> y;
						if (y < 1 || y > 60) cout << "Please re-enter" << endl;
					} while (y < 1 || y > 60);
					current->data.end1.minute = y;
					cout << "DONE" << endl;
					break;
				case 10:
					cout << "Enter Room :";
					cin >> temp;
					strcpy(current->data.room, temp);
					cout << "DONE" << endl;
					break;
				case 11:
				{
					break;
				}
				default:
					cout << "You Enter Wrong" << endl;
					break;
				}
			} while (check != 11);
			return true;
		}
		current = current->next;
	}
}
//
void removecourse(listcr &lcr)
{
	char ID[100];
	char cla[20];
	char check[10];
	char Date[10];
	int h, m;
	int a = 0;
	int flag = 0;
	cout << "Remove a course!" << endl;
	cout << "Enter the Course ID of the Course you want to remove: ";
	cin >> ID;
	cout << "Enter the class of the Course you want to remove: ";
	cin >> cla;
	cout << "Input the Date of the Course you want to remove: ";
	cin >> Date;
	cout << "Input the Start Hour:Minute you want to remove" << endl;
	cout << "Input Hour: ";
	cin >> h;
	cout << "Input Minute: ";
	cin >> m;

	nodecr*curr = new nodecr;
	nodecr*prev = new nodecr;
	curr = lcr.head;
	prev = NULL;
	while (curr != NULL)
	{
		if (strcmp(lcr.head->data.id, ID) == 0 && strcmp(lcr.head->data.classn, cla) == 0 && strcmp(lcr.head->data.day, Date) == 0 && lcr.head->data.start1.hour == h && lcr.head->data.start1.minute == m)
		{
			cout << "Found the course with ID: " << ID << " with the class: " << cla << endl;
			do
			{
				cout << "Do you want to remove this course(Yes/No): ";
				cin >> check;
				if (strcmp(check, "Yes") == 0)
				{
					lcr.head = lcr.head->next;
					delete curr;
					curr = lcr.head;
					while (curr != NULL)
					{
						curr->data.no -= 1;
						curr = curr->next;
					}
					curr = lcr.head;
					flag = 1;
					a = 1;
				}
				else if (strcmp(check, "No") == 0)
				{
					return;
				}
				else cout << "You can only input Yes/No! Please input again!" << endl;
			} while (a == 0);

		}
		else if (strcmp(curr->data.id, ID) == 0 && strcmp(curr->data.classn, cla) == 0 && strcmp(curr->data.day, Date) == 0 && curr->data.start1.hour == h && curr->data.start1.minute == m)
		{
			cout << "Found the course with ID: " << ID << " with the class: " << cla << endl;
			do
			{
				cout << "Do you want to remove this course(Yes/No): ";
				cin >> check;
				if (strcmp(check, "Yes") == 0)
				{
					prev->next = curr->next;
					if (curr != lcr.tail)
						delete curr;
					else
					{
						lcr.tail = prev;
					}
					curr = prev->next;
					while (curr != NULL)
					{
						curr->data.no -= 1;
						curr = curr->next;
					}
					a = 1;
					curr = prev;
					flag = 1;
				}
				else if (strcmp(check, "No") == 0)
				{
					return;
				}
				else cout << "You can only input Yes/No! Please input again!" << endl;
			} while (a == 0);
		}
		prev = curr;
		curr = curr->next;
	}
	if (flag == 0)
		cout << "Can't find the course with ID: " << ID << " and class: " << cla << endl;
	else cout << "Remove course successfully" << endl;
}
bool loadStudentcheck(const string file, listst &lst)
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	char b[100];
	student st;
	fin.getline(b, 50, '\n');
	init(lst);
	while (fin >> st.no)
	{
		fin.get();
		fin.getline(st.id, 9, ',');
		fin.getline(st.lastname, 101, ',');
		fin.getline(st.firstname, 101, ',');
		fin.getline(st.sex, 10, ',');
		fin.getline(st.birth.month, 5, '/');
		fin.getline(st.birth.day, 5, '/');
		fin.getline(st.birth.year, 5, '\n');
		nodest *p = createNode(st);
		insertTail(lst, p);
	}
	fin.close();
	return true;
}
bool saveStudentcheck(const char *name, listst &lst)
{
	ofstream fout;
	fout.open(name);
	if (fout.fail())
		return false;
	fout << "No,Student ID,Lastname,Firstname,Gender,DoB" << endl;
	for (nodest *p = lst.head; p != NULL; p = p->next)
	{
		student st = p->data;
		if (st.no < 0) break;
		fout << st.no << "," << st.id << "," << st.lastname << "," << st.firstname << "," << st.sex << "," << st.birth.month << "/" << st.birth.day << "/" << st.birth.year << endl;
	}
	fout.close();
	return true;
}
void check1(listcr &lcr, listst &lst)
{
	for (nodecr *p = lcr.head; p != NULL; p = p->next)
	{
		if (p->data.start.day > 1 && p->data.start.month == 9 && p->data.start.year == 2018 && p->data.end.day < 30 && p->data.end.month == 11 && p->data.end.year == 2018)
		{
			if (strcmp(p->data.classn, "18CLC1") == 0)
			{
				char a[100] = "2018 - 2019/Semester 1/";
				char c[15] = " - 18CLC1.csv";
				loadStudentcheck("18CLC1Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC2") == 0)
			{
				char a[100] = "2018 - 2019/Semester 1/";
				char c[15] = " - 18CLC2.csv";
				loadStudentcheck("18CLC2Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC3") == 0)
			{
				char a[100] = "2018 - 2019/Semester 1/";
				char c[15] = " - 18CLC3.csv";
				loadStudentcheck("18CLC3Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC4") == 0)
			{
				char a[100] = "2018 - 2019/Semester 1/";
				char c[15] = " - 18CLC4.csv";
				loadStudentcheck("18CLC4Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC5") == 0)
			{
				char a[100] = "2018 - 2019/Semester 1/";
				char c[15] = " - 18CLC5.csv";
				loadStudentcheck("18CLC5Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC6") == 0)
			{
				char a[100] = "2018 - 2019/Semester 1/";
				char c[15] = " - 18CLC6.csv";
				loadStudentcheck("18CLC6Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
		}
		else if (p->data.start.day > 1 && p->data.start.month == 1 && p->data.start.year == 2019 && p->data.end.day < 30 && p->data.end.month == 4 && p->data.end.year == 2019)
		{
			if (strcmp(p->data.classn, "18CLC1") == 0)
			{
				char a[100] = "2018 - 2019/Semester 2/";
				char c[15] = " - 18CLC1.csv";
				loadStudentcheck("18CLC1Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC2") == 0)
			{
				char a[100] = "2018 - 2019/Semester 2/";
				char c[15] = " - 18CLC2.csv";
				loadStudentcheck("18CLC2Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC3") == 0)
			{
				char a[100] = "2018 - 2019/Semester 2/";
				char c[15] = " - 18CLC3.csv";
				loadStudentcheck("18CLC3Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC4") == 0)
			{
				char a[100] = "2018 - 2019/Semester 2/";
				char c[15] = " - 18CLC4.csv";
				loadStudentcheck("18CLC4Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC5") == 0)
			{
				char a[100] = "2018 - 2019/Semester 2/";
				char c[15] = " - 18CLC5.csv";
				loadStudentcheck("18CLC5Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC6") == 0)
			{
				char a[100] = "2018 - 2019/Semester 2/";
				char c[15] = " - 18CLC6.csv";
				loadStudentcheck("18CLC6Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
		}
		else
		{
			if (strcmp(p->data.classn, "18CLC1") == 0)
			{
				char a[100] = "2018 - 2019/Semester 3/";
				char c[15] = " - 18CLC1.csv";
				loadStudentcheck("18CLC1Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC2") == 0)
			{
				char a[100] = "2018 - 2019/Semester 3/";
				char c[15] = " - 18CLC2.csv";
				loadStudentcheck("18CLC2Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC3") == 0)
			{
				char a[100] = "2018 - 2019/Semester 3/";
				char c[15] = " - 18CLC3.csv";
				loadStudentcheck("18CLC3Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC4") == 0)
			{
				char a[100] = "2018 - 2019/Semester 3/";
				char c[15] = " - 18CLC4.csv";
				loadStudentcheck("18CLC4Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC5") == 0)
			{
				char a[100] = "2018 - 2019/Semester 3/";
				char c[15] = " - 18CLC5.csv";
				loadStudentcheck("18CLC5Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
			else if (strcmp(p->data.classn, "18CLC6") == 0)
			{
				char a[100] = "2018 - 2019/Semester 3/";
				char c[15] = " - 18CLC6.csv";
				loadStudentcheck("18CLC6Student.csv", lst);
				strcat(a, p->data.name);
				strcat(a, c);
				saveStudentcheck(a, lst);
			}
		}
	}
}
////////////////////////////////
void removestcr(listcr &lcr, listst &lst)
{
	char ID[10];
	int flag = 0;
	int check = 0;
	int check1 = 0;
	char a[10];
	do
	{
		cout << "Input the student ID you want to remove from course: ";
		cin >> ID;
		{
			for (nodest *p = lst.head; p != NULL; p = p->next)
			{
				if (strcmp(lst.head->data.id, ID) == 0)
				{
					check1 = 1;
					cout << "Yeahh, Had found student with ID " << ID << " in the course " << lcr.head->data.name << "" << endl;
					cout << "Do you want to remove ??? (yes/no): ";
					cin >> a;
					if (strcmp(a, "yes") == 0)
					{
						lst.head = lst.head->next;
						while (p->next != NULL)
						{
							p->next->data.no -= 1;
							p = p->next;
						}
						flag = 1;
						break;
					}
					else break;
				}
				if (p->next != NULL)
				{
					if (strcmp(p->next->data.id, ID) == 0)
					{
						check1 = 1;
						cout << "Yeahh, Had found student with ID " << ID << " in the course " << lcr.head->data.name << "" << endl;
						cout << "Do you want to remove ??? (yes/no): ";
						cin >> a;
						if (strcmp(a, "yes") == 0)
						{
							p->next = p->next->next;
							while (p->next != NULL)
							{
								p->next->data.no -= 1;
								p = p->next;
							}
							flag = 1;
							break;
						}
						else break;
					}
				}
				else
				{
					if (flag != 1)
					{
						flag = 0;
						check1 = 0;
					}
				}
			}
			if (flag == 1) break;
		}
		if (check1 == 0)
		{
			cout << "Can't find student with ID " << ID << " in the course!" << endl;
		}
	} while (flag == 0);
}
void removestcrreal(listcr &lcr)
{
	char ID[100];
	char cla[10];
	int check = 0;
	int flag = 0;
	cout << "Remove student from a course!" << endl;
	listst lst;
	do
	{
		cout << "Enter the Course ID of the course you want to remove a student: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				char to[4] = " - ";
				char csv[5] = ".csv";
				strcat(a, cr->data.name);
				strcat(a, to);
				strcat(a, cla);
				strcat(a, csv);
				loadStudentcheck(a, lst);
				removestcr(lcr, lst);
				saveStudentcheck(a, lst);
				cout << "Remove student from the course successfully" << endl;
				return;
			}
		}
	} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
}
void addstcr(listcr &lcr)
{
	{
		char ID[100];
		char cla[10];
		int check = 0;
		int flag = 0;
		cout << "Remove student from a course!" << endl;
		listst lst;
		do
		{
			cout << "Enter the Course ID of the course you want to remove a student: ";
			cin >> ID;
			cout << "Enter the class of the course: ";
			cin >> cla;
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
				{
					flag = 1;
					cout << "Find the course!!" << endl;
					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					char to[4] = " - ";
					char csv[5] = ".csv";
					strcat(a, cr->data.name);
					strcat(a, to);
					strcat(a, cla);
					strcat(a, csv);
					loadStudentcheck(a, lst);

					student st;
					cout << "Add a specific student to a course" << endl;
					st.no = lst.tail->data.no + 1;
					cout << "Enter ID: ";
					cin >> st.id;
					cin.get();
					cout << "Enter Lastname: ";
					cin.getline(st.lastname, '/n');
					cout << "Enter Firstname: ";
					cin >> st.firstname;
					do
					{
						cout << "Enter gender(Male/Female): ";
						cin >> st.sex;
					} while ((strcmp(st.sex, "Male") != 0 && strcmp(st.sex, "Female") != 0) && cout << "You can only enter Male/Female");
					cout << "Enter day of DOB: ";
					cin >> st.birth.day;
					cout << "Enter month of DOB: ";
					cin >> st.birth.month;
					cout << "Enter year of DOB: ";
					cin >> st.birth.year;
					nodest*p = createNode(st);
					insertTail(lst, p);
					saveStudentcheck(a, lst);
					cout << "Add a specific student to a course Successfull" << endl;
					return;
				}
			}
		} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
	}
}
string abc()
{
	time_t     now;
	struct tm  ts;
	char       buf[80];
	time(&now);
	ts = *localtime(&now);
	strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
	cout << "Today's calendar is " << buf << endl;
	char a[20] = "2018-04-09";
	string s;
	int n = 0;
	for (int i = 4; i < strlen(a) + 4; i++)
	{
		n = 0;
		s = s + buf[i];
		n++;
	}
	return s;
}
bool viewpro8(listcr &lcr)
{
	cout << "------| SCHOLASTIC 2018 - 2019 |------" << endl;
	cout << "Semester 1" << endl;
	cout << "Semester 2" << endl;
	cout << "Semester 3" << endl;
	char b[200];
	char smt[4];
	string h = abc();
	string k1 = "2018-09-01";
	string k1l = "2018-11-30";
	string k2 = "2019-01-01";
	string k2l = "2019-04-30";
	cout << "Do you want to view list of courses in the current semester? (yes/no): ";
	cin >> smt;
	if ((strcmp("yes", smt) == 0))
	{
		if (h > k1 && h < k1l)
		{
			cout << "\n	The current semester is the first semester" << endl << endl;
			cout << "                                       __List of courses in the first semester__" << endl << endl;
			loadCourse("2018 - 2019/Semester 1/courseS1.csv", lcr, b);
			cout << "|No|Course ID|Course Name|Class|LecturerAccount|Start Date|End Date|Day of Week|Start Hour:Minute|End Hour:Minute|Room|" << endl;
			for (nodecr *p = lcr.head; p != NULL; p = p->next)
			{
				course cr = p->data;
				if (cr.no < 0) break;
				cout << "|" << cr.no << "|" << cr.id << "|" << cr.name << "|" << cr.classn << "|" << cr.lecture << "|" << cr.start.day << "/" << cr.start.month << "/" << cr.start.year << '|' << cr.end.day << "/" << cr.end.month << "/" << cr.end.year << '|' << cr.day << '|' << cr.start1.hour << ':' << cr.start1.minute << '|' << cr.end1.hour << ':' << cr.end1.minute << '|' << cr.room << "|" << endl;
			}
			return true;
		}
		else if (h > k2 && h < k2l)
		{
			cout << "\n	The current semester is the second semester" << endl << endl;
			cout << "                                       __List of courses in the second semester__" << endl << endl;
			loadCourse("2018 - 2019/Semester 2/courseS2.csv", lcr, b);
			cout << "|No|Course ID|Course Name|Class|LecturerAccount|Start Date|End Date|Day of Week|Start Hour:Minute|End Hour:Minute|Room|" << endl;
			for (nodecr *p = lcr.head; p != NULL; p = p->next)
			{
				course cr = p->data;
				if (cr.no < 0) break;
				cout << "|" << cr.no << "|" << cr.id << "|" << cr.name << "|" << cr.classn << "|" << cr.lecture << "|" << cr.start.day << "/" << cr.start.month << "/" << cr.start.year << '|' << cr.end.day << "/" << cr.end.month << "/" << cr.end.year << '|' << cr.day << '|' << cr.start1.hour << ':' << cr.start1.minute << '|' << cr.end1.hour << ':' << cr.end1.minute << '|' << cr.room << "|" << endl;
			}
			return true;
		}
		else
		{
			cout << "\n	The current semester is the 3rd semester" << endl << endl;
			cout << "                                       __List of courses in the 3rd semester__" << endl << endl;
			loadCourse("2018 - 2019/Semester 3/courseS3.csv", lcr, b);
			cout << "|No|Course ID|Course Name|Class|LecturerAccount|Start Date|End Date|Day of Week|Start Hour:Minute|End Hour:Minute|Room|" << endl;
			for (nodecr *p = lcr.head; p != NULL; p = p->next)
			{
				course cr = p->data;
				if (cr.no < 0) break;
				cout << "|" << cr.no << "|" << cr.id << "|" << cr.name << "|" << cr.classn << "|" << cr.lecture << "|" << cr.start.day << "/" << cr.start.month << "/" << cr.start.year << '|' << cr.end.day << "/" << cr.end.month << "/" << cr.end.year << '|' << cr.day << '|' << cr.start1.hour << ':' << cr.start1.minute << '|' << cr.end1.hour << ':' << cr.end1.minute << '|' << cr.room << "|" << endl;
			}
			return true;
		}
	}
	return false;
}
void viewpro9(listcr &lcr)
{
	char ID[100];
	char cla[10];
	int check = 0;
	int flag = 0;
	listst lst;
	do
	{
		cout << "Enter the Course ID of the course you want view list of student of course: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
			{
				flag = 1;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				char to[4] = " - ";
				char csv[5] = ".csv";
				strcat(a, cr->data.name);
				strcat(a, to);
				strcat(a, cla);
				strcat(a, csv);
				loadStudentcheck(a, lst);
				cout << "        No        |      StudentID     |                          Name                        |          Sex        |                                        Birthday" << endl;
				for (nodest *p = lst.head; p != NULL; p = p->next)
					cout << p->data.no << "|" << p->data.id << "|" << p->data.lastname << " " << p->data.firstname << "|" << p->data.sex << "|" << p->data.birth.month << "/" << p->data.birth.day << "/" << p->data.birth.year << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				return;
			}
		}
	} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
}
void insertTail(listat &lat, nodeat *p)
{
	if (lat.head == NULL)
	{
		lat.head = lat.tail = p;
	}
	else
	{
		lat.tail->next = p;
		lat.tail = p;
	}
}
void insertTail(listat1 &lat, nodeat1 *p)
{
	if (lat.head == NULL)
	{
		lat.head = lat.tail = p;
	}
	else
	{
		lat.tail->next = p;
		lat.tail = p;
	}
}
bool loadattheory(const char*file, listat &lat, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	att att;
	fin.getline(b, 200, '\n');
	lat.head = lat.tail = NULL;
	while (fin.getline(att.id, 12, ','))
	{
		fin >> att.w1;
		fin.get();
		fin >> att.w2;
		fin.get();
		fin >> att.w3;
		fin.get();
		fin >> att.w4;
		fin.get();
		fin >> att.w5;
		fin.get();
		fin >> att.w6;
		fin.get();
		fin >> att.w7;
		fin.get();
		fin >> att.w8;
		fin.get();
		fin >> att.w9;
		fin.get();
		fin >> att.w10;
		fin.get();
		fin >> att.w11;
		fin.get();
		nodeat *p = createnodeat(att);
		insertTail(lat, p);
	}
	return true;
}
bool loadatprac(const char*file, listat1 &lat, char b[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	att1 att;
	fin.getline(b, 200, '\n');
	lat.head = lat.tail = NULL;
	while (fin.getline(att.id, 12, ','))
	{
		fin >> att.w1;
		fin.get();
		fin >> att.w2;
		fin.get();
		fin >> att.w3;
		fin.get();
		fin >> att.w4;
		fin.get();
		fin >> att.w5;
		fin.get();
		fin >> att.w6;
		fin.get();
		fin >> att.w7;
		fin.get();
		fin >> att.w8;
		fin.get();
		fin >> att.w9;
		fin.get();
		fin >> att.w10;
		fin.get();
		nodeat1 *p = createnodeat(att);
		insertTail(lat, p);
	}
	return true;
}
bool saveatprac(const char*file, listat1 &lat, char b[])
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << b << endl;
	for (nodeat1 *t = lat.head; t != NULL; t = t->next)
	{
		fout << t->data.id << "," << t->data.w1 << "," << t->data.w2 << "," << t->data.w3 << "," << t->data.w4 << "," << t->data.w5 << "," << t->data.w6 << "," << t->data.w7 << "," << t->data.w8 << "," << t->data.w9 << "," << t->data.w10 << endl;
	}
	fout.close();
	return true;
}
bool saveattheory(const char*file, listat &lat, char b[])
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << b << endl;
	for (nodeat *t = lat.head; t != NULL; t = t->next)
	{
		fout << t->data.id << "," << t->data.w1 << "," << t->data.w2 << "," << t->data.w3 << "," << t->data.w4 << "," << t->data.w5 << "," << t->data.w6 << "," << t->data.w7 << "," << t->data.w8 << "," << t->data.w9 << "," << t->data.w10 << "," << t->data.w11 << endl;
	}
	fout.close();
	return true;
}
void viewatten(listat &lat, listcr &lcr, listat1 &lat1)
{
	{
		char ID[100];
		char cla[10];
		int check = 0;
		int flag = 0;
		do
		{
			cout << "Enter the Course ID of the course you want view attendance list of a course: ";
			cin >> ID;
			cout << "Enter the class of the course: ";
			cin >> cla;
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				int str = strlen(ID);
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
				{
					flag = 1;
					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					strcat(a, cla);
					char to[2] = "-";
					strcat(a, to);
					char csv[5] = ".csv";
					strcat(a, cr->data.id);
					strcat(a, csv);
					char b[200];
					if (ID[str - 1] == 'h' && ID[str - 2] == 't')
					{
						loadatprac(a, lat1, b);
						cout << "Practice(0:absent, 1: present)" << endl;
						cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10" << endl;
						for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
						{
							cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10;
						}
						return;
					}
					else
					{
						loadattheory(a, lat, b);
						cout << "Practice(0:absent, 1: present)" << endl;
						cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;
						for (nodeat *t = lat.head; t != NULL; t = t->next)
						{
							cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << "  " << t->data.w11;
						}
						return;
					}
				}
			}
		} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
	}
}
bool Createlectu(const char *file, listlt &llt, char a[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	lecturer lt;
	fin.getline(lt.name, 200, '\n');
	init(llt);
	while (fin.getline(lt.name, 50, ','))
	{
		fin.getline(lt.user, 20, ',');
		fin.getline(lt.pass, 100, ',');
		fin.getline(lt.mail, 50, '\n');
		nodelt *p = createNode(lt);
		insertTail(llt, p);
	}
	fin.close();
	return true;
}
bool Updatelectu(const char *file, listlt &llt)
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << "Name,User,Password,Email" << endl;;
	for (nodelt *p = llt.head; p != NULL; p = p->next)
	{
		fout << p->data.name << "," << p->data.user << "," << p->data.pass << "," << p->data.mail << endl;
	}
	fout.close();
	return true;
}
void viewlectu(listlt &llt)
{
	cout << "Name Email" << endl;
	for (nodelt *p = llt.head; p != NULL; p = p->next)
	{
		cout << p->data.name << "|" << p->data.mail << endl;
	}
	return;
}
void menulecture(listlt &llt)
{
	cout << "1: Create all lecturers" << endl;
	cout << "2: Update all lecturers" << endl;
	cout << "3: Delete all lecturers" << endl;
	cout << "4: View all lecturers" << endl;
	cout << "5: Back" << endl;
	int s;
	cout << "Let's choose request you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		char a[200];
		if (Createlectu("Teacher.csv", llt, a))
			cout << "Create all lecturers successfull" << endl;

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			menulecture(llt);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 2:
	{
		system("cls");
		char a[200];
		int h = Createlectu("Teacher.csv", llt, a);
		if (h)
		{
			h = Updatelectu("Teacher.csv", llt);
			if (h)
			{
				cout << "Update all lecturers successfull" << endl;
			}
		}

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			menulecture(llt);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 3:
	{
		system("cls");
		char a[200];
		int h = Createlectu("Teacher.csv", llt, a);
		if (h)
		{
			if (DeleteFile("Teacher.csv"))
			{
				cout << "Delete all lecturers successfull" << endl;
			}
		}

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			menulecture(llt);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 4:
	{
		system("cls");
		char a[200];
		int h = Createlectu("Teacher.csv", llt, a);
		if (h)
		{
			viewlectu(llt);
		}

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			menulecture(llt);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 5:
	{
		system("cls");
		coursemenu();
		break;
	}
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		menulecture(llt);
		break;
	}
	}
}
void coursemenu()
{
	listcr *lcr = new listcr[100];
	course *cr = new course[200];
	course *crr = new course[200];
	char b[200];
	int i = 0;
	cout << "__COURSE__" << endl;
	cout << "1: Create/update/delete/view academic years (2018 - 2019) & semesters" << endl;
	cout << "2: Import courses to semester" << endl;
	cout << "3: Manually add a new course" << endl;
	cout << "4: Edit an existing course" << endl;
	cout << "5: Remove a course" << endl;
	cout << "6: Remove a specific student from a course" << endl;
	cout << "7: Add a specific student to a course" << endl;
	cout << "8: View list of courses in the current semester" << endl;
	cout << "9: View list of students of a course" << endl;
	cout << "10: View attendance list of a course" << endl;
	cout << "11: Create/update/delete/view all lecturers" << endl;
	cout << "12: Back" << endl;
	int s;
	cout << "Let's choose request you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		course1menu(lcr, i, cr, crr);
		break;

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
	}
	case 2:
	{
		system("cls");
		if (semester(cr, lcr, crr)) cout << "Import Successfull" << endl;
		else cout << "Can't load data" << endl;

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 3:
	{
		system("cls");
		char a[200];
		listcr lcr;
		loadCourse("Course.csv", lcr, a);
		addnewcourse(lcr);
		saveCourse("Course.csv", lcr, a);
		if (importcourse(lcr, a))
			cout << "Manually add a new course Successfull" << endl;

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 4:
	{
		system("cls");
		listcr lcr;
		char a[200];
		char ID[20];
		char Class[10];
		char Date[10];
		int h, m;
		cout << "Input the Course ID of the Course: ";
		cin >> ID;
		cout << "Input the Class of the Course: ";
		cin >> Class;
		cout << "Input the Date of the Course: ";
		cin >> Date;
		cout << "Input the Start Hour:Minute" << endl;
		cout << "Input Hour: ";
		cin >> h;
		cout << "Input Minute: ";
		cin >> m;
		loadCourse("Course.csv", lcr, a);
		int tt = editCourses(lcr, ID, Class, Date, h, m);
		saveCourse("Course.csv", lcr, a);
		int ttt = importcourse(lcr, a);
		if (tt == true && ttt == true)  cout << "Edit an existing course Successfull" << endl;

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 5:
	{
		system("cls");
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		removecourse(lcr);
		//saveCourse("Course.csv", lcr, a);
		importcourse(lcr, a);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 6:
	{
		system("cls");
		listcr lcr;
		listst lst;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		check1(lcr, lst);
		loadCourse("Course.csv", lcr, a);
		removestcrreal(lcr);
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 7:
	{
		system("cls");
		listcr lcr;
		listst lst;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		addstcr(lcr);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 8:
	{
		system("cls");
		listcr lcr;
		listst lst;
		char a[200];
		viewpro8(lcr);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 9:
	{
		system("cls");
		listcr lcr;
		listst lst;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		viewpro9(lcr);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 10:
	{
		system("cls");
		listcr lcr;
		listst lst;
		listat lat;
		listat1 lat1;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		viewatten(lat, lcr, lat1);

		cout << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 11:
	{
		system("cls");
		listlt llt;
		menulecture(llt);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			coursemenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	}
	case 12:
	{
		staffmenu();
		break;
	}
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		coursemenu();
		break;
	}
	}

}
void classmenu(listallst &last, listst *&lst, listallstsave &lasts)
{
	int i = 0;
	cout << "__CLASS__" << endl;
	cout << "1: Import students of a class" << endl;
	cout << "2: Add a new student" << endl;
	cout << "3: Edit an exitsing student" << endl;
	cout << "4: Remove astudent" << endl;
	cout << "5: Change student of a classes" << endl;
	cout << "6: View list of classes & View list of student in a class" << endl;
	cout << "7: Back" << endl;
	int s;
	char savest[100];
	char savepw[100];
	char import[100];
	cout << "Let's choose request you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		cout << "Import student of a class from a csv file" << endl;
		outputClass(last);
		int n = listn();
		importClass(last, lst[n + 1], lasts);

		cout << "Import student of a class from a csv file successfull" << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			classmenu(last, lst, lasts);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 2:
	{
		char a[100];
		outputClass(last);
		cout << "Choose class: ";
		cin >> i;
		addnewstudent(lst[i], i);
		cout << "Choose save class (suggest: 18CLC" << i << "Student.csv): ";
		cin >> a;
		for (nodeallstsave * p = lasts.head; p != NULL; p = p->next)
		{
			if (strcmp(p->data.savename, a) == 0)
			{
				saveStudent(p, lst[i]);
				break;
			}
		}
		cout << "Add new student successfull" << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			classmenu(last, lst, lasts);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 3:
	{
		char ID[100];
		char a[30];
		cout << "Edit an existing student" << endl;
		cout << "Input the student ID of the student: ";
		cin >> ID;
		for (int i = 0; i < listn(); i++)
		{
			if (editstudent(lst[i], ID))
			{
				cout << "Choose save class (suggest: 18CLC" << i << "SaveStudent.csv): ";
				cin >> a;
				for (nodeallstsave * p = lasts.head; p != NULL; p = p->next)
				{
					if (strcmp(p->data.savename, a) == 0)
					{
						saveStudent(p, lst[i]);
						break;
					}
				}
			}
		}
		cout << "Edit an exitsing student successfull" << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			classmenu(last, lst, lasts);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 4:
	{
		cout << "Remove a student" << endl;
		moveStudent(lst, lasts);
		cout << "Remove a student successfull" << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			classmenu(last, lst, lasts);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 5:
	{
		int a;
		int b;
		cout << "Change students from class A to class B" << endl;
		changeStudent(lst, last, lasts, a, b);
		cout << "Change students from class " << a << " to class " << b << " successfull" << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			classmenu(last, lst, lasts);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 6:
	{
		char a[10];
		viewClassandList(last, lst);
		cout << "Do you want to continue with another function??? (yes/no): ";
		cin >> a;
		cout << "Open the class list successfull !!!" << endl;
		if (strcmp(a, "yes") == 0)
		{
			system("cls");
			classmenu(last, lst, lasts);
		}

		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 7:
	{
		system("cls");
		staffmenu();
		break;
	};
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		classmenu(last, lst, lasts);
		break;
	}
	}
}
bool loadscore(const char *file, listsb &lsb, char a[])
{
	ifstream fin;
	fin.open(file);
	if (fin.fail())
		return false;
	score sc;
	fin.getline(a, 200, '\n');
	init(lsb);
	while (fin >> sc.ID)
	{
		fin.ignore();
		fin >> sc.midterm;
		fin.ignore();
		fin >> sc.final;
		fin.ignore();
		fin >> sc.lab;
		fin.ignore();
		fin >> sc.bonus;
		nodesb *p = createNode(sc);
		insertTail(lsb, p);
	}
	fin.close();
	return true;
}
bool savescore(const char *file, listsb &lsb)
{
	ofstream fout;
	fout.open(file);
	if (fout.fail())
		return false;
	fout << "Student ID,Midterm,Final,Lab,Bonus" << endl;
	for (nodesb *p = lsb.head; p != NULL; p = p->next)
	{
		fout << p->data.ID << "," << p->data.midterm << "," << p->data.final << "," << p->data.lab << "," << p->data.bonus << endl;
	}
	fout.close();
	return true;
}
void scoreboard(listcr &lcr, listsb &lsb)
{
	char ID[20];
	char cla[20];
	int flag = 0;
	char b[200];
	do
	{
		cout << "Enter the Course ID of the course you want to remove a student: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				strcat(a, cr->data.classn);
				strcat(a, "-");
				strcat(a, cr->data.id);
				strcat(a, "-");
				strcat(a, "score");
				strcat(a, ".csv");

				if (loadscore(a, lsb, b))
				{
					char an[4];
					cout << "Seach scoreboard of a course successfull" << endl;
					cout << "You want to view scoreboard of a course (yes/no): ";
					cin >> an;
					if (strcmp(an, "yes") == 0)
					{
						cout << "Student ID , Midterm , Final , Lab , Bonus" << endl;
						for (nodesb *p = lsb.head; p != NULL; p = p->next)
						{
							cout << p->data.ID << " , " << p->data.midterm << " , " << p->data.final << " , " << p->data.lab << " , " << p->data.bonus << endl;
						}
						return;
					}
					else return;
				}

			}
		}
	} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
}
void saveascore(listsb &lsb, listcr &lcr)
{
	char ID[20];
	char cla[20];
	int flag = 0;
	char b[200];
	do
	{
		cout << "Enter the Course ID of the course you want to export a scoreboard to a csv file: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				strcat(a, cr->data.classn);
				strcat(a, "-");
				strcat(a, cr->data.id);
				strcat(a, "-");
				strcat(a, "score");
				strcat(a, ".csv");

				int h = loadscore(a, lsb, b);
				if (h)
				{
					h = savescore(a, lsb);
					if (h)
					{
						cout << "Export a scoreboard to a csv file successfull" << endl;
						return;
					}
				}
				else
				{
					cout << "Can't not export a scoreboard to a csv file" << endl;
					return;
				}
			}
		}
	} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
}
void scoremenu()
{
	cout << "1: Search and view scoreboard of a course" << endl;
	cout << "2: Export a scoreboard to a csv file" << endl;
	cout << "3: Back" << endl;
	int s;
	cout << "Let's choose the function you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		listcr lcr;
		listsb lsb;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		scoreboard(lcr, lsb);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			scoremenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 2:
	{
		system("cls");
		listsb lsb;
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		saveascore(lsb, lcr);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			scoremenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 3:
	{
		system("cls");
		staffmenu();
		break;
	};
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		scoremenu();
	}
	}
}
void seachviewatten(listat &lat, listcr &lcr, listat1 &lat1)
{
	{
		char ID[100];
		char cla[10];
		int check = 0;
		int flag = 0;
		do
		{
			cout << "Enter the Course ID of the course you want view attendance list of a course: ";
			cin >> ID;
			cout << "Enter the class of the course: ";
			cin >> cla;
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				int str = strlen(ID);
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
				{
					flag = 1;
					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					strcat(a, cla);
					char to[2] = "-";
					strcat(a, to);
					char csv[5] = ".csv";
					strcat(a, cr->data.id);
					strcat(a, csv);
					char b[200];
					if (ID[str - 1] == 'h' && ID[str - 2] == 't')
					{
						int zz = loadatprac(a, lat1, b);
						if (zz)
						{
							char an[4];
							cout << "Search attendance list of a course successfull" << endl << endl;
							cout << "Do you want to view attendance list of a course? (yes/no): ";
							cin >> an;
							if (strcmp(an, "yes") == 0)
							{
								cout << "Practice(0:absent, 1: present)" << endl;
								cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10" << endl;
								for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
								{
									cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10;
								}
								return;
							}
							else
							{
								cout << "Good bye, See you again !!!" << endl;
								return;
							}
						}
					}
					else
					{
						loadattheory(a, lat, b);
						cout << "Practice(0:absent, 1: present)" << endl;
						cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;
						for (nodeat *t = lat.head; t != NULL; t = t->next)
						{
							cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << "  " << t->data.w11;
						}
						return;
					}
				}
			}
		} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
	}
}
void saveaatten(listat &lat, listcr &lcr, listat1 &lat1)
{
	{
		char ID[100];
		char cla[10];
		int check = 0;
		int flag = 0;
		do
		{
			cout << "Enter the Course ID of the course you want view attendance list of a course: ";
			cin >> ID;
			cout << "Enter the class of the course: ";
			cin >> cla;
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				int str = strlen(ID);
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
				{
					flag = 1;
					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					strcat(a, cla);
					char to[2] = "-";
					strcat(a, to);
					char csv[5] = ".csv";
					strcat(a, cr->data.id);
					strcat(a, csv);
					char b[200];
					if (ID[str - 1] == 'h' && ID[str - 2] == 't')
					{
						int zz = loadatprac(a, lat1, b);
						if (zz)
						{
							zz = saveatprac(a, lat1, b);
							if (zz)
							{
								cout << "Export a attendance list to a csv file successfull" << endl;
								return;
							}
						}
						else
						{
							cout << "Thank you, See you again !!!" << endl;
							return;
						}
					}
					else
					{
						int zz = loadattheory(a, lat, b);
						if (zz)
						{
							zz = saveattheory(a, lat, b);
							if (zz)
							{
								cout << "Export a attendance list to a csv file successfull" << endl;
								return;
							}
						}
						else
						{
							cout << "Thank you, See you again !!!" << endl;
							return;
						}

					}
				}
			}
		} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
	}
}
void attenmenu()
{
	cout << "1: Search and view attendance list of a course" << endl;
	cout << "2: Export a attendance list to a csv file" << endl;
	cout << "3: Back" << endl;
	int s;
	cout << "Let's choose the function you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		listcr lcr;
		listat lat;
		listat1 lat1;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		seachviewatten(lat, lcr, lat1);

		cout << endl;
		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			attenmenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 2:
	{
		system("cls");
		listat lat;
		listat1 lat1;
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		saveaatten(lat, lcr, lat1);

		char y[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			attenmenu();
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 3:
	{
		system("cls");
		staffmenu();
		break;
	};
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		attenmenu();
	}
	}
}
void staffmenu()
{
	int size = listn();
	listst*lst = new listst[size];
	for (int i = 0; i < size; i++)
	{
		init(lst[i]);
	}
	listallst last;
	listallstsave lasts;
	int h = loadall(lst, last, lasts);
	cout << "Staffmenu: " << endl;
	cout << "1: Class" << endl;
	cout << "2: Course" << endl;
	cout << "3: Scoreboard" << endl;
	cout << "4: Attendance List" << endl;
	cout << "5: Logout" << endl;
	int s;
	cout << "Let's choose the function you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		classmenu(last, lst, lasts);
		break;
	};
	case 2:
	{
		system("cls");
		coursemenu();
		break;
	};
	case 3:
	{
		system("cls");
		scoremenu();
		break;
	};
	case 4:
	{
		system("cls");
		attenmenu();
		break;
	};
	case 5:
	{
		char y[10];
		cout << "Do you sure want to logout ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "                                       _____THANK YOU_____" << endl;
			cout << "                                       ___SEE YOU AGAIN___" << endl;
			Sleep(2000);
			system("cls");
			menu();
		}
		else
		{
			staffmenu();
		}
		break;
	};
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		system("cls");
		staffmenu();
	}
	}
}
void lecte1(char y[], listcr lcr)
{
	char a[200];
	int k = strlen(y);
	int no = 1;
	string h = abc();
	string k1 = "2018-09-01";
	string k1l = "2018-11-30";
	string k2 = "2019-01-01";
	string k2l = "2019-04-30";
	int check = 0;
	int flag = 0;
	if (h > k1 && h < k1l)
	{
		cout << "\n	The current semester is the first semester" << endl << endl;
		cout << "                                       __List of courses in the first semester__" << endl << endl;
		check = 1;
	}
	else if (h > k2 && h < k2l)
	{
		cout << "\n	The current semester is the second semester" << endl << endl;
		cout << "                                       __List of courses in the second semester__" << endl << endl;
		check = 2;
	}
	else
	{
		cout << "\n	The current semester is the 3rd semester" << endl << endl;
		cout << "                                       __List of courses in the 3rd semester__" << endl << endl;
		check = 3;
	}
	cout << "\n|No|Course ID|Course Name|Class|LecturerAccount|Start Date|End Date|Day of Week|Start Hour:Minute|End Hour:Minute|Room|" << endl;
	for (nodecr *p = lcr.head; p != NULL; p = p->next)
	{
		int n = strlen(p->data.lecture);
		if (check == 1)
		{
			if (k <= n)
			{
				if (strcmp(p->data.lecture, y) == 0 || strstr(p->data.lecture, y) != NULL)
				{
					if (p->data.start.day > 1 && p->data.start.month == 9 && p->data.start.year == 2018 && p->data.end.day < 30 && p->data.end.month == 11 && p->data.end.year == 2018)
					{
						flag = 1;
						course cr = p->data;
						if (cr.no < 0) break;
						cout << "|" << no << "|" << cr.id << "|" << cr.name << "|" << cr.classn << "|" << cr.lecture << "|" << cr.start.day << "/" << cr.start.month << "/" << cr.start.year << '|' << cr.end.day << "/" << cr.end.month << "/" << cr.end.year << '|' << cr.day << '|' << cr.start1.hour << ':' << cr.start1.minute << '|' << cr.end1.hour << ':' << cr.end1.minute << '|' << cr.room << "|" << endl;
						no++;
					}
				}
			}
		}
		else if (check == 2)
		{
			if (k <= n)
			{
				if (strcmp(p->data.lecture, y) == 0 || strstr(p->data.lecture, y) != NULL)
				{
					if (p->data.start.day > 1 && p->data.start.month == 1 && p->data.start.year == 2019 && p->data.end.day < 30 && p->data.end.month == 4 && p->data.end.year == 2019)
					{
						flag = 1;
						course cr = p->data;
						if (cr.no < 0) break;
						cout << "|" << no << "|" << cr.id << "|" << cr.name << "|" << cr.classn << "|" << cr.lecture << "|" << cr.start.day << "/" << cr.start.month << "/" << cr.start.year << '|' << cr.end.day << "/" << cr.end.month << "/" << cr.end.year << '|' << cr.day << '|' << cr.start1.hour << ':' << cr.start1.minute << '|' << cr.end1.hour << ':' << cr.end1.minute << '|' << cr.room << "|" << endl;
						no++;
					}
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << "\n\n\n\n         ___________________Opps, Sorry!!! Teachers do not teach any subject this term______________________" << endl;
		return;
	}
}
void viewlecte2(listcr &lcr, char y[])
{
	char ID[100];
	char cla[10];
	int check = 0;
	int flag = 0;
	int k = strlen(y);
	listst lst;
	do
	{
		cout << "Enter the Course ID of the course you want view student list of a course: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			int n = strlen(cr->data.lecture);
			if (k <= n)
			{
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0 && (strcmp(cr->data.lecture, y) == 0 || strstr(cr->data.lecture, y) != NULL))
				{
					cout << "\n                   ____________Student list of subjects " << cr->data.name << "____________" << endl << endl;
					flag = 1;
					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					char to[4] = " - ";
					char csv[5] = ".csv";
					strcat(a, cr->data.name);
					strcat(a, to);
					strcat(a, cla);
					strcat(a, csv);
					loadStudentcheck(a, lst);
					cout << "  No  |  StudentID  |       Name       |     Sex    |            Birthday" << endl;
					for (nodest *p = lst.head; p != NULL; p = p->next)
						cout << "   " << p->data.no << "   |   " << p->data.id << "   |   " << p->data.lastname << " " << p->data.firstname << "   |   " << p->data.sex << "   |    " << p->data.birth.day << "/" << p->data.birth.month << "/" << p->data.birth.year << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					return;
				}
			}
		}
	} while (flag == 0 && cout << "Teachers don't teach this class, please repeat" << endl);
}
void lecte3(char y[], listcr lcr)
{
	listat lat;
	listat1 lat1;
	char a[200];
	int no = 1;
	char ID[20];
	char cla[10];
	int flag = 0;
	int k = strlen(y);
	do
	{
		cout << "Enter the Course ID of the course you want view attendance list of a course: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		int str = strlen(ID);
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			int n = strlen(cr->data.lecture);
			if (k <= n)
			{
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0 && (strcmp(cr->data.lecture, y) == 0 || strstr(cr->data.lecture, y) != NULL))
				{
					cout << "\n                       ____________Attendance list of subjects " << cr->data.name << "____________" << endl;
					flag = 1;

					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					strcat(a, cla);
					char to[2] = "-";
					strcat(a, to);
					char csv[5] = ".csv";
					strcat(a, cr->data.id);
					strcat(a, csv);
					char b[200];
					if (ID[str - 1] == 'h' && ID[str - 2] == 't')
					{
						loadatprac(a, lat1, b);
						cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
						cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10" << endl;
						for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
						{
							cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << endl;
						}
						return;
					}
					else
					{
						loadattheory(a, lat, b);
						cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
						cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;
						for (nodeat *t = lat.head; t != NULL; t = t->next)
						{
							cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << "  " << t->data.w11 << endl;
						}
						return;
					}
				}
			}
		}
	} while (flag == 0 && cout << "Teachers don't teach this class, please repeat" << endl);
	return;
}
void lecte4(char y[], listcr lcr)
{
	{
		listat lat;
		listat1 lat1;
		char a[200];
		int no = 1;
		char ID[20];
		char cla[10];
		int flag = 0;
		char SID[20];
		int flagcheck = 0;
		int k = strlen(y);
		do
		{
			cout << "Enter the Course ID of the course you want edit an attendance: ";
			cin >> ID;
			cout << "Enter the class of the course: ";
			cin >> cla;
			int str = strlen(ID);
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				int n = strlen(cr->data.lecture);
				if (k <= n)
				{
					if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0 && (strcmp(cr->data.lecture, y) == 0 || strstr(cr->data.lecture, y) != NULL))
					{
						cout << "\n                       ____________Attendance list of subjects " << cr->data.name << "____________" << endl;
						flag = 1;

						char a[100] = "2018 - 2019/Semester";
						if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
						{
							char smt[4] = " 1/";
							strcat(a, smt);
						}
						else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
						{
							char smt[4] = " 2/";
							strcat(a, smt);
						}
						else
						{
							char smt[4] = " 3/";
							strcat(a, smt);
						}
						strcat(a, cla);
						char to[2] = "-";
						strcat(a, to);
						char csv[5] = ".csv";
						strcat(a, cr->data.id);
						strcat(a, csv);
						char b[200];
						if (ID[str - 1] == 'h' && ID[str - 2] == 't')
						{
							loadatprac(a, lat1, b);
							cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
							cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10" << endl;
							for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
							{
								cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << endl;
							}

							do
							{
								cout << "Enter the student ID to edit: ";
								cin >> SID;

								for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
								{
									if (strcmp(t->data.id, SID) == 0)
									{
										flagcheck = 1;
										cout << "Attendance sheet for this " << t->data.id << "" << endl;
										cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << endl;
										do
										{
											cout << "Edit (Please enter 0:absent, 1: present)" << endl;
											cout << "Week 01: ";
											cin >> t->data.w1;
											cout << "Week 02: ";
											cin >> t->data.w2;
											cout << "Week 03: ";
											cin >> t->data.w3;
											cout << "Week 04: ";
											cin >> t->data.w4;
											cout << "Week 05: ";
											cin >> t->data.w5;
											cout << "Week 06: ";
											cin >> t->data.w6;
											cout << "Week 07: ";
											cin >> t->data.w7;
											cout << "Week 08: ";
											cin >> t->data.w8;
											cout << "Week 09: ";
											cin >> t->data.w9;
											cout << "Week 10: ";
											cin >> t->data.w10;
										} while ((t->data.w1 != 0 && t->data.w1 != 1) && (t->data.w2 != 0 && t->data.w2 != 1) && (t->data.w3 != 0 && t->data.w3 != 1) && (t->data.w4 != 0 && t->data.w4 != 1) && (t->data.w5 != 0 && t->data.w5 != 1) && (t->data.w6 != 0 && t->data.w6 != 1) && (t->data.w7 != 0 && t->data.w7 != 1) && (t->data.w8 != 0 && t->data.w8 != 1) && (t->data.w9 != 0 && t->data.w9 != 1) && (t->data.w10 != 0 && t->data.w10 != 1) && cout << "Please, Enter 0:absent, 1: present" << endl);
										int qq = saveatprac(a, lat1, b);
										if (qq) cout << "Edit an attendance successfull" << endl;
										else cout << "Don't edit an attendance sucessfull" << endl;
										return;
									}
								}
							} while (flagcheck == 0 && cout << "Student not found, please re-enter !!!" << endl);
						}
						else
						{
							cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
							cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week 11" << endl;
							loadattheory(a, lat, b);
							for (nodeat *t = lat.head; t != NULL; t = t->next)
							{
								cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << "  " << t->data.w11 << endl;
							}

							do
							{
								cout << "\nEnter the student ID to edit: ";
								cin >> SID;
								for (nodeat *t = lat.head; t != NULL; t = t->next)
								{
									if (strcmp(t->data.id, SID) == 0)
									{
										cout << "\nAttendance sheet for this " << t->data.id << "" << endl;
										cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << "  " << t->data.w11 << endl;;
										do
										{
											cout << "Edit (Please enter 0:absent, 1: present)" << endl;
											cout << "Week 01: ";
											cin >> t->data.w1;
											cout << "Week 02: ";
											cin >> t->data.w2;
											cout << "Week 03: ";
											cin >> t->data.w3;
											cout << "Week 04: ";
											cin >> t->data.w4;
											cout << "Week 05: ";
											cin >> t->data.w5;
											cout << "Week 06: ";
											cin >> t->data.w6;
											cout << "Week 07: ";
											cin >> t->data.w7;
											cout << "Week 08: ";
											cin >> t->data.w8;
											cout << "Week 09: ";
											cin >> t->data.w9;
											cout << "Week 10: ";
											cin >> t->data.w10;
											cout << "Week 11: ";
											cin >> t->data.w11;
										} while ((t->data.w1 != 0 && t->data.w1 != 1) && (t->data.w2 != 0 && t->data.w2 != 1) && (t->data.w3 != 0 && t->data.w3 != 1) && (t->data.w4 != 0 && t->data.w4 != 1) && (t->data.w5 != 0 && t->data.w5 != 1) && (t->data.w6 != 0 && t->data.w6 != 1) && (t->data.w7 != 0 && t->data.w7 != 1) && (t->data.w8 != 0 && t->data.w8 != 1) && (t->data.w9 != 0 && t->data.w9 != 1) && (t->data.w10 != 0 && t->data.w10 != 1) && (t->data.w11 != 0 && t->data.w11 != 1) && cout << "Please, Enter 0:absent, 1: present" << endl);
										int qq = saveattheory(a, lat, b);
										if (qq) cout << "Edit an attendance successfull" << endl;
										else cout << "Don't edit an attendance sucessfull" << endl;
										return;
									}
								}
							} while (flagcheck == 0 && cout << "Student not found, please re-enter !!!" << endl);
						}
					}
				}
			}
		} while (flag == 0 && cout << "Teachers don't teach this class, please repeat" << endl);
		return;
	}
}
void lecte5(char y[], listcr &lcr, listsb &lsb)
{
	char ID[20];
	char cla[20];
	int flag = 0;
	char b[200];
	do
	{
		cout << "Enter the Course ID of the course you want import scoreboard from a csv file: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0 && (strcmp(cr->data.lecture, y) == 0 || strstr(cr->data.lecture, y) != NULL))
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				strcat(a, cr->data.classn);
				strcat(a, "-");
				int str = strlen(ID);
				if (ID[str - 1] == 'h' && ID[str - 2] == 't')
				{
					char *z = strtok(ID, "th");
					strcat(a, z);
				}
				else
				{
					strcat(a, ID);
				}
				strcat(a, "-");
				strcat(a, "score");
				strcat(a, ".csv");

				if (loadscore(a, lsb, b))
				{
					cout << "Import scoreboard of a course from a csv file successfull" << endl;
					return;
				}
				else cout << "Can't import scoreboard of a course from a csv file" << endl;
			}
		}
	} while (flag == 0 && cout << "Teacher don't teach this subject, Please input again!!" << endl);
}
void lecte6(char y[], listcr &lcr, listsb &lsb)
{
	char ID[20];
	char cla[20];
	int flag = 0;
	char b[200];
	do
	{
		cout << "Enter the Course ID of the course you want edit grade: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0 && (strcmp(cr->data.lecture, y) == 0 || strstr(cr->data.lecture, y) != NULL))
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				strcat(a, cr->data.classn);
				strcat(a, "-");
				int str = strlen(ID);
				if (ID[str - 1] == 'h' && ID[str - 2] == 't')
				{
					char *z = strtok(ID, "th");
					strcat(a, z);
				}
				else
				{
					strcat(a, ID);
				}
				strcat(a, "-");
				strcat(a, "score");
				strcat(a, ".csv");
				int stu;
				int checkcheck = 0;
				if (loadscore(a, lsb, b))
				{
					do
					{
						cout << "\n        ____Scoreboard subject " << ID << " of class " << cla << "____" << endl << endl;
						cout << "Student ID,Midterm,Final,Lab,Bonus" << endl;
						for (nodesb *sb = lsb.head; sb != NULL; sb = sb->next)
						{
							cout << " " << sb->data.ID << "," << sb->data.midterm << "," << sb->data.final << "," << sb->data.lab << "," << sb->data.bonus << endl;
						}
						cout << "\nEnter StudentID you want to edit grade: ";
						cin >> stu;
						for (nodesb *sb = lsb.head; sb != NULL; sb = sb->next)
						{
							if (sb->data.ID == stu)
							{
								checkcheck = 1;
								cout << "\n____Edit grade student " << sb->data.ID << "____" << endl;
								do
								{
									cout << "Enter score Midterm: ";
									cin >> sb->data.midterm;
								} while (sb->data.midterm < 0 || sb->data.midterm > 10);
								do
								{
									cout << "Enter score Final: ";
									cin >> sb->data.final;
								} while (sb->data.final < 0 || sb->data.final > 10);
								do
								{
									cout << "Enter score Lab: ";
									cin >> sb->data.lab;
								} while (sb->data.lab < 0 || sb->data.lab > 10);
								do
								{
									cout << "Enter score Bonus: ";
									cin >> sb->data.bonus;
								} while (sb->data.bonus < 0 || sb->data.bonus > 10);
								break;
							}
						}
					} while (checkcheck == 0 && cout << "Don't found StudentID of class " << cla << "" << endl);
					if (savescore(a, lsb))
					{
						cout << "Edit grade student " << stu << " successfull" << endl;
					}
					else cout << "Can't edit grade student " << stu << "" << endl;
					return;
				}
				else cout << "Can't found scoreboard of a course from a csv file" << endl;
			}
		}
	} while (flag == 0 && cout << "Teacher don't teach this subject, Please input again!!" << endl);
}
void lecte7(char y[], listcr &lcr, listsb &lsb)
{
	char ID[20];
	char cla[20];
	int flag = 0;
	char b[200];
	do
	{
		cout << "Enter the Course ID of the course you want import scoreboard from a csv file: ";
		cin >> ID;
		cout << "Enter the class of the course: ";
		cin >> cla;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0 && (strcmp(cr->data.lecture, y) == 0 || strstr(cr->data.lecture, y) != NULL))
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				strcat(a, cr->data.classn);
				strcat(a, "-");
				int str = strlen(ID);
				if (ID[str - 1] == 'h' && ID[str - 2] == 't')
				{
					char *z = strtok(ID, "th");
					strcat(a, z);
				}
				else
				{
					strcat(a, ID);
				}
				strcat(a, "-");
				strcat(a, "score");
				strcat(a, ".csv");

				if (loadscore(a, lsb, b))
				{
					cout << "\n        ____Scoreboard subject " << ID << " of class " << cla << "____" << endl << endl;
					cout << "Student ID,Midterm,Final,Lab,Bonus" << endl;
					for (nodesb *sb = lsb.head; sb != NULL; sb = sb->next)
					{
						cout << "  " << sb->data.ID << "  ,  " << sb->data.midterm << "  ,  " << sb->data.final << "  ,  " << sb->data.lab << "  ,  " << sb->data.bonus << endl;
					}
					return;
				}
				else cout << "Can't import scoreboard of a course from a csv file" << endl;
			}
		}
	} while (flag == 0 && cout << "Teacher don't teach this subject, Please input again!!" << endl);
}
void lecturermenu(char y[])
{
	cout << "_________Lecturer_________" << endl;
	cout << "1: View list of courses in the current semester" << endl;
	cout << "2: View list of students of a course" << endl;
	cout << "3: View attendance list of a course" << endl;
	cout << "4: Edit an attendance" << endl;
	cout << "5: Import scoreboard of a course from a csv file" << endl;
	cout << "6: Edit grade of a student" << endl;
	cout << "7: View a scoreboard" << endl;
	cout << "8: Logout" << endl;
	int s;
	cout << "Let's choose the function you want: ";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		system("cls");
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		lecte1(y, lcr);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 2:
	{
		system("cls");
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		viewlecte2(lcr, y);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 3:
	{
		system("cls");
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		lecte3(y, lcr);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 4:
	{
		system("cls");
		listcr lcr;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		lecte4(y, lcr);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 5:
	{
		system("cls");
		listcr lcr;
		listsb lsb;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		lecte5(y, lcr, lsb);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 6:
	{
		system("cls");
		listcr lcr;
		listsb lsb;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		lecte6(y, lcr, lsb);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 7:
	{
		system("cls");
		listcr lcr;
		listsb lsb;
		char a[200];
		loadCourse("Course.csv", lcr, a);
		lecte7(y, lcr, lsb);

		cout << endl << endl;
		char kkk[10];
		cout << "Do you want to continue ??? (yes/no): ";
		cin >> kkk;
		if (strcmp(kkk, "yes") == 0)
		{
			system("cls");
			lecturermenu(y);
		}
		else
		{
			cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
			_getch();
			exit(0);
		}
		break;
	};
	case 8:
	{
		char y[10];
		cout << "Do you sure want to logout ??? (yes/no): ";
		cin >> y;
		if (strcmp(y, "yes") == 0)
		{
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "                                              _____THANK YOU_____" << endl;
			cout << "                                              ___SEE YOU AGAIN___" << endl;
			Sleep(2000);
			system("cls");
			menu();
		}
		break;
	};
	default:
	{
		system("cls");
		cout << "Incorrect,please enter again! " << endl;
		lecturermenu(y);
	}
	}
}
void checkin(char y[], listcr &lcr, int &cur)
{
	{
		listat lat;
		listat1 lat1;
		listallst last;
		char a[200];
		int no = 1;
		char ID[20];
		int flag = 0;
		char SID[20];
		int flagcheck = 0;
		int k = strlen(y);
		loadAllStudent(last);
		int i = 0;
		char *cla = new char;
		for (nodeallst *lt = last.head; lt != NULL; lt = lt->next)
		{
			if (i == cur)
			{
				cla = strtok(lt->data.name, "S");
				break;
			}
			i++;
		}
		do
		{
			cout << "Enter the Course ID of the course that student " << y << " want to check-in: ";
			cin >> ID;
			int str = strlen(ID);
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
				{
					cout << "\n           ____________Attendance list of subjects " << cr->data.name << "____________" << endl;
					flag = 1;

					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					strcat(a, cla);
					char to[2] = "-";
					strcat(a, to);
					char csv[5] = ".csv";
					strcat(a, cr->data.id);
					strcat(a, csv);
					char b[200];
					if (ID[str - 1] == 'h' && ID[str - 2] == 't')
					{
						loadatprac(a, lat1, b);
						do
						{
							for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
							{
								if (strcmp(t->data.id, y) == 0)
								{
									flagcheck = 1;
									cout << "             ___________________Attendance sheet for this student " << t->data.id << "___________________" << endl;
									cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
									cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10" << endl;
									cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << endl << endl;

									int s = 0;
									do
									{
										cout << "Enter the week you want to check-in: ";
										cin >> s;
									} while (s < 0 || s>10);
									cout << "Check-in (Please enter 0:absent, 1: present)" << endl << endl;
									switch (s)
									{
									case 1:
									{
										do
										{
											cout << "Week 01: ";
											cin >> t->data.w1;
										} while (t->data.w1 < 0 || t->data.w1 > 1);
										break;
									}
									case 2:
									{
										do
										{
											cout << "Week 02: ";
											cin >> t->data.w2;
										} while (t->data.w2 < 0 || t->data.w2 > 1);
										break;
									}
									case 3:
									{
										do
										{
											cout << "Week 03: ";
											cin >> t->data.w3;
										} while (t->data.w3 < 0 || t->data.w3 > 1);
										break;
									}
									case 4:
									{
										do
										{
											cout << "Week 04: ";
											cin >> t->data.w4;
										} while (t->data.w4 < 0 || t->data.w4 > 1);
										break;
									}
									case 5:
									{
										do
										{
											cout << "Week 05: ";
											cin >> t->data.w5;
										} while (t->data.w5 < 0 || t->data.w5 > 1);
										break;
									}
									case 6:
									{
										do
										{
											cout << "Week 06: ";
											cin >> t->data.w6;
										} while (t->data.w6 < 0 || t->data.w6 > 1);
										break;
									}
									case 7:
									{
										do
										{
											cout << "Week 07: ";
											cin >> t->data.w7;
										} while (t->data.w7 < 0 || t->data.w7 > 1);
										break;
									}
									case 8:
									{
										do
										{
											cout << "Week 08: ";
											cin >> t->data.w8;
										} while (t->data.w8 < 0 || t->data.w8 > 1);
										break;
									}
									case 9:
									{
										do
										{
											cout << "Week 09: ";
											cin >> t->data.w9;
										} while (t->data.w9 < 0 || t->data.w9 > 1);
										break;
									}
									case 10:
									{
										do
										{
											cout << "Week 10: ";
											cin >> t->data.w10;
										} while (t->data.w10 < 0 || t->data.w10 > 1);
										break;
									}
									}
									int qq = saveatprac(a, lat1, b);
									if (qq) cout << "\nEdit an attendance successfull" << endl;
									else cout << "\nDon't edit an attendance sucessfull" << endl;
									return;
								}
							}
						} while (flagcheck == 0 && cout << "Student not found, please re-enter !!!" << endl);
					}
					else
					{
						loadattheory(a, lat, b);
						do
						{
							for (nodeat *t = lat.head; t != NULL; t = t->next)
							{
								if (strcmp(t->data.id, y) == 0)
								{
									flagcheck = 1;
									cout << "             ___________________Attendance sheet for this student " << t->data.id << "___________________" << endl;
									cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
									cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week11" << endl;
									cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << "  " << t->data.w11 << endl << endl;

									int s = 0;
									do
									{
										cout << "Enter the week you want to check-in: ";
										cin >> s;
									} while (s < 0 || s>11);
									cout << "\nCheck-in (Please enter 0:absent, 1: present)" << endl;
									switch (s)
									{
									case 1:
									{
										do
										{
											cout << "Week 01: ";
											cin >> t->data.w1;
										} while (t->data.w1 < 0 || t->data.w1 > 1);
										break;
									}
									case 2:
									{
										do
										{
											cout << "Week 02: ";
											cin >> t->data.w2;
										} while (t->data.w2 < 0 || t->data.w2 > 1);
										break;
									}
									case 3:
									{
										do
										{
											cout << "Week 03: ";
											cin >> t->data.w3;
										} while (t->data.w3 < 0 || t->data.w3 > 1);
										break;
									}
									case 4:
									{
										do
										{
											cout << "Week 04: ";
											cin >> t->data.w4;
										} while (t->data.w4 < 0 || t->data.w4 > 1);
										break;
									}
									case 5:
									{
										do
										{
											cout << "Week 05: ";
											cin >> t->data.w5;
										} while (t->data.w5 < 0 || t->data.w5 > 1);
										break;
									}
									case 6:
									{
										do
										{
											cout << "Week 06: ";
											cin >> t->data.w6;
										} while (t->data.w6 < 0 || t->data.w6 > 1);
										break;
									}
									case 7:
									{
										do
										{
											cout << "Week 07: ";
											cin >> t->data.w7;
										} while (t->data.w7 < 0 || t->data.w7 > 1);
										break;
									}
									case 8:
									{
										do
										{
											cout << "Week 08: ";
											cin >> t->data.w8;
										} while (t->data.w8 < 0 || t->data.w8 > 1);
										break;
									}
									case 9:
									{
										do
										{
											cout << "Week 09: ";
											cin >> t->data.w9;
										} while (t->data.w9 < 0 || t->data.w9 > 1);
										break;
									}
									case 10:
									{
										do
										{
											cout << "Week 10: ";
											cin >> t->data.w10;
										} while (t->data.w10 < 0 || t->data.w10 > 1);
										break;
									}
									case 11:
									{
										do
										{
											cout << "Week 11: ";
											cin >> t->data.w11;
										} while (t->data.w11 < 0 || t->data.w11 > 1);
										break;
									}
									}
									int qq = saveattheory(a, lat, b);
									if (qq) cout << "\nEdit an attendance successfull" << endl;
									else cout << "\nDon't edit an attendance sucessfull" << endl;
									return;
								}
							}
						} while (flagcheck == 0 && cout << "Student not found, please re-enter !!!" << endl);
					}
				}
			}
		} while (flag == 0 && cout << "Teachers don't teach this class, please repeat" << endl);
		return;
	}
}
void viewcheckin(char y[], listcr &lcr, int &cur)
{
	{
		listat lat;
		listat1 lat1;
		listallst last;
		char a[200];
		int no = 1;
		char ID[20];
		int flag = 0;
		char SID[20];
		int flagcheck = 0;
		int k = strlen(y);
		loadAllStudent(last);
		int i = 0;
		char *cla = new char;
		for (nodeallst *lt = last.head; lt != NULL; lt = lt->next)
		{
			if (i == cur)
			{
				cla = strtok(lt->data.name, "S");
				break;
			}
			i++;
		}
		do
		{
			cout << "Enter the Course ID of the course that student " << y << " want to check-in: ";
			cin >> ID;
			int str = strlen(ID);
			for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
			{
				if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
				{
					cout << "\nAttendance list of subjects " << cr->data.name << "" << endl;
					flag = 1;

					char a[100] = "2018 - 2019/Semester";
					if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
					{
						char smt[4] = " 1/";
						strcat(a, smt);
					}
					else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
					{
						char smt[4] = " 2/";
						strcat(a, smt);
					}
					else
					{
						char smt[4] = " 3/";
						strcat(a, smt);
					}
					strcat(a, cla);
					char to[2] = "-";
					strcat(a, to);
					char csv[5] = ".csv";
					strcat(a, cr->data.id);
					strcat(a, csv);
					delete cla;
					char b[200];
					if (ID[str - 1] == 'h' && ID[str - 2] == 't')
					{
						loadatprac(a, lat1, b);
						do
						{
							for (nodeat1 *t = lat1.head; t != NULL; t = t->next)
							{
								if (strcmp(t->data.id, y) == 0)
								{
									flagcheck = 1;
									cout << "             ___________________Attendance sheet for this student " << t->data.id << "___________________" << endl;
									cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
									cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10" << endl;
									cout << t->data.id << "  " << t->data.w1 << "  " << t->data.w2 << "  " << t->data.w3 << "  " << t->data.w4 << "  " << t->data.w5 << "  " << t->data.w6 << "  " << t->data.w7 << "  " << t->data.w8 << "  " << t->data.w9 << "  " << t->data.w10 << endl << endl;
									int qq = saveatprac(a, lat1, b);
									if (qq) cout << "\nEdit an attendance successfull" << endl;
									else cout << "\nDon't edit an attendance sucessfull" << endl;
									return;
								}
							}
						} while (flagcheck == 0 && cout << "Student not found, please re-enter !!!" << endl);
					}
					else
					{
						loadattheory(a, lat, b);
						do
						{
							for (nodeat *t = lat.head; t != NULL; t = t->next)
							{
								if (strcmp(t->data.id, y) == 0)
								{
									flagcheck = 1;
									cout << "            ___________________Attendance sheet for this student " << t->data.id << "___________________" << endl;
									cout << "                                        Practice(0:absent, 1: present)" << endl << endl;
									cout << "Student ID  Week 01  Week 02  Week 03  Week 04  Week 05  Week 06  Week 07  Week 08  Week 09  Week 10  Week11" << endl;
									cout << t->data.id << "       " << t->data.w1 << "        " << t->data.w2 << "        " << t->data.w3 << "        " << t->data.w4 << "        " << t->data.w5 << "        " << t->data.w6 << "        " << t->data.w7 << "        " << t->data.w8 << "        " << t->data.w9 << "        " << t->data.w10 << "        " << t->data.w11 << endl << endl;
									return;
								}
							}
						} while (flagcheck == 0 && cout << "Student not found, please re-enter !!!" << endl);
					}
				}
			}
		} while (flag == 0 && cout << "Teachers don't teach this class, please repeat" << endl);
		return;
	}
}
void viewschedu(char y[], listst *&lst, listcr &lcr, int &k, listallst &last)
{
	int check = 0;
	int i = 0;
	char a[200];
	int flag = 0;
	int flagcheck = 0;
	char *cla = new char;
	for (nodest *p = lst[k].head; p != NULL; p = p->next)
	{
		if (strcmp(y, p->data.id) == 0)
		{
			cout << p->data.no << endl << p->data.id
				<< endl << p->data.lastname << " "
				<< p->data.firstname << endl << p->data.sex
				<< endl << p->data.birth.month << "/"
				<< p->data.birth.day << "/" << p->data.birth.year << endl;
			check = 1;
			break;
		}
	}
	for (nodeallst *lt = last.head; lt != NULL; lt = lt->next)
	{
		if (i == k)
		{
			cla = strtok(lt->data.name, "S");
			break;
		}
		i++;
	}
	string b[6][4][2];
	for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
	{
		char c = cr->data.classn[5];
		if (c != k + 49)
			continue;
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][0][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][0][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][0][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][0][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][0][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][0][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][0][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][0][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][0][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][0][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][0][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 7)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][0][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][1][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][1][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][1][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][1][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][1][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][1][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][1][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][1][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][1][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][1][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][1][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 9)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][1][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][2][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][2][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][2][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][2][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][2][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][2][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][2][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][2][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][2][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][2][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][2][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 13)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][2][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][3][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][3][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][3][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][3][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][3][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == 't' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][3][0] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Monday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[0][3][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Tuesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[1][3][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Wednesday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[2][3][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Thursday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[3][3][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Friday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[4][3][1] = name + '-' + room;
		}
		if (strcmp(cr->data.day, "Saturday") == 0 && cr->data.id[6] == '\0' && cr->data.start1.hour == 15)
		{
			string name = &cr->data.id[0];
			string room = &cr->data.room[0];
			b[5][3][1] = name + '-' + room;
		}
	}
	string l[4] = { "7:30-9:10","9:30-11:10", "13:30-15:10", "15:30-17:10" };
	string t[4] = { "7:30-9:30","9:30-11:30", "13:30-15:30", "15:30-17:30" };
	if (check == 1)
	{
		cout << "\n				_________________________SCHEDULES_________________________ " << endl;
		cout << "						       Class: " << cla << "" << endl << endl;
	}
	cout << "Shift     Hour/Day         Monday        Tuesday        Wednesday        Thursday        Friday        Saturday" << endl;
	for (int j = 0; j < 4; j++)
	{
		cout << "  " << j + 1 << "     ";
		for (int i = 1; i >= 0; i--)
		{
			if (i == 0)
			{
				cout << "        TH:" << t[j] << "    ";
				if (j == 0) cout << "  ";
				if (j == 1) cout << " ";
			}
			else
			{
				cout << "LT:" << l[j] << "   ";
				if (j == 0) cout << "  ";
				if (j == 1) cout << " ";
			}
			for (int k = 0; k < 6; k++)
			{
				if (b[k][j][i] != "")
				{
					if (i == 0)
					{
						cout << b[k][j][i];
						for (int h = 0; h < 15 - b[k][j][i].size(); h++)
							cout << " ";
					}
					else
					{
						cout << b[k][j][i];
						for (int h = 0; h < 16 - b[k][j][i].size(); h++)
							cout << " ";
					}
				}
				else
				{
					if (i == 0)
					{
						for (int h = 0; h < 15; h++)
							cout << " ";
					}
					else
						for (int h = 0; h < 16; h++)
							cout << " ";
				}
			}
			cout << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << endl;
	cout << "CTT008: Programming Techniques" << endl;
	cout << "CTT010: Introduction to Information Technology 2" << endl;
	cout << "TTH026: Analytics B1" << endl;
	cout << "KTH001: General Economic" << endl;
	cout << "CTH001: Principles of Marxist and Lennist" << endl;
}
void viewst4(char y[], listcr &lcr, int &k, listallst &last)
{
	char ID[20];
	int flag = 0;
	char b[200];
	char *cla = new char;
	listsb lsb;
	int i = 0;
	for (nodeallst *lt = last.head; lt != NULL; lt = lt->next)
	{
		if (i == k)
		{
			cla = strtok(lt->data.name, "S");
			break;
		}
		i++;
	}
	do
	{
		cout << "Enter the Course ID of the course you want to view the scoreboard: ";
		cin >> ID;
		for (nodecr *cr = lcr.head; cr != NULL; cr = cr->next)
		{
			if (strcmp(cr->data.id, ID) == 0 && strcmp(cr->data.classn, cla) == 0)
			{
				flag = 1;
				cout << "Find the course!!" << endl;
				char a[100] = "2018 - 2019/Semester";
				if (cr->data.start.day > 1 && cr->data.start.month == 9 && cr->data.start.year == 2018 && cr->data.end.day < 30 && cr->data.end.month == 11 && cr->data.end.year == 2018)
				{
					char smt[4] = " 1/";
					strcat(a, smt);
				}
				else if (cr->data.start.day > 1 && cr->data.start.month == 1 && cr->data.start.year == 2019 && cr->data.end.day < 30 && cr->data.end.month == 4 && cr->data.end.year == 2019)
				{
					char smt[4] = " 2/";
					strcat(a, smt);
				}
				else
				{
					char smt[4] = " 3/";
					strcat(a, smt);
				}
				strcat(a, cr->data.classn);
				strcat(a, "-");
				strcat(a, cr->data.id);
				strcat(a, "-");
				strcat(a, "score");
				strcat(a, ".csv");
				int val = atoi(y);

				if (loadscore(a, lsb, b))
				{
					cout << "\nView student " << y << " scores of a course" << endl << endl;
					cout << "Student ID , Midterm , Final , Lab , Bonus" << endl;
					for (nodesb *p = lsb.head; p != NULL; p = p->next)
					{
						if (p->data.ID == val)
						{
							cout << p->data.ID << " , " << p->data.midterm << " , " << p->data.final << " , " << p->data.lab << " , " << p->data.bonus << endl;
							return;
						}
					}
				}
			}
		}
	} while (flag == 0 && cout << "Can't find the course, Please input again!!" << endl);
}
void studentmenu(char y[], listst *&lst, listallst &last)
{
	int k = 0;
	int check = 0;
	for (int i = 0; i < listn(); i++)
	{
		for (nodest *p = lst[i].head; p != NULL; p = p->next)
		{
			if (strcmp(y, p->data.id) == 0)
			{
				cout << p->data.no << endl << p->data.id
					<< endl << p->data.lastname << " "
					<< p->data.firstname << endl << p->data.sex
					<< endl << p->data.birth.month << "/"
					<< p->data.birth.day << "/" << p->data.birth.year << endl;
				check = 1;
				k = i;
				break;
			}
		}
		if (check == 1)
		{
			cout << "\n________Student________" << endl;
			cout << "1: Check-in" << endl;
			cout << "2: View check-in result" << endl;
			cout << "3: View schedules" << endl;
			cout << "4: View his/her scores of a course" << endl;
			cout << "5: Logout" << endl;
			int s;
			cout << "Let's choose the function you want: ";
			cin >> s;
			switch (s)
			{
			case 1:
			{
				system("cls");
				listcr lcr;
				char a[200];
				loadCourse("Course.csv", lcr, a);
				checkin(y, lcr, k);

				cout << endl << endl;
				char kkk[10];
				cout << "Do you want to continue ??? (yes/no): ";
				cin >> kkk;
				if (strcmp(kkk, "yes") == 0)
				{
					system("cls");
					studentmenu(y, lst, last);
				}
				else
				{
					cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
					_getch();
					exit(0);
				}
				break;
			};
			case 2:
			{
				system("cls");
				listcr lcr;
				char a[200];
				loadCourse("Course.csv", lcr, a);
				viewcheckin(y, lcr, k);

				cout << endl << endl;
				char kkk[10];
				cout << "Do you want to continue ??? (yes/no): ";
				cin >> kkk;
				if (strcmp(kkk, "yes") == 0)
				{
					system("cls");
					studentmenu(y, lst, last);
				}
				else
				{
					cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
					_getch();
					exit(0);
				}
				break;
			};
			case 3:
			{
				system("cls");
				listcr lcr;
				char a[200];
				loadCourse("Course.csv", lcr, a);
				viewschedu(y, lst, lcr, k, last);

				cout << endl << endl;
				char kkk[10];
				cout << "Do you want to continue ??? (yes/no): ";
				cin >> kkk;
				if (strcmp(kkk, "yes") == 0)
				{
					system("cls");
					studentmenu(y, lst, last);
				}
				else
				{
					cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
					_getch();
					exit(0);
				}
				break;
			};
			case 4:
			{
				system("cls");
				listcr lcr;
				char a[200];
				loadCourse("Course.csv", lcr, a);
				viewst4(y, lcr, k, last);

				cout << endl << endl;
				char kkk[10];
				cout << "Do you want to continue ??? (yes/no): ";
				cin >> kkk;
				if (strcmp(kkk, "yes") == 0)
				{
					system("cls");
					studentmenu(y, lst, last);
				}
				else
				{
					cout << "Thanks, See you again !!! \n Click enter to exit !!!" << endl;
					_getch();
					exit(0);
				}
				break;

			};
			case 5:
			{
				char y[10];
				cout << "Do you sure want to logout ??? (yes/no): ";
				cin >> y;
				if (strcmp(y, "yes") == 0)
				{
					system("cls");
					cout << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "                                  _____THANK YOU_____" << endl;
					cout << "                                  ___SEE YOU AGAIN___" << endl;
					Sleep(2000);
					system("cls");
					menu();
				}
				else
				{
					studentmenu(y, lst, last);
				}
				break;
			}
			default:
			{
				system("cls");
				cout << "Incorrect,please enter again! " << endl;

				studentmenu(y, lst, last);
			}
			}
			break;
		}
	}
}
void changePassword(listpw &l, listlt&llt, char user[50], string pass)
{
	char check[50];
	char a[50], b[50];
	string c;
	do
	{
		cout << "Enter your old password: ";
		inputpassword(check);
		c = sha256(check);
		if (c == pass)
		{
			do
			{
				cout << "Enter new password: ";
				inputpassword(a);
				cout << "Enter new password again: ";
				inputpassword(b);
				if (strcmp(a, b) == 0)
				{
					nodepw*p = l.head;
					while (p != NULL)
					{
						if (strcmp(p->data.user, user) == 0)
						{
							strcpy(p->data.pass, sha256(a).c_str());
							savePassword("Password.csv", l);
							return;
						}
						p = p->next;
					}
					nodelt*lt = llt.head;
					while (lt != NULL)
					{
						if (strcmp(lt->data.user, user) == 0)
						{
							strcpy(lt->data.pass, sha256(a).c_str());
							saveTeacher("Teacher.csv", llt);
							return;
						}
						lt = lt->next;
					}
				}
			} while (a != b);
		}
	} while (c != pass && cout << "Wrong!! Please do it again!" << endl);
}

int login(char y[])
{
	listpw pw;
	listlt llt;
	char a[200];
	int k = loadPassword("Password.csv", pw, a);
	if (k)
	{
		k = savePassword("Password.csv", pw);
	}
	Createlectu("Teacher.csv", llt, a);
	char user[20];
	char password[50];
	int index = 0;
	int temp = 0;
	int check = 0;
	cout << "Select: " << endl;
	do
	{
		cout << "1: Login" << endl;
		cout << "2: Change Password" << endl;
		cout << "Enter: ";
		cin >> temp;
		cout << "--------------------------------------" << endl;
	} while (temp > 2);
	do
	{
		if (index == 1) cout << "Wrong user or password!! Please try again!!" << endl;
		index = 0;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		inputpassword(password);
		string pass = sha256(password);

		nodepw *lpw = pw.head;
		for (nodepw *lpw = pw.head; lpw != NULL; lpw = lpw->next)
		{
			if (strcmp(user, lpw->data.user) == 0 && strcmp(pass.c_str(), lpw->data.pass) == 0)
			{
				strcpy(y, user);
				check = 1;
				break;
			}
		}
		for (nodelt *lt = llt.head; lt != NULL; lt = lt->next)
		{
			if (strcmp(user, lt->data.user) == 0 && strcmp(pass.c_str(), lt->data.pass) == 0)
			{
				strcpy(y, user);
				check = 2;
				break;
			}
		}
		if (check == 1 || check == 2)
		{
			if (temp == 1)
			{
				if (user[0] < 'A')
					return 3;
				else if (strcmp(user, "admin") == 0)
					return 1;
				else return 2;
			}
			else if (temp == 2)
			{
				changePassword(pw, llt, user, pass);
				return 4;
			}
		}
		else index = 1;
	} while (index == 1);
}

void menu()
{
	int size = listn();
	listst*lst = new listst[size];
	for (int i = 0; i < size; i++)
	{
		init(lst[i]);
	}
	listallst last;
	listallstsave lasts;
	int h = loadall(lst, last, lasts);
	cout << "--------------------------------------" << endl;
	cout << "1: OPEN" << endl;
	cout << "2: EXIT" << endl;
	cout << "--------------------------------------" << endl;
	int x;
	int x1;
	cout << "Please, Enter the request you want: ";
	cin >> x;
	cout << "--------------------------------------" << endl;
	char y[11];
	if (x == 1)
	{
		x1 = login(y);
		if (x1 == 1)
		{
			system("cls");
			char b[100];
			int k = 0;
			staffmenu();

		}
		if (x1 == 2)
		{
			system("cls");
			lecturermenu(y);

		}
		if (x1 == 3)
		{
			system("cls");
			studentmenu(y, lst, last);
		}
		if (x1 == 4)
		{
			cout << "Change the password successfully. HAVE A NICE DAY" << endl;
			system("pause");
			exit(0);
		}
	}
	else if (x == 2)
	{
		cout << "Have a nice day!" << endl;
		system("pause");
		exit(0);

	}
	else
	{
		system("cls");
		cout << "Invalid,please enter again!" << endl;

		menu();
	}
}

//void main()
{
	cout << "\n                   |************* WELCOME TO PROJECT *************|\n\n" << endl;
	CreateAll();
	listcr lcr;
	char z[200];
	loadCourse("Course.csv", lcr, z);
	int zz = importcourse(lcr, z);
	menu();
	_getch();
}
