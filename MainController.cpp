#include "MainController.h"

void MainController::DisplayAdminMenu()
{
	menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Пользователи", std::vector<MenuView>{
			MenuView("Список пользователей", [&]() {userController.displayUsers(); system("pause"); }),
				MenuView("Добавить пользователя", [&]() { userController.addUser(); }),
				MenuView("Изменть пользователя", [&]() {userController.editUser(); }),
				MenuView("Удалить пользователя", [&]() {userController.deleteUser(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", []() {}),
					MenuView("Сортировать по имени", []() {}),
					MenuView("Сортировать по логину", []() {})
			})
				
		}),
			MenuView("Товары", std::vector<MenuView>{
			MenuView("Список товаров", [&]() {productController.displayProducts(); system("pause"); }),
				MenuView("Добавить товар", [&]() {productController.addProduct(); }),
				MenuView("Изменть товар", [&]() {productController.editProduct(); }),
				MenuView("Удалить товар", [&]() {productController.deleteProduct(); }),
				MenuView("Сортировка", std::vector<MenuView>{
				MenuView("Сортировать по ID", []() {}),
					MenuView("Сортировать по наименованию", []() {}),
					MenuView("Сортировать по категории", []() {}),
					MenuView("Сортировать по марке", []() {}),
					MenuView("Сортировать по цене", []() {})
			})
		}),
			MenuView("Выйти из аккаунта", [&]() { userController.deauthorizeUser(); Display(); })});
}

void MainController::DisplayUserMenu()
{
	menu = MenuView("Главное меню", std::vector<MenuView>{
		MenuView("Список товаров", []() {}),
			MenuView("Сортировка", std::vector<MenuView>{
			MenuView("Сортировать по ID", []() {}),
				MenuView("Сортировать по наименованию", []() {}),
				MenuView("Сортировать по категории", []() {}),
				MenuView("Сортировать по марке", []() {}),
				MenuView("Сортировать по цене", []() {})
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
