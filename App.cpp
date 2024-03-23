#include <Windows.h>
#include "MenuView.h"
#include <vector>
#include "ProductController.h"
#include "UserController.h"
#include "App.h"
#include "AuthorizationController.h"

MenuView _menu;
ConsoleView _consoleView;
UserRepository _modelUser("users.ser");
ProductRepository _modelProduct("products.ser");
AuthorizationController _authorizationController(_modelUser, _consoleView);
UserController _userController(_modelUser, _consoleView);
ProductController _productController(_modelProduct, _consoleView);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DisplayAuthorization();
	_menu.execute();
	return 0;
}

void DisplayAuthorization(){
	_menu = MenuView("Авторизация", std::vector<MenuView>{
		MenuView("Авторизоваться", [&]() {
			_authorizationController.authorizeUser();
			if (_authorizationController.isLoggedIn())
				_authorizationController.isAdmin() ? DisplayAdminMenu() : DisplayUserMenu();
			}),
			MenuView("Зарегистрироваться", [&]() { _authorizationController.registerUser();  }),
	});
}

void DisplayAdminMenu()
{
	_menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Пользователи", std::vector<MenuView>{
			MenuView("Список пользователей", [&]() {_userController.displayUsers(); system("pause"); }),
				MenuView("Добавить пользователя", [&]() { _userController.addUser(); }),
				MenuView("Изменть пользователя", [&]() {_userController.editUser(); }),
				MenuView("Удалить пользователя", [&]() {_userController.deleteUser(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() {_userController.sort<int>(&User::getId); }),
					MenuView("Сортировать по имени", [&]() {_userController.sort<std::string>(&User::getName); }),
					MenuView("Сортировать по логину", [&]() {_userController.sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {_productController.displayProducts(); system("pause"); }),
				MenuView("Добавить товар", [&]() {_productController.addProduct(); }),
				MenuView("Изменть товар", [&]() {_productController.editProduct(); }),
				MenuView("Удалить товар", [&]() {_productController.deleteProduct(); }),
				MenuView("Импорт из Csv", [&]() {_productController.importCsvProducts(); }),
				MenuView("Экспорт в Csv", [&]() {_productController.exportCsvProducts(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() { _productController.sort<int>(&Product::getId); }),
					MenuView("Сортировать по наименованию", [&]() {_productController.sort<std::string>(&Product::getName); }),
					MenuView("Сортировать по категории", [&]() {_productController.sort<std::string>(&Product::getCategory); }),
					MenuView("Сортировать по марке", [&]() {_productController.sort<std::string>(&Product::getMark); }),
					MenuView("Сортировать по цене", [&]() {_productController.sort<double>(&Product::getCost); })
			})
		}),
			MenuView("Выйти из аккаунта", [&]() { _authorizationController.deauthorizeUser(); DisplayAuthorization(); })});
}

void DisplayUserMenu()
{
	_menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Список товаров", [&]() {_productController.displayProducts(); system("pause"); }),
			MenuView("Сортировка", std::vector<MenuView>{
			MenuView("Сортировать по ID", [&]() {_productController.sort<int>(&Product::getId); }),
				MenuView("Сортировать по наименованию", [&]() {_productController.sort<std::string>(&Product::getName); }),
				MenuView("Сортировать по категории", [&]() {_productController.sort<std::string>(&Product::getCategory); }),
				MenuView("Сортировать по марке", [&]() {_productController.sort<std::string>(&Product::getMark); }),
				MenuView("Сортировать по цене", [&]() {_productController.sort<double>(&Product::getCost); })
		}),
			MenuView("Выйти из аккаунта", [&]() { _authorizationController.deauthorizeUser();  DisplayAuthorization(); })});
}

