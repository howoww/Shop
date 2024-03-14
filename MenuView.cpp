#include "MenuView.h"
#include <vector>
#include <functional>
#include "ConsoleInputView.h"


MenuView::MenuView(std::string lable, std::vector<MenuView> menus) {
	_lable = lable;
	_menus = menus;
}


void MenuView::execute()
{
	bool flag = true;
	while (flag) {
		this->printMenu();
		int select = -1;
		if (this->_action == nullptr) {
			while (select < 0 || select > this->_menus.size()) {
				select = _input.inputValue<int>("\033[3;42;30mВведите число (0 - Назад) << \033[0m");
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
		std::cout << " __ _                 " << std::endl;
		std::cout << "/ _\\ |__   ___  _ __  " << std::endl;
		std::cout << "\\ \\| '_ \\ / _ \\| '_ \\ " << std::endl;
		std::cout << "_\\ \\ | | | (_) | |_) |" << std::endl;
		std::cout << "\\__/_| |_|\\___/| .__/ " << std::endl;
		std::cout << "               |_|   " << std::endl;

		std::cout << getLable() << std::endl;
	}

	for (int i = 0; i < this->_menus.size(); i++) {
		std::cout << i + 1 << ". " << this->_menus[i].getLable() << std::endl;
	}
}

MenuView::MenuView()
{
}

std::string MenuView::getLable() {
	return this->_lable;
}
