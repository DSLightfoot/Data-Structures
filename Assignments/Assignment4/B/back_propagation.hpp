#ifndef BACK_PROPAGATION_HPP_INCLUDED
#define BACK_PROPAGATION_HPP_INCLUDED

#include <string>

class Back_Prop{
    private:
        std::string data;
        Back_Prop* next;
        Back_Prop* prev;

    public:
        Back_Prop(std::string data);
        ~Back_Prop();

        int insert(Back_Prop*& head, std::string data);
        int traverse_forward(Back_Prop* head);
        int traverse_backward(Back_Prop* head);

        int back_propagation(double bigram, double bias, double slope);
};

#endif //BACK_PROPAGATION_HPP_INCLUDED