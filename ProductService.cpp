#include <iomanip>
#include "Product.h"

void ProductService::sortProductsByID()
{
	char choice = ConsoleInput::inputString("����������� ID �� �����������?(y - ��,n - ���):")[0];
	if (choice == 'y' || choice == 'Y')
		_products.sort<int>(&Product::_id, true);
	else
		_products.sort<int>(&Product::_id, false);
	displayProducts();
	system("pause");
}
void ProductService::sortProductsByName()
{
	char choice = ConsoleInput::inputString("����������� ������������ �� �����������?(y - ��,n - ���):")[0];
	if (choice == 'y' || choice == 'Y')
		_products.sort<std::string>(&Product::_name, true);
	else
		_products.sort<std::string>(&Product::_name, false);
	displayProducts();
	system("pause");
}
void ProductService::sortProductsByCategory()
{
	char choice = ConsoleInput::inputString("����������� ��������� �� �����������?(y - ��,n - ���):")[0];
	if (choice == 'y' || choice == 'Y')
		_products.sort<std::string>(&Product::_category, true);
	else
		_products.sort<std::string>(&Product::_category, false);
	displayProducts();
	system("pause");
}
void ProductService::sortProductsByCost()
{
	char choice = ConsoleInput::inputString("����������� ���� �� �����������?(y - ��,n - ���):")[0];
	if (choice == 'y' || choice == 'Y')
		_products.sort<double>(&Product::_cost, true);
	else
		_products.sort<double>(&Product::_cost, false);
	displayProducts();
	system("pause");
}

void ProductService::exportToCSV()
{
	std::string filepath = ConsoleInput::inputString("������� ���� ��� �������� �����('�:\\\\file.txt'):");
	_products.exportToCSV(filepath);
	system("pause");
}

void ProductService::importFromCSV()
{
	std::string filepath = ConsoleInput::inputString("������� ���� ��� ������� �����('�:\\\\file.txt'):");
	_products.importFromCSV(filepath);
	_products.saveToFile();
	system("pause");
}

