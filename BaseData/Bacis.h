#include <string>
#include <iostream>

using std::string;

class Data {
public:
	void AddInformationAboutPerson(const string& fileName, const Data& ap);
	void DisplayInformation(const string nameFile);
	Data(const string name = " ", int d = 0, int m = 0, int y = 0);
	void SearchNamePerson(const string &nameFile);
	void OverWrite(string nameFile);
	bool CleaningFile();
	int NumberString(const string fileName);
	void SortingStringInRear();

private:
	string namePerson;
	int day, month, year; //  store the birth a person
};