#ifndef MORSEDECODER_NODE_H
#define MORSEDECODER_NODE_H


#include <memory>

/**
 * @brief Node class for the morse tree
 */
class Node {
public:
    char letter;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    /**
     * @brief default constructor
     */
    Node();

    /**
     * @brief constructor with letter
     * @param letter letter of the node
     */
    explicit Node(char letter);
};


#endif //MORSEDECODER_NODE_H
