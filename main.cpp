#include <iostream>
#include <fstream>
#include "MorseDecoder.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Invalid arguments" << std::endl;
    }

    // read encoded string from file
    std::string file = argv[1];
    std::string encodedString;
    std::ifstream inputFile(file);
    if (inputFile.is_open()) {
        std::getline(inputFile, encodedString);
    } else {
        std::cout << "Could not open file" << std::endl;
    }

    MorseDecoder decoder;
    std::cout << decoder.decodeMessage(encodedString) << std::endl;
    return 0;
}
