// linked_list.cpp
#include "linked_list.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

Node* calculate_values(int degree) {
    double x = degree / 90.0;  // Normalize degree to range [0, 1]
    double b = -0.5;
    double m = 1;
    double w = 1;

    // Compute values for Loki, Thor, Odin, Freyja, and Asgard
    double loki = fabs(1 - (tanh(x) - b));
    double thor = 0.01 * loki;
    double odin = 0.1 * thor;
    double freyja = 1.0 * odin;
    double asgard = 10.0 * freyja;

    return new Node(degree, x, b, m, w, asgard, freyja, odin, thor, loki);
}

Node* create_linked_list() {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int degree = 0; degree <= 90; degree += 9) {
        Node* newNode = calculate_values(degree);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void display_linked_list(Node* head) {
    cout << left << setw(10) << "Degrees" << setw(10) << "x" << setw(10) << "b"
         << setw(10) << "m" << setw(10) << "w" << setw(15) << "Asgard"
         << setw(15) << "Freyja" << setw(15) << "Odin" << setw(15) << "Thor"
         << setw(15) << "Loki" << endl;
    cout << string(120, '-') << endl;

    Node* current = head;
    while (current) {
        cout << left << setw(10) << current->degree << setw(10) << current->x << setw(10) << current->b
             << setw(10) << current->m << setw(10) << current->w << setw(15) << current->asgard
             << setw(15) << current->freyja << setw(15) << current->odin << setw(15) << current->thor
             << setw(15) << current->loki << endl;
        current = current->next;
    }
}
