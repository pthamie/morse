#include "../include/wave.h"

void wave::EncodeMorseCodesAsSound(const std::string &filename, const std::string &morse)
{
    libEncodeMorseCodesAsSound(filename, morse);
}

std::string wave::DecodeMorseWavFile(const std::string &filename)
{
    return libDecodeMorseWavFile(filename);
}



