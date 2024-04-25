#pragma once
#include <iostream>
#include <iomanip>
#include "DomainRepository.h"
#include "User.h"
class UserRepository : public  DomainRepository<User>
{
public:
	UserRepository(const std::string& filename);
	User& getUserForAuth(const std::string& login, const std::string& password);
	bool containsLogin(const std::string& login) const;
	void addItem(User& item) override;
	void UpdateItemById(const User& item) override;
};

