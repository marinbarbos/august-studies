#include <iostream>
#include <string>

using namespace std;

int isCharInWord(string word, char guessedChar) {
	int i = 0;
	for (char letter : word) {
		if(guessedChar == letter) {
			return i;
		}
		i++;
	}
	return -1;
}

int main() {
	char guessedChar;
	string guessed_word;
	char hardness;
	int tries = 0;
	int lives = 6;
	/* 13     6
	 SO2      o
	/ | \   / | \
	o | o    / \
	 / \
	 o o
	 */
	double points = 1000.0;
	cout << "++++++++++++++++++++" << endl;
	cout << "+++++ Bem vindo ++++" << endl;
	cout << "++++++++++++++++++++" << endl;
	cout << endl;
	cout << "Pick a dificculty (e)asy, (m)edium, (h)ard" << endl;
	cin >> hardness;
	switch(hardness) {
		case 'e' : {
			lives = 13;
			points = 500.0;
		}
		case 'E' : {
			break;
		}
		case 'm' : {
			lives = 6;
			points = 2000.0;
		}
		case 'M' : {
			break;
		}
		case 'h' : {
		}
		case 'H' : {
			lives = 6;
			points = 5000.0;
			break;
		}
	}

	const string word = "PALAVRA";
	string currentWord = "";
	int charCount = word.size();

	for (int i = 0; i < charCount; ++i) {
		currentWord = currentWord + "_";
	}
	int position = -1;

	while (true) {
		cout << "WORD: " << currentWord << endl;
		cout << "Guess a character: " << endl;
		cin >> guessedChar;
		position = isCharInWord(word, guessedChar);
		if (position > -1) {
			cout << "Nice!" << endl;
			string str(1, guessedChar);
			currentWord.replace(position, 1, str);
			tries++;
			//updateWord(currentWord, position, guessedChar);
		} else {
			cout << "Wrong!!" << endl;
			tries++;
			lives--;
			points = points - (abs(charCount+tries)*2);		
		}

		//std::cout << "guess the word" << std::endl;
		//std::cout << "meow meow meow placeholder" << std::endl;
		//cin >> guessed_word
		if(currentWord == word) {
			cout << "Correct!!" << word << endl;
			cout << "meow meow you did it in " << tries << " tries!" << endl;
			cout << "that gives you " << points << " monies!" << endl;
			return 0;
		}
	}
	cout << word << endl;
	return 0;
}