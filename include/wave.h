#include <vector>
#include <string>

extern void libEncodeMorseCodesAsSound(const std::string &filename, const std::string &morse_code);
extern std::string libDecodeMorseWavFile(const std::string &filename);



class wave
{
public:
    wave(){};
    ~wave(){};

private:


private:
public:
    void EncodeMorseCodesAsSound(const std::string &filename, const std::string &morse);
    std::string DecodeMorseWavFile(const std::string &filename);

    
    void test_write_binary(std::uint32_t v);
    std::uint32_t test_read_binary();
};
