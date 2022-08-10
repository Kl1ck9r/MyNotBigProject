#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include "List.h"


void ViewForProduct(std::list<std::string>& add)
{
	for (auto it  = add.begin(); it != add.end(); ++it)
		std::cout << std::endl << *it<<" ";
}


void ViewForNumberProduct(std::list<int> add)
{
	for (auto it = add.begin(); it != add.end(); ++it)
		std::cout << std::endl << *it<<" ";
}

void ConclusionForSortNumber(std::vector < std::list<int>> st)
{
	for (const auto exam : st)
		for (const auto plan : exam)
			std::cout << "Sort: " << plan << " ";
}

bool CheckOnCorrectly(const int& val)
{
	return val < 0;
}

void ConclusionForSortProduct(std::vector < std::list<std::string>> lep)
{
	for (const auto cons : lep)
		for (const auto evol : cons)
			std::cout << "Sort: " << evol << " ";
}

bool WorseThan(const std::list<int> sort,const std::list<int>sort2)
{
	if (sort >sort2)
		return true;
	else
		return false;
}

int main(void)
{
	srand(time(0));
	std::list<int> solt;
	std::list<std::string> psor;
	std::vector<std::list<int>> sorT;
	std::vector <std::list<std::string>> wasem;
	std::string Product;
	std::string Conclusion;
	int numberProduct;

		std::cout << "Enter : ";
		getline(std::cin, Conclusion);
	
		while (Conclusion != "All") {
			if (Conclusion == "Add") {

				std::cout << "Products : ";
				getline(std::cin, Product);

				std::cout << "Number Products: ";
				std::cin >> numberProduct;

				psor.push_back(Product);
				solt.push_back(numberProduct);

				sorT.push_back(solt);
				wasem.push_back(psor);
			}

			else if (Conclusion == "Print") {
				std::cout << "Your entered products: ";
				ViewForProduct(psor);
				ViewForNumberProduct(solt);
			}

			else if (Conclusion == "Dubplicats") {
				if (psor.empty()) {
					std::cout << "List empty() \n";
				}
				else {
					auto it = unique(psor.begin(), psor.end());
					psor.erase(it, psor.end());

					auto pt = unique(solt.begin(), solt.end());
					solt.erase(pt, solt.end());

					auto sol = unique(sorT.begin(), sorT.end());
					sorT.erase(sol, sorT.end());
					std::cout << "Dubplicats seccussfull removing !\n";
				}
			}
			else if (Conclusion == "Sort") {
				std::cout << "If you want sort number enter 1/2: ";
				int choice;
				std::cin >> choice;

				if (choice == 1) {
					sort(sorT.begin(), sorT.end(), WorseThan);
					ConclusionForSortNumber(sorT);
				}
				else {
					sort(wasem.begin(), wasem.end());
					ConclusionForSortProduct(wasem);
				}
				
			}

			else if (Conclusion == "General") {
				std::cout << "Place where you can look at front and back elements\n";
				std::cout << "Enter : ";
				int viewCh;
				std::cin >> viewCh;
				while (viewCh != 0) {

					if (viewCh == 1) {
						if (solt.empty()) {
							int num = std::rand() % 50;
							solt.push_front(num);
							std::cout << "\nAdded: " << solt.front();
						}
						else {
							solt.insert(solt.begin(), 18); // add elements ViewCh in solt front() 
							solt.remove_if(CheckOnCorrectly);// if have number less than 0 this string removing it's
						}
					}
					else if (viewCh == 2) {
						if (solt.back()>1) {
							solt.pop_back();
							std::cout << "Remove element in list \n";
						}
					}

					std::cout << "\nChoice: ";
					std::cin >> viewCh;
				}
			}
			std::cin.get();
			std::cout << "\nFor continue doing choice : ";
			getline(std::cin, Conclusion);
		}


	return 0;
}