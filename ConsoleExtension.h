#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "StringExtension.h"
class ConsoleExtension
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

	static std::string inputString(const std::string& prompt);
	static char inputChar(const std::string& prompt);

	template <typename T> requires std::is_same_v<T, int> || std::is_same_v<T, double>
	static T inputPositiveValue(const std::string& prompt);

	template <typename T> requires std::is_same_v<T, int> || std::is_same_v<T, double>
	static std::vector<T> inputPositiveValues(const std::string& prompt, const char& delimiter);

	static void printTextWithColor(const std::string& text, const Colors& color);

	static void printError(const std::string& errorMessage);
};

template<typename T> requires std::is_same_v<T, int> || std::is_same_v<T, double>
T ConsoleExtension::inputPositiveValue(const std::string& prompt)
{
	T input;
	std::string line;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, line);
		if (line.empty()) { printTextWithColor("Вы ничего не ввели.", Colors::Red); continue; }
		std::stringstream ss(line);
		if (ss >> input && ss.eof()) {
			if (input < 0) { printTextWithColor("Число должно быть положительным", Colors::Red); continue; }
			break;
		}
		printTextWithColor("Неверный ввод. Введите число.", Colors::Red);
	}
	return input;
}

template<typename T> requires std::is_same_v<T, int> || std::is_same_v<T, double>
std::vector<T> ConsoleExtension::inputPositiveValues(const std::string& prompt, const char& delimiter)
{
	std::vector<T> positiveInputValues;
	std::string line;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, line);
		if (line.empty()) { printTextWithColor("Вы ничего не ввели.", Colors::Red); continue; }
		std::vector<std::string> splittedInputValues = StringExtension::split(line, delimiter);
		bool isRightValue = true;
		for (size_t i = 0; i < splittedInputValues.size(); i++) {
			std::stringstream ss(splittedInputValues[i]);
			T value;
			if (ss >> value && ss.eof()) {
				if (value < 0) { isRightValue = false; continue; }
				positiveInputValues.push_back(value);
			} else isRightValue = false;
		}
		if (positiveInputValues.empty() || !isRightValue)
			printTextWithColor("Неверный ввод. Введите положительные/ое числа/о.", Colors::Red);
		else
			break;
	}
	return positiveInputValues;
}
