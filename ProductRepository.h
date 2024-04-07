#pragma once
#include "Product.h"
#include "DomainRepository.h"
class ProductRepository : public  DomainRepository<Product>
{
public:
	ProductRepository(std::string filename) : DomainRepository<Product>(filename) {  };
	bool exportCsvProducts(std::string filepath);
	bool importCsvProducts(std::string filepath);
};

