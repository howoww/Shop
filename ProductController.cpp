#include "ProductController.h"
ProductController::ProductController(): _productRepository("products") {
}

ProductController::~ProductController() { 
	_productRepository.saveData();
}

void ProductController::addProduct()
{
	char choice = 'n';
	do {
		Product product(
			ConsoleIO::inputString("Введите наименование товара:"),
			ConsoleIO::inputString("Введите категорию товара:"),
			ConsoleIO::inputString("Введите марку товара:"),
			ConsoleIO::inputPositiveValue<double>("Введите цену товара:"));
		_productRepository.addItem(product);
		ConsoleIO::printTextWithColor("Товар успешно добавлен.", ConsoleIO::Colors::Green);
		choice = ConsoleIO::inputChar("Хотите добавить еще товар?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = ConsoleIO::inputPositiveValue<int>("Введите ID товара:");
		try {
			Product product = _productRepository.getItemById(id);
			product.setName(ConsoleIO::inputString("Введите новое наименование товара:"));
			product.setCategory(ConsoleIO::inputString("Введите новую категорию товара:"));
			product.setMark(ConsoleIO::inputString("Введите новую марку товара:"));
			product.setCost(ConsoleIO::inputPositiveValue<double>("Введите новую цену товара:"));
			ConsoleIO::printTextWithColor("Товар успешно изменен.", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputChar("Хотите изменить еще товар?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		std::vector<int> ids = ConsoleIO::inputPositiveValues<int>("Введите ID товара/ов через пробел(1 2 3):", ' ');
		char isDelete = ConsoleIO::inputChar("Вы уверены?(y - Да,n - Нет):");
		if (isDelete == 'y' || isDelete == 'Y')
			try
		{
			_productRepository.deleteItemsById(ids);
			ConsoleIO::printTextWithColor("Товар/ы успешно удален/ы", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputChar("Хотите удалить еще товар/ы?(y - Да,n - Нет):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::displayProducts()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "Наименование" << std::setw(20) << "Категория" << std::setw(20) << "Марка" << std::setw(10) << "Цена" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _productRepository.getAll().size(); i++) {
		_productRepository.getAll()[i].toConsole();
	}
}

void ProductController::importFromCSV()
{
	std::string filepath = ConsoleIO::inputString("Введите путь к csv файлу(C:\\Template\\file):");
	char separator = ConsoleIO::inputString("Введите разделитель между данными(, или ;):")[0];
	if (separator == ',' || separator == ';')
	{
		_productRepository.importFromCSV(filepath, separator);
	}
	else
		ConsoleIO::printTextWithColor("Неверный разделитель. Введите , или ;", ConsoleIO::Colors::Red);
	system("pause");
}

void ProductController::exportToCSV()
{
	std::string filepath = ConsoleIO::inputString("Введите путь к csv файлу(C:\\Template\\file):");
	char separator = ConsoleIO::inputChar("Введите разделитель между данными(, или ;):");
	if (separator == ',' || separator == ';')
		_productRepository.exportToCSV(filepath, separator);
	else
		ConsoleIO::printTextWithColor("Неверный разделитель. Введите , или ;", ConsoleIO::Colors::Red);
	system("pause");
}

void ProductController::saveProducts()
{
	_productRepository.saveData();
	system("pause");
}





