// linked_list.hpp
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct Node {
    int degree;
    double x;
    double b;
    double m;
    double w;
    double asgard;
    double freyja;
    double odin;
    double thor;
    double loki;
    Node* next;

    Node(int d, double xVal, double bVal, double mVal, double wVal, double asgardVal, double freyjaVal, double odinVal, double thorVal, double lokiVal)
        : degree(d), x(xVal), b(bVal), m(mVal), w(wVal), asgard(asgardVal), freyja(freyjaVal), odin(odinVal), thor(thorVal), loki(lokiVal), next(nullptr) {}
};

Node* calculate_values(int degree);
Node* create_linked_list();
void display_linked_list(Node* head);

#endif // LINKED_LIST_HPP