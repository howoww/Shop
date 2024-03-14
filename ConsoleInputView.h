#pragma once
#include <string>
#include <iostream>
#include "sstream"
class ConsoleInputView
{
public:
	enum class Colors {
		Default = 0,
		Black = 30,
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White
	};

	std::string inputString(std::string prompt);
	template <typename T>
	T inputValue(std::string prompt);
	void printColoredText(std::string text, Colors color);

};

template<typename T>
T ConsoleInputView::inputValue(std::string prompt)
{
	if ((!std::is_same<T, int>::value) && (!std::is_same<T, double>::value) && (!std::is_same<T, float>::value)) {
		throw std::invalid_argument("Неверный тип. Поддерживается только double, float, int.");
	}
	T input;
	std::string line;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, line);
		if (line.empty()) { printColoredText("Вы ничего не ввели.", Colors::Red); continue; }
		std::stringstream ss(line);
		if (ss >> input && ss.eof()) {
			if (input < 0) { printColoredText("Число должно быть положительным", Colors::Red); continue; }
			break;
		}
		printColoredText("Неверный ввод. Введите число.", Colors::Red);
	}
	return input;
}
