#include "Product.h"
Product::Product() {}
Product::Product(std::string name, double cost, std::string mark, std::string category) :_name(name), _cost(cost), _mark(mark), _category(category) {}
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
	Domain::toConsole();
	std::cout << std::setw(25) << _name << std::setw(20) << _category << std::setw(20) << _mark << std::setw(10) << _cost << std::endl;
}

void Product::serialize(std::ofstream& outFile)
{
	Domain::serialize(outFile);
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

void Product::deserialize(std::ifstream& inFile)
{
	Domain::deserialize(inFile);
	//Name
	size_t nameLength;
	inFile.read((char*)&nameLength, sizeof(nameLength));
	std::vector<char> nameBuffer(nameLength + 1); // Добавляем 1 для завершающего нулевого символа
	inFile.read(nameBuffer.data(), nameLength);
	nameBuffer[nameLength] = '\0';
	_name = nameBuffer.data();
	//Mark
	size_t markLength;
	inFile.read((char*)&markLength, sizeof(markLength));
	std::vector<char> markBuffer(markLength + 1); // Добавляем 1 для завершающего нулевого символа
	inFile.read(markBuffer.data(), markLength);
	markBuffer[markLength] = '\0';
	_mark = markBuffer.data();
	//Category
	size_t categoryLength;
	inFile.read((char*)&categoryLength, sizeof(categoryLength));
	std::vector<char> categoryBuffer(categoryLength + 1); // Добавляем 1 для завершающего нулевого символа
	inFile.read(categoryBuffer.data(), categoryLength);
	categoryBuffer[categoryLength] = '\0';
	_category = categoryBuffer.data();
	//Cost
	inFile.read((char*)&_cost, sizeof(_cost));

}

void Product::exportCSV(std::ofstream& outFile)
{
	outFile << _name << "," << _category << "," << _mark << "," << _cost << std::endl;
}

void Product::importCSV(std::string line)
{
		std::stringstream ss(line);
		std::string token;
		
		std::getline(ss, token, ',');
		_name = token;

		std::getline(ss, token, ',');
		_mark = token;

		std::getline(ss, token, ',');
		_category = token;

		std::getline(ss, token, ',');
		_cost = std::stod(token);
}

void Product::writeCSVHeader(std::ofstream& outFile)
{
	outFile << "Наименование товара" << "," << "Категория" << "," << "Марка" << "," << "Цена" << std::endl;
}





