#pragma once
#include "Product.h"
#include "ConsoleInputView.h"
#include "ProductRepository.h"
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
};

