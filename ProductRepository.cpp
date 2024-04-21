#include "ProductRepository.h"

ProductRepository::ProductRepository(std::string filename) : DomainRepository(filename){}

void ProductRepository::exportToCSV(std::string filepath, char separator)
{
	CSVDataService<Product> csvService(separator);
	csvService.exportToCSV(_items, filepath);
}

void ProductRepository::importFromCSV(std::string filepath, char separator)
{
	CSVDataService<Product> csvService(separator);
	std::vector<Product> dataForImport;
	csvService.importFromCSV(dataForImport, filepath);
	if (!dataForImport.empty()) {
		addItems(dataForImport);
		ConsoleIO::printTextWithColor("������ ������������� �� " + filepath, ConsoleIO::Colors::Green);
	}
}
