#include "ProductController.h"
ProductController::ProductController() : _productRepository(App::PRODUCTS_FILENAME) {
}

void ProductController::displayProducts(const std::vector<Product>& products)
{
	if (products.empty()) {
		std::cout << "������ ����" << std::endl;
		return;
	}
	std::cout << "ID" << std::setw(5) << "������������" << std::setw(25) << "���������" << std::setw(20) << "�����" << std::setw(20) << "����" << std::setw(10) << std::endl;
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
			ConsoleExtension::inputString("������� ������������ ������:"),
			ConsoleExtension::inputString("������� ��������� ������:"),
			ConsoleExtension::inputString("������� ����� ������:"),
			ConsoleExtension::inputPositiveValue<double>("������� ���� ������:"));
		_productRepository.addItem(product);
		try {
			_productRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		ConsoleExtension::printTextWithColor("����� ������� ��������.", ConsoleExtension::Colors::Green);
		choice = ConsoleExtension::inputChar("������ �������� ��� �����?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		displayProducts();
		int id = 0;
		id = ConsoleExtension::inputPositiveValue<int>("������� ID ������:");
		try {
			Product product = _productRepository.getItemById(id);
			product.setName(ConsoleExtension::inputString("������� ����� ������������ ������:"));
			product.setCategory(ConsoleExtension::inputString("������� ����� ��������� ������:"));
			product.setMark(ConsoleExtension::inputString("������� ����� ����� ������:"));
			product.setCost(ConsoleExtension::inputPositiveValue<double>("������� ����� ���� ������:"));
			_productRepository.UpdateItemById(product);
			ConsoleExtension::printTextWithColor("����� ������� �������.", ConsoleExtension::Colors::Green);
			_productRepository.saveData();
		}
		catch (const std::exception& e) {
			ConsoleExtension::printError(e.what());
		}
		choice = ConsoleExtension::inputChar("������ �������� ��� �����?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		displayProducts();
		std::vector<int> ids = ConsoleExtension::inputPositiveValues<int>("������� ID ������/�� ����� ������(1 2 3):", ' ');
		char isDelete = ConsoleExtension::inputChar("�� �������?(y - ��,n - ���):");
		if (isDelete == 'y' || isDelete == 'Y')
		{
			try
			{
				_productRepository.deleteItemsByIds(ids);
				ConsoleExtension::printTextWithColor("�����/� ������� ������/�", ConsoleExtension::Colors::Green);
				_productRepository.saveData();
			}
			catch (const std::exception& e) {
				ConsoleExtension::printError(e.what());
			}
		}
		choice = ConsoleExtension::inputChar("������ ������� ��� �����/�?(y - ��,n - ���):");
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
	std::string filepath = ConsoleExtension::inputString("������� ���� � csv �����(C:\\Template\\file):");
	char separator = ConsoleExtension::inputString("������� ����������� ����� �������(, ��� ;):")[0];
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
		ConsoleExtension::printTextWithColor("�������� �����������. ������� , ��� ;", ConsoleExtension::Colors::Red);

	system("pause");
}

void ProductController::exportToCSV()
{
	std::string filepath = ConsoleExtension::inputString("������� ���� � csv �����(C:\\Template\\file):");
	char separator = ConsoleExtension::inputChar("������� ����������� ����� �������(, ��� ;):");
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
		ConsoleExtension::printTextWithColor("�������� �����������. ������� , ��� ;", ConsoleExtension::Colors::Red);
	system("pause");
}







