// main.cpp
#include "linked_list.hpp"
#include "linked_list.cpp"

#include <iostream>
using namespace std;

int main() {
    Node* head = create_linked_list();
    display_linked_list(head);

    // Free memory
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
