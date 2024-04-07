#include <Windows.h>
#include "MenuView.h"
#include <vector>
#include "ProductController.h"
#include "UserController.h"
#include "App.h"
#include "AuthorizationController.h"

UserRepository modelUser("users.ser");
ProductRepository modelProduct("products.ser");
MenuView _menu;
AuthorizationController authorizationController(modelUser);
UserController userController(modelUser);
ProductController productController(modelProduct);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DisplayAuthorization();
	_menu.execute();
	return 0;
}

void DisplayAuthorization() {
	_menu = MenuView("Авторизация", std::vector<MenuView>{
		MenuView("Авторизоваться", [&]() {
			authorizationController.authorizeUser();
			if (authorizationController.isLoggedIn())
				authorizationController.isAdmin() ? DisplayAdminMenu() : DisplayUserMenu();
			}),
			MenuView("Зарегистрироваться", [&]() { authorizationController.registerUser();  }),
	});
}

void DisplayAdminMenu()
{
	_menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Пользователи", std::vector<MenuView>{
			MenuView("Список пользователей", [&]() {userController.displayUsers(); system("pause"); }),
				MenuView("Добавить пользователя", [&]() { userController.addUser(); }),
				MenuView("Изменть пользователя", [&]() {userController.editUser(); }),
				MenuView("Удалить пользователя", [&]() {userController.deleteUser(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() {userController.sort<int>(&User::getId); }),
					MenuView("Сортировать по имени", [&]() {userController.sort<std::string>(&User::getName); }),
					MenuView("Сортировать по логину", [&]() {userController.sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {productController.displayProducts(); system("pause"); }),
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { productController.searchProducts<int>(&Product::getId); }),
					MenuView("Поиск по наименованию", [&]() {productController.searchProducts<std::string>(&Product::getName); }),
					MenuView("Поиск по категории", [&]() {productController.searchProducts<std::string>(&Product::getCategory); }),
					MenuView("Поиск по марке", [&]() {productController.searchProducts<std::string>(&Product::getMark); }),
					MenuView("Поиск по цене", [&]() {productController.searchProducts<double>(&Product::getCost); })
			}),
				MenuView("Добавить товар", [&]() {productController.addProduct(); }),
				MenuView("Изменть товар", [&]() {productController.editProduct(); }),
				MenuView("Удалить товар", [&]() {productController.deleteProduct(); }),
				MenuView("Импорт из Csv", [&]() {productController.importCsvProducts(); }),
				MenuView("Экспорт в Csv", [&]() {productController.exportCsvProducts(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() { productController.sort<int>(&Product::getId); }),
					MenuView("Сортировать по наименованию", [&]() {productController.sort<std::string>(&Product::getName); }),
					MenuView("Сортировать по категории", [&]() {productController.sort<std::string>(&Product::getCategory); }),
					MenuView("Сортировать по марке", [&]() {productController.sort<std::string>(&Product::getMark); }),
					MenuView("Сортировать по цене", [&]() {productController.sort<double>(&Product::getCost); })
			})
		}),
			MenuView("Выйти из аккаунта", [&]() {authorizationController.deauthorizeUser();  DisplayAuthorization(); })});
}

void DisplayUserMenu()
{
	_menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Список товаров", [&]() {productController.displayProducts(); system("pause"); }),
			MenuView("Поиск", std::vector<MenuView>{
			MenuView("Поиск по ID", [&]() { productController.searchProducts<int>(&Product::getId); }),
				MenuView("Поиск по наименованию", [&]() {productController.searchProducts<std::string>(&Product::getName); }),
				MenuView("Поиск по категории", [&]() {productController.searchProducts<std::string>(&Product::getCategory); }),
				MenuView("Поиск по марке", [&]() {productController.searchProducts<std::string>(&Product::getMark); }),
				MenuView("Поиск по цене", [&]() {productController.searchProducts<double>(&Product::getCost); })
		}),
			MenuView("Сортировка", std::vector<MenuView>{
			MenuView("Сортировать по ID", [&]() {productController.sort<int>(&Product::getId); }),
				MenuView("Сортировать по наименованию", [&]() {productController.sort<std::string>(&Product::getName); }),
				MenuView("Сортировать по категории", [&]() {productController.sort<std::string>(&Product::getCategory); }),
				MenuView("Сортировать по марке", [&]() {productController.sort<std::string>(&Product::getMark); }),
				MenuView("Сортировать по цене", [&]() {productController.sort<double>(&Product::getCost); })
		}),
			MenuView("Выйти из аккаунта", [&]() {authorizationController.deauthorizeUser();  DisplayAuthorization(); })});
}

