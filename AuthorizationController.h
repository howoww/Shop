#pragma once
#include "UserRepository.h"
#include "AuthorizationService.h"
#include "ConsoleView.h"
class AuthorizationController
{
private:
	UserRepository* _model;
	ConsoleView* _view; //View
	User* _authorizedUser = nullptr;
public:
	AuthorizationController(UserRepository & model, ConsoleView& view);
	//Авторизация, деавторизация, регистрация
	void registerUser();
	void authorizeUser();
	void deauthorizeUser();
	bool isLoggedIn();
	bool isAdmin();
};

