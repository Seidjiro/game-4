// Виселица
// Классическая игра "Виселица"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;int main()
{
	const int МАХ_WRONG = 8; // максимально допустимое количество ошибок
	vector<string>words; // подборка слов для загадывания
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0]; //слово для отгадывания
	int wrong = 0;// 11 количество ошибочных вариантов
	string soFar(THE_WORD.size(), '-'); // 1 часть слова.открытая на данный момент
	string used = ""; // 1 уже отгаданные буквы
	cout << "Welcome to Hangman. Good luck!\n";	// основной цикл
	while ((wrong < МАХ_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (МАХ_WRONG - wrong);
		cout << " incorrect guesses left. \n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far. the word is:\n" << soFar << endl;
		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); //перевод в верхний регистр.
		// так как загаданное слово записано в верхнем регистре
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right ! " << guess << " is in the word. \n";
			// обновить переменную soFar.включив в нее новую угаданную букву
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry. " << guess << " isn't in the word.\n";
			++wrong;
		}

	}
	// конец игры
		if (wrong == МАХ_WRONG) 
		{
			
			cout << "\nYou've been hanged!";
		}
		else
		{
			cout << "\nYou guessed it!";
		}
		cout << "\nThe word was " << THE_WORD << endl;
		return 0;
}
