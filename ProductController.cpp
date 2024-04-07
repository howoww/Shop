#include "ProductController.h"
ProductController::ProductController(ProductRepository& model) : _model(&model) { }

void ProductController::addProduct()
{
	char choice = 'n';
	do {

		Product product;
		product.setName(_view.inputString("������� ������������ ������:"));
		product.setCategory(_view.inputString("������� ��������� ������:"));
		product.setMark(_view.inputString("������� ����� ������:"));
		product.setCost(_view.inputValue<double>("������� ���� ������:"));
		_model->addItem(product);
		_model->saveData();
		_view.printColoredText("����� ������� ��������.", ConsoleView::Colors::Green);

		choice = _view.inputString("������ �������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _view.inputValue<int>("������� ID ������:");
		Product* product = _model->getItemById(id);
		if (product != nullptr) {
			product->setName(_view.inputString("������� ����� ������������ ������:"));
			product->setCategory(_view.inputString("������� ����� ��������� ������:"));
			product->setMark(_view.inputString("������� ����� ����� ������:"));
			product->setCost(_view.inputValue<double>("������� ����� ���� ������:"));
			_model->saveData();
			_view.printColoredText("����� ������� �������.", ConsoleView::Colors::Green);
		}
		else
			_view.printColoredText("������ � �������� ID �� ����������.", ConsoleView::Colors::Red);
		choice = _view.inputString("������ �������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	_model->saveData();
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		int id;
		id = _view.inputValue<int>("������� ID ������:");
		std::string isDelete = _view.inputString("�� �������?(y - ��,n - ���):");
		if (isDelete == "y" || isDelete == "Y")
			if (!_model->deleteItemById(id))
				_view.printColoredText("������ � �������� ID �� ����������.", ConsoleView::Colors::Red);
			else
			{
				_model->saveData();
				_view.printColoredText("����� ������� ������.", ConsoleView::Colors::Green);
			}
		choice = _view.inputString("������ ������� ��� �����?(y - ��,n - ���):")[0];
	} while (choice == 'y' || choice == 'Y');
	_model->saveData();
	system("pause");
}
void ProductController::displayProducts()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "������������" << std::setw(20) << "���������" << std::setw(20) << "�����" << std::setw(10) << "����" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _model->getAll().size(); i++) {
		_model->getAll()[i].toConsole();
	}
}

void ProductController::importCsvProducts()
{
	std::string filepath = _view.inputString("������� ���� � �����(C:\\Template\\file.csv):");
	if (_model->importCsvProducts(filepath)) 
	{
		_model->saveData();
		_view.printColoredText("������ �������������.", ConsoleView::Colors::Green);
	}
	else
		_view.printColoredText("��������� ������ ��� ������� ������.", ConsoleView::Colors::Red);
	system("pause");
}

void ProductController::exportCsvProducts()
{
	std::string filepath = _view.inputString("������� ���� � �����(C:\\Template\\file.csv):");
	if (_model->exportCsvProducts(filepath))
		_view.printColoredText("������ ��������������.", ConsoleView::Colors::Green);
	else
		_view.printColoredText("��������� ������ ��� �������� ������.", ConsoleView::Colors::Red);
	system("pause");
}




