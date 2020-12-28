#pragma once
#include <iostream>

class wave
{
public:
    wave();
    ~wave();

public:
    void test_write_binary(std::uint32_t v);
    std::uint32_t test_read_binary();
};
