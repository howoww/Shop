#include <Windows.h>
#include "MenuView.h"
#include <vector>
#include "ProductController.h"
#include "UserController.h"
#include "App.h"
#include "AuthorizationController.h"

MenuView _menu;
ConsoleView _consoleView;
UserRepository _modelUser("users.ser");
ProductRepository _modelProduct("products.ser");
AuthorizationController _authorizationController(_modelUser, _consoleView);
UserController _userController(_modelUser, _consoleView);
ProductController _productController(_modelProduct, _consoleView);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DisplayAuthorization();
	_menu.execute();
	return 0;
}

void DisplayAuthorization(){
	_menu = MenuView("�����������", std::vector<MenuView>{
		MenuView("��������������", [&]() {
			_authorizationController.authorizeUser();
			if (_authorizationController.isLoggedIn())
				_authorizationController.isAdmin() ? DisplayAdminMenu() : DisplayUserMenu();
			}),
			MenuView("������������������", [&]() { _authorizationController.registerUser();  }),
	});
}

void DisplayAdminMenu()
{
	_menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������������", std::vector<MenuView>{
			MenuView("������ �������������", [&]() {_userController.displayUsers(); system("pause"); }),
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
				MenuView("�������� �����", [&]() {_productController.addProduct(); }),
				MenuView("������� �����", [&]() {_productController.editProduct(); }),
				MenuView("������� �����", [&]() {_productController.deleteProduct(); }),
				MenuView("������ �� Csv", [&]() {_productController.importCsvProducts(); }),
				MenuView("������� � Csv", [&]() {_productController.exportCsvProducts(); }),
				MenuView("����������", std::vector<MenuView>{
				MenuView("����������� �� ID", [&]() { _productController.sort<int>(&Product::getId); }),
					MenuView("����������� �� ������������", [&]() {_productController.sort<std::string>(&Product::getName); }),
					MenuView("����������� �� ���������", [&]() {_productController.sort<std::string>(&Product::getCategory); }),
					MenuView("����������� �� �����", [&]() {_productController.sort<std::string>(&Product::getMark); }),
					MenuView("����������� �� ����", [&]() {_productController.sort<double>(&Product::getCost); })
			})
		}),
			MenuView("����� �� ��������", [&]() { _authorizationController.deauthorizeUser(); DisplayAuthorization(); })});
}

void DisplayUserMenu()
{
	_menu = MenuView("������� ����", std::vector<MenuView>{
		MenuView("������ �������", [&]() {_productController.displayProducts(); system("pause"); }),
			MenuView("����������", std::vector<MenuView>{
			MenuView("����������� �� ID", [&]() {_productController.sort<int>(&Product::getId); }),
				MenuView("����������� �� ������������", [&]() {_productController.sort<std::string>(&Product::getName); }),
				MenuView("����������� �� ���������", [&]() {_productController.sort<std::string>(&Product::getCategory); }),
				MenuView("����������� �� �����", [&]() {_productController.sort<std::string>(&Product::getMark); }),
				MenuView("����������� �� ����", [&]() {_productController.sort<double>(&Product::getCost); })
		}),
			MenuView("����� �� ��������", [&]() { _authorizationController.deauthorizeUser();  DisplayAuthorization(); })});
}

