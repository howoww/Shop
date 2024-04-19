#include "Domain.h"
int Domain::getId()
{
	return _id;
}

void Domain::setId(int id)
{
	_id = id;
}

void Domain::toConsole()
{
	std::cout << std::left << std::setw(5) << _id;
}

void Domain::serialize(std::ofstream& outFile)
{
	outFile.write((char*)&_id, sizeof(_id));
}

void Domain::deserialize(std::ifstream& inFile)
{
	inFile.read((char*)&_id, sizeof(_id));
}
