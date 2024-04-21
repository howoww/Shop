#pragma once
#include "ProductController.h"
#include "UserController.h"
#include "MenuView.h"
class AdminController : public ProductController, public UserController
{
private:
	MenuView _menuView;
public:
	AdminController() : _menuView("������� ����", std::vector<MenuView>{
		MenuView("������������", std::vector<MenuView>{
			MenuView("������ �������������", [&]() {UserController::displayUsers(); system("pause"); }),
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { UserController::searchUsers<int>(&User::getId); }),
					MenuView("����� �� �����", [&]() {UserController::searchUsers<std::string>(&User::getName); }),
					MenuView("����� �� ������", [&]() {UserController::searchUsers<std::string>(&User::getLogin); })}),
				MenuView("�������� ������������", [&]() { UserController::addUser(); }),
				MenuView("������� ������������", [&]() {UserController::editUser(); }),
				MenuView("������� ������������", [&]() {UserController::deleteUser(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() {UserController::sort<int>(&User::getId); }),
					MenuView("����������� �� �����", [&]() {UserController::sort<std::string>(&User::getName); }),
					MenuView("����������� �� ������", [&]() {UserController::sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("������", std::vector<MenuView>{
			MenuView("������ �������", [&]() {ProductController::displayProducts(); system("pause"); }),
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { ProductController::searchProducts<int>(&Product::getId); }),
					MenuView("����� �� ������������", [&]() {ProductController::searchProducts<std::string>(&Product::getName); }),
					MenuView("����� �� ���������", [&]() {ProductController::searchProducts<std::string>(&Product::getCategory); }),
					MenuView("����� �� �����", [&]() {ProductController::searchProducts<std::string>(&Product::getMark); }),
					MenuView("����� �� ����", [&]() {ProductController::searchProducts<double>(&Product::getCost); })
			}),
				MenuView("�������� �����", [&]() {ProductController::addProduct(); }),
				MenuView("������� �����", [&]() {ProductController::editProduct(); }),
				MenuView("������� �����", [&]() {ProductController::deleteProduct(); }),
				MenuView("������ �� Csv", [&]() {ProductController::importFromCSV(); }),
				MenuView("������� � Csv", [&]() {ProductController::exportToCSV(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() { ProductController::sort<int>(&Product::getId); }),
					MenuView("����������� �� ������������", [&]() {ProductController::sort<std::string>(&Product::getName); }),
					MenuView("����������� �� ���������", [&]() {ProductController::sort<std::string>(&Product::getCategory); }),
					MenuView("����������� �� �����", [&]() {ProductController::sort<std::string>(&Product::getMark); }),
					MenuView("����������� �� ����", [&]() {ProductController::sort<double>(&Product::getCost); })
			})
		})}) {
		system("cls");
		_menuView.execute();
	};
};

