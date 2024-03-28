#pragma once
#include <functional>
#include "ConsoleView.h"
#include <vector>
class MenuView {
private:
	std::string _lable;
	std::vector<MenuView> _menus;
	std::function<void()> _action;
	ConsoleView _view;
	void printMenu();
public:
	MenuView(std::string lable, std::function<void()> function);
	MenuView(std::string lable,  std::vector<MenuView> menus);
	MenuView();
	void execute();
};