#pragma once
#include "ProductController.h"
#include "MenuView.h"
class DefaultUserController : public ProductController
{
private:
	MenuView _menuView;
public:
	DefaultUserController() : _menuView("Главное меню", std::vector<MenuView>{
		MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {ProductController::displayProducts(); system("pause"); }),
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { ProductController::searchProducts<int>(&Product::getId); }),
					MenuView("Поиск по наименованию", [&]() {ProductController::searchProducts<std::string>(&Product::getName); }),
					MenuView("Поиск по категории", [&]() {ProductController::searchProducts<std::string>(&Product::getCategory); }),
					MenuView("Поиск по марке", [&]() {ProductController::searchProducts<std::string>(&Product::getMark); }),
					MenuView("Поиск по цене", [&]() {ProductController::searchProducts<double>(&Product::getCost); })
			}),
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
