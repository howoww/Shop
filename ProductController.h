#pragma once
#include "Product.h"
#include "ProductRepository.h"
#include "Product.h"
#include "Domain.h"
#include "ConsoleIO.h"
class ProductController
{
private:
	ProductRepository _productRepository;
public:
	ProductController();
	~ProductController();
	void addProduct();
	void editProduct();
	void deleteProduct();
	void displayProducts();
	void importFromCSV();
	void exportToCSV();
	void saveProducts();
	template<typename TypeGetter>
	void sort(TypeGetter (Product::* getter)() const);

	template<typename TypeGetter>
	void searchProducts(TypeGetter(Product::* getter)() const);
};

template<typename TypeGetter>
void ProductController::sort(TypeGetter (Product::* getter)() const)
{
	char choice = ConsoleIO::inputChar("����������� �� �����������?(y - ��,n - ���):");
	_productRepository.sort(choice == 'y' || choice == 'Y', getter);
	displayProducts();
	system("pause");
}

template<typename TypeGetter>
void ProductController::searchProducts(TypeGetter(Product::* getter)() const)
{
	std::string searchText = ConsoleIO::inputString("������� ����� ��� ������:");
	auto searchedProducts = _productRepository.searchItems(getter, searchText);

	std::cout << std::setw(5) << "ID" << std::setw(25) << "������������" << std::setw(20) << "���������" << std::setw(20) << "�����" << std::setw(10) << "����" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < searchedProducts.size(); i++) {
		searchedProducts[i].toConsole();
	}
	system("pause");
}
