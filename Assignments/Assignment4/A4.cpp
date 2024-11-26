#include "A4.hpp"
#include <cmath>
#include <iostream>

// Constructor to initialize the Node
Node::Node(const std::string& nodeName) : name(nodeName), next(nullptr) {}

// Function to create the linked list
Node* createLinkedList() {
    // Create nodes
    Node* loki = new Node("Loki");
    Node* thor = new Node("Thor");
    Node* odin = new Node("Odin");
    Node* freja = new Node("Freja");

    freja->next = odin;
    odin->next = thor;
    thor->next = loki;

    return freja;
}

double traverseLinkedList(Node* node, double lambda, double count, double total) {
   if (node == nullptr) {
        return 0;
    }

    traverseLinkedList(node->next, lambda, count + 1, total);

    double result = pow((1.0 / lambda), (total - count));

    std::cout << "Visiting: " << node->name << "   " << result << std::endl;

    return result;
}

int getSize(Node* node) {
    int size = 0;
    while (node != nullptr) {
        size++;
        node = node->next;
    }
    return size;
}
