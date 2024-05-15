#include "UserController.h"
UserController::UserController() : _userRepository(App::USERS_FILENAME) {
}

void UserController::displayUsers(const std::vector<User>& users)
{
	if (users.empty()) {
		std::cout << "������ ����" << std::endl;
		return;
	}
	std::cout << std::left << std::setw(5) << "ID" << std::setw(25) << "���" << std::setw(20) << "�����" << std::setw(20) << "������" << std::setw(10) << "������� �������" << std::endl;
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
			ConsoleExtension::inputString("������� ���� ���:"),
			ConsoleExtension::inputString("������� ���� �����:"),
			ConsoleExtension::inputString("������� ���� ������:"), false);

		char isAdmin = ConsoleExtension::inputChar("� ������������ ��� ������� �������������?(y - ��,n - ���):");
		user.setIsAdmin(isAdmin == 'y' || isAdmin == 'Y');

		try {
			_userRepository.addItem(user);
			ConsoleExtension::printTextWithColor("������������ ������� ��������.", ConsoleExtension::Colors::Green);
			_userRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		choice = ConsoleExtension::inputChar("������ �������� ��� ������������?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		displayUsers();
		int id = 0;
		id = ConsoleExtension::inputPositiveValue<int>("������� ID ������������:");
		try {
			User user = _userRepository.getItemById(id);
			user.setName(ConsoleExtension::inputString("������� ����� ���:"));
			user.setLogin(ConsoleExtension::inputString("������� ����� �����:"));
			user.setPassword(ConsoleExtension::inputString("������� ����� ������:"));
			char inputIsAdmin = ConsoleExtension::inputChar("� ������������ ��� ������� �������������?(y - ��,n - ���):");
			user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			_userRepository.UpdateItemById(user);
			ConsoleExtension::printTextWithColor("������������ ������� �������.", ConsoleExtension::Colors::Green);
			_userRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		choice = ConsoleExtension::inputString("������ �������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		displayUsers();
		std::vector<int> idsForDelete = ConsoleExtension::inputPositiveValues<int>("������� ID ������������/�� ����� ������(1 2 3):", ' ');
		char isDelete = ConsoleExtension::inputChar("�� �������?(y - ��,n - ���):");

		if (isDelete == 'y' || isDelete == 'Y') {
			try {
				_userRepository.deleteItemsByIds(idsForDelete);
				ConsoleExtension::printTextWithColor("������������/� ������� ������/�", ConsoleExtension::Colors::Green);
				_userRepository.saveData();
			}
			catch (const std::exception& e) {
				ConsoleExtension::printError(e.what());
			}
		}
		choice = ConsoleExtension::inputString("������ ������� ��� ������������/��?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	const std::vector<User>& users = _userRepository.getAll();
	displayUsers(users);
	system("pause");
}

