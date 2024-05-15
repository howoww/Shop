#include "UserController.h"
UserController::UserController() : _userRepository(App::USERS_FILENAME) {
}

void UserController::displayUsers(const std::vector<User>& users)
{
	if (users.empty()) {
		std::cout << "Список пуст" << std::endl;
		return;
	}
	std::cout << std::left << std::setw(5) << "ID" << std::setw(25) << "Имя" << std::setw(20) << "Логин" << std::setw(20) << "Пароль" << std::setw(10) << "Уровень доступа" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < users.size(); i++) {
		users[i].toTableLine();
	}
}

void UserController::addUser()
{
	char choice = 'n';
	do {
		User user(
			ConsoleExtension::inputString("Введите свое имя:"),
			ConsoleExtension::inputString("Введите свой логин:"),
			ConsoleExtension::inputString("Введите свой пароль:"), false);

		char isAdmin = ConsoleExtension::inputChar("У пользователя тип доступа администратор?(y - Да,n - Нет):");
		user.setIsAdmin(isAdmin == 'y' || isAdmin == 'Y');

		try {
			_userRepository.addItem(user);
			ConsoleExtension::printTextWithColor("Пользователь успешно добавлен.", ConsoleExtension::Colors::Green);
			_userRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		choice = ConsoleExtension::inputChar("Хотите добавить еще пользователя?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		displayUsers();
		int id = 0;
		id = ConsoleExtension::inputPositiveValue<int>("Введите ID пользователя:");
		try {
			User user = _userRepository.getItemById(id);
			user.setName(ConsoleExtension::inputString("Введите новое имя:"));
			user.setLogin(ConsoleExtension::inputString("Введите новый логин:"));
			user.setPassword(ConsoleExtension::inputString("Введите новый пароль:"));
			char inputIsAdmin = ConsoleExtension::inputChar("У пользователя тип доступа администратор?(y - Да,n - Нет):");
			user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			_userRepository.UpdateItemById(user);
			ConsoleExtension::printTextWithColor("Пользователь успешно изменен.", ConsoleExtension::Colors::Green);
			_userRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		choice = ConsoleExtension::inputString("Хотите изменить еще пользователя?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		displayUsers();
		std::vector<int> idsForDelete = ConsoleExtension::inputPositiveValues<int>("Введите ID пользователя/ей через пробел(1 2 3):", ' ');
		char isDelete = ConsoleExtension::inputChar("Вы уверены?(y - Да,n - Нет):");

		if (isDelete == 'y' || isDelete == 'Y') {
			try {
				_userRepository.deleteItemsByIds(idsForDelete);
				ConsoleExtension::printTextWithColor("Пользователь/и успешно удален/ы", ConsoleExtension::Colors::Green);
				_userRepository.saveData();
			}
			catch (const std::exception& e) {
				ConsoleExtension::printError(e.what());
			}
		}
		choice = ConsoleExtension::inputString("Хотите удалить еще пользователя/ей?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	const std::vector<User>& users = _userRepository.getAll();
	displayUsers(users);
	system("pause");
}

