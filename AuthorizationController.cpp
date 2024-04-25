#include "AuthorizationController.h"
AuthorizationController::AuthorizationController() :_userRepository(App::USERS_FILENAME), _menuView("Авторизация", std::vector<MenuView>{
	MenuView("Авторизоваться", [&]() {
		authorizeUser();
		if (isLoggedIn()) {
			if (isAdmin())
				AdminController adminController;
			else
				DefaultUserController userController;
		}
		}),
		MenuView("Зарегистрироваться", [&]() {
		registerUser(); })})
{
	_menuView.execute();
}


void AuthorizationController::registerUser()
{
	User user
	(ConsoleExtension::inputString("Введите свое имя:"),
		ConsoleExtension::inputString("Введите свой логин:"),
		ConsoleExtension::inputString("Введите свой пароль:"),
		false);
	try {
		_userRepository.addItem(user);
		_userRepository.saveData();
		ConsoleExtension::printTextWithColor("Вы успешно зарегистрировались.", ConsoleExtension::Colors::Green);
	}
	catch (const std::exception& e) {
		ConsoleExtension::printError(e.what());
	}
	system("pause");
}

void AuthorizationController::authorizeUser()
{
	try {
		User user =
			_userRepository.getUserForAuth(
				ConsoleExtension::inputString("Введите свой логин:"),
				ConsoleExtension::inputString("Введите свой пароль:"));
		_isAdmin = user.getIsAdmin();
		_isLoggedIn = true;
		ConsoleExtension::printTextWithColor("Здравствуйте " + user.getName(), ConsoleExtension::Colors::Magenta);
	}
	catch (const std::exception& e) {
		ConsoleExtension::printError(e.what());
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
