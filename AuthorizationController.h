#pragma once
#include "UserRepository.h"
#include "ConsoleIO.h"
#include "MenuView.h"
#include "AdminController.h"
#include "DefaultUserController.h"
class AuthorizationController
{
private:
	UserRepository _userRepository;
	MenuView _menuView;
	bool _isLoggedIn = false;
	bool _isAdmin = false;
public:
	AuthorizationController();
	~AuthorizationController();
	void registerUser();
	void authorizeUser();
	bool isAdmin() const;
	bool isLoggedIn() const;
};

