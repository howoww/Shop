#include "Product.h"
Product::Product() :_cost(0.0) {}
Product::Product(std::string name, std::string category, std::string mark, double cost):_name(name), _cost(cost), _mark(mark), _category(category) 
{
}

std::string Product::getName() const
{
	return _name;
}

double Product::getCost() const
{
	return _cost;
}

std::string Product::getMark() const
{
	return _mark;
}

std::string Product::getCategory() const
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
	Domain::toConsole();
	std::cout << std::setw(25) << _name << std::setw(20) << _category << std::setw(20) << _mark << std::setw(10) << _cost << std::endl;
}

std::string Product::getCSVHeader(const char& separator) const
{
	return "Наименование товара" + std::string(1, separator) + "Категория" + std::string(1, separator) + "Марка" + std::string(1, separator) + "Цена";
}
std::string Product::toCSVLine(const char& separator) const
{
	return _name + std::string(1, separator) + _category + std::string(1, separator) + _mark + std::string(1, separator) + std::to_string(_cost);
}
void Product::parseCSVLine(const std::string& line, const char& separator)
{
	std::vector<std::string> splitStrings = StringExtension::split(line, separator);
	if (splitStrings.empty()) throw std::invalid_argument("Пустая строка");
	if (splitStrings.size() != 4) throw std::invalid_argument("Неверное количество полей в строке"); //Количество полей в классе
	_name = splitStrings[0];
	_category = splitStrings[1];
	_mark = splitStrings[2];
	_cost = std::stod(splitStrings[3]);
}


void Product::toBinary(std::ofstream& outFile) const
{
	Domain::toBinary(outFile);
	//Name
	size_t nameLength = _name.length();
	outFile.write((char*)&nameLength, sizeof(nameLength));
	outFile.write(_name.c_str(), nameLength);
	//Mark
	size_t markLength = _mark.length();
	outFile.write((char*)&markLength, sizeof(markLength));
	outFile.write(_mark.c_str(), markLength);
	//Category
	size_t categoryLength = _mark.length();
	outFile.write((char*)&categoryLength, sizeof(categoryLength));
	outFile.write(_category.c_str(), categoryLength);
	//Cost
	outFile.write((char*)&_cost, sizeof(_cost));
}

void Product::fromBinary(std::ifstream& inFile)
{
	Domain::fromBinary(inFile);
	//Name
	size_t nameLength;
	inFile.read((char*)&nameLength, sizeof(nameLength));
	std::vector<char> nameBuffer(nameLength + 1);
	inFile.read(nameBuffer.data(), nameLength);
	nameBuffer[nameLength] = '\0';
	_name = nameBuffer.data();
	//Mark
	size_t markLength;
	inFile.read((char*)&markLength, sizeof(markLength));
	std::vector<char> markBuffer(markLength + 1);
	inFile.read(markBuffer.data(), markLength);
	markBuffer[markLength] = '\0';
	_mark = markBuffer.data();
	//Category
	size_t categoryLength;
	inFile.read((char*)&categoryLength, sizeof(categoryLength));
	std::vector<char> categoryBuffer(categoryLength + 1);
	inFile.read(categoryBuffer.data(), categoryLength);
	categoryBuffer[categoryLength] = '\0';
	_category = categoryBuffer.data();
	//Cost
	inFile.read((char*)&_cost, sizeof(_cost));
}





