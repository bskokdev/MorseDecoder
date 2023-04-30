#include "MorseDecoder.h"

MorseDecoder::MorseDecoder() {
    this->morseTable = {
            {'A', ".-"},
            {'B', "-..."},
            {'C', "-.-."},
            {'D', "-.."},
            {'E', "."},
            {'F', "..-."},
            {'G', "--."},
            {'H', "...."},
            {'I', ".."},
            {'J', ".---"},
            {'K', "-.-"},
            {'L', ".-.."},
            {'M', "--"},
            {'N', "-."},
            {'O', "---"},
            {'P', ".--."},
            {'Q', "--.-"},
            {'R', ".-."},
            {'S', "..."},
            {'T', "-"},
            {'U', "..-"},
            {'V', "...-"},
            {'W', ".--"},
            {'X', "-..-"},
            {'Y', "-.--"},
            {'Z', "--.."}
    };
    buildMorseTree();
}

void MorseDecoder::buildMorseTree() {
    this->morseTree = std::make_unique<Node>();
    // iterate through morseTable and add each letter to the tree
    for (auto &[letter, code] : this->morseTable) {
        addMorseLetterToTree(letter, code);
    }
}

void MorseDecoder::addMorseLetterToTree(char letter, const std::string& morseCode) {
    Node*currentNode = this->morseTree.get();
    for (char i : morseCode) {
        // dots are left, dashes are right
        if (i == '.') {
            // check if left node is empty -> add new node
            if (currentNode->left == nullptr) {
                currentNode->left = std::make_unique<Node>();
            }
            currentNode = currentNode->left.get(); // move to left node
        } else if (i == '-') {
            // check if right node is empty -> add new node
            if (currentNode->right == nullptr) {
                currentNode->right = std::make_unique<Node>();
            }
            currentNode = currentNode->right.get(); // move to right node
        }
    }
    currentNode->letter = letter;
}

std::string MorseDecoder::decodeMessage(std::string &encodedString) {
    std::string decodedString;
    std::string currentMorseLetter;
    Node* currentNode = this->morseTree.get();

    // iterate through encodedString and decode each letter
    int slashCount = 0;
    for (char i : encodedString) {
        // if we find a slash, we need to check how many slashes we have
        if (i == '/') {
            slashCount++;
            // if only one slash, we have a complete letter
            if (slashCount == 1) {
                decodedString += currentNode->letter;
                currentNode = this->morseTree.get();
                // if two slashes, we have a space
            } else if (slashCount == 2) {
                decodedString += ' ';
                // if three slashes, we have the end of the message
            } else if (slashCount == 3) {
                // remove last space
                decodedString.pop_back();
                decodedString += ". ";
            }
        } else {
            slashCount = 0;
            // if we find a dot, we move left, if we find a dash, we move right in the tree
            if(i == '.') {
                currentNode = currentNode->left.get();
            } else if (i == '-') {
                currentNode = currentNode->right.get();
            }
        }
    }

    if (slashCount == 1) decodedString += currentNode->letter;
    return decodedString;
}

