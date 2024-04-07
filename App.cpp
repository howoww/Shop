#include <Windows.h>
#include "MenuView.h"
#include <vector>
#include "ProductController.h"
#include "UserController.h"
#include "App.h"
#include "AuthorizationController.h"

UserRepository modelUser("users.ser");
ProductRepository modelProduct("products.ser");
MenuView _menu;
AuthorizationController authorizationController(modelUser);
UserController userController(modelUser);
ProductController productController(modelProduct);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DisplayAuthorization();
	_menu.execute();
	return 0;
}

void DisplayAuthorization() {
	_menu = MenuView("�����������", std::vector<MenuView>{
		MenuView("��������������", [&]() {
			authorizationController.authorizeUser();
			if (authorizationController.isLoggedIn())
				authorizationController.isAdmin() ? DisplayAdminMenu() : DisplayUserMenu();
			}),
			MenuView("������������������", [&]() { authorizationController.registerUser();  }),
	});
}

void DisplayAdminMenu()
{
	_menu = MenuView("������� ����", std::vector<MenuView>{
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
				MenuView("�����", std::vector<MenuView>{
				MenuView("����� �� ID", [&]() { productController.searchProducts<int>(&Product::getId); }),
					MenuView("����� �� ������������", [&]() {productController.searchProducts<std::string>(&Product::getName); }),
					MenuView("����� �� ���������", [&]() {productController.searchProducts<std::string>(&Product::getCategory); }),
					MenuView("����� �� �����", [&]() {productController.searchProducts<std::string>(&Product::getMark); }),
					MenuView("����� �� ����", [&]() {productController.searchProducts<double>(&Product::getCost); })
			}),
				MenuView("�������� �����", [&]() {productController.addProduct(); }),
				MenuView("������� �����", [&]() {productController.editProduct(); }),
				MenuView("������� �����", [&]() {productController.deleteProduct(); }),
				MenuView("������ �� Csv", [&]() {productController.importCsvProducts(); }),
				MenuView("������� � Csv", [&]() {productController.exportCsvProducts(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() { productController.sort<int>(&Product::getId); }),
					MenuView("����������� �� ������������", [&]() {productController.sort<std::string>(&Product::getName); }),
					MenuView("����������� �� ���������", [&]() {productController.sort<std::string>(&Product::getCategory); }),
					MenuView("����������� �� �����", [&]() {productController.sort<std::string>(&Product::getMark); }),
					MenuView("����������� �� ����", [&]() {productController.sort<double>(&Product::getCost); })
			})
		}),
			MenuView("����� �� ��������", [&]() {authorizationController.deauthorizeUser();  DisplayAuthorization(); })});
}

void DisplayUserMenu()
{
	_menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������ �������", [&]() {productController.displayProducts(); system("pause"); }),
			MenuView("�����", std::vector<MenuView>{
			MenuView("����� �� ID", [&]() { productController.searchProducts<int>(&Product::getId); }),
				MenuView("����� �� ������������", [&]() {productController.searchProducts<std::string>(&Product::getName); }),
				MenuView("����� �� ���������", [&]() {productController.searchProducts<std::string>(&Product::getCategory); }),
				MenuView("����� �� �����", [&]() {productController.searchProducts<std::string>(&Product::getMark); }),
				MenuView("����� �� ����", [&]() {productController.searchProducts<double>(&Product::getCost); })
		}),
			MenuView("����������", std::vector<MenuView>{
			MenuView("����������� �� ID", [&]() {productController.sort<int>(&Product::getId); }),
				MenuView("����������� �� ������������", [&]() {productController.sort<std::string>(&Product::getName); }),
				MenuView("����������� �� ���������", [&]() {productController.sort<std::string>(&Product::getCategory); }),
				MenuView("����������� �� �����", [&]() {productController.sort<std::string>(&Product::getMark); }),
				MenuView("����������� �� ����", [&]() {productController.sort<double>(&Product::getCost); })
		}),
			MenuView("����� �� ��������", [&]() {authorizationController.deauthorizeUser();  DisplayAuthorization(); })});
}

