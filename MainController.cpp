#include "MainController.h"
#include "Product.h"
#include "string"
void MainController::DisplayAdminMenu()
{
	menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Пользователи", std::vector<MenuView>{
			MenuView("Список пользователей", [&]() {userController.displayUsers(); system("pause"); }),
				MenuView("Добавить пользователя", [&]() { userController.addUser(); }),
				MenuView("Изменть пользователя", [&]() {userController.editUser(); }),
				MenuView("Удалить пользователя", [&]() {userController.deleteUser(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() {userController.sort<int>(&User::getId); }),
					MenuView("Сортировать по имени", [&]() {userController.sort<std::string>(&User::getName); }),
					MenuView("Сортировать по логину", [&]() {userController.sort<std::string>(&User::getLogin); })
			})
		}),
			MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {productController.displayProducts(); system("pause"); }),
				MenuView("Добавить товар", [&]() {productController.addProduct(); }),
				MenuView("Изменть товар", [&]() {productController.editProduct(); }),
				MenuView("Удалить товар", [&]() {productController.deleteProduct(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", [&]() { productController.sort<int>(&Product::getId); }),
					MenuView("Сортировать по наименованию", [&]() {productController.sort<std::string>(&Product::getName); }),
					MenuView("Сортировать по категории", [&]() {productController.sort<std::string>(&Product::getCategory); }),
					MenuView("Сортировать по марке", [&]() {productController.sort<std::string>(&Product::getMark); }),
					MenuView("Сортировать по цене", [&]() {productController.sort<double>(&Product::getCost); })
			})
		}),
			MenuView("Выйти из аккаунта", [&]() { userController.deauthorizeUser(); Display(); })});
}

void MainController::DisplayUserMenu()
{
	menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Список товаров", [&]() {productController.displayProducts(); system("pause"); }),
			MenuView("Сортировка", std::vector<MenuView>{
			MenuView("Сортировать по ID", [&]() {productController.sort<int>(&Product::getId); }),
				MenuView("Сортировать по наименованию", [&]() {productController.sort<std::string>(&Product::getName); }),
				MenuView("Сортировать по категории", [&]() {productController.sort<std::string>(&Product::getCategory); }),
				MenuView("Сортировать по марке", [&]() {productController.sort<std::string>(&Product::getMark); }),
				MenuView("Сортировать по цене", [&]() {productController.sort<double>(&Product::getCost); })
		}),
			MenuView("Выйти из аккаунта", [&]() { userController.deauthorizeUser(); Display(); })});
}

MainController::MainController()
{
	Display();
	menu.execute();
}

void MainController::Display()
{
	menu = MenuView("Авторизация", std::vector<MenuView>{
		MenuView("Авторизоваться", [&]() {
			userController.authorizeUser();
			if (userController.isLoggedIn())
				userController.isAdmin() ? DisplayAdminMenu() : DisplayUserMenu();
			}),
			MenuView("Зарегистрироваться", [&]() { userController.registerUser();  }),
	});
}
