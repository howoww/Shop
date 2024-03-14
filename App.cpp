#include <Windows.h>
#include "MenuView.h"
#include <vector>
#include "ProductController.h"
#include "UserController.h"
#include "MainController.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MainController mainController;
	mainController.Display();
	return 0;
}


