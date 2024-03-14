#pragma once
#include "IDomain.h"
#include <vector>
#include <algorithm>
#include "DomainComparator.h"
template <class IDomain>
class IRepository
{
protected:
	std::vector<IDomain> _items;
public:
	virtual void addItem(IDomain item);
	virtual bool deleteItemById(int id);
	virtual IDomain* getItemById(int id);
	template<typename Type>
	void sort(bool isAscending, DomainComparator<IDomain, Type> comparator);
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

template<class IDomain>
template<typename Type>
void IRepository<IDomain>::sort(bool isAscending, DomainComparator<IDomain, Type> comparator)
{
	isAscending ?
		std::sort(_items.begin(), _items.end(), comparator) :
		std::sort(_items.rbegin(), _items.rend(), comparator);
}
