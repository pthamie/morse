# Morse

## CMake
Le fichier CMakeLists.txt prend en charge tous les fichiers .cpp du sous-répertoire ./src
et tous les fichiers .h du sous-répertoire ./include
=> vous n'avez plus a y toucher si vous respectez cette organisation.
Lorsque vous ajoutez des fichiers .cpp et .h a votre projet il faut parfois ouvrir le fichier CMakeLists.txt et de le sauvagarder sans rien changer pour que le makefile soit re-généré automatiquement en prenant en compte les nouveaux fichiers. C'est tout.


## Utilisation d'un graphe
Il semble que cette indication concerne l'utilisation d'un arbre pour le décodage morse.
Un arbre étant un certain type de graphe.


## Lib encodage/decodage
Exemple de génération et relecture de fichier .wav contenant du morse suivant les hypothèses suivantes :
1)
    dot_duration : quelconque
    dash_duration = 3*_dot_duration
    intra_letter_duration : quelconque
    inter_letter_duration = 3*_intra_letter_duration
    inter_word_duration = 7*_intra_letter_duration

Un peu de marge a été prise lors du décodage.

2)
L'absence de signal morse est codé avec une valeur de signal = 0 => pas de bruit

3)
Dans la chaine de caractères passée en argument de l'encodeur : 
- un espace représente la séparation entre 2 caractères
- deux espaces représente la séparation entre 2 mots.

La fréquence du signal morse ne devrait pas poser de problème pour le décodage.
Les encodages 8 et 16 bits sont supportés pour le décodage.
La fréqence d'échantillonnage ne devrait pas poser de problème pour le décodage.

Toutes les varaiations possibles n'ont pas été testées.

En exemple de fichier .wav est présent dans le répertoire wave_examples.

## Ecriture des tailles dans un fichier .wav

```cpp

    std::ofstream _wav;
    
    _wav.open(filename, std::ofstream::out | std::ofstream::binary);
    if (_wav.is_open())
    {
        // Ecriture entête
        // ... votre code ...
        
        // Ecriture des échantillons audio
        // ... votre code ...

        // Ecriture des tailles maintenant connues
        _wav.seekp (4);
        _size = _data_chunk_size + 36;
        _wav.write(reinterpret_cast<char *>(&_size), sizeof(_size));
        _wav.seekp (40);
        _wav.write(reinterpret_cast<char *>(&_data_chunk_size), sizeof(_data_chunk_size));

        _wav.close();
    }

```

## Lecture header fichier .wav
```cpp

class wave_header
{
public:
    wave_header();
    ~wave_header();

public:
    char            RIFF[4] = {0};
    std::uint32_t   size = 0;
    char            WAVE[4] = {0};
    char            fmt[4] = {0};
    std::uint32_t   sub_chunk_size = 0;
    std::uint16_t   audio_format = 0;
    std::uint16_t   nb_channels;
    std::uint32_t   sample_rate;
    std::uint32_t   byte_rate;
    std::uint16_t   block_align;
    std::uint16_t   bit_depth;
    char            data[4] = {0};
    std::uint32_t   data_chunk_size;
    void            *psamples = 0;

public:
    void Load (std::ifstream &ifs);   
};



wave_header::wave_header()
{

}

wave_header::~wave_header()
{
    if (psamples)
    {
        free (psamples);
        psamples = 0;
    }
}

void wave_header::Load(std::ifstream &ifs)
{
    if (psamples)
    {
        free (psamples);
        psamples = 0;
    }

    ifs.read(reinterpret_cast<char *>(&RIFF), sizeof(RIFF));

    ifs.read(reinterpret_cast<char *>(&size), sizeof(size));
    ifs.read(reinterpret_cast<char *>(&WAVE), sizeof(WAVE));
    ifs.read(reinterpret_cast<char *>(&fmt), sizeof(fmt));
    ifs.read(reinterpret_cast<char *>(&sub_chunk_size), sizeof (sub_chunk_size));
    ifs.read(reinterpret_cast<char *>(&audio_format), sizeof(audio_format));
    ifs.read(reinterpret_cast<char *>(&nb_channels), sizeof(nb_channels));
    ifs.read(reinterpret_cast<char *>(&sample_rate), sizeof(sample_rate));
    ifs.read(reinterpret_cast<char *>(&byte_rate), sizeof(byte_rate));
    ifs.read(reinterpret_cast<char *>(&block_align), sizeof(block_align));
    ifs.read(reinterpret_cast<char *>(&bit_depth), sizeof(bit_depth));
    ifs.read(reinterpret_cast<char *>(&data), sizeof(data));
    ifs.read(reinterpret_cast<char *>(&data_chunk_size), sizeof(data_chunk_size));

    psamples = malloc (data_chunk_size);
    ifs.read(reinterpret_cast<char *>(psamples), data_chunk_size);


}

```
