#include "ConsoleInputView.h"	



std::string ConsoleInputView::inputString(std::string prompt)
{
	std::string input;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) { printColoredText("Вы ничего не ввели.", Colors::Red); continue; }
		break;
	}
	return input;
}


void ConsoleInputView::printColoredText(std::string message, Colors color)
{
	std::cout << "\033[" << (int)color << "m" << message << "\033[0m" << std::endl;
}
