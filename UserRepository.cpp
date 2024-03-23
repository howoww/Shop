#include "UserRepository.h"

void UserRepository::displayUsers()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "Имя" << std::setw(20) << "Логин" << std::setw(20) << "Пароль" << std::setw(10) << "Уровень доступа" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _items.size(); i++) {
		_items[i].toConsole();
	}
}

User* UserRepository::getUserForAuth(std::string login, std::string password)
{
	if (_items.size() == 0) return nullptr;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].Equals(login, password)) return &_items[i];
	return nullptr;
}

bool UserRepository::ContainsLogin(std::string login)
{
	if (_items.size() == 0) return false;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].Equals(login)) return true;
	return false;
}
