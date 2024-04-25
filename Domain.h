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
	Domain() { _id = 0; };
	void setId(const int& id);
	int getId() const;
	virtual void toTableLine() const;

	// Унаследовано через BinaryData
	void toBinary(std::ofstream& outFile) const override;
	void fromBinary(std::ifstream& inFile) override;


};

