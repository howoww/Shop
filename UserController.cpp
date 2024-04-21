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
			ConsoleIO::inputString("������� ���� ���:"),
			ConsoleIO::inputString("������� ���� �����:"),
			ConsoleIO::inputString("������� ���� ������:"), false);

		char isAdmin = ConsoleIO::inputChar("� ������������ ��� ������� �������������?(y - ��,n - ���):");
		user.setIsAdmin(isAdmin == 'y' || isAdmin == 'Y');

		try {
			_userRepository.addItem(user);
			ConsoleIO::printTextWithColor("������������ ������� ��������.", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputChar("������ �������� ��� ������������?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		int id = 0;
		id = ConsoleIO::inputPositiveValue<int>("������� ID ������������:");
		try {
			User user = _userRepository.getItemById(id);
			user.setName(ConsoleIO::inputString("������� ����� ���:"));
			user.setLogin(ConsoleIO::inputString("������� ����� �����:"));
			user.setPassword(ConsoleIO::inputString("������� ����� ������:"));
			char inputIsAdmin = ConsoleIO::inputChar("� ������������ ��� ������� �������������?(y - ��,n - ���):");
			user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			ConsoleIO::printTextWithColor("������������ ������� �������.", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputString("������ �������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		std::vector<int> idsForDelete = ConsoleIO::inputPositiveValues<int>("������� ID ������������/�� ����� ������(1 2 3):", ' ');
		char isDelete = ConsoleIO::inputChar("�� �������?(y - ��,n - ���):");

		if (isDelete == 'y' || isDelete == 'Y')
			try {
			_userRepository.deleteItemsById(idsForDelete);
			ConsoleIO::printTextWithColor("������������/� ������� ������/�", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputString("������ ������� ��� ������������/��?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "���" << std::setw(20) << "�����" << std::setw(20) << "������" << std::setw(10) << "������� �������" << std::endl;
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


