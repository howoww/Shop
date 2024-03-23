#include "UserController.h"

UserController::UserController(UserRepository& model, ConsoleView& view): _model(&model), _view(&view) {}
void UserController::addUser()
{
	char choice = 'n';
	do {
		User user;
		user.setName(_view->inputString("Введите свое имя:"));
		user.setLogin(_view->inputString("Введите свой логин:"));
		user.setPassword(_view->inputString("Введите свой пароль:"));
		char inputIsAdmin = _view->inputString("У пользователя тип доступа администратор?(y - Да,n - Нет):")[0];
		user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
		if (!_model->ContainsLogin(user.getLogin()))
		{
			_model->addItem(user);
			_view->printColoredText("Пользователь успешно добавлен.", ConsoleView::Colors::Green);
		}
		else { _view->printColoredText("Пользователь с таким логином уже зарегистрирован.", ConsoleView::Colors::Red); }
		choice = _view->inputString("Хотите добавить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _view->inputValue<int>("Введите ID пользователя:");
		User* user = _model->getItemById(id);
		if (user != nullptr) {
			user->setName(_view->inputString("Введите новое имя:"));
			user->setLogin(_view->inputString("Введите новый логин:"));
			user->setPassword(_view->inputString("Введите новый пароль:"));
			char inputIsAdmin = _view->inputString("У пользователя тип доступа администратор?(y - Да,n - Нет):")[0];
			user->setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			_view->printColoredText("Пользователь успешно изменен.", ConsoleView::Colors::Green);
		}
		else
			_view->printColoredText("Пользователя с веденным ID не существует.", ConsoleView::Colors::Red);
		choice = _view->inputString("Хотите изменить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		int id;
		id = _view->inputValue<int>("Введите ID пользователя:");
		std::string isDelete = _view->inputString("Вы уверены?(y - Да,n - Нет):");
		if (isDelete == "y" || isDelete == "Y")
			if (!_model->deleteItemById(id))
				_view->printColoredText("Пользователя с веденным ID не существует.", ConsoleView::Colors::Red);
			else
				_view->printColoredText("Пользователь успешно удален.", ConsoleView::Colors::Green);
		choice = _view->inputString("Хотите удалить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	_model->displayUsers();
}


