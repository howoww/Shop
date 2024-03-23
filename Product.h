#pragma once
#include "IDomain.h"

class Product : public IDomain
{
private:
	std::string _name;
	double _cost;
	std::string _mark;
	std::string _category;
public:
	//Конструкторы
	Product();
	Product(std::string name, double cost, std::string mark, std::string category);

	//Геттеры и сеттеры
	std::string getName();
	double getCost();
	std::string getMark();
	std::string getCategory();
	void setName(std::string name);
	void setCost(double cost);
	void setMark(std::string mark);
	void setCategory(std::string category);
	
	//Вывод в консоль
	void toConsole() override;

	//Сериализация и десериализация
	void serialize(std::ofstream& outFile) override;
	void deserialize(std::ifstream& inFile) override;

	//Импорт и экспорт CSV
	void exportCSV(std::ofstream& outFile);
	void importCSV(std::string line);
	void writeCSVHeader(std::ofstream& outFile);
};

