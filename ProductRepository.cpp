#include "ProductRepository.h"

void ProductRepository::displayProducts()
{
    std::cout << std::setw(5) << "ID" << std::setw(25) << "Наименование" << std::setw(20) << "Категория" << std::setw(20) << "Марка" << std::setw(10) << "Цена" << std::endl;
    std::cout << std::setfill('-') << std::setw(70) << "" << std::setfill(' ') << std::endl;
    for (int i = 0; i < _items.size(); i++) {
        _items[i].toConsole();
    }
}
