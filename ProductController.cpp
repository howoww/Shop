#include "ProductController.h"
ProductController::ProductController(ProductRepository& model) : _model(&model) { }

void ProductController::addProduct()
{
	char choice = 'n';
	do {

		Product product;
		product.setName(_view.inputString("Введите наименование товара:"));
		product.setCategory(_view.inputString("Введите категорию товара:"));
		product.setMark(_view.inputString("Введите марку товара:"));
		product.setCost(_view.inputValue<double>("Введите цену товара:"));
		_model->addItem(product);
		_model->saveData();
		_view.printColoredText("Товар успешно добавлен.", ConsoleView::Colors::Green);

		choice = _view.inputString("Хотите добавить еще товар?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	system("pause");
}
void ProductController::editProduct()
{
	char choice = 'n';
	do {
		int id = 0;
		id = _view.inputValue<int>("Введите ID товара:");
		Product* product = _model->getItemById(id);
		if (product != nullptr) {
			product->setName(_view.inputString("Введите новое наименование товара:"));
			product->setCategory(_view.inputString("Введите новую категорию товара:"));
			product->setMark(_view.inputString("Введите новую марку товара:"));
			product->setCost(_view.inputValue<double>("Введите новую цену товара:"));
			_model->saveData();
			_view.printColoredText("Товар успешно изменен.", ConsoleView::Colors::Green);
		}
		else
			_view.printColoredText("Товара с веденным ID не существует.", ConsoleView::Colors::Red);
		choice = _view.inputString("Хотите изменить еще товар?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	_model->saveData();
	system("pause");
}
void ProductController::deleteProduct()
{
	char choice = 'n';
	do {
		int id;
		id = _view.inputValue<int>("Введите ID товара:");
		std::string isDelete = _view.inputString("Вы уверены?(y - Да,n - Нет):");
		if (isDelete == "y" || isDelete == "Y")
			if (!_model->deleteItemById(id))
				_view.printColoredText("Товара с веденным ID не существует.", ConsoleView::Colors::Red);
			else
			{
				_model->saveData();
				_view.printColoredText("Товар успешно удален.", ConsoleView::Colors::Green);
			}
		choice = _view.inputString("Хотите удалить еще товар?(y - Да,n - Нет):")[0];
	} while (choice == 'y' || choice == 'Y');
	_model->saveData();
	system("pause");
}
void ProductController::displayProducts()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "Наименование" << std::setw(20) << "Категория" << std::setw(20) << "Марка" << std::setw(10) << "Цена" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _model->getAll().size(); i++) {
		_model->getAll()[i].toConsole();
	}
}

void ProductController::importCsvProducts()
{
	std::string filepath = _view.inputString("Введите путь к файлу(C:\\Template\\file.csv):");
	if (_model->importCsvProducts(filepath)) 
	{
		_model->saveData();
		_view.printColoredText("Данные импортированы.", ConsoleView::Colors::Green);
	}
	else
		_view.printColoredText("Произошла ошибка при импорте файлов.", ConsoleView::Colors::Red);
	system("pause");
}

void ProductController::exportCsvProducts()
{
	std::string filepath = _view.inputString("Введите путь к файлу(C:\\Template\\file.csv):");
	if (_model->exportCsvProducts(filepath))
		_view.printColoredText("Данные экспортированы.", ConsoleView::Colors::Green);
	else
		_view.printColoredText("Произошла ошибка при экспорте файлов.", ConsoleView::Colors::Red);
	system("pause");
}




