#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "Bacis.h"


int main(void)
{
	using namespace std;

	vector<Data>clink;
	Data app;
	string choice;
	cout << "Enter need your variant : ";
	getline(cin, choice);

	while (choice != "exit") {

		if (choice == "Add") {
			string name;
			int d, m, y;
			cout << "Enter your name : ";
			getline(cin, name);
			cout << "Enter your store birth :";
			cin >> d >> m >> y;
			app = Data(name, d, m, y);
			app.AddInformationAboutPerson("Base.txt", app);

		}
		else if (choice == "Print") {
			app.DisplayInformation("Base.txt");
		
		}
		else if (choice == "Search") {
			app.SearchNamePerson("Base.txt");
		}
		else if (choice == "Overwrite") {   // OverWrite() - здесь при необходимости есть возможность переписать наши данные в другой файл 
			string nameNew;
			app.OverWrite(nameNew);
	
		}
		else if (choice == "Number") {
			app.NumberString("Base.txt");
		}
		else if (choice == "Sort") {
			app.SortingStringInRear();
		
		}
		else {
			cout << "Incorrect input !\n";
		}
		
		
		cin.get();
		cout << "\nYour chocie: ";
		cin >>choice;
		system("cls");
	}

	cout << "Do you want clear of file? : enter <Clear> if you want >: ";
	string poll;
	getline(cin, poll);
	if (poll=="Clear")
		if (app.CleaningFile()) {
			cout << "Clear!\n";
		}
		else{
			cout << "Failed clearning\n";
	}

	
	return 0;
}
