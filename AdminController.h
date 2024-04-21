#pragma once
#include "ProductController.h"
#include "UserController.h"
#include "MenuView.h"
class AdminController : public ProductController, public UserController
{
private:
	MenuView _menuView;
public:
	AdminController() : _menuView("Главное меню", std::vector<MenuView>{
		MenuView("Пользователи", std::vector<MenuView>{
			MenuView("Список пользователей", [&]() {UserController::displayUsers(); system("pause"); }),
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { UserController::searchUsers<int>(&User::getId); }),
					MenuView("Поиск по имени", [&]() {UserController::searchUsers<std::string>(&User::getName); }),
					MenuView("Поиск по логину", [&]() {UserController::searchUsers<std::string>(&User::getLogin); })}),
				MenuView("Добавить пользователя", [&]() { UserController::addUser(); }),
				MenuView("Изменть пользователя", [&]() {UserController::editUser(); }),
				MenuView("Удалить пользователя", [&]() {UserController::deleteUser(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() {UserController::sort<int>(&User::getId); }),
					MenuView("Сортировать по имени", [&]() {UserController::sort<std::string>(&User::getName); }),
					MenuView("Сортировать по логину", [&]() {UserController::sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {ProductController::displayProducts(); system("pause"); }),
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { ProductController::searchProducts<int>(&Product::getId); }),
					MenuView("Поиск по наименованию", [&]() {ProductController::searchProducts<std::string>(&Product::getName); }),
					MenuView("Поиск по категории", [&]() {ProductController::searchProducts<std::string>(&Product::getCategory); }),
					MenuView("Поиск по марке", [&]() {ProductController::searchProducts<std::string>(&Product::getMark); }),
					MenuView("Поиск по цене", [&]() {ProductController::searchProducts<double>(&Product::getCost); })
			}),
				MenuView("Добавить товар", [&]() {ProductController::addProduct(); }),
				MenuView("Изменть товар", [&]() {ProductController::editProduct(); }),
				MenuView("Удалить товар", [&]() {ProductController::deleteProduct(); }),
				MenuView("Импорт из Csv", [&]() {ProductController::importFromCSV(); }),
				MenuView("Экспорт в Csv", [&]() {ProductController::exportToCSV(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() { ProductController::sort<int>(&Product::getId); }),
					MenuView("Сортировать по наименованию", [&]() {ProductController::sort<std::string>(&Product::getName); }),
					MenuView("Сортировать по категории", [&]() {ProductController::sort<std::string>(&Product::getCategory); }),
					MenuView("Сортировать по марке", [&]() {ProductController::sort<std::string>(&Product::getMark); }),
					MenuView("Сортировать по цене", [&]() {ProductController::sort<double>(&Product::getCost); })
			})
		})}) {
		system("cls");
		_menuView.execute();
	};
};

