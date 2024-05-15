#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "BinaryData.h"
#include "Product.h"
#include "ConsoleExtension.h"
template <typename T> requires std::is_base_of_v<BinaryData, T>
class BinaryDataService
{
private:
	std::string _filename;
public:
	BinaryDataService(const std::string& filename) : _filename(filename + ".bin") {};
	void saveToBinary(const std::vector<T>& data);
	void loadFromBinary(std::vector<T>& data);
};

template<typename T> requires std::is_base_of_v<BinaryData, T>
void BinaryDataService<T>::saveToBinary(const std::vector<T>& data)
{
		std::ofstream file(_filename, std::ios::binary);
		if (!file.is_open()) {
			throw std::exception("Файл не может быть открыт");
			return;
		}
		size_t sizeData = data.size();
		file.write((char*)&sizeData, sizeof(sizeData));
		for (size_t i = 0; i < sizeData; i++) {
			data[i].toBinary(file);
		}
		ConsoleExtension::printTextWithColor("Данные сохранены в " + _filename, ConsoleExtension::Colors::Green);
		file.close();
}

template<typename T> requires std::is_base_of_v<BinaryData, T>
void BinaryDataService<T>::loadFromBinary(std::vector<T>& data)
{
		std::ifstream file(_filename, std::ios::binary);
		if (!file.is_open()) {
			throw std::invalid_argument("Файл не может быть открыт");
		}
		size_t sizeData = 0;
		file.read((char*)&sizeData, sizeof(sizeData));
		if (sizeData == 0) {
			throw std::runtime_error("Невозможно загрузить файл");
		}
		std::vector<T> dataForLoad;
		for (size_t i = 0; i < sizeData; i++) {
			T tempItemData;
			tempItemData.fromBinary(file);
			dataForLoad.push_back(tempItemData);
		}
		data = dataForLoad;
		file.close();
}