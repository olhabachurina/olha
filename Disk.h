#pragma once
#include "storage.h"
#include "iusb.h"

class Disk : public Storage {
private:
    bool writable;

public:
    Disk(const std::string& brand, int capacity, bool writable);

    void writeData() override;
    void readData() override;
    void format() override;
};

