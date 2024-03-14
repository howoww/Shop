#pragma once
#include <string>
#include "IDomain.h"
class User : public IDomain
{
private:
	std::string _name;
	std::string _login;
	std::string _password;
	bool _isAdmin;
public:
	User();
	User(std::string name, std::string login, std::string password);
	std::string getName();
	std::string getLogin();
	std::string getPassword();
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();
	bool Equals(std::string login, std::string password);
	void toConsole() override;
	bool Equals(std::string login);
};

