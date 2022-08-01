#include <iostream>
#include "Station.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

BusStation::BusStation()
{
	numberRoute = 0;
	numberFreeSeats[0] = 0;
	nameBus = "Auto";
	time = "11:00";
	WhereTo = "Derbent";
	WhereFrom = "Moscow";
}

BusStation::BusStation(int numberRoute, int numberFreeSeats[], const string& nameBus,
	const string& time, const string& WhereTo, const string& WhereFrom)
{
	int l = sizeof(numberFreeSeats);
	this->numberRoute = numberRoute;
	this->numberFreeSeats[l] = numberFreeSeats[l];
	this->nameBus = nameBus;
	this->time = time;
	this->WhereTo = WhereTo;
	this->WhereFrom = WhereFrom;
}

void BusStation::Show()const {
	std::cout << "\n#1)NumberRout: " << numberRoute;
	std::cout << "\n#2)NameBus: " << nameBus;
	std::cout << "\n#3)Time: " << time;
	std::cout << "\n#4)WhereFrom: " << WhereFrom;
	std::cout << "\n#5)WhereTo: " << WhereTo;
}

void BusStation::AddInFile(const BusStation &st,const string nameFile)
{
	using namespace std;
	ofstream fout(nameFile,ios::app);
	if (!fout.is_open()) {
		cout << "Failed open !\n";
	}	
	
	fout << st.numberRoute << "\n" << st.numberFreeSeats << "\n"
		<< st.nameBus << "\n" << st.time << "\n" << st.WhereTo << "\n"
		<< WhereFrom << "\n";

	fout.close();
}

void BusStation::ViewOfFile(const string nameFile)
{
	using namespace std;
	ifstream fout(nameFile);
	string conclusionOfFile;

	if (!fout.is_open()) {
		cout << "Failed open !\n";
	}
	
	while (!fout.eof())
	{
		fout >> conclusionOfFile;
		cout << conclusionOfFile << " ";
		cout << endl;
	}

	fout.close();
}

void BusStation::OnlyNumber(const string& nameFile)
{
	using namespace std;
	std::ifstream file(nameFile);
	int price;
	do
	{
		if (file >> price)
		{
	
			cout << price << " ";
		}
		else
		{
			file.clear();
			file.ignore(1, ' ');
		}
	} while (!file.eof());
	file.close();
}

void BusStation::RemoveChoiceString(const string& nameFile) 
{
	using std::cout;
	using std::cin;
	using std::ifstream;
	using std::ofstream;

	string str;
	int choice;
	ifstream fout(nameFile,std::ios::app);
	ofstream read(nameFile,std::ios::out);

	cout << "Enter string so you want remove: ";
	cin >> choice;
	while (getline(fout, str)) 
		str.erase(str.begin()+choice);
		read << str << " ";
	
	fout.close();
	read.close();

}

int BusStation::NumFree() {
	int l = sizeof(numberFreeSeats);
	for (int i = 0; i < l; i++)
		return numberFreeSeats[l];
}

PricesOnBus::PricesOnBus(int numberRoute, int numberFreeSeats[], const string& nameBus,
	const string& time, const string& WhereTo, const string& WhereFrom, double prc)
	:BusStation(numberRoute, numberFreeSeats, nameBus, time, WhereTo, WhereFrom)
{
	price = prc;
}

void PricesOnBus::AddInFile(const PricesOnBus &st,const string nameFile)
{
	using namespace std;

	ofstream fout(nameFile,ios::app);
	if (!fout.is_open()) {
		cout << "Failed open !\n";
	}		
	
	fout << st.price << "\n";
	fout.close();
}

void PricesOnBus::ViewOfFile(const string nameFile)
{
	using namespace std;
	ifstream fout(nameFile);
	string infoOfFile;

	if (!fout.is_open()) {
		cout << "Failed open !\n";
	}

	while (!fout.eof())
	{
		fout >> infoOfFile;
		cout <<infoOfFile << "\n";
	}
	fout.close();
}

void PricesOnBus::Show()const
{
	std::cout << "\n#6)Price: " << price;
}
