#include "../include/wave.h"
#include <iostream>
#include <fstream>

void wave::EncodeMorseCodesAsSound(const std::string &filename, const std::string &morse)
{
    libEncodeMorseCodesAsSound(filename, morse);
}

std::string wave::DecodeMorseWavFile(const std::string &filename)
{
    return libDecodeMorseWavFile(filename);
}



void wave::test_write_binary(std::uint32_t v)
{
    std::ofstream wav;

    wav.open("test.bin", std::ofstream::out | std::ofstream::binary);
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

    wav.open("test.bin", std::ifstream::in | std::ifstream::binary);
    if (wav.is_open())
    {
        wav.read(reinterpret_cast<char *>(&ret), sizeof(ret));
        wav.close();
    }

    return ret;
}

