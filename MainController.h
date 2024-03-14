#pragma once
#include "UserController.h"
#include "ProductController.h"
#include "MenuView.h"
class MainController
{
private:
	MenuView menu;
	UserController userController;
	ProductController productController;
	void DisplayAdminMenu();
	void DisplayUserMenu();
public:
	MainController();
	void Display();

};

