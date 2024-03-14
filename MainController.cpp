#include "MainController.h"
#include "Product.h"
#include "string"
void MainController::DisplayAdminMenu()
{
	menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������������", std::vector<MenuView>{
			MenuView("������ �������������", [&]() {userController.displayUsers(); system("pause"); }),
				MenuView("�������� ������������", [&]() { userController.addUser(); }),
				MenuView("������� ������������", [&]() {userController.editUser(); }),
				MenuView("������� ������������", [&]() {userController.deleteUser(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() {userController.sort<int>(&User::getId); }),
					MenuView("����������� �� �����", [&]() {userController.sort<std::string>(&User::getName); }),
					MenuView("����������� �� ������", [&]() {userController.sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("������", std::vector<MenuView>{
			MenuView("������ �������", [&]() {productController.displayProducts(); system("pause"); }),
				MenuView("�������� �����", [&]() {productController.addProduct(); }),
				MenuView("������� �����", [&]() {productController.editProduct(); }),
				MenuView("������� �����", [&]() {productController.deleteProduct(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() { productController.sort<int>(&Product::getId); }),
					MenuView("����������� �� ������������", [&]() {productController.sort<std::string>(&Product::getName); }),
					MenuView("����������� �� ���������", [&]() {productController.sort<std::string>(&Product::getCategory); }),
					MenuView("����������� �� �����", [&]() {productController.sort<std::string>(&Product::getMark); }),
					MenuView("����������� �� ����", [&]() {productController.sort<double>(&Product::getCost); })
			})
		}),
			MenuView("����� �� ��������", [&]() { userController.deauthorizeUser(); Display(); })});
}

void MainController::DisplayUserMenu()
{
	menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������ �������", [&]() {productController.displayProducts(); system("pause"); }),
			MenuView("����������", std::vector<MenuView>{
			MenuView("����������� �� ID", [&]() {productController.sort<int>(&Product::getId); }),
				MenuView("����������� �� ������������", [&]() {productController.sort<std::string>(&Product::getName); }),
				MenuView("����������� �� ���������", [&]() {productController.sort<std::string>(&Product::getCategory); }),
				MenuView("����������� �� �����", [&]() {productController.sort<std::string>(&Product::getMark); }),
				MenuView("����������� �� ����", [&]() {productController.sort<double>(&Product::getCost); })
		}),
			MenuView("����� �� ��������", [&]() { userController.deauthorizeUser(); Display(); })});
}

MainController::MainController()
{
	Display();
	menu.execute();
}

void MainController::Display()
{
	menu = MenuView("�����������", std::vector<MenuView>{
		MenuView("��������������", [&]() {
			userController.authorizeUser();
			if (userController.isLoggedIn())
				userController.isAdmin() ? DisplayAdminMenu() : DisplayUserMenu();
			}),
			MenuView("������������������", [&]() { userController.registerUser();  }),
	});
}
