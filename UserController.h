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
};

