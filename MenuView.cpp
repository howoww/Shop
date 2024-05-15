#include "MenuView.h"
#include <vector>
#include <functional>
#include <string>


MenuView::MenuView(std::string lable, std::function<void()> function) : _action(function), _lable(lable) {}
MenuView::MenuView(std::string lable, std::vector<MenuView> menus) : _lable(lable), _menus(menus) {}



void MenuView::execute()
{
	bool flag = true;
	while (flag) {
		this->printMenu();
		int select = -1;
		if (this->_action == nullptr) {
			while (select < 0 || select > this->_menus.size()) {
				select = ConsoleExtension::inputPositiveValue<int>("Введите число (0 - Назад) << ");
			}
			select--;
			if (select == -1) {
				flag = false;
			}
			else {
				system("cls");
				_menus[select].execute();
			}
		}
		else {
			_action();
			flag = false;
		}
		system("cls");
	}
}

void MenuView::printMenu() {
	if (this->_action == nullptr) {
		ConsoleExtension::printTextWithColor(" ···························· ", ConsoleExtension::Colors::Cyan);
		ConsoleExtension::printTextWithColor(":   _____ _                  :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(":  / ____| |                 :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(": | (___ | |__   ___  _ __   :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(":  \\___ \\| '_ \\ / _ \\| '_ \\  :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(":  ____) | | | | (_) | |_) | :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(": |_____/|_| |_|\\___/| .__/  :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(":                    | |     :", ConsoleExtension::Colors::Green);
		ConsoleExtension::printTextWithColor(" ···························· ", ConsoleExtension::Colors::Cyan);
		ConsoleExtension::printTextWithColor(_lable, ConsoleExtension::Colors::Magenta);
	}

	for (int i = 0; i < this->_menus.size(); i++) {
		ConsoleExtension::printTextWithColor(std::to_string(i + 1)  + ". " + this->_menus[i]._lable, ConsoleExtension::Colors::Yellow);
	}
}


