#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Domain.h"
#include <cctype>
#include "SerializationService.h"

template <class Domain>
class DomainRepository
{
protected:
	std::string _filename;
	std::vector<Domain> _items;
public:
	DomainRepository(std::string filename);

	void addItem(Domain item);

	bool deleteItemById(int id);

	Domain* getItemById(int id);

	std::vector<Domain> getAll();

	void saveData();

	template<typename TypeGetter>
	std::vector<Domain> searchItems(TypeGetter(Domain::* getter)(), std::string searchText);

	template<typename TypeGetter>
	void sort(bool isAscending, TypeGetter(Domain::* getter)());

};

template<class Domain>
DomainRepository<Domain>::DomainRepository(std::string filename) : _filename(filename) 
{
	SerializationService _serializationService(_filename);
	_serializationService.deserializeRepository<Domain>(_items);
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
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) return &_items[i];
	return nullptr;
}

template<class Domain>
std::vector<Domain> DomainRepository<Domain>::getAll()
{
	return _items;
}

template<class Domain>
 void DomainRepository<Domain>::saveData()
{
	 SerializationService _serializationService(_filename);
	 _serializationService.serializeRepository<Domain>(_items);
}

template<class Domain>
template<typename TypeGetter>
std::vector<Domain> DomainRepository<Domain>::searchItems(TypeGetter(Domain::* getter)(), std::string searchText)
{
	std::vector<Domain> findItems;
	for (int i = 0; i < _items.size(); i++) {
		std::ostringstream os;
		os << (_items[i].*getter)();
		if (os.str().find(searchText) != std::string::npos) findItems.push_back(_items[i]);
	}
	return findItems;
}

template<class Domain>
template<typename TypeGetter>
void DomainRepository<Domain>::sort(bool isAscending, TypeGetter(Domain::* getter)())
{
	isAscending ?
		std::sort(_items.begin(), _items.end(), [&](Domain& lhs, Domain& rhs) {return (lhs.*getter)() < (rhs.*getter)(); }) :
		std::sort(_items.rbegin(), _items.rend(), [&](Domain& lhs, Domain& rhs) {return (lhs.*getter)() < (rhs.*getter)(); });
}

