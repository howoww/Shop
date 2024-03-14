#include "UserRepository.h"



void UserRepository::displayUsers()
{
    std::cout << std::setw(5) << "ID" << std::setw(25) << "Имя" << std::setw(20) << "Логин" << std::setw(20) << "Пароль" << std::endl;
    std::cout << std::setfill('-') << std::setw(70) << "" << std::setfill(' ') << std::endl;
    for (int i = 0; i < _items.size(); i++) {
        _items[i].toConsole();
    }
}

User* UserRepository::getUserForAuth(std::string login, std::string password)
{
    if (_items.size() == 0) return NULL;
    for (int i = 0; i < _items.size(); i++)
        if (_items[i].Equals(login, password)) return &_items[i];
    return NULL;
}

bool UserRepository::ContainsLogin(std::string login)
{
    if (_items.size() == 0) return false;
    for (int i = 0; i < _items.size(); i++)
        if (_items[i].Equals(login)) return true;
    return false;
}
