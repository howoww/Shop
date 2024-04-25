#include "Domain.h"
int Domain::getId() const
{
	return _id;
}

void Domain::setId(const int& id)
{
	_id = id;
}

void Domain::toBinary(std::ofstream& outFile) const
{
	outFile.write((char*)&_id, sizeof(_id));
}

void Domain::fromBinary(std::ifstream& inFile)
{
	inFile.read((char*)&_id, sizeof(_id));
}

void Domain::toTableLine() const
{
	std::cout << std::left << std::setw(5) << _id;
}


