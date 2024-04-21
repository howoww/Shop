#pragma once
#include "User.h"
#include "UserRepository.h"
#include "ConsoleIO.h"
class UserController
{
private:
	UserRepository _userRepository;
public:
	UserController();
	~UserController();
	void addUser();
	void editUser();
	void deleteUser();
	void displayUsers();
	void saveUsers();
	
	template<typename TypeGetter>
	void sort(TypeGetter(User::* field)() const);

	template<typename TypeGetter>
	void searchUsers(TypeGetter(User::* getter)() const);
};

template<typename TypeGetter>
void UserController::sort(TypeGetter(User::* field)() const)
{
	char choice = ConsoleIO::inputChar("Сортировать по возрастанию?(y - Да,n - Нет):");
	_userRepository.sort(choice == 'y' || choice == 'Y',field);
	displayUsers();
	system("pause");
}

template<typename TypeGetter>
 void UserController::searchUsers(TypeGetter(User::* getter)() const)
{
	 std::string searchText = ConsoleIO::inputString("Введите текст для поиска:");
	 auto searchedUsers = _userRepository.searchItems(getter, searchText);

	 std::cout << std::setw(5) << "ID" << std::setw(25) << "Имя" << std::setw(20) << "Логин" << std::setw(20) << "Пароль" << std::setw(10) << "Уровень доступа" << std::endl;
	 std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	 for (int i = 0; i < searchedUsers.size(); i++) {
		 searchedUsers[i].toConsole();
	 }
	 system("pause");
}
