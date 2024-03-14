#include "ProductController.h"

void ProductController::addProduct()
{
	char choice = 'n';
	do {
		Product product;
		product.setName(_input.inputString("Введите наименование товара:"));
		product.setCategory(_input.inputString("Введите категорию товара:"));
		product.setMark(_input.inputString("Введите марку товара:"));
		product.setCost(_input.inputValue<double>("Введите цену товара:"));
		_model.addItem(product);
		_input.printColoredText("Товар успешно добавлен.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("Хотите добавить еще товар?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _input.inputValue<int>("Введите ID товара:");
		Product* product = _model.getItemById(id);
		if (product != NULL) {
			product->setName(_input.inputString("Введите новое наименование товара:"));
			product->setCategory(_input.inputString("Введите новую категорию товара:"));
			product->setMark(_input.inputString("Введите новую марку товара:"));
			product->setCost(_input.inputValue<double>("Введите новую цену товара:"));
			_input.printColoredText("Товар успешно изменен.", ConsoleInputView::Colors::Green);
		}
		else
			_input.printColoredText("Товара с веденным ID не существует.", ConsoleInputView::Colors::Red);
		choice = _input.inputString("Хотите изменить еще товар?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		int id;
		id = _input.inputValue<int>("Введите ID товара:");
		std::string choice = _input.inputString("Вы уверены?(y - Да,n - Нет):");
		if (choice == "y" || choice == "Y")
			if (!_model.deleteItemById(id))
				_input.printColoredText("Товара с веденным ID не существует.", ConsoleInputView::Colors::Red);
			else
				_input.printColoredText("Товар успешно удален.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("Хотите удалить еще товар?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void ProductController::displayProducts()
{
	_model.displayProducts();
}

