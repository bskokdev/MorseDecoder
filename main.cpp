#include <iostream>
#include "MorseDecoder.h"

int main() {
    // get encoded string from cin
    std::string encodedString;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        encodedString += line;
    }

    MorseDecoder decoder;
    std::cout << decoder.decodeMessage(encodedString) << std::endl;
    return 0;
}
