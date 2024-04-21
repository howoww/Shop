#include "User.h"

User::User():_isAdmin(false) {}

User::User(std::string name, std::string login, std::string password, bool isAdmin) :_name(name), _login(login), _password(password), _isAdmin(isAdmin) {}

std::string User::getName() const
{
	return _name;
}

std::string User::getLogin() const
{
	return _login;
}

std::string User::getPassword() const
{
	return _password;
}

void User::setName(std::string name)
{
	_name = name;
}

void User::setLogin(std::string login)
{
	_login = login;
}

void User::setPassword(std::string password)
{
	_password = password;
}

void User::setIsAdmin(bool isAdmin)
{
	_isAdmin = isAdmin;
}

bool User::getIsAdmin() const
{
	return _isAdmin;
}

bool User::Equals(std::string login, std::string password) const
{
	return _login == login && _password == password;
}

bool User::Equals(std::string login) const
{
	return _login == login;
}

void User::toConsole()
{
	Domain::toConsole();
	std::cout << std::setw(25) << _name << std::setw(20) << _login << std::setw(20) << _password << std::setw(10) << (_isAdmin ? "Администратор" : "Пользователь") << std::endl;
}

void User::toBinary(std::ofstream& outFile) const
{
	Domain::toBinary(outFile);
	//Name
	size_t nameLength = _name.length();
	outFile.write((char*)&nameLength, sizeof(nameLength));
	outFile.write(_name.c_str(), nameLength);
	//Login
	size_t loginLength = _login.length();
	outFile.write((char*)&loginLength, sizeof(loginLength));
	outFile.write(_login.c_str(), loginLength);
	//Password
	size_t passwordLength = _password.length();
	outFile.write((char*)&passwordLength, sizeof(passwordLength));
	outFile.write(_password.c_str(), passwordLength);
	//IsAdmin
	outFile.write((char*)&_isAdmin, sizeof(_isAdmin));
}

void User::fromBinary(std::ifstream& inFile)
{
	Domain::fromBinary(inFile);
	//Name
	size_t nameLength;
	inFile.read((char*)&nameLength, sizeof(nameLength));
	std::vector<char> nameBuffer(nameLength + 1); // Добавляем 1 для завершающего нулевого символа
	inFile.read(nameBuffer.data(), nameLength);
	nameBuffer[nameLength] = '\0';
	_name = nameBuffer.data();
	//Login
	size_t loginLength;
	inFile.read((char*)&loginLength, sizeof(loginLength));
	std::vector<char> loginBuffer(loginLength + 1); // Добавляем 1 для завершающего нулевого символа
	inFile.read(loginBuffer.data(), loginLength);
	loginBuffer[loginLength] = '\0';
	_login = loginBuffer.data();
	//Password
	size_t passwordLength;
	inFile.read((char*)&passwordLength, sizeof(passwordLength));
	std::vector<char> passwordBuffer(passwordLength + 1); // Добавляем 1 для завершающего нулевого символа
	inFile.read(passwordBuffer.data(), passwordLength);
	passwordBuffer[passwordLength] = '\0';
	_password = passwordBuffer.data();
	//IsAdmin
	inFile.read((char*)&_isAdmin, sizeof(_isAdmin));
}


