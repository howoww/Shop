#include <Windows.h>
#include "ConsoleExtension.h"
#include "App.h"
#include "AuthorizationController.h"
const std::string App::USERS_FILENAME = "users";
const std::string App::PRODUCTS_FILENAME = "products";
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	system("cls");
	AuthorizationController authController;
	return 0;
}

