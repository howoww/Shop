#include "ConsoleView.h"	


std::string ConsoleView::inputString(std::string prompt)
{
	std::string input;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) { printColoredText("�� ������ �� �����.", Colors::Red); continue;  }
		break;
	}
	return input;
}


void ConsoleView::printColoredText(std::string message, Colors color)
{
	std::cout << "\033[" << (int)color << "m" << message << "\033[0m" << std::endl;
}
