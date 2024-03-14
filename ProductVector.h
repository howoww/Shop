#pragma once
#include <vector>
#include "Product.h"
#include <algorithm>
#include "CompareByMember.h"
class ProductVector
{
private:
	std::vector<Product> _products;
	std::string _filename;
public:
	void loadFromFile();
	void saveToFile();
	ProductVector();
	ProductVector(std::string filename);
	void addProduct(Product product);
	Product* getProductById(int id);
	bool deleteProductById(int id);
	std::vector<std::string> getLineProducts();
	void exportToCSV(std::string filepath);
	void importFromCSV(std::string filepath);

	template<typename T>
	void sort(T Product::* f, bool isAscending)
	{
		std::sort(_products.begin(), _products.end(), CompareByMember<Product, T>(f, isAscending));
	}
};