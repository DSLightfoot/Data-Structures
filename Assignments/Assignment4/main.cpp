#include <iostream>
#include <iomanip>
#include "A4.hpp"
#include "A4.cpp"

int main() {
    // Create the linked list
    Node* head = createLinkedList();

    // Set the lambda value (e.g., 2)
    double lambda = 2;
    double count = 0;
    double total = getSize(head);

    // Traverse the linked list and compute the result
    std::cout << std::fixed << std::setprecision(10); // Set output precision
    double result = traverseLinkedList(head, lambda, count, total);

    // Output the final result
    std::cout << "Asgard: " << result / 2 << std::endl;

    // Cleanup: Free allocated memory
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}