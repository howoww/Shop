#include "UserController.h"

void UserController::addUser()
{
	char choice = 'n';
	do {
		User user;
		user.setName(_input.inputString("������� ���� ���:"));
		user.setLogin(_input.inputString("������� ���� �����:"));
		user.setPassword(_input.inputString("������� ���� ������:"));
		char inputIsAdmin = _input.inputString("� ������������ ��� ������� �������������?(y - ��,n - ���):")[0];
		user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
		_model.addItem(user);
		_input.printColoredText("������������ ������� ��������.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("������ �������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _input.inputValue<int>("������� ID ������������:");
		User* user = _model.getItemById(id);
		if (user != NULL) {
			user->setName(_input.inputString("������� ����� ���:"));
			user->setLogin(_input.inputString("������� ����� �����:"));
			user->setPassword(_input.inputString("������� ����� ������:"));
			char inputIsAdmin = _input.inputString("� ������������ ��� ������� �������������?(y - ��,n - ���):")[0];
			user->setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			_input.printColoredText("������������ ������� �������.", ConsoleInputView::Colors::Green);
		}
		else
			_input.printColoredText("������������ � �������� ID �� ����������.", ConsoleInputView::Colors::Red);
		choice = _input.inputString("������ �������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		int id;
		id = _input.inputValue<int>("������� ID ������������:");
		std::string choice = _input.inputString("�� �������?(y - ��,n - ���):");
		if (choice == "y" || choice == "Y")
			if (!_model.deleteItemById(id))
				_input.printColoredText("������������ � �������� ID �� ����������.", ConsoleInputView::Colors::Red);
			else
				_input.printColoredText("������������ ������� ������.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("������ ������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	_model.displayUsers();
}

void UserController::registerUser()
{
	User user;
	user.setName(_input.inputString("������� ���� ���:"));
	user.setLogin(_input.inputString("������� ���� �����:"));
	user.setPassword(_input.inputString("������� ���� ������:"));
	if(_authorizationService.registerUser(user))
		_input.printColoredText("�� ������� ������������������.", ConsoleInputView::Colors::Green);
	else
		_input.printColoredText("������������ � ����� ������� ��� ���������������.", ConsoleInputView::Colors::Red);
	system("pause");
}

void UserController::authorizeUser()
{
	std::string login, password;
	login = _input.inputString("������� ���� �����:");
	password = _input.inputString("������� ���� ������:");
	_authorizedUser = _authorizationService.authorizeUser(login, password);
	if (_authorizedUser!=NULL)
		_input.printColoredText("������������ " + _authorizedUser->getName(), ConsoleInputView::Colors::Magenta);
	else 
		_input.printColoredText("�������� ����� ��� ������.", ConsoleInputView::Colors::Red);
	system("pause");
}

void UserController::deauthorizeUser()
{
	_authorizedUser = NULL;
}

bool UserController::isLoggedIn()
{
	return _authorizedUser != NULL;
}

bool UserController::isAdmin()
{
	return isLoggedIn() && _authorizedUser->getIsAdmin();
}
