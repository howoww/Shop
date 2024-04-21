#pragma once
#include "Domain.h"
#include "CSVData.h"
#include "StringExtension.h"
class Product : public Domain, public CSVData
{
private:
	std::string _name;
	double _cost;
	std::string _mark;
	std::string _category;
public:
	Product();
	Product(std::string name,std::string category, std::string mark, double cost );

	//Геттеры и сеттеры
	std::string getName() const;
	double getCost() const;
	std::string getMark() const;
	std::string getCategory() const;
	void setName(std::string name);
	void setCost(double cost);
	void setMark(std::string mark);
	void setCategory(std::string category);
	
	//Вывод в консоль
	void toConsole() override;

	// Унаследовано через CSVData
	std::string getCSVHeader(const char& separator) const override;
	std::string toCSVLine(const char& separator) const override;
	void parseCSVLine(const std::string& line, const char& separator) override;


	// Унаследовано через BinaryData
	void toBinary(std::ofstream& outFile) const override;
	void fromBinary(std::ifstream& inFile) override;

};

