#include <iostream>
#include <string>

using namespace std;

void checkForSameCharacters();
int searchWordForNumberOfCharacters(string tempString, char tempLetter);
int searchWordForNumberOfCharacters(string tempString, char tempLetter);
bool isCharacterString(string tempString);
string turnToLowerCase(string tempString);
void reverseWordOrder();
void computeFactorial();

int main()
{
	int option;
	cout << "What do you want to do?" << endl;
	cout << "1: Parse a string for the number of a chosen letter\n2) Reverse the order of a character string\n3) Calculate the factorial of a value\n";
	cin >> option;
	while (isdigit(option))
	{
		cout << "Input a freaking number dang it!" << endl;
		cin >> option;
	}
	if (option == 1) 
		checkForSameCharacters();
	else if (option == 2)
		reverseWordOrder();
	else
		computeFactorial();
	system("pause");
	return 0;
}

void checkForSameCharacters()
{
	string word = "";
	cout << "Input a word: " << endl;
	//getline(cin, word);
	cin >> word;

	word = turnToLowerCase(word);
	while(!isCharacterString(word))
	{
		cout << "Make sure to enter ONLY CHARACTERS" << endl;
		cout << "Input a word: " << endl;
		getline(cin, word);
	}
	cout << "Word length: " << word.length() << endl;


	char letter;
	cout << "The world is \"" << word << "\"" << endl;
	cout << "Choose a letter to search for: " << endl;
	cin >> letter;
	letter = tolower(letter);

	while (!isalpha(letter))
	{
		cout << "Choose only one letter" << endl;
		cin >> letter;
		tolower(letter);
	}

	int numberOfTimesRepeated = searchWordForNumberOfCharacters(word, letter);
	cout << "The number of times the letter \"" << letter << "\" is: " << numberOfTimesRepeated << endl;
	if (numberOfTimesRepeated == 0)
	{
		cout << "...there are none of those letters...." << endl;
	}
}

string turnToLowerCase(string tempString)
{
	string tempStringAllLower = tempString;
	for (int i = 0; i < tempString.length(); i++)
	{
		tempStringAllLower[i] = tolower(tempString[i]);
	}
	return tempStringAllLower;
}


int searchWordForNumberOfCharacters(string tempString, char tempLetter)
{
	int tempNumber = 0;

	for (int i = 0; i < tempString.length(); i++)
	{
		if (tempString[i] == tempLetter)
		{
			tempNumber++;
		}
	}

	return tempNumber;
}

bool isCharacterString(string tempString)
{
	for (int i = 0; i < tempString.length(); i++)
	{
		if (!isalpha(tempString[i]))
			return false;
	}
	return true;
}



/********************************************
* Reverse the word order
******************************************/
void reverseWordOrder()
{
	string tempString;
	string reversedString = "";
	cout << "Input a character string: ";
	//Not sure why the getline is not working
	//getline(cin, tempString);
	cin >> tempString;

	for (int i = tempString.length() - 1; i >= 0; i--)
	{
		reversedString += tempString[i];
	}
	cout << "Reversed: " << reversedString << endl;
}


/********************************************
* Calculating factorial
******************************************/
void computeFactorial()
{
	int tempNumber = 0;

	cout << "Input a number: ";
	cin >> tempNumber;
	while (isdigit(tempNumber))
	{
		cout << "Input a freaking number: ";
		cin >> tempNumber;
	}
	int number = tempNumber;
	if (number == 0)
	{
		cout << 0 << "! is: " << 1 << endl;
	}
	else
	{
		for (int i = tempNumber - 1; i > 0; i--)
		{
			number *= i;
		}
		cout << tempNumber << "! is: " << number << endl;
	}
}
