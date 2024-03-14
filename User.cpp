#include "User.h"

User::User()
{
    _name = "";
    _login = "";
    _password = "";
    _isAdmin = false;
}

User::User(std::string name, std::string login, std::string password)
{
    _name = name;
    _login = login;
    _password = password;
    _isAdmin = false;
}

std::string User::getName()
{
    return _name;
}

std::string User::getLogin()
{
    return _login;
}

std::string User::getPassword()
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

bool User::getIsAdmin()
{
    return _isAdmin;
}

bool User::Equals(std::string login, std::string password)
{
    return _login == login && _password == password;
}

void User::toConsole()
{
    IDomain::toConsole();
    std::cout << std::setw(25) << _name << std::setw(20) << _login << std::setw(20) << _password  << std::endl;
}

bool User::Equals(std::string login)
{
    return _login == login;
}


