#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Domain.h"
#include <cctype>
#include "StringExtension.h"
#include "VectorExtension.h"
#include "BinaryDataService.h"
template <class Domain>
class DomainRepository
{
protected:
	std::string _filename;
	std::vector<Domain> _items;
public:
	DomainRepository(const std::string& filename);
	virtual void addItem(Domain& item);
	void addItems(std::vector<Domain>& items);
	void deleteItemsById(std::vector<int>& ids);
	Domain& getItemById(const int& id);
	std::vector<Domain> getAll() const;
	void saveData();
	template<typename TypeGetter>
	std::vector<Domain> searchItems(TypeGetter(Domain::* getter)() const, const std::string& searchText);
	template<typename TypeGetter>
	void sort(bool isAscending, TypeGetter(Domain::* getter)() const);

};

template<class Domain>
DomainRepository<Domain>::DomainRepository(const std::string& filename) : _filename(filename)
{
	BinaryDataService<Domain> _serializationService(_filename);
	_serializationService.loadFromBinary(_items);
}


template<class Domain>
void DomainRepository<Domain>::addItem(Domain& item)
{
	if (_items.size() != 0) item.setId(_items.back().getId() + 1);
	else item.setId(1);
	_items.push_back(item);
}

template<class Domain>
void DomainRepository<Domain>::addItems(std::vector<Domain>& items)
{
	if (items.empty())
		throw std::invalid_argument("�� ������ �� ����������");
	for (size_t i = 0; i < items.size(); i++) {
		addItem(items[i]);
	}
}

template<class Domain>
void DomainRepository<Domain>::deleteItemsById(std::vector<int>& ids)
{
	if (ids.empty())
		throw std::invalid_argument("�� ������ �� ��������");
	std::vector<int> rightIdsForDelete;
	//��������� ������������ ID
	for (size_t i = 0; i < _items.size(); i++) {
		for (size_t j = 0; j < ids.size(); j++) {
			if (_items[i].getId() == ids[j]) {
				rightIdsForDelete.push_back(ids[j]);
				break;
			}
		}
	}

	std::vector<int> missingIDs = VectorExtension::removeMatchingElements<int>(ids, rightIdsForDelete);
	if (!missingIDs.empty()) {
		std::string messageIDs;
		for (const int& id : missingIDs) {
			messageIDs += std::to_string(id) + ",";
		}
		messageIDs.pop_back();
		throw std::invalid_argument("�������� ��������, �� ���������� ��������� ID:" + messageIDs);
	} 
	else {
		for (size_t i = 0; i < _items.size(); i++) {
			for (size_t j = 0; j < rightIdsForDelete.size(); j++) {
				if (_items[i].getId() == rightIdsForDelete[j]) {
					_items.erase(_items.begin() + i);
					break;
				}
			}
		}
	}
}

template<class Domain>
Domain& DomainRepository<Domain>::getItemById(const int& id)
{
	for (int i = 0; i < _items.size(); i++)
		if (_items[i].getId() == id) return _items[i];
	throw
		std::invalid_argument("������� � id: " + std::to_string(id) + " �� ������");
}

template<class Domain>
std::vector<Domain> DomainRepository<Domain>::getAll() const
{
	return _items;
}

template<class Domain>
void DomainRepository<Domain>::saveData() 
{
	BinaryDataService<Domain> _serializationService(_filename);
	_serializationService.saveToBinary(_items);
}

template<class Domain>
template<typename TypeGetter>
std::vector<Domain> DomainRepository<Domain>::searchItems(TypeGetter(Domain::* getter)() const, const std::string& searchText)
{
	std::vector<Domain> findItems;
	for (int i = 0; i < _items.size(); i++) {
		std::ostringstream os;
		os << (_items[i].*getter)();
		if (StringExtension::toDownString(os.str()).find(StringExtension::toDownString(searchText)) != std::string::npos)
			findItems.push_back(_items[i]);
	}
	return findItems;
}

template<class Domain>
template<typename TypeGetter>
void DomainRepository<Domain>::sort(bool isAscending, TypeGetter(Domain::* getter)() const)
{
	isAscending ?
		std::sort(_items.begin(), _items.end(), [&](Domain& lhs, Domain& rhs) {return (lhs.*getter)() < (rhs.*getter)(); }) :
		std::sort(_items.rbegin(), _items.rend(), [&](Domain& lhs, Domain& rhs) {return (lhs.*getter)() < (rhs.*getter)(); });
}

