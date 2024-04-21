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
			ConsoleIO::inputString("������� ������������ ������:"),
			ConsoleIO::inputString("������� ��������� ������:"),
			ConsoleIO::inputString("������� ����� ������:"),
			ConsoleIO::inputPositiveValue<double>("������� ���� ������:"));
		_productRepository.addItem(product);
		ConsoleIO::printTextWithColor("����� ������� ��������.", ConsoleIO::Colors::Green);
		choice = ConsoleIO::inputChar("������ �������� ��� �����?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = ConsoleIO::inputPositiveValue<int>("������� ID ������:");
		try {
			Product product = _productRepository.getItemById(id);
			product.setName(ConsoleIO::inputString("������� ����� ������������ ������:"));
			product.setCategory(ConsoleIO::inputString("������� ����� ��������� ������:"));
			product.setMark(ConsoleIO::inputString("������� ����� ����� ������:"));
			product.setCost(ConsoleIO::inputPositiveValue<double>("������� ����� ���� ������:"));
			ConsoleIO::printTextWithColor("����� ������� �������.", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputChar("������ �������� ��� �����?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		std::vector<int> ids = ConsoleIO::inputPositiveValues<int>("������� ID ������/�� ����� ������(1 2 3):", ' ');
		char isDelete = ConsoleIO::inputChar("�� �������?(y - ��,n - ���):");
		if (isDelete == 'y' || isDelete == 'Y')
			try
		{
			_productRepository.deleteItemsById(ids);
			ConsoleIO::printTextWithColor("�����/� ������� ������/�", ConsoleIO::Colors::Green);
		}
		catch (const std::exception& e) {
			ConsoleIO::printError(e.what());
		}
		choice = ConsoleIO::inputChar("������ ������� ��� �����/�?(y - ��,n - ���):");
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::displayProducts()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "������������" << std::setw(20) << "���������" << std::setw(20) << "�����" << std::setw(10) << "����" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _productRepository.getAll().size(); i++) {
		_productRepository.getAll()[i].toConsole();
	}
}

void ProductController::importFromCSV()
{
	std::string filepath = ConsoleIO::inputString("������� ���� � csv �����(C:\\Template\\file):");
	char separator = ConsoleIO::inputString("������� ����������� ����� �������(, ��� ;):")[0];
	if (separator == ',' || separator == ';')
	{
		_productRepository.importFromCSV(filepath, separator);
	}
	else
		ConsoleIO::printTextWithColor("�������� �����������. ������� , ��� ;", ConsoleIO::Colors::Red);
	system("pause");
}

void ProductController::exportToCSV()
{
	std::string filepath = ConsoleIO::inputString("������� ���� � csv �����(C:\\Template\\file):");
	char separator = ConsoleIO::inputChar("������� ����������� ����� �������(, ��� ;):");
	if (separator == ',' || separator == ';')
		_productRepository.exportToCSV(filepath, separator);
	else
		ConsoleIO::printTextWithColor("�������� �����������. ������� , ��� ;", ConsoleIO::Colors::Red);
	system("pause");
}

void ProductController::saveProducts()
{
	_productRepository.saveData();
	system("pause");
}





