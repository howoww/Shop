#include "IDomain.h"


IDomain::IDomain() :_id(0) {}

int IDomain::getId()
{
	return _id;
}

void IDomain::setId(int id)
{
	_id = id;
}

void IDomain::toConsole()
{
	std::cout << std::left << std::setw(5) << _id;
}

void IDomain::serialize(std::ofstream& outFile)
{
	outFile.write((char*)&_id, sizeof(_id));
}

void IDomain::deserialize(std::ifstream& inFile)
{
	inFile.read((char*)&_id, sizeof(_id));
}
