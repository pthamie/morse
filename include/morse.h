#pragma once
#include <string>

class morse
{
public:
    morse();
    ~morse();

public:
    std::string encode(const std::string &ascii_string);
    std::string decode(const std::string &morse_string);

};
