#include "ProductRepository.h"

ProductRepository::ProductRepository(const std::string& filename) : DomainRepository(filename){}

void ProductRepository::exportToCSV(const std::string& filepath, const char& separator) const
{
	CSVDataService<Product> csvService(separator);
	csvService.exportToCSV(_items, filepath);
}

void ProductRepository::importFromCSV(const std::string& filepath, const char& separator)
{
	CSVDataService<Product> csvService(separator);
	std::vector<Product> dataForImport;
	csvService.importFromCSV(dataForImport, filepath);
	if (!dataForImport.empty()) {
		addItems(dataForImport);
		ConsoleExtension::printTextWithColor("Данные импортированы из " + filepath, ConsoleExtension::Colors::Green);
	}
}
