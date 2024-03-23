#include "ProductController.h"
ProductController::ProductController(ProductRepository& model, ConsoleView& view) : _model(&model), _view(&view) {}

void ProductController::addProduct()
{
	char choice = 'n';
	do {
		Product product;
		product.setName(_view->inputString("������� ������������ ������:"));
		product.setCategory(_view->inputString("������� ��������� ������:"));
		product.setMark(_view->inputString("������� ����� ������:"));
		product.setCost(_view->inputValue<double>("������� ���� ������:"));
		_model->addItem(product);
		_view->printColoredText("����� ������� ��������.", ConsoleView::Colors::Green);
		choice = _view->inputString("������ �������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _view->inputValue<int>("������� ID ������:");
		Product* product = _model->getItemById(id);
		if (product != nullptr) {
			product->setName(_view->inputString("������� ����� ������������ ������:"));
			product->setCategory(_view->inputString("������� ����� ��������� ������:"));
			product->setMark(_view->inputString("������� ����� ����� ������:"));
			product->setCost(_view->inputValue<double>("������� ����� ���� ������:"));
			_view->printColoredText("����� ������� �������.", ConsoleView::Colors::Green);
		}
		else
			_view->printColoredText("������ � �������� ID �� ����������.", ConsoleView::Colors::Red);
		choice = _view->inputString("������ �������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		int id;
		id = _view->inputValue<int>("������� ID ������:");
		std::string isDelete = _view->inputString("�� �������?(y - ��,n - ���):");
		if (isDelete == "y" || isDelete == "Y")
			if (!_model->deleteItemById(id))
				_view->printColoredText("������ � �������� ID �� ����������.", ConsoleView::Colors::Red);
			else
				_view->printColoredText("����� ������� ������.", ConsoleView::Colors::Green);
		choice = _view->inputString("������ ������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::displayProducts()
{
	_model->displayProducts();
}

void ProductController::importCsvProducts()
{
	std::string filepath = _view->inputString("������� ���� � �����(C:\\Template\\file.csv):");
	if (_model->importCsvProducts(filepath)) 
		_view->printColoredText("������ �������������.", ConsoleView::Colors::Green);
	else
		_view->printColoredText("��������� ������ ��� ������� ������.", ConsoleView::Colors::Red);
	system("pause");
}

void ProductController::exportCsvProducts()
{
	//_model->exportCsvProducts("1.csv");
	//_model->importCsvProducts("1.csv");
	std::string filepath = _view->inputString("������� ���� � �����(C:\\Template\\file.csv):");
	if (_model->exportCsvProducts(filepath))
		_view->printColoredText("������ ��������������.", ConsoleView::Colors::Green);
	else
		_view->printColoredText("��������� ������ ��� �������� ������.", ConsoleView::Colors::Red);
	system("pause");
}




