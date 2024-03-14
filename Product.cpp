#include "Product.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
Product::Product()
{
	_name = "";
	_cost = 0;
	_mark = "";
	_category = "";
}
Product::Product(std::string name, double cost, std::string mark, std::string category)
{
	_name = name;
	_cost = cost;
	_mark = mark;
	_category = category;
}

std::string Product::getName()
{
	return _name;
}

double Product::getCost()
{
	return _cost;
}

std::string Product::getMark()
{
	return _mark;
}

std::string Product::getCategory()
{
	return _category;
}

void Product::setName(std::string name)
{
	_name = name;
}

void Product::setCost(double cost)
{
	_cost = cost;
}

void Product::setMark(std::string mark)
{
	_mark = mark;
}

void Product::setCategory(std::string category)
{
	_category = category;
}

void Product::toConsole()
{
	IDomain::toConsole();
	std::cout << std::setw(25) << _name << std::setw(20) << _category << std::setw(20)<< _mark << std::setw(10) << _cost << std::endl;
}





