#include "../include/wave.h"
#include <iostream>
#include <fstream>

wave::wave()
{
}

wave::~wave()
{
}

void wave::test_write_binary(std::uint32_t v)
{
    std::ofstream wav;

    wav.open("test.wav", std::ofstream::out | std::ofstream::binary);
    if (wav.is_open())
    {
        wav.write(reinterpret_cast<char *>(&v), sizeof(v));
        wav.close();
    }
}

std::uint32_t wave::test_read_binary()
{
    std::uint32_t ret = 0;
    std::ifstream wav;

    wav.open("test.wav", std::ifstream::in | std::ifstream::binary);
    if (wav.is_open())
    {
        wav.read(reinterpret_cast<char *>(&ret), sizeof(ret));
        wav.close();
    }

    return ret;
}
