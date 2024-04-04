#pragma once
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
class Domain 
{
private:
	int _id;
public:
	Domain();
	int getId();
	void setId(int id);
	virtual void toConsole();

	virtual void serialize(std::ofstream& outFile);
	virtual void deserialize(std::ifstream& inFile);
};

