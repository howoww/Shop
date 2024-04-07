#pragma once
#include "Product.h"
#include "ConsoleView.h"
#include "ProductRepository.h"
#include "Product.h"
#include "Domain.h"
class ProductController
{

private:
	ProductRepository* _model; //Model
	ConsoleView _view; //View
	
public:
	ProductController(ProductRepository& model);
	~ProductController() {  };
	void addProduct();
	void editProduct();
	void deleteProduct();
	void displayProducts();
	void importCsvProducts();
	void exportCsvProducts();

	template<typename TypeGetter>
	void sort(TypeGetter (Product::* getter)());

	template<typename TypeGetter>
	void searchProducts(TypeGetter(Product::* getter)());
};

template<typename TypeGetter>
void ProductController::sort(TypeGetter (Product::* getter)())
{
	char choice = _view.inputString("Сортировать по возрастанию?(y - Да,n - Нет):")[0];
	_model->sort(choice == 'y' || choice == 'Y', getter);
	displayProducts();
	system("pause");
}

template<typename TypeGetter>
void ProductController::searchProducts(TypeGetter(Product::* getter)())
{
	std::string searchText = _view.inputString("Введите текст для поиска:");
	auto searchedProducts = _model->searchItems(getter, searchText);

	std::cout << std::setw(5) << "ID" << std::setw(25) << "Наименование" << std::setw(20) << "Категория" << std::setw(20) << "Марка" << std::setw(10) << "Цена" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < searchedProducts.size(); i++) {
		searchedProducts[i].toConsole();
	}
	system("pause");
}
