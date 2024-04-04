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

	//Конструкторы
	User();
	User(std::string name, std::string login, std::string password, bool isAdmin);

	//Геттеры и сеттеры
	std::string getName();
	std::string getLogin();
	std::string getPassword();
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setIsAdmin(bool isAdmin);
	bool getIsAdmin();

	//Вывод в консоль
	void toConsole() override;

	//Сравнение
	bool Equals(std::string login, std::string password);
	bool Equals(std::string login);

	void serialize(std::ofstream& outFile) override;
	void deserialize(std::ifstream& inFile) override;
};

