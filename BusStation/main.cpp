#include <iostream>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>
#include "Station.h"


void CheckOnCorrectly(const std::string& str);
void CheckOnPrice(double price);
void CheckFreeSeats(int number,int size, int *arr);
void PrintInfo(BusStation &st,PricesOnBus &add);

void Menu() {
	using std::cout;
	using std::endl;
	cout << "____________________________________________\n";
	cout << "'A') Here you can add info in file \n";
	cout << "'B') Here you can add info in file !\n";
	cout << "'D') Here you can see information in file !\n";
	cout << "'C') Here you can info in Class \n";
	cout << "_____________________________________________\n";
	cout << endl;

}

int main(void)
{
	using namespace std;

	string nameFile = "file1.txt";
	char choice;
	BusStation lout;
	PricesOnBus Add;
	
	Menu();
	cout << "You need do correcly choice ! :> ";
	

	while (cin >> choice) {
		choice = tolower(choice);
		while (strchr("a,b,c,d,e,q", choice) == nullptr)
		{
			cout << "You can repeat : ";
			cin >> choice;
		}

		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'a':PrintInfo(lout,Add);
			cout << endl;
			break;

		case 'b':lout.AddInFile(lout, "file1.txt");
			Add.AddInFile(Add, "file1.txt");
			break;

		case 'c':lout.Show();
			Add.Show();
			break;

		case'd':if (choice == 'd') { lout.ViewOfFile("file1.txt"); }
			  else if (choice == 'D') { Add.ViewOfFile("file1.txt"); }
			break;

		case 'e':if(choice=='e'){lout.OnlyNumber("file1.txt");}
			else if(choice=='E'){lout.RemoveChoiceString("file1.txt");}
			break;
		}
		cout << "\nYou can do yet choice: ";
		cout << endl;
	}
	cin.get();
	return 0;
}

void PrintInfo(BusStation &st,PricesOnBus &add)
{
	using std::cout;
	using std::string;
	using std::cin;
	using std::endl;

	string nameBus;
	string time;
	string WhereTo;
	string WhereFrom;
	int numberFreeSeats[12]={0};
	int numberRoute;
	double price;
	cout << endl;	

	cout << "NumberRoute: ";
	cin >> numberRoute;
	cin.get();

	cout << "Enter nameBus: ";
	getline(cin, nameBus);
	

	cout << "Enter time: ";
	getline(cin, time);

	cout << "Where you from: ";
	getline(cin, WhereFrom);

	cout << "Where you want travel: ";
	getline(cin, WhereTo);
	cout << "Enter price: ";
	cin >> price;
	cout << endl;

	try {

		CheckFreeSeats(numberRoute,8,numberFreeSeats);
		
	}
	catch (std::logic_error& st) {
		cout << st.what();
		cout << "There is error here !\n";
	}

	try {
		CheckOnCorrectly(nameBus);
	}
	catch (std::logic_error& st) {
		cout << st.what();
		cout << "There is error here #2\n";
	}

	try {
		CheckOnPrice(price);
	}
	catch (std::logic_error& st) {
		cout << st.what();
		cout << "There is eror here #3\n";
	}
	
	st = BusStation(numberRoute, numberFreeSeats, nameBus, time, WhereFrom, WhereTo);
	add = PricesOnBus(numberRoute,numberFreeSeats,nameBus,time,WhereFrom,WhereTo,price);
}

void CheckFreeSeats(int number, int size, int *arr)
{
	using std::cout;
	srand(time(0));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 20;

	cout << "Your free seats:\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	

	for (int i = 0; i < size; i++) {
		if (arr[i] == number) {
			cout << std::endl;
			cout << "Your seats: "<<number<<std::endl;
		}
	}
	cout << std::endl;
}

void CheckOnCorrectly(const std::string& str)
{
	using std::cout;
	if (str.length() == 0) {
		cout << "String empty !\n";
	}
	else
	{
		cout << "Correctly !\n";
	}
}

void CheckOnPrice(double price)
{
	if (price < 0 && price < 3500) {
		std::cout << "You not enough money !\n";
	}
	else {
		std::cout << "You enough money !\n";
	}
}
