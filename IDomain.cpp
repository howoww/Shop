#include "IDomain.h"


IDomain::IDomain()
{
	_id = 0;
}

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
	std::cout << std::setw(5) << _id;
}
