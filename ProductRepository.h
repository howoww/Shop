#pragma once
#include "Product.h"
#include "DomainRepository.h"
class ProductRepository : public  DomainRepository<Product>
{
public:
	ProductRepository(std::string filename) : DomainRepository<Product>(filename) {  };
	//Отображение товаров
	void displayProducts();
	bool exportCsvProducts(std::string filepath);
	bool importCsvProducts(std::string filepath);
};

