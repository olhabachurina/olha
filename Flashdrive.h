#pragma once
#include "storage.h"
#include "iusb.h"

class FlashDrive : public Storage, public IUsb {
public:
    FlashDrive(const std::string& brand, int capacity);

    void writeData() override;
    void readData() override;
    void format() override;
    void connect() override;
    void disconnect() override;
};