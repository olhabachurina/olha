#include "flashdrive.h"
#include <iostream>

FlashDrive::FlashDrive(const std::string& brand, int capacity) : Storage(brand, capacity) {}

void FlashDrive::writeData() {
    std::cout << "Writing data to FlashDrive" << std::endl;
}

void FlashDrive::readData() {
    std::cout << "Reading data from FlashDrive" << std::endl;
}

void FlashDrive::format() {
    std::cout << "Formatting FlashDrive" << std::endl;
}

void FlashDrive::connect() {
    std::cout << "Connecting FlashDrive via USB" << std::endl;
}

void FlashDrive::disconnect() {
    std::cout << "Disconnecting FlashDrive from USB" << std::endl;
}