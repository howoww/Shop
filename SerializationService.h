#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Domain.h"
class SerializationService
{
private:
	std::string _filename;
public:
	SerializationService(std::string filename) : _filename(filename) {
	};
	template <class Domain>
	void serializeRepository(std::vector<Domain>& vector);
	template <class Domain>
	void deserializeRepository(std::vector<Domain>& vector);
};
template <class Domain>
void SerializationService::serializeRepository(std::vector<Domain>& vector)
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
template <class Domain>
void SerializationService::deserializeRepository(std::vector<Domain>& vector)
{
	std::ifstream file(_filename, std::ios::binary);
	if (file) {
		size_t count;
		try {
			file.read((char*)&count, sizeof(count));
			for (size_t i = 0; i < count; i++) {
				Domain serializable;
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
