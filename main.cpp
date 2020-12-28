#include <iostream>
#include "./include/morse.h"
#include <string>


int main(int, char**) {
    morse m;

    std::string ascii_string_ori = "Hello world";
    std::string ascii_string = ascii_string_ori;
    std::string morse_string;

    // Affichage valeur de départ.
    std::cout << "ascii : " << ascii_string << std::endl;

    // Encodage
    morse_string = m.encode(ascii_string);
    std::cout << "encodage morse : " << morse_string << std::endl;

    // Décodage
    ascii_string = m.decode(morse_string);
    std::cout << "decodage morse : " << ascii_string << std::endl;

    // Tests a enrichir.
    if (ascii_string == ascii_string_ori)
    {
        std::cout << "peut être ok..." << std::endl;
    }
    else
    {
        std::cout << "nok" << std::endl;
    }
    


    
}
