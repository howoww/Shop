#include "AuthorizationController.h"

AuthorizationController::AuthorizationController(UserRepository& model, ConsoleView& view) : _model(&model), _view(&view) {}

void AuthorizationController::registerUser()
{
	User user;
	user.setName(_view->inputString("Введите свое имя:"));
	user.setLogin(_view->inputString("Введите свой логин:"));
	user.setPassword(_view->inputString("Введите свой пароль:"));
	if (!_model->ContainsLogin(user.getLogin())) {
		user.setIsAdmin(false);
		_model->addItem(user);
		_view->printColoredText("Вы успешно зарегистрировались.", ConsoleView::Colors::Green);
	}
	else
		_view->printColoredText("Пользователь с таким логином уже зарегистрирован.", ConsoleView::Colors::Red);
	system("pause");
}

void AuthorizationController::authorizeUser()
{
	std::string login, password;
	login = _view->inputString("Введите свой логин:");
	password = _view->inputString("Введите свой пароль:");
	_authorizedUser = _model->getUserForAuth(login, password);
	if (_authorizedUser != nullptr)
		_view->printColoredText("Здравствуйте " + _authorizedUser->getName(), ConsoleView::Colors::Magenta);
	else
		_view->printColoredText("Неверный логин или пароль.", ConsoleView::Colors::Red);
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
