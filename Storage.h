#pragma once
#include <string>

class Storage {
protected:
    std::string brand;
    int capacity;

public:
    Storage(const std::string& brand, int capacity);

    virtual void writeData() = 0;
    virtual void readData() = 0;
    virtual void format() = 0;
};
