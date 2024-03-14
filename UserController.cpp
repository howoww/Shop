#include "UserController.h"

void UserController::addUser()
{
	char choice = 'n';
	do {
		User user;
		user.setName(_input.inputString("Введите свое имя:"));
		user.setLogin(_input.inputString("Введите свой логин:"));
		user.setPassword(_input.inputString("Введите свой пароль:"));
		char inputIsAdmin = _input.inputString("У пользователя тип доступа администратор?(y - Да,n - Нет):")[0];
		user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
		_model.addItem(user);
		_input.printColoredText("Пользователь успешно добавлен.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("Хотите добавить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _input.inputValue<int>("Введите ID пользователя:");
		User* user = _model.getItemById(id);
		if (user != NULL) {
			user->setName(_input.inputString("Введите новое имя:"));
			user->setLogin(_input.inputString("Введите новый логин:"));
			user->setPassword(_input.inputString("Введите новый пароль:"));
			char inputIsAdmin = _input.inputString("У пользователя тип доступа администратор?(y - Да,n - Нет):")[0];
			user->setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			_input.printColoredText("Пользователь успешно изменен.", ConsoleInputView::Colors::Green);
		}
		else
			_input.printColoredText("Пользователя с веденным ID не существует.", ConsoleInputView::Colors::Red);
		choice = _input.inputString("Хотите изменить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		int id;
		id = _input.inputValue<int>("Введите ID пользователя:");
		std::string choice = _input.inputString("Вы уверены?(y - Да,n - Нет):");
		if (choice == "y" || choice == "Y")
			if (!_model.deleteItemById(id))
				_input.printColoredText("Пользователя с веденным ID не существует.", ConsoleInputView::Colors::Red);
			else
				_input.printColoredText("Пользователь успешно удален.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("Хотите удалить еще пользователя?(y - Да,n - Нет):")[0];
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
	user.setName(_input.inputString("Введите свое имя:"));
	user.setLogin(_input.inputString("Введите свой логин:"));
	user.setPassword(_input.inputString("Введите свой пароль:"));
	if(_authorizationService.registerUser(user))
		_input.printColoredText("Вы успешно зарегистрировались.", ConsoleInputView::Colors::Green);
	else
		_input.printColoredText("Пользователь с таким логином уже зарегистрирован.", ConsoleInputView::Colors::Red);
	system("pause");
}

void UserController::authorizeUser()
{
	std::string login, password;
	login = _input.inputString("Введите свой логин:");
	password = _input.inputString("Введите свой пароль:");
	_authorizedUser = _authorizationService.authorizeUser(login, password);
	if (_authorizedUser!=NULL)
		_input.printColoredText("Здравствуйте " + _authorizedUser->getName(), ConsoleInputView::Colors::Magenta);
	else 
		_input.printColoredText("Неверный логин или пароль.", ConsoleInputView::Colors::Red);
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
