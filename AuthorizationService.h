#pragma once
#include "User.h"
#include "UserRepository.h"
class AuthorizationService
{
private:
	UserRepository _model;
public:
	bool registerUser(User user);
	User* authorizeUser(std::string login, std::string password);
};

