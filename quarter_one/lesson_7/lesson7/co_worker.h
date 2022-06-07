#pragma once
#include <iostream>
#include <string>
#include <fstream>

enum Gender {Mail, Femail};

#pragma pack(push, 1) // без выравнивания 128 байт, с выравниванием 124 байта

struct Co_Worker {
private:
    std::string first_name;
    std::string last_name;
    std::string department;
    uint32_t age;
    uint32_t passport_serial;
    uint32_t passport_number;
    uint32_t experience;
    Gender gender;

    size_t size;

public:
    Co_Worker (std:: string name, std::string last_name, std:: string department, uint32_t passport_serial,
               uint32_t passport_number, uint32_t experience = 3, Gender gender = Gender::Mail, uint32_t age = 0);

    size_t SizeOfCo_Worker(const Co_Worker& worker);
    int32_t Print(std::ostream& stream = std::cout);
};

#pragma pack(pop)
