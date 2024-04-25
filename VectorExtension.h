#pragma once
#include <vector>
#include <algorithm>
class VectorExtension {
public:
    template<typename T>
    static std::vector<T> removeMatchingElements(const std::vector<T>& firstVector, const std::vector<T>& secondVector) {
        std::vector<T> result;
        for (const T& element : firstVector) {
            if (std::find(secondVector.begin(), secondVector.end(), element) == secondVector.end()) {
                result.push_back(element);
            }
        }
        return result;
    }


};