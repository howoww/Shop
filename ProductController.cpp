#include "ProductController.h"
ProductController::ProductController() : _productRepository(App::PRODUCTS_FILENAME) {
}

void ProductController::displayProducts(const std::vector<Product>& products)
{
	if (products.empty()) {
		std::cout << "Список пуст" << std::endl;
		return;
	}
	std::cout << "ID" << std::setw(5) << "Наименование" << std::setw(25) << "Категория" << std::setw(20) << "Марка" << std::setw(20) << "Цена" << std::setw(10) << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < products.size(); i++) {
		products[i].toTableLine();
	}
}

void ProductController::addProduct()
{
	char choice = 'n';
	do {
		Product product(
			ConsoleExtension::inputString("Введите наименование товара:"),
			ConsoleExtension::inputString("Введите категорию товара:"),
			ConsoleExtension::inputString("Введите марку товара:"),
			ConsoleExtension::inputPositiveValue<double>("Введите цену товара:"));
		_productRepository.addItem(product);
		try {
			_productRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		ConsoleExtension::printTextWithColor("Товар успешно добавлен.", ConsoleExtension::Colors::Green);
		choice = ConsoleExtension::inputChar("Хотите добавить еще товар?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		displayProducts();
		int id = 0;
		id = ConsoleExtension::inputPositiveValue<int>("Введите ID товара:");
		try {
			Product product = _productRepository.getItemById(id);
			product.setName(ConsoleExtension::inputString("Введите новое наименование товара:"));
			product.setCategory(ConsoleExtension::inputString("Введите новую категорию товара:"));
			product.setMark(ConsoleExtension::inputString("Введите новую марку товара:"));
			product.setCost(ConsoleExtension::inputPositiveValue<double>("Введите новую цену товара:"));
			_productRepository.UpdateItemById(product);
			ConsoleExtension::printTextWithColor("Товар успешно изменен.", ConsoleExtension::Colors::Green);
			_productRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		choice = ConsoleExtension::inputChar("Хотите изменить еще товар?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		displayProducts();
		std::vector<int> ids = ConsoleExtension::inputPositiveValues<int>("Введите ID товара/ов через пробел(1 2 3):", ' ');
		char isDelete = ConsoleExtension::inputChar("Вы уверены?(y - Да,n - Нет):");
		if (isDelete == 'y' || isDelete == 'Y')
		{
			try
			{
				_productRepository.deleteItemsByIds(ids);
				ConsoleExtension::printTextWithColor("Товар/ы успешно удален/ы", ConsoleExtension::Colors::Green);
				_productRepository.saveData();
			}
			catch (const std::exception& e) {
				ConsoleExtension::printError(e.what());
			}
		}
		choice = ConsoleExtension::inputChar("Хотите удалить еще товар/ы?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');

	system("pause");
}
void ProductController::displayProducts()
{
	const std::vector<Product>& products = _productRepository.getAll();
	displayProducts(products);
}

void ProductController::importFromCSV()
{
	std::string filepath = ConsoleExtension::inputString("Введите путь к csv файлу(C:\\Template\\file):");
	char separator = ConsoleExtension::inputString("Введите разделитель между данными(, или ;):")[0];
	if (separator == ',' || separator == ';')
	{
		try
		{
			_productRepository.importFromCSV(filepath, separator);
			_productRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
	}
	else
		ConsoleExtension::printTextWithColor("Неверный разделитель. Введите , или ;", ConsoleExtension::Colors::Red);

	system("pause");
}

void ProductController::exportToCSV()
{
	std::string filepath = ConsoleExtension::inputString("Введите путь к csv файлу(C:\\Template\\file):");
	char separator = ConsoleExtension::inputChar("Введите разделитель между данными(, или ;):");
	if (separator == ',' || separator == ';') {
		try
		{
			_productRepository.exportToCSV(filepath, separator);
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
	}
	else
		ConsoleExtension::printTextWithColor("Неверный разделитель. Введите , или ;", ConsoleExtension::Colors::Red);
	system("pause");
}







