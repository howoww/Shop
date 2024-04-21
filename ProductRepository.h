#pragma once
#include "Product.h"
#include "DomainRepository.h"
#include "CSVDataService.h"
class ProductRepository : public  DomainRepository<Product>
{
public:
	ProductRepository(std::string filename);
	void exportToCSV(std::string filepath, char separator);
	void importFromCSV(std::string filepath, char separator);
};

