#pragma once
#include <iostream>
#include <iomanip>
#include "IRepository.h"
#include "User.h"
class UserRepository : public  IRepository<User>
{
public:
	void displayUsers();
	User* getUserForAuth(std::string login, std::string password);
	bool ContainsLogin(std::string login);
};

