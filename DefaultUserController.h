#pragma once
#include "ProductController.h"
#include "MenuView.h"
class DefaultUserController
{
private:
	MenuView _menuView;
	ProductController _productController;
public:
	DefaultUserController() : _menuView("Главное меню", std::vector<MenuView>{
		MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {_productController.displayProducts();  }),
				MenuView("Поиск", std::vector<MenuView>{
				MenuView("Поиск по ID", [&]() { _productController.searchProducts<int>(&Product::getId); }),
					MenuView("Поиск по наименованию", [&]() {_productController.searchProducts<std::string>(&Product::getName); }),
					MenuView("Поиск по категории", [&]() {_productController.searchProducts<std::string>(&Product::getCategory); }),
					MenuView("Поиск по марке", [&]() {_productController.searchProducts<std::string>(&Product::getMark); }),
					MenuView("Поиск по цене", [&]() {_productController.searchProducts<double>(&Product::getCost); })
			}),
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
