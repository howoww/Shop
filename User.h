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

	std::string getName() const;
	std::string getLogin() const;
	std::string getPassword() const;
	bool getIsAdmin() const;
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setIsAdmin(bool isAdmin);
	void toTableLine() const  override;
	bool Equals(std::string login, std::string password) const;
	bool Equals(std::string login) const;

	// Унаследовано через BinaryData
	void toBinary(std::ofstream& outFile) const override;
	void fromBinary(std::ifstream& inFile) override;


};

