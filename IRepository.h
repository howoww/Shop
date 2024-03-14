#pragma once
#include "IDomain.h"
#include <vector>
template <class IDomain> 
class IRepository
{
protected:
	std::vector<IDomain> _items;
public:
	virtual void addItem(IDomain item);
	virtual bool deleteItemById(int id);
	virtual IDomain* getItemById(int id);
};

template<class IDomain>
void IRepository<IDomain>::addItem(IDomain item)
{
	if (_items.size() != 0) item.setId(_items.back().getId() + 1);
	else item.setId(1);
	_items.push_back(item);
}

template<class IDomain>
bool IRepository<IDomain>::deleteItemById(int id)
{
	if (_items.size() == 0) return false;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) {
			_items.erase(_items.begin() + i);
			return true;
		}
	return false;
}

template<class IDomain>
IDomain* IRepository<IDomain>::getItemById(int id)
{
	if (_items.size() == 0) return NULL;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) return &_items[i];
	return NULL;
}