#ifndef A4_HPP_INCLUDED
#define A4_HPP_INCLUDED

#include <string>
#include <string>

struct Node {
    std::string name;
    Node* next;

    Node(const std::string& nodeName);
};

Node* createLinkedList();
double traverseLinkedList(Node* node, double lambda, double count, double total);
int getSize(Node* node);


#endif //A4_H_INCLUDED