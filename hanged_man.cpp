#include <iostream>
#include <string>

using namespace std;
int main() {
	char guessed_char;
	string guessed_word;
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
	bool not_corect = true;
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << "+++++ Bem vindo ++++" << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << "Pick a dificculty (e)asy, (m)edium, (h)ard" << std::endl;
	std::cin >> hardness;
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

	string word = "PALAVRA";
	int char_count = word.length();


	while (not_correct) {
		for (int i = 0; i < char_count; ++i) {
			cout << "_";
		}
		std::cout << "guess a character >.<" << std::endl;
		std::cout << "meow meow meow placeholder" << std::endl;
		cin >> guessed_char		
		int position = charInWord(word);
		if (charInWord(word)) {
			cout << "Nice!" << endl;

		}

		std::cout << "guess the word" << std::endl;
		std::cout << "meow meow meow placeholder" << std::endl;
		cin >> guessed_word
		if (guessed_word != word) {
			std::cout << "Wrong!!" << std::endl;
			tries++;
			lives--;
			points = point - (abs(char_count+tries)*2);
			return 0;
		
		} else {
			std::cout << "Correct!!" << std::endl;
			std::cout << "meow meow you did it in " << tries << " tries!" << std::endl;
			std::cout << "that gives you " << points << " monies!" << std::endl;
			return 0;
		}
	}
	cout << word << endl;
	return 0;
}