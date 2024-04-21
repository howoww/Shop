#pragma once
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "BinaryData.h"
class Domain : public BinaryData
{
private:
	int _id;
public:
	Domain() { _id = NULL; };
	int getId() const;
	void setId(int id);

	virtual void toConsole();

	// Унаследовано через BinaryData
	void toBinary(std::ofstream& outFile) const override;
	void fromBinary(std::ifstream& inFile) override;

};

