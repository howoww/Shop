#pragma once
#include "ProductController.h"
#include "MenuView.h"
class DefaultUserController
{
private:
	MenuView _menuView;
	ProductController _productController;
public:
	DefaultUserController() : _menuView("������� ����", std::vector<MenuView>{
		MenuView("������", std::vector<MenuView>{
			MenuView("������ �������", [&]() {_productController.displayProducts();  }),
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { _productController.searchProducts<int>(&Product::getId); }),
					MenuView("����� �� ������������", [&]() {_productController.searchProducts<std::string>(&Product::getName); }),
					MenuView("����� �� ���������", [&]() {_productController.searchProducts<std::string>(&Product::getCategory); }),
					MenuView("����� �� �����", [&]() {_productController.searchProducts<std::string>(&Product::getMark); }),
					MenuView("����� �� ����", [&]() {_productController.searchProducts<double>(&Product::getCost); })
			}),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() { _productController.sort<int>(&Product::getId); }),
					MenuView("����������� �� ������������", [&]() {_productController.sort<std::string>(&Product::getName); }),
					MenuView("����������� �� ���������", [&]() {_productController.sort<std::string>(&Product::getCategory); }),
					MenuView("����������� �� �����", [&]() {_productController.sort<std::string>(&Product::getMark); }),
					MenuView("����������� �� ����", [&]() {_productController.sort<double>(&Product::getCost); })
			})
		})}) {
		system("cls");
		_menuView.execute();
	};
};
