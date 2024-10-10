// Rainfall.h
#ifndef RAINFALL_H
#define RAINFALL_H

#include <string>

class Rainfall {
private:
    std::string month;
    int rainfall;
public:
    Rainfall();
    Rainfall(const std::string& month, int rainfall);
    std::string getMonth() const;
    int getRainfall() const;
    void setMonth(const std::string& month);
    void setRainfall(int rainfall);
};

#endif
