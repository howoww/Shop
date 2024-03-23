#pragma once
#include "User.h"
#include "UserRepository.h"
class AuthorizationService
{
private:
	UserRepository _model;
public:
	AuthorizationService(UserRepository& userRepository);
	//Регистрация пользователя
	bool registerUser(User user);
	//Авторизация пользователя
	User* authorizeUser(std::string login, std::string password);
};

