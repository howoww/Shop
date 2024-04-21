#pragma once
#include <iostream>
#include <iomanip>
#include "DomainRepository.h"
#include "User.h"
class UserRepository : public  DomainRepository<User>
{
public:
	UserRepository(const std::string& filename);
	User getUserForAuth(const std::string& login, const std::string& password);
	bool containsLogin(const std::string& login);
	void addItem(User& item) override;
};

