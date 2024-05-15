#include "UserRepository.h"

UserRepository::UserRepository(const std::string& filename) : DomainRepository(filename)
{
	if (_items.size() == 0)
		_items.push_back(User("�������������", "admin", "admin", true));
}

const User& UserRepository::getUserForAuth(const std::string& login, const std::string& password)
{
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].Equals(login, password)) return _items[i];
	throw std::invalid_argument("�������� ����� ��� ������");
}

bool UserRepository::containsLogin(const std::string& login) const
{
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].Equals(login)) return true;
	return false;
}

void UserRepository::addItem(User& item)
{
	if (containsLogin(item.getLogin()))
		throw std::invalid_argument("������������ � ����� ������� ��� ����������");
	DomainRepository::addItem(item);
}

void UserRepository::UpdateItemById(const User& item)
{
	if (containsLogin(item.getLogin()))
		throw std::invalid_argument("������������ � ����� ������� ��� ����������");
	DomainRepository::UpdateItemById(item);
}
