#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "CSVData.h"
#include "ConsoleExtension.h"
template <typename T> requires std::is_base_of_v<CSVData, T>
class CSVDataService
{
private:
	char _separator;
public:
	CSVDataService(char separator) { _separator = separator; }
	void exportToCSV(const std::vector<T>& data, const std::string& filepath) const;
	void importFromCSV(std::vector<T>& data, const std::string& filepath);
};

template <typename T> requires std::is_base_of_v<CSVData, T>
void CSVDataService<T>::exportToCSV(const std::vector<T>& data, const std::string& filepath) const {
	
		if (data.empty()) {
			throw std::invalid_argument("Попытка экспорта пустых данных");
		}
		std::ofstream file(filepath + ".csv");
		if (!file.is_open()) {
			throw std::exception("Файл " + filepath + " не может быть открыт");
		}
		file << data[0].getCSVHeader(_separator) << std::endl;
		for (const auto& value : data) {
			file << value.toCSVLine(_separator) << std::endl;
		}
		file.close();
		ConsoleExtension::printTextWithColor("Данные экспортированы в " + filepath, ConsoleExtension::Colors::Green);
}

template <typename T> requires std::is_base_of_v<CSVData, T>
void CSVDataService<T>::importFromCSV(std::vector<T>& data, const std::string& filepath) {
		std::ifstream file(filepath + ".csv");
		if (!file.is_open()) {
			throw std::invalid_argument("Файл " + filepath + " не может быть открыт");
		}
		std::string lineCSV;
		T tempItemData;
		std::vector<T> dataForImport;

		std::getline(file, lineCSV);
		if (!lineCSV.empty() && lineCSV != tempItemData.getCSVHeader(_separator)) {
			tempItemData.parseCSVLine(lineCSV, _separator);
			dataForImport.push_back(tempItemData);
		}
		while (std::getline(file, lineCSV)) {
			if (!lineCSV.empty()) {
				tempItemData.parseCSVLine(lineCSV, _separator);
				dataForImport.push_back(tempItemData);
			}
		}
		if (dataForImport.empty()) {
			throw std::invalid_argument("Файл для импорта пуст");
		}
		data.insert(data.end(), dataForImport.begin(), dataForImport.end());
		file.close();
}