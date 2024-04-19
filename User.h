#pragma once
#include "Domain.h"
class User : public Domain
{
private:
	std::string _name;
	std::string _login;
	std::string _password;
	bool _isAdmin;
public:
	User();
	User(std::string name, std::string login, std::string password, bool isAdmin);

	std::string getName();
	std::string getLogin();
	std::string getPassword();
	bool getIsAdmin();
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setIsAdmin(bool isAdmin);

	void toConsole() override;

	bool Equals(std::string login, std::string password);
	bool Equals(std::string login);

	void serialize(std::ofstream& outFile) override;
	void deserialize(std::ifstream& inFile) override;
};

