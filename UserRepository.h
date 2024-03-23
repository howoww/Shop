#pragma once
#include <iostream>
#include <iomanip>
#include "DomainRepository.h"
#include "User.h"
class UserRepository : public  DomainRepository<User>
{
public:
	UserRepository(std::string filename) : DomainRepository(filename) { if (_items.size() == 0) _items.push_back(User("Администратор", "admin", "admin", true)); };
	//Отображение пользователя
	void displayUsers();
	//Получение пользователя при авторизации
	User* getUserForAuth(std::string login, std::string password);
	//Проверка на повторение логина в списке (обязательно при добавлении пользователя)
	bool ContainsLogin(std::string login);
};

