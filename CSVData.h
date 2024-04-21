#pragma once
#include <string>
class CSVData
{
public:
	virtual std::string toCSVLine(const char& separator) const = 0;
	virtual void parseCSVLine(const std::string& line, const char& separator) = 0;
	virtual std::string getCSVHeader(const char& separator) const = 0;
};

