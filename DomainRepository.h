#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "IDomain.h"
#include "DomainComparator.h"
#include "SerializationService.h"

template <class IDomain>
class DomainRepository
{
protected:
	std::string _filename;
	std::vector<IDomain> _items;
public:
	DomainRepository(std::string filename);
	~DomainRepository();
	void addItem(IDomain item);
	bool deleteItemById(int id);
	IDomain* getItemById(int id);
	template<typename Type>
	void sort(bool isAscending, DomainComparator<IDomain, Type> comparator);
};

template<class IDomain>
DomainRepository<IDomain>::DomainRepository(std::string filename) : _filename(filename)
{
	SerializationService _serializationService(_filename);
	_serializationService.deserializeRepository<IDomain>(_items);
}

template<class IDomain>
 DomainRepository<IDomain>::~DomainRepository()
{
	 SerializationService _serializationService(_filename);
	 _serializationService.serializeRepository<IDomain>(_items);
}

template<class IDomain>
void DomainRepository<IDomain>::addItem(IDomain item)
{
	if (_items.size() != 0) item.setId(_items.back().getId() + 1);
	else item.setId(1);
	_items.push_back(item);
}

template<class IDomain>
bool DomainRepository<IDomain>::deleteItemById(int id)
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
IDomain* DomainRepository<IDomain>::getItemById(int id)
{
	if (_items.size() == 0) return nullptr;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) return &_items[i];
	return nullptr;
}

template<class IDomain>
template<typename Type>
void DomainRepository<IDomain>::sort(bool isAscending, DomainComparator<IDomain, Type> comparator)
{
	isAscending ?
		std::sort(_items.begin(), _items.end(), comparator) :
		std::sort(_items.rbegin(), _items.rend(), comparator);
}
