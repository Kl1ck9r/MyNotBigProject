#include <iostream>
#include "Bacis.h"
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>  

void Data::AddInformationAboutPerson(const string& fileName, const Data& ap)
{
	using namespace std;
	ofstream fout(fileName, ios::in | ios::out);
	if (!fout.is_open()) {
		cout << "Failed open file !\n";
		exit(EXIT_FAILURE);
	}
	else {
		fout << ap.namePerson<<" ";
		fout<< "\n";
		fout <<""<< ap.day << " " << ap.month << " " << ap.year;
		cout << "Data recorded !\n";
	}
	fout.close();
}

void Data::DisplayInformation(const string nameFile)
{
	using namespace std;

	ifstream conclus(nameFile,ios::app);
	int num=0;
	string info;
	cout << "\n-------------------------\n";
	cout << "\nInformation About Person  \n";
	cout << "\n---------------------------- \n";
	while (!conclus.eof()) {
		conclus >> info;
		cout  << info << "  ";
		cout << endl;
	}

	conclus.close();
}

void Data::OverWrite(string nameFile)
{
	using namespace std;

	ifstream newApp("Base.txt");
	cout << "Enter name new file : ";
	string copyLit;
	getline(cin, nameFile);
	ofstream oc(nameFile);

	if (!oc.is_open()) {
		cout << "Failed open file !\n";
		exit(EXIT_FAILURE);
	}
	while (!newApp.eof()) {
		newApp >> copyLit;
		oc << copyLit<<" ";
	}
	cout << "Data Successfully recorded !\n";
	oc.close();
	newApp.close();
}

void Data::SearchNamePerson(const string &nameFile)
{
	using namespace std;

	ifstream find(nameFile);
	string person;
	cout << "Enter person name so you wany find: ";
	getline(cin, person);
	string name;
	int y, m, d;

	while (find >> name>>y>>m>>d) {
		if (person == name) {
			cout << "Person: " << name << " " << y << " " << m << " " << d << endl;
		}
	}

	cin.get();
	find.close();
}

int Data::NumberString(const string fileName) 
{
	using namespace std;
	int num=0;
	char buf[100];
	ifstream fout(fileName);
	while (!fout.eof()) {
		num++;
		fout.getline(buf, 100);
	}
	cout << "\nNumbers strings:> "<<num << " ";
	fout.close();
	return num;
}

void Data::SortingStringInRear()
{
	
	using namespace std;
	
	ifstream in("Base.txt");
	vector<string> vs;
	string s;
	while (getline(in, s)) 
		vs.push_back(s);
	sort(vs.begin(), vs.end());
	ofstream on("Base.txt",ios::app | std::fstream::out);
	copy(vs.begin(), vs.end(), ostream_iterator<string>(on, "\n"));

	in.close();
	on.close();
}

bool Data::CleaningFile()
{
	using namespace std;
	bool clear = false;
	fstream  fout("Base.txt", ios::out);

	if (!fout.is_open()) {
		cout << "Failed open file !\n";
		exit(EXIT_FAILURE);
	}

	fout.clear();
	if (fout.peek() == EOF)
		clear = true;
	else
		clear = false;
	fout.close();
	return clear;
}

Data::Data(const string name, int d, int m, int y)
{
	namePerson = name;
	day = d;
	month = m;
	year = y;
}