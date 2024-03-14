#include "MainController.h"

void MainController::DisplayAdminMenu()
{
	menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������������", std::vector<MenuView>{
			MenuView("������ �������������", [&]() {userController.displayUsers(); system("pause"); }),
				MenuView("�������� ������������", [&]() { userController.addUser(); }),
				MenuView("������� ������������", [&]() {userController.editUser(); }),
				MenuView("������� ������������", [&]() {userController.deleteUser(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", []() {}),
					MenuView("����������� �� �����", []() {}),
					MenuView("����������� �� ������", []() {})
			})
				
		}),
			MenuView("������", std::vector<MenuView>{
			MenuView("������ �������", [&]() {productController.displayProducts(); system("pause"); }),
				MenuView("�������� �����", [&]() {productController.addProduct(); }),
				MenuView("������� �����", [&]() {productController.editProduct(); }),
				MenuView("������� �����", [&]() {productController.deleteProduct(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", []() {}),
					MenuView("����������� �� ������������", []() {}),
					MenuView("����������� �� ���������", []() {}),
					MenuView("����������� �� �����", []() {}),
					MenuView("����������� �� ����", []() {})
			})
		}),
			MenuView("����� �� ��������", [&]() { userController.deauthorizeUser(); Display(); })});
}

void MainController::DisplayUserMenu()
{
	menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������ �������", []() {}),
			MenuView("����������", std::vector<MenuView>{
			MenuView("����������� �� ID", []() {}),
				MenuView("����������� �� ������������", []() {}),
				MenuView("����������� �� ���������", []() {}),
				MenuView("����������� �� �����", []() {}),
				MenuView("����������� �� ����", []() {})
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
