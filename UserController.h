#pragma once
#include "User.h"
#include "ConsoleInputView.h"
#include "UserRepository.h"
#include "AuthorizationService.h"
class UserController
{
private:
	UserRepository _model; //Model
	AuthorizationService _authorizationService; //service
	ConsoleInputView _input; //View
    User* _authorizedUser = NULL;
public:
	void addUser();
	void editUser();
	void deleteUser();
	void displayUsers();
	void registerUser();
	void authorizeUser();
	void deauthorizeUser();
	bool isLoggedIn();
	bool isAdmin();
	template<typename Type>
	void sort(Type(User::* field)());
};

template<typename Type>
void UserController::sort(Type(User::* field)())
{
	char choice = _input.inputString("Сортировать по возрастанию?(y - Да,n - Нет):")[0];
	_model.sort(choice == 'y' || choice == 'Y', DomainComparator<User, Type>(field));
	displayUsers();
	system("pause");
}
