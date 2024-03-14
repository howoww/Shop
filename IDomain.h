#pragma once
#include <iomanip>
#include <iostream>
class IDomain
{
private:
	int _id;
public:
	IDomain();
	int getId();
	void setId(int id);
	virtual void toConsole();
};

