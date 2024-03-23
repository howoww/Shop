#include "AuthorizationController.h"

AuthorizationController::AuthorizationController(UserRepository& model, ConsoleView& view) : _model(&model), _view(&view) {}

void AuthorizationController::registerUser()
{
	User user;
	user.setName(_view->inputString("������� ���� ���:"));
	user.setLogin(_view->inputString("������� ���� �����:"));
	user.setPassword(_view->inputString("������� ���� ������:"));
	if (!_model->ContainsLogin(user.getLogin())) {
		user.setIsAdmin(false);
		_model->addItem(user);
		_view->printColoredText("�� ������� ������������������.", ConsoleView::Colors::Green);
	}
	else
		_view->printColoredText("������������ � ����� ������� ��� ���������������.", ConsoleView::Colors::Red);
	system("pause");
}

void AuthorizationController::authorizeUser()
{
	std::string login, password;
	login = _view->inputString("������� ���� �����:");
	password = _view->inputString("������� ���� ������:");
	_authorizedUser = _model->getUserForAuth(login, password);
	if (_authorizedUser != nullptr)
		_view->printColoredText("������������ " + _authorizedUser->getName(), ConsoleView::Colors::Magenta);
	else
		_view->printColoredText("�������� ����� ��� ������.", ConsoleView::Colors::Red);
	system("pause");
}

void AuthorizationController::deauthorizeUser()
{
	_authorizedUser = nullptr;
}

bool AuthorizationController::isLoggedIn()
{
	return _authorizedUser != nullptr;
}

bool AuthorizationController::isAdmin()
{
	return isLoggedIn() && _authorizedUser->getIsAdmin();
}
