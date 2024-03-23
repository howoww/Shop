#include "ProductRepository.h"

void ProductRepository::displayProducts()
{
	std::cout << std::setw(5) << "ID" << std::setw(25) << "Наименование" << std::setw(20) << "Категория" << std::setw(20) << "Марка" << std::setw(10) << "Цена" << std::endl;
	std::cout << std::left << std::setfill('-') << std::setw(80) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < _items.size(); i++) {
		_items[i].toConsole();
	}
}

//Эти методы лучше вынести в отдельный класс, но я не буду
bool ProductRepository::exportCsvProducts(std::string filepath)
{
	std::ofstream file(filepath);
	if (file) {
		size_t count = _items.size();
		if (count == 0) return false;
		try {
			_items[0].writeCSVHeader(file);
			for (size_t i = 0; i < count; i++) {
				_items[i].exportCSV(file);
			}
			file.close();
			return true;
		}
		catch (...) {
			//Log Error
		}
	}
	else {
		//Log ErrorCreateFile
	}
	return false;
}

bool ProductRepository::importCsvProducts(std::string filepath)
{
	std::ifstream file(filepath);
	if (file) {
		try {
			std::string line;
			std::getline(file, line);
			Product product;
			while (std::getline(file, line)) {
				if (!line.empty()) {
					product.importCSV(line);
					addItem(product);
				}
			}
			file.close();
			return true;
		}
		catch (...) {
			///Log Error
		}
	}
	else {
		//Log ErrorOpenFile
	}
	return false;
}
