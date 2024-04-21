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
	AdminController() : _menuView("������� ����", std::vector<MenuView>{
		MenuView("������������", std::vector<MenuView>{
			MenuView("������ �������������", [&]() {_userController.displayUsers(); system("pause"); }),
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { _userController.searchUsers<int>(&User::getId); }),
					MenuView("����� �� �����", [&]() {_userController.searchUsers<std::string>(&User::getName); }),
					MenuView("����� �� ������", [&]() {_userController.searchUsers<std::string>(&User::getLogin); })}),
				MenuView("�������� ������������", [&]() { _userController.addUser(); }),
				MenuView("������� ������������", [&]() {_userController.editUser(); }),
				MenuView("������� ������������", [&]() {_userController.deleteUser(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() {_userController.sort<int>(&User::getId); }),
					MenuView("����������� �� �����", [&]() {_userController.sort<std::string>(&User::getName); }),
					MenuView("����������� �� ������", [&]() {_userController.sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("������", std::vector<MenuView>{
			MenuView("������ �������", [&]() {_productController.displayProducts(); system("pause"); }),
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { _productController.searchProducts<int>(&Product::getId); }),
					MenuView("����� �� ������������", [&]() {_productController.searchProducts<std::string>(&Product::getName); }),
					MenuView("����� �� ���������", [&]() {_productController.searchProducts<std::string>(&Product::getCategory); }),
					MenuView("����� �� �����", [&]() {_productController.searchProducts<std::string>(&Product::getMark); }),
					MenuView("����� �� ����", [&]() {_productController.searchProducts<double>(&Product::getCost); })
			}),
				MenuView("�������� �����", [&]() {_productController.addProduct(); }),
				MenuView("������� �����", [&]() {_productController.editProduct(); }),
				MenuView("������� �����", [&]() {_productController.deleteProduct(); }),
				MenuView("������ �� Csv", [&]() {_productController.importFromCSV(); }),
				MenuView("������� � Csv", [&]() {_productController.exportToCSV(); }),
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

