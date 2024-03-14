#pragma once
#include "Product.h"
#include "IRepository.h"
class ProductRepository :public  IRepository<Product>
{
public:
	void displayProducts();
};

