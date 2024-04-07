#include "UserRepository.h"

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
