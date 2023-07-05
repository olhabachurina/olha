#include "Disk.h"
#include <iostream>

Disk::Disk(const std::string& brand, int capacity, bool writable) : Storage(brand, capacity), writable(writable) {}

void Disk::writeData() {
    if (writable) {
        std::cout << "Writing data to Disk" << std::endl;
    }
    else {
        std::cout << "Cannot write data to the non-writable Disk" << std::endl;
    }
}

void Disk::readData() {
    std::cout << "Reading data from Disk" << std::endl;
}

void Disk::format() {
    std::cout << "Formatting Disk" << std::endl;
}