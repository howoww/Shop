#pragma once
#include <fstream>
class BinaryData
{
public:
	virtual void toBinary(std::ofstream& outFile) const = 0;
	virtual void fromBinary(std::ifstream& inFile) = 0;
};

