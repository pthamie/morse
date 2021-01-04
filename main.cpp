#include <iostream>
#include "./include/morse.h"
#include "./include/wave.h"
#include <string>


int main(int, char**) {
    morse m;

    // 1) Structure du code encodage/décodage de texte tel qu'il pourrait-être attendu
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
    

    // 2) Exemple d'utilisation de la librairie d'aide pour la création et la lectiure de fichier .wav.
    // Cette librairie ne doit pas être utilisée dans votre code défintif.
    // L'exercice consiste aussi a re-coder l'équivalent de cette librairie.
    // La mise à disposition sous-forme de librairie a pour unique but de "cacher" le code => il n'est pas utile de mettre
    // votre code sous forme de librairie.
    wave w;

    w.EncodeMorseCodesAsSound("../wave_examples/sos.wav", "... --- ...  ... --- ...");

    std::cout << w.DecodeMorseWavFile("../wave_examples/sos.wav");
    std::cout << std::endl;

    // 3) Exemple d'écriture et lecture au format "binaire" dans un fichier d'un mot de 32 bits
    w.test_write_binary(42);
    std::uint32_t v = w.test_read_binary();

    std::cout << v << std::endl;
}
