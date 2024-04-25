#include "AuthorizationController.h"
AuthorizationController::AuthorizationController() :_userRepository(App::USERS_FILENAME), _menuView("�����������", std::vector<MenuView>{
	MenuView("��������������", [&]() {
		authorizeUser();
		if (isLoggedIn()) {
			if (isAdmin())
				AdminController adminController;
			else
				DefaultUserController userController;
		}
		}),
		MenuView("������������������", [&]() {
		registerUser(); })})
{
	_menuView.execute();
}


void AuthorizationController::registerUser()
{
	User user
	(ConsoleExtension::inputString("������� ���� ���:"),
		ConsoleExtension::inputString("������� ���� �����:"),
		ConsoleExtension::inputString("������� ���� ������:"),
		false);
	try {
		_userRepository.addItem(user);
		_userRepository.saveData();
		ConsoleExtension::printTextWithColor("�� ������� ������������������.", ConsoleExtension::Colors::Green);
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
				ConsoleExtension::inputString("������� ���� �����:"),
				ConsoleExtension::inputString("������� ���� ������:"));
		_isAdmin = user.getIsAdmin();
		_isLoggedIn = true;
		ConsoleExtension::printTextWithColor("������������ " + user.getName(), ConsoleExtension::Colors::Magenta);
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
