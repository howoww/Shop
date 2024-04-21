#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "CSVData.h"
#include "ConsoleIO.h"
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
	try {
		if (data.empty()) {
			ConsoleIO::printError("Попытка экспорта пустых данных");
			return;
		}
		std::ofstream file(filepath + ".csv");
		if (!file.is_open()) {
			ConsoleIO::printError("Файл не может быть открыт");
			return;
		}
		file << data[0].getCSVHeader(_separator) << std::endl;
		for (const auto& value : data) {
			file << value.toCSVLine(_separator) << std::endl;
		}
		file.close();
		ConsoleIO::printTextWithColor("Данные экспортированы в " + filepath, ConsoleIO::Colors::Green);
	}
	catch (const std::exception& e) {
		ConsoleIO::printError(e.what());
	}
	catch (...) {
		ConsoleIO::printError("Неизвестная ошибка");
	}
}

template <typename T> requires std::is_base_of_v<CSVData, T>
void CSVDataService<T>::importFromCSV(std::vector<T>& data, const std::string& filepath) {
	try {
		std::ifstream file(filepath + ".csv");
		if (!file.is_open()) {
			ConsoleIO::printError("Файл не может быть открыт");
			return;
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
			ConsoleIO::printError("Попытка импорта пустых данных");
			return;
		}
		data.insert(data.end(), dataForImport.begin(), dataForImport.end());
		file.close();
	}
	catch (const std::exception& e) {
		ConsoleIO::printError(e.what());
	}
	catch (...) {
		ConsoleIO::printError("Неизвестная ошибка");
	}
}