#include "ConsoleExtension.h"
std::string ConsoleExtension::inputString(const std::string& prompt)
{
	std::string input;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) { printTextWithColor("�� ������ �� �����.", Colors::Red); continue; }
		break;
	}
	return input;
}
char ConsoleExtension::inputChar(const std::string& prompt)
{
	std::string input;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty()) { printTextWithColor("�� ������ �� �����.", Colors::Red); continue; }
		if(input.size()>1){ printTextWithColor("������� ���� ������.", Colors::Red); continue; }
		break;
	}
	return input[0];
}
void ConsoleExtension::printTextWithColor(const std::string& text, const Colors& color)
{
	std::cout << "\033[" << (int)color << "m" << text << "\033[0m" << std::endl;
}

void ConsoleExtension::printError(const std::string& errorMessage)
{
	std::cerr << "\033[31m������: \033[0m" << errorMessage << std::endl;
}
