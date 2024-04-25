#pragma once
#include "Product.h"
#include "DomainRepository.h"
#include "CSVDataService.h"
class ProductRepository : public  DomainRepository<Product>
{
public:
	ProductRepository(const std::string& filename);
	void exportToCSV(const std::string& filepath, const char& separator) const;
	void importFromCSV(const std::string& filepath, const char& separator);
};

