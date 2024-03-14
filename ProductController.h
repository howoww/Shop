#pragma once
#include "Product.h"
#include "ConsoleInputView.h"
#include "ProductRepository.h"
#include "DomainComparator.h"
#include "Product.h"
#include "IDomain.h"
class ProductController
{
private:
	ProductRepository _model; //Model
	ConsoleInputView _input; //View
public:
	void addProduct();
	void editProduct();
	void deleteProduct();
	void displayProducts();
	template<typename Type>
	void sort(Type (Product::* field)());

};

template<typename Type>
void ProductController::sort(Type (Product::* field)())
{
	char choice = _input.inputString("Сортировать по возрастанию?(y - Да,n - Нет):")[0];
	_model.sort(choice == 'y' || choice == 'Y', DomainComparator<Product, Type>(field));
	displayProducts();
	system("pause");
}
