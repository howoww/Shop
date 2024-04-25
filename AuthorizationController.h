#pragma once
#include "UserRepository.h"
#include "ConsoleExtension.h"
#include "MenuView.h"
#include "AdminController.h"
#include "DefaultUserController.h"
#include "BinaryDataService.h"
#include "App.h"
class AuthorizationController
{
private:
	UserRepository _userRepository;
	MenuView _menuView;
	bool _isLoggedIn = false;
	bool _isAdmin = false;
public:
	AuthorizationController();
	void registerUser();
	void authorizeUser();
	bool isAdmin() const;
	bool isLoggedIn() const;
};

