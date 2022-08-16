#include <iostream>
#include "string.h"


int main(void)
{
	String sp;
	sp = "Hello world";
	std::cout << sp;

	String str;
	str = sp;

	std::cout << "\n" << str;

	std::cout << sp.length()<<"\n";

	std::cout << str[2] << "\n";
	
	sp = "One";
	str = "Two";
	std::cout << "\nSp:" << sp << "\nStr: " << str;
	std::cout << "\nUsing At() " << sp.at(2);

	String ssp = sp+"soft";
	std::cout << "\nAmount: " << ssp;
	
	String temp = "Free time";
	char temps[10] = "Helllo";
	temp.copy(temps, 4, 0);
	std::cout <<"\nTemps: "<< temps << "\n";

	if (ssp < str) {
		std::cout << "Str more !\n";
	}
	else {
		std::cout << "Ssp more !\n";
	}

	if (ssp == str) {
		std::cout << "Similar\n";
	}
}