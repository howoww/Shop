#pragma once
#include "Product.h"
#include "ConsoleView.h"
#include "ProductRepository.h"
#include "DomainComparator.h"
#include "Product.h"
#include "IDomain.h"
#include <filesystem>
class ProductController
{
private:
	ProductRepository* _model; //Model
	ConsoleView* _view; //View
public:
	ProductController(ProductRepository& model, ConsoleView& view);
	void addProduct();
	void editProduct();
	void deleteProduct();
	void displayProducts();
	void importCsvProducts();
	void exportCsvProducts();
	template<typename Type>
	void sort(Type (Product::* field)());

};

template<typename Type>
void ProductController::sort(Type (Product::* field)())
{
	char choice = _view->inputString("Сортировать по возрастанию?(y - Да,n - Нет):")[0];
	_model->sort(choice == 'y' || choice == 'Y', DomainComparator<Product, Type>(field));
	displayProducts();
	system("pause");
}
