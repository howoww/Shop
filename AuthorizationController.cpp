#include "AuthorizationController.h"
AuthorizationController::AuthorizationController() :_userRepository("users"), _menuView("Авторизация", std::vector<MenuView>{
	MenuView("Авторизоваться", [&]() {
		authorizeUser();
		if (isLoggedIn())
			if (isAdmin())
				AdminController adminController;
			else
				DefaultUserController userController;
		}),
		MenuView("Зарегистрироваться", [&]() {
		registerUser(); })})
{
	_menuView.execute();
}

AuthorizationController::~AuthorizationController()
{
	_userRepository.saveData();
}

void AuthorizationController::registerUser()
{
	User user
	(ConsoleIO::inputString("Введите свое имя:"),
		ConsoleIO::inputString("Введите свой логин:"),
		ConsoleIO::inputString("Введите свой пароль:"),
		false);
	try {
		_userRepository.addItem(user);
		_userRepository.saveData();
		ConsoleIO::printTextWithColor("Вы успешно зарегистрировались.", ConsoleIO::Colors::Green);
	}
	catch (const std::exception& e) {
		ConsoleIO::printError(e.what());
	}
	system("pause");
}

void AuthorizationController::authorizeUser()
{
	try {
		User user =
			_userRepository.getUserForAuth(
				ConsoleIO::inputString("Введите свой логин:"),
				ConsoleIO::inputString("Введите свой пароль:"));
		_isAdmin = user.getIsAdmin();
		_isLoggedIn = true;
		ConsoleIO::printTextWithColor("Здравствуйте " + user.getName(), ConsoleIO::Colors::Magenta);
	}
	catch (const std::exception& e) {
		ConsoleIO::printError(e.what());
	}
	system("pause");
}

bool AuthorizationController::isLoggedIn() const
{
	return _isLoggedIn;
}

bool AuthorizationController::isAdmin() const
{
	return _isAdmin;
}
