#include <iostream>
#include <cstdlib>

// TODO: add scoreboard to a locally stored text file
// TODO: add pauses in prints for dramatic effect
int main() {
	srand(time(NULL));
	const int correct_num = rand() % 100;
	int guessed_num = 0;
	int lives = 50;
	int tries = 0;
	char hardness;
	double points = 1000.0;
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << "+++++ Bem vindo ++++" << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << "Pick a dificculty (e)asy, (m)edium, (h)ard" << std::endl;
	std::cin >> hardness;
	switch(hardness) {
		case 'e' : {
			lives = 100;
			points = 500.0;
		}
		case 'E' : {
			break;
		}
		case 'm' : {
			lives = 50;
			points = 2000.0;
		}
		case 'M' : {
			break;
		}
		case 'h' : {
		}
		case 'H' : {
			lives = 20;
			points = 5000.0;
			break;
		}
	}
	std::cout << "+ You have " << lives << " lives +" << std::endl;
	std::cout << "+ Try to guess the number in as little tries as possible. +" << std::endl;
	std::cout << "+ Cash prize is " << points << " max." << std::endl;
	
	while (lives > 0) {
		std::cin >> guessed_num;
		std::cout << "You guessed "<< guessed_num << " hmmmm..." << std::endl;	
		points = points - abs(guessed_num - correct_num)/2;
		if (guessed_num < correct_num) {
			std::cout << "Maybe go a little higher." << std::endl;
			lives--;
			tries++;
		}
		else if (guessed_num > correct_num) {
			std::cout << "Calm down cowboy try something smaller." << std::endl;
			lives--;
			tries++;
		} else {
			std::cout << "Correct!!" << std::endl;
			std::cout << "Youre free to go, for now." << std::endl;
			std::cout << "You guessed right in " << tries << " tries." << std::endl;
			std::cout.precision(2);
			std::cout << std::fixed;
			std::cout << "That gives you R$" << points << "." << std::endl;
			return 0;
		}
	}
	std::cout << "You werent able to guess the number in under " << tries << " tries." << std::endl;
	std::cout << "Unfortunately were going to have to kill you." << std::endl;
	return 0;
}