#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

const int NUM =10;

const char *wordlist[NUM] = {
	"laptop","socket","usb","airpods",
	"iphone","computer","mouse","camera"
};

int main()
{
  srand(time(0));
  
	char play;
	cout << "If you want begin game enter : <y/n> ";
	cin >> play;
  play=tolower(play);
	while (play=='y')
	{
		string target = wordlist[std::rand() % NUM];
		int length = target.length();
		int guess = 5;
		string attempt(length,'-');
		string badWord;
		cout << "Your word: " << attempt << endl;

		while (guess > 0 && attempt != target)
		{
			char letter;
			cout << "You need letter: ";
			cin >> letter;

			if (badWord.find(letter) != string::npos 
			|| attempt.find(letter) != string::npos)
			{
				cout << "Try again Man !\n";
				continue;
			}
      
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "Bad guess Man !!! \n";
				--guess;
				badWord = letter;
			}
			else {
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << endl;
			cout << "Your guess word: " << "[" << attempt << "]"<<endl;
			if (attempt != target) {
				cout << guess << "You have remained try !"<<endl;
				cout << "Your wrong try : " << badWord << endl;
			}
		}

		if (guess > 0) {
			cout << "That's right ! Very Well !!!  \n";
		}
		else {
			cout << "The word that was -> " << target << endl;
		}

		cout << "Enter 'y'/'n' : ";
		cin >> play;
    play=tolower(play);
	}
	
	return 0;
}
