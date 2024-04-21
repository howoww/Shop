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
				select = ConsoleIO::inputPositiveValue<int>("Введите число (0 - Назад) << ");
			}
			select--;
			if (select == -1) {
				flag = false;
			}
			else {
				//Отображение подменю	
				system("cls");
				_menus[select].execute();
			
			}
		}
		else {
			//Выполнение действия
			_action();
			flag = false;
		}
		system("cls");
	}
}


void MenuView::printMenu() {
	if (this->_action == nullptr) {
		ConsoleIO::printTextWithColor(" ···························· ", ConsoleIO::Colors::Cyan);
		ConsoleIO::printTextWithColor(":   _____ _                  :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(":  / ____| |                 :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(": | (___ | |__   ___  _ __   :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(":  \\___ \\| '_ \\ / _ \\| '_ \\  :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(":  ____) | | | | (_) | |_) | :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(": |_____/|_| |_|\\___/| .__/  :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(":                    | |     :", ConsoleIO::Colors::Green);
		ConsoleIO::printTextWithColor(" ···························· ", ConsoleIO::Colors::Cyan);
		ConsoleIO::printTextWithColor(_lable, ConsoleIO::Colors::Magenta);
	}

	for (int i = 0; i < this->_menus.size(); i++) {
		ConsoleIO::printTextWithColor(std::to_string(i + 1)  + ". " + this->_menus[i]._lable, ConsoleIO::Colors::Yellow);
	}
}


