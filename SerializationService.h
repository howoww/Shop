#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "IDomain.h"
class SerializationService
{
private:
	std::string _filename;
public:
	SerializationService(std::string filename) : _filename(filename) {
	};
	template <class IDomain>
	void serializeRepository(std::vector<IDomain>& vector);
	template <class IDomain>
	void deserializeRepository(std::vector<IDomain>& vector);
};
template <class IDomain>
void SerializationService::serializeRepository(std::vector<IDomain>& vector)
{
	std::ofstream file(_filename, std::ios::binary);
	if (file) {
		size_t count = vector.size();
		if (count == 0) return;
		try {
			file.write((char*)&count, sizeof(count));
			for (int i = 0; i < count; i++) {
				vector[i].serialize(file);
			}
			file.close();
		}
		catch (...) {
			//Log Error
		}
	}
	else {
		//Log ErrorCreateFile
	}
}
template <class IDomain>
void SerializationService::deserializeRepository(std::vector<IDomain>& vector)
{
	std::ifstream file(_filename, std::ios::binary);
	if (file) {
		size_t count;
		try {
			file.read((char*)&count, sizeof(count));
			for (size_t i = 0; i < count; i++) {
				IDomain serializable;
				serializable.deserialize(file);
				vector.push_back(serializable);
			}
			file.close();
		}
		catch (...) {
			///Log Error
		}
	}
	else {
		//Log ErrorOpenFile
	}
}
