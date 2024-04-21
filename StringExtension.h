#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <locale>
#include <algorithm>
class StringExtension {
public:
    static std::vector<std::string> split(const std::string& s, char delimiter) {
        if (s.empty()) {
            throw std::length_error("Передана пустая строка");
        }

        size_t pos = s.find(delimiter);
        if (pos == std::string::npos) {
            return { s };
        }

        std::vector<std::string> splitStrings;
        std::string splitString;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, splitString, delimiter)) {
            splitStrings.push_back(splitString);
        }
        return splitStrings;
    }

   static std::string toDownString(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return result;
    }
    // Другие методы расширения строк могут быть добавлены здесь
};