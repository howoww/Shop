#pragma once
#include "Product.h"
#include "ProductRepository.h"
#include "Product.h"
#include "Domain.h"
#include "ConsoleExtension.h"
#include "App.h"
class ProductController
{
private:
	ProductRepository _productRepository;
	void displayProducts(const std::vector<Product>& products);
public:
	ProductController();
	void addProduct();
	void editProduct();
	void deleteProduct();
	void displayProducts();
	void importFromCSV();
	void exportToCSV();
	template<typename TypeGetter>
	void sort(TypeGetter (Product::* getter)() const);

	template<typename TypeGetter>
	void searchProducts(TypeGetter(Product::* getter)() const);
};

template<typename TypeGetter>
void ProductController::sort(TypeGetter (Product::* getter)() const)
{
	char choice = ConsoleExtension::inputChar("Сортировать по возрастанию?(y - Да,n - Нет):");
	const std::vector<Product>& sortedProducts = _productRepository.getSortedVector(choice == 'y' || choice == 'Y', getter);
	displayProducts(sortedProducts);
	system("pause");
}

template<typename TypeGetter>
void ProductController::searchProducts(TypeGetter(Product::* getter)() const)
{
	std::string searchText = ConsoleExtension::inputString("Введите текст для поиска:");
	const std::vector<Product>& searchedProducts = _productRepository.searchItems(getter, searchText);
	displayProducts(searchedProducts);
	system("pause");
}
