#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;
// posso buscar na palavra preenchida para ver se ja tem uma letra na posicao encontrada
vector<int> isCharInWord(string word, char guessedChar, string currentWord) {
  vector<int> aux;
  int i = 0;
  for (char letter : word) {
    if(guessedChar == letter) {
      if(guessedChar != currentWord.at(i)) {
        aux.push_back(i);
      }
    }
    i++;
  }
  return aux;
}

void printLivesLeft(int lives, char hardness) {
  int originalLives;
  int livesDiff;
    /* 13     6
   SO2      o
  / | \   / | \
  o | o    / \
   / \
   o o
   */
  if(hardness == 'e' || hardness == 'E') {
    originalLives = 13;
    livesDiff = originalLives-lives;
    switch(livesDiff) {
      case 1: {
        cout << " S" << endl;
        break;
      }
      case 2: {
        cout << " SO" << endl;
        break;
      }
      case 3: {
        cout << " SO2" << endl;
        break;
      }
      case 4: {
        cout << " SO2" << endl;
        cout << "/" << endl;
        break;
      }
      case 5: {
        cout << " SO2" << endl;
        cout << "/ |" << endl;
        break;
      }
      case 6: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        break;
      }
      case 7: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o" << endl;
        break;
      }
      case 8: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o |" << endl;
        break;
      }
      case 9: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o | o" << endl;
        break;
      }
      case 10: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o | o" << endl;
        cout << " /" << endl;
        break;
      }
      case 11: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o | o" << endl;
        cout << " / \\" << endl;
        break;
      }
      case 12: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o | o" << endl;
        cout << " / \\" << endl;
        cout << "o" << endl;
        break;
      }
      case 13: {
        cout << " SO2" << endl;
        cout << "/ | \\" << endl;
        cout << "o | o" << endl;
        cout << " / \\" << endl;
        cout << "o   o" << endl;
        break;
      }
    }
  } else {
    originalLives = 6;
    livesDiff = originalLives-lives;
    switch(livesDiff) {
      case 1: {
        cout << " O " << endl;
        break;
      }
      case 2: {
        cout << " O " << endl;
        cout << "/" << endl;
        break;
      }
      case 3: {
        cout << " O " << endl;
        cout << "/|" << endl;
        break;
      }
      case 4: {
        cout << " O " << endl;
        cout << "/|\\" << endl;
        break;
      }
      case 5: {
        cout << " O " << endl;
        cout << "/|\\" << endl;
        cout << "/" << endl;
        break;
      }
      case 6: {
        cout << " O " << endl;
        cout << "/|\\" << endl;
        cout << "/ \\" << endl;
        break;
      }
    }
  }  
}

int main() {
  srand(time(NULL));
  char guessedChar;
  string guessedWord;
  char hardness;
  int tries = 0;
  int lives = 6;

  double points = 1000.0;
  cout << "++++++++++++++++++++" << endl;
  cout << "+++++ Bem vindo ++++" << endl;
  cout << "++++++++++++++++++++" << endl;
  cout << endl;
  cout << ">> Pick a dificculty (e)asy, (m)edium, (h)ard" << endl;
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

  string line;
  vector<string> availableWords;
  ifstream rfile;
  rfile.open("palavras.txt");
  if (rfile.is_open()) {
      while (getline(rfile, line)) {
          cout << line << endl;
          availableWords.push_back(line);
      }
      rfile.close();
  }

  const int wordIndex = rand() % 7;
  string word = availableWords.at(wordIndex);

  string currentWord = "";
  int charCount = word.size();
  for (int i = 0; i < charCount; ++i) {
    currentWord = currentWord + "_";
  }

  vector<int> position;
  vector<char> wrongGuesses;

  char menuOption;
  while (lives > 0) {
    cout << "WORD: " << currentWord << endl;
    cout << "Wrong guesses: ";
    for (char g: wrongGuesses)
        std::cout << g << ' ';
    cout << endl;
    cout << ">> Do you want to guess a (c)haracter or the whole (w)ord?" << endl;
    cin >> menuOption;
    switch (menuOption) {
      case 'c': {
        cout << "Guess a character: " << endl;
        cin >> guessedChar;
        guessedChar = (char)toupper(guessedChar);
        position = isCharInWord(word, guessedChar, currentWord);
        if (!position.empty()) {
          cout << "Nice!" << endl;
          string str(1, guessedChar);
          for(int j : position) {
            currentWord.replace(j, 1, str);
          }
          tries++;
        } else {
          cout << "Wrong!!" << endl;
          wrongGuesses.push_back(guessedChar);
          tries++;
          lives--;
          points = points - (abs(charCount+tries)*2);   
        }
        break;
      }
      case 'w': {
        cout << "Guess the word:" << endl;
        cin >> guessedWord;
        for (auto & c: guessedWord) c = (char)toupper(c);
        if(guessedWord == word) {
            currentWord.replace(0, charCount, guessedWord);
        } else {
          cout << "Wrong!!" << endl;
          tries++;
          lives = lives - 2;
          points = points - (abs(charCount*tries)*2);           
        }
        break;
      }
    }

    printLivesLeft(lives, hardness);
    if(currentWord == word) {
      cout << "Correct!! The word is: " << word << endl;
      cout << "You guessed correctly in " << tries << " tries!" << endl;
      cout << "That gives you " << points << " points!" << endl;
      return 0;
    }
  }
  cout << "You failed!! The word is: " << word << endl;
  cout << "You couldnt guess correctly in " << tries << " tries!" << endl;
  cout << "That gives you no points!" << endl;
  return 0;
}