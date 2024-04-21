#include "UserController.h"

UserController::UserController(): _userRepository("users") {
}
UserController::~UserController()
{
	_userRepository.saveData();
}
void UserController::addUser()
{
	char choice = 'n';
	do {
		User user(
			ConsoleIO::inputString("Введите свое имя:"),
			ConsoleIO::inputString("Введите свой логин:"),
			ConsoleIO::inputString("Введите свой пароль:"), false);

		char isAdmin = ConsoleIO::inputChar("У пользователя тип доступа администратор?(y - Да,n - Нет):");
		user.setIsAdmin(isAdmin == 'y' || isAdmin == 'Y');

		try {
			_userRepository.addItem(user);
			ConsoleIO::printTextWithColor("Пользователь успешно добавлен.", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputChar("Хотите добавить еще пользователя?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		int id = 0;
		id = ConsoleIO::inputPositiveValue<int>("Введите ID пользователя:");
		try {
			User user = _userRepository.getItemById(id);
			user.setName(ConsoleIO::inputString("Введите новое имя:"));
			user.setLogin(ConsoleIO::inputString("Введите новый логин:"));
			user.setPassword(ConsoleIO::inputString("Введите новый пароль:"));
			char inputIsAdmin = ConsoleIO::inputChar("У пользователя тип доступа администратор?(y - Да,n - Нет):");
			user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			ConsoleIO::printTextWithColor("Пользователь успешно изменен.", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputString("Хотите изменить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		std::vector<int> idsForDelete = ConsoleIO::inputPositiveValues<int>("Введите ID пользователя/ей через пробел(1 2 3):", ' ');
		char isDelete = ConsoleIO::inputChar("Вы уверены?(y - Да,n - Нет):");

		if (isDelete == 'y' || isDelete == 'Y')
			try {
			_userRepository.deleteItemsById(idsForDelete);
			ConsoleIO::printTextWithColor("Пользователь/и успешно удален/ы", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputString("Хотите удалить еще пользователя/ей?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "Имя" << std::setw(20) << "Логин" << std::setw(20) << "Пароль" << std::setw(10) << "Уровень доступа" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _userRepository.getAll().size(); i++) {
		_userRepository.getAll()[i].toConsole();
	}
}

void UserController::saveUsers()
{
	_userRepository.saveData();
	system("pause");
}


