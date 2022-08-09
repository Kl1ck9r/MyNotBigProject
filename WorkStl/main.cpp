
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include "Top.h"

bool operator<(const Remote& st, const Remote& st2) {
    if (st.channel < st2.channel)
        return true;
    else if (st.channel == st2.channel && st.numberChannel < st2.numberChannel)
        return true;
    else
        return false;
}

bool WorseThan(const Remote& st, const Remote& st2)
{
    if (st.numberChannel > st2.numberChannel)
        return true;
    else
        return false;
}

int main()
{
   
    Remote Samsung;
    std::vector<Remote> add;
    std::stack<Remote> ourl;
    std::string channel;
    std::string choice;
    int numberChannel;
        
    std::cout << "Choice: ";
    while (getline(std::cin, choice) && choice[0]!= '!')
    {
       std::cout << std::endl;
        if (choice == "Add") {
            std::cout << "Enter name channel that you want turn on: ";
            getline(std::cin, channel);
            std::cout << "Enter number сhannel: ";
            std::cin >> numberChannel;

            if (Samsung.CheckOff(true)) {
                Samsung = Remote(1, 0, channel, numberChannel);
                ourl.push(Samsung);
               add.push_back(Samsung);
               std::cout << "Add() !\n";
            }
            else {
                std::cout << "Televesion Turned Off !\n";
                std::cout << "\nYou need turn on it's,enter 'Switch': ";
                getline(std::cin, choice);

            }
           
        }

        if (choice == "Remove") {
            if (ourl.empty()) {
                std::cout << "Stack empty() !!! \n";
            }
            else {
                   ourl.pop();
                if (ourl.empty()) {
                    std::cout << "All elements removing of stack !\n";
                }
            }
        }

        if (choice == "Check") {
            while (!ourl.empty()) {

                if (!ourl.empty()) {
                    std::cout << ourl.top()<<" ";
                    ourl.pop();
                }
                else {
                    std::cout << "It's Empty()";
                }

            }
        }
  
        if (choice == "Sort_one") {
            if (!add.empty()) {
                std::sort(add.begin(), add.end());
                for (auto conclusion : add)
                    std::cout << conclusion << " ";
            }
            else {
                std::cout << "It's empty()";
            }
        }

        else if (choice == "Sort_two") {
            if (!add.empty()) {
                sort(add.begin(), add.end(), WorseThan);
                for (auto conclusion : add) {
                    std::cout << conclusion;
                }
            }
            else {
                std::cout << "It's empty()";
            }
        }
        

        if (choice == "Switch") {
            int OffOrOn;
            std::cout << "You want turn on Or turn off Tv?: ";
            std::cin >> OffOrOn;

            if (OffOrOn == true) {
                Samsung.CheckOn(OffOrOn);
                std::cout << "Television seccussful turn on !\n";
            }
            else if(OffOrOn==false) {
                Samsung.CheckOff(OffOrOn);
                std::cout << "Failed tv turn off !\n";
            }
            else {
                std::cout << " ";
            }

        }
        
    }
    
    add.clear();
    return 0;
}

