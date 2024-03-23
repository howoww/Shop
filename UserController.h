#pragma once
#include "User.h"
#include "ConsoleView.h"
#include "UserRepository.h"
#include "AuthorizationService.h"
class UserController
{
private:
	UserRepository* _model; //Model
	ConsoleView* _view; //View
public:
	UserController(UserRepository& model, ConsoleView& view);
	//�������� ����������, ��������, ���������, �����������
	void addUser();
	void editUser();
	void deleteUser();
	void displayUsers();

	//����������
	template<typename Type>
	void sort(Type(User::* field)());
};

template<typename Type>
void UserController::sort(Type(User::* field)())
{
	char choice = _view->inputString("����������� �� �����������?(y - ��,n - ���):")[0];
	_model->sort(choice == 'y' || choice == 'Y', DomainComparator<User, Type>(field));
	displayUsers();
	system("pause");
}
