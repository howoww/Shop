#include "ProductController.h"

void ProductController::addProduct()
{
	char choice = 'n';
	do {
		Product product;
		product.setName(_input.inputString("������� ������������ ������:"));
		product.setCategory(_input.inputString("������� ��������� ������:"));
		product.setMark(_input.inputString("������� ����� ������:"));
		product.setCost(_input.inputValue<double>("������� ���� ������:"));
		_model.addItem(product);
		_input.printColoredText("����� ������� ��������.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("������ �������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _input.inputValue<int>("������� ID ������:");
		Product* product = _model.getItemById(id);
		if (product != NULL) {
			product->setName(_input.inputString("������� ����� ������������ ������:"));
			product->setCategory(_input.inputString("������� ����� ��������� ������:"));
			product->setMark(_input.inputString("������� ����� ����� ������:"));
			product->setCost(_input.inputValue<double>("������� ����� ���� ������:"));
			_input.printColoredText("����� ������� �������.", ConsoleInputView::Colors::Green);
		}
		else
			_input.printColoredText("������ � �������� ID �� ����������.", ConsoleInputView::Colors::Red);
		choice = _input.inputString("������ �������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		int id;
		id = _input.inputValue<int>("������� ID ������:");
		std::string choice = _input.inputString("�� �������?(y - ��,n - ���):");
		if (choice == "y" || choice == "Y")
			if (!_model.deleteItemById(id))
				_input.printColoredText("������ � �������� ID �� ����������.", ConsoleInputView::Colors::Red);
			else
				_input.printColoredText("����� ������� ������.", ConsoleInputView::Colors::Green);
		choice = _input.inputString("������ ������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}

void ProductController::displayProducts()
{
	_model.displayProducts();
}

