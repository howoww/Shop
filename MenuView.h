#pragma once
#include <functional>
#include <vector>
#include <string>
#include "ConsoleIO.h"
class MenuView {
private:
	std::string _lable;
	std::vector<MenuView> _menus;
	std::function<void()> _action;
	void printMenu();
public:
	MenuView(std::string lable, std::function<void()> function);
	MenuView(std::string lable,  std::vector<MenuView> menus);
	void execute();
};