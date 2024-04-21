#pragma once
#include "ProductController.h"
#include "MenuView.h"
class DefaultUserController : public ProductController
{
private:
	MenuView _menuView;
public:
	DefaultUserController() : _menuView("������� ����", std::vector<MenuView>{
		MenuView("������", std::vector<MenuView>{
			MenuView("������ �������", [&]() {ProductController::displayProducts(); system("pause"); }),
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { ProductController::searchProducts<int>(&Product::getId); }),
					MenuView("����� �� ������������", [&]() {ProductController::searchProducts<std::string>(&Product::getName); }),
					MenuView("����� �� ���������", [&]() {ProductController::searchProducts<std::string>(&Product::getCategory); }),
					MenuView("����� �� �����", [&]() {ProductController::searchProducts<std::string>(&Product::getMark); }),
					MenuView("����� �� ����", [&]() {ProductController::searchProducts<double>(&Product::getCost); })
			}),
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
