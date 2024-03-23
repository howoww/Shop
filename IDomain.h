#pragma once
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
class IDomain 
{
private:
	int _id;
public:
	IDomain();
	int getId();
	void setId(int id);
	virtual void toConsole();

	virtual void serialize(std::ofstream& outFile);
	virtual void deserialize(std::ifstream& inFile);
};

