#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "BinaryData.h"
#include "Product.h"
#include "ConsoleIO.h"
template <typename T> requires std::is_base_of_v<BinaryData, T>
class BinaryDataService
{
private:
	std::string _filename;
public:
	BinaryDataService(const std::string& filename) : _filename(filename + ".bin") {};
	void saveToBinary(std::vector<T>& data);
	void loadFromBinary(std::vector<T>& data);
};

template<typename T> requires std::is_base_of_v<BinaryData, T>
void BinaryDataService<T>::saveToBinary(std::vector<T>& data)
{
	try {
		if (data.empty()) {
			ConsoleIO::printError("Попытка сохранения пустых данных");
			return;
		}
		std::ofstream file(_filename, std::ios::binary);
		if (!file.is_open()) {
			ConsoleIO::printError("Файл не может быть открыт");
			return;
		}
		size_t sizeData = data.size();
		file.write((char*)&sizeData, sizeof(sizeData));
		for (size_t i = 0; i < sizeData; i++) {
			data[i].toBinary(file);
		}
		ConsoleIO::printTextWithColor("Данные сохранены в " + _filename, ConsoleIO::Colors::Green);
		file.close();
	}
	catch (const std::exception& e) {
		ConsoleIO::printError(e.what());
	}
	catch (...) {
		ConsoleIO::printError("Неизвестная ошибка");
	}

}

template<typename T> requires std::is_base_of_v<BinaryData, T>
void BinaryDataService<T>::loadFromBinary(std::vector<T>& data)
{
	try {
		std::ifstream file(_filename, std::ios::binary);
		if (!file.is_open()) {
			ConsoleIO::printError("Файл не может быть открыт");
			return;
		}
		size_t sizeData = NULL;
		file.read((char*)&sizeData, sizeof(sizeData));
		if (sizeData == NULL) {
			ConsoleIO::printError("Невозможно загрузить файл");
			return;
		}
		std::vector<T> dataForLoad;
		for (size_t i = 0; i < sizeData; i++) {
			T tempItemData;
			tempItemData.fromBinary(file);
			dataForLoad.push_back(tempItemData);
		}
		if (dataForLoad.empty()) {
			ConsoleIO::printError("Попытка загрузки пустого файла");
			return;
		}
		data = dataForLoad;
		file.close();
	}
	catch (const std::exception& e) {
		ConsoleIO::printError(e.what());
	}
	catch (...) {
		ConsoleIO::printError("Неизвестная ошибка");
	}
}