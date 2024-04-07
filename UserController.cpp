#include "UserController.h"

UserController::UserController(UserRepository& model) : _model(&model) {  }
void UserController::addUser()
{
	char choice = 'n';
	do {
		User user;
		user.setName(_view.inputString("������� ���� ���:"));
		user.setLogin(_view.inputString("������� ���� �����:"));
		user.setPassword(_view.inputString("������� ���� ������:"));
		char inputIsAdmin = _view.inputString("� ������������ ��� ������� �������������?(y - ��,n - ���):")[0];
		user.setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
		if (!_model->ContainsLogin(user.getLogin()))
		{
			_model->addItem(user);
			_model->saveData();
			_view.printColoredText("������������ ������� ��������.", ConsoleView::Colors::Green);
		}
		else { _view.printColoredText("������������ � ����� ������� ��� ���������������.", ConsoleView::Colors::Red); }
		choice = _view.inputString("������ �������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::editUser()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _view.inputValue<int>("������� ID ������������:");
		User* user = _model->getItemById(id);
		if (user != nullptr) {
			user->setName(_view.inputString("������� ����� ���:"));
			user->setLogin(_view.inputString("������� ����� �����:"));
			user->setPassword(_view.inputString("������� ����� ������:"));
			char inputIsAdmin = _view.inputString("� ������������ ��� ������� �������������?(y - ��,n - ���):")[0];
			user->setIsAdmin(inputIsAdmin == 'y' || inputIsAdmin == 'Y');
			_model->saveData();
			_view.printColoredText("������������ ������� �������.", ConsoleView::Colors::Green);
		}
		else
			_view.printColoredText("������������ � �������� ID �� ����������.", ConsoleView::Colors::Red);
		choice = _view.inputString("������ �������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::deleteUser()
{
	char choice = 'n';
	do {
		int id;
		id = _view.inputValue<int>("������� ID ������������:");
		std::string isDelete = _view.inputString("�� �������?(y - ��,n - ���):");
		if (isDelete == "y" || isDelete == "Y")
			if (!_model->deleteItemById(id))
				_view.printColoredText("������������ � �������� ID �� ����������.", ConsoleView::Colors::Red);
			else
			{
				_view.printColoredText("������������ ������� ������.", ConsoleView::Colors::Green);
				_model->saveData();
			}
		choice = _view.inputString("������ ������� ��� ������������?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void UserController::displayUsers()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "���" << std::setw(20) << "�����" << std::setw(20) << "������" << std::setw(10) << "������� �������" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _model->getAll().size(); i++) {
		_model->getAll()[i].toConsole();
	}
}


