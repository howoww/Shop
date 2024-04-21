#include "AuthorizationController.h"
AuthorizationController::AuthorizationController() :_userRepository("users"), _menuView("�����������", std::vector<MenuView>{
	MenuView("��������������", [&]() {
		authorizeUser();
		if (isLoggedIn())
			if (isAdmin())
				AdminController adminController;
			else
				DefaultUserController userController;
		}),
		MenuView("������������������", [&]() {
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
	(ConsoleIO::inputString("������� ���� ���:"),
		ConsoleIO::inputString("������� ���� �����:"),
		ConsoleIO::inputString("������� ���� ������:"),
		false);
	try {
		_userRepository.addItem(user);
		_userRepository.saveData();
		ConsoleIO::printTextWithColor("�� ������� ������������������.", ConsoleIO::Colors::Green);
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
				ConsoleIO::inputString("������� ���� �����:"),
				ConsoleIO::inputString("������� ���� ������:"));
		_isAdmin = user.getIsAdmin();
		_isLoggedIn = true;
		ConsoleIO::printTextWithColor("������������ " + user.getName(), ConsoleIO::Colors::Magenta);
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
