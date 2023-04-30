#ifndef MORSEDECODER_MORSEDECODER_H
#define MORSEDECODER_MORSEDECODER_H


#include <string>
#include <unordered_map>
#include <memory>
#include "Node.h"

/**
 * @brief Class to decode morse code
 * @details This class contains a morse table and a morse tree.
 */
class MorseDecoder {
private:
    std::unordered_map<char, std::string> morseTable;
    std::unique_ptr<Node> morseTree;

    /**
     * @brief builds the morse tree
     * @details iterates through the morseTable and adds each letter to the tree
     */
    void buildMorseTree();

    /**
     * @brief adds a morse letter to the tree
     * @param Letter Letter to be added
     * @param morseCode Morse code of the letter
     */
    void addMorseLetterToTree(char letter, const std::string& morseCode);
public:
    /**
     * @brief default constructor
     * @details initializes the morseTable and builds the morseTree
     */
    MorseDecoder();

    /*
     * @brief decodes a morse code string
     * @param encodedString the morse code string to decode
     * @return the decoded string
     */
    std::string decodeMessage(std::string &encodedString);

};


#endif //MORSEDECODER_MORSEDECODER_H
