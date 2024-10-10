// Rainfall.cpp
#include "Rainfall.h"

Rainfall::Rainfall() : month(""), rainfall(0) {}

Rainfall::Rainfall(const std::string& month, int rainfall) : month(month), rainfall(rainfall) {}

std::string Rainfall::getMonth() const {
    return month;
}

int Rainfall::getRainfall() const {
    return rainfall;
}

void Rainfall::setMonth(const std::string& month) {
    this->month = month;
}

void Rainfall::setRainfall(int rainfall) {
    this->rainfall = rainfall;
}
