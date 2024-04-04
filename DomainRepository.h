#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Domain.h"
#include "DomainComparator.h"
#include "SerializationService.h"

template <class Domain>
class DomainRepository
{
protected:
	std::string _filename;
	std::vector<Domain> _items;
public:
	DomainRepository(std::string filename);
	~DomainRepository();
	void addItem(Domain item);
	bool deleteItemById(int id);
	Domain* getItemById(int id);
	template<typename Type>
	void sort(bool isAscending, DomainComparator<Domain, Type> comparator);
};

template<class Domain>
DomainRepository<Domain>::DomainRepository(std::string filename) : _filename(filename)
{
	SerializationService _serializationService(_filename);
	_serializationService.deserializeRepository<Domain>(_items);
}

template<class Domain>
 DomainRepository<Domain>::~DomainRepository()
{
	 SerializationService _serializationService(_filename);
	 _serializationService.serializeRepository<Domain>(_items);
}

template<class Domain>
void DomainRepository<Domain>::addItem(Domain item)
{
	if (_items.size() != 0) item.setId(_items.back().getId() + 1);
	else item.setId(1);
	_items.push_back(item);
}

template<class Domain>
bool DomainRepository<Domain>::deleteItemById(int id)
{
	if (_items.size() == 0) return false;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) {
			_items.erase(_items.begin() + i);
			return true;
		}
	return false;
}

template<class Domain>
Domain* DomainRepository<Domain>::getItemById(int id)
{
	if (_items.size() == 0) return nullptr;
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) return &_items[i];
	return nullptr;
}

template<class Domain>
template<typename Type>
void DomainRepository<Domain>::sort(bool isAscending, DomainComparator<Domain, Type> comparator)
{
	isAscending ?
		std::sort(_items.begin(), _items.end(), comparator) :
		std::sort(_items.rbegin(), _items.rend(), comparator);
}
