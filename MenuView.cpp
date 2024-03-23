#include "MenuView.h"
#include <vector>
#include <functional>
#include "ConsoleView.h"


MenuView::MenuView(std::string lable, std::function<void()> function) : _action(function), _lable(lable) {}
MenuView::MenuView(std::string lable, std::vector<MenuView> menus) : _lable(lable), _menus(menus) {}

MenuView::MenuView()
{
}


void MenuView::execute()
{
	bool flag = true;
	while (flag) {
		this->printMenu();
		int select = -1;
		if (this->_action == nullptr) {
			while (select < 0 || select > this->_menus.size()) {
				select = _view.inputValue<int>("Введите число (0 - Назад) << ");
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
		_view.printColoredText(" ···························· ", ConsoleView::Colors::Cyan);
		_view.printColoredText(":   _____ _                  :", ConsoleView::Colors::Green);
		_view.printColoredText(":  / ____| |                 :", ConsoleView::Colors::Green);
		_view.printColoredText(": | (___ | |__   ___  _ __   :", ConsoleView::Colors::Green);
		_view.printColoredText(":  \\___ \\| '_ \\ / _ \\| '_ \\  :", ConsoleView::Colors::Green);
		_view.printColoredText(":  ____) | | | | (_) | |_) | :", ConsoleView::Colors::Green);
		_view.printColoredText(": |_____/|_| |_|\\___/| .__/  :", ConsoleView::Colors::Green);
		_view.printColoredText(":                    | |     :", ConsoleView::Colors::Green);
		_view.printColoredText(" ···························· ", ConsoleView::Colors::Cyan);
		_view.printColoredText(_lable, ConsoleView::Colors::Magenta);
	}

	for (int i = 0; i < this->_menus.size(); i++) {
		_view.printColoredText(std::to_string(i + 1)  + ". " + this->_menus[i]._lable, ConsoleView::Colors::Yellow);
	}
}


