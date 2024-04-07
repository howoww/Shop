#pragma once
#include "User.h"
#include "ConsoleView.h"
#include "UserRepository.h"
class UserController
{
private:
	UserRepository* _model; //Model
	ConsoleView _view; //View
	
public:
	UserController(UserRepository& model);
	~UserController() {  };
	//Операции добавления, удаления, изменения, отображения
	void addUser();
	void editUser();
	void deleteUser();
	void displayUsers();

	//Сортировка
	template<typename Type>
	void sort(Type(User::* field)());
};

template<typename Type>
void UserController::sort(Type(User::* field)())
{
	char choice = _view.inputString("Сортировать по возрастанию?(y - Да,n - Нет):")[0];
	_model->sort(choice == 'y' || choice == 'Y',field);
	displayUsers();
	system("pause");
}