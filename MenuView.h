#pragma once
#include <functional>
#include "ConsoleInputView.h"
class MenuView {
private:
	std::string _lable;
	std::vector<MenuView> _menus;
	std::function<void()> _action;
	ConsoleInputView _input;
	void printMenu();
public:
	MenuView();
	MenuView(std::string lable, std::function<void()> function) : _action(function) {
		_lable = lable;
	};
	MenuView(std::string lable,  std::vector<MenuView> menus);
	void execute();

	std::string getLable();

    
};