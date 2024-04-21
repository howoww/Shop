#pragma once
#include "ProductController.h"
#include "UserController.h"
#include "MenuView.h"
class AdminController
{
private:
	MenuView _menuView;
	ProductController _productController;
	UserController _userController;
public:
	AdminController() : _menuView("Главное меню", std::vector<MenuView>{
		MenuView("Пользователи", std::vector<MenuView>{
			MenuView("Список пользователей", [&]() {_userController.displayUsers(); system("pause"); }),
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { _userController.searchUsers<int>(&User::getId); }),
					MenuView("Поиск по имени", [&]() {_userController.searchUsers<std::string>(&User::getName); }),
					MenuView("Поиск по логину", [&]() {_userController.searchUsers<std::string>(&User::getLogin); })}),
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
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { _productController.searchProducts<int>(&Product::getId); }),
					MenuView("Поиск по наименованию", [&]() {_productController.searchProducts<std::string>(&Product::getName); }),
					MenuView("Поиск по категории", [&]() {_productController.searchProducts<std::string>(&Product::getCategory); }),
					MenuView("Поиск по марке", [&]() {_productController.searchProducts<std::string>(&Product::getMark); }),
					MenuView("Поиск по цене", [&]() {_productController.searchProducts<double>(&Product::getCost); })
			}),
				MenuView("Добавить товар", [&]() {_productController.addProduct(); }),
				MenuView("Изменть товар", [&]() {_productController.editProduct(); }),
				MenuView("Удалить товар", [&]() {_productController.deleteProduct(); }),
				MenuView("Импорт из Csv", [&]() {_productController.importFromCSV(); }),
				MenuView("Экспорт в Csv", [&]() {_productController.exportToCSV(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() { _productController.sort<int>(&Product::getId); }),
					MenuView("Сортировать по наименованию", [&]() {_productController.sort<std::string>(&Product::getName); }),
					MenuView("Сортировать по категории", [&]() {_productController.sort<std::string>(&Product::getCategory); }),
					MenuView("Сортировать по марке", [&]() {_productController.sort<std::string>(&Product::getMark); }),
					MenuView("Сортировать по цене", [&]() {_productController.sort<double>(&Product::getCost); })
			})
		})}) {
		system("cls");
		_menuView.execute();
	};
};

