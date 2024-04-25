#pragma once
#include "User.h"
#include "UserRepository.h"
#include "ConsoleExtension.h"
#include "App.h"
class UserController
{
private:
	UserRepository _userRepository;
	void displayUsers(const std::vector<User>& users);
public:
	UserController();
	void addUser();
	void editUser();
	void deleteUser();
	void displayUsers();
	
	template<typename TypeGetter>
	void sort(TypeGetter(User::* field)() const);

	template<typename TypeGetter>
	void searchUsers(TypeGetter(User::* getter)() const);
};

template<typename TypeGetter>
void UserController::sort(TypeGetter(User::* field)() const)
{
	char choice = ConsoleExtension::inputChar("Сортировать по возрастанию?(y - Да,n - Нет):");
	const std::vector<User>& sortedUsers = _userRepository.getSortedVector(choice == 'y' || choice == 'Y', field);
	displayUsers(sortedUsers);
	system("pause");
}

template<typename TypeGetter>
 void UserController::searchUsers(TypeGetter(User::* getter)() const)
{
	 std::string searchText = ConsoleExtension::inputString("Введите текст для поиска:");
	 const std::vector<User>& searchedUsers = _userRepository.searchItems(getter, searchText);
	 displayUsers(searchedUsers);
	 system("pause");
}
