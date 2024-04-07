#include "ProductRepository.h"

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
