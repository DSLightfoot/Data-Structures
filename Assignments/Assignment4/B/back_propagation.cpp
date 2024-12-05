#include "back_propagation.hpp"

#include <iostream>

Back_Prop::Back_Prop(std::string data){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

Back_Prop::~Back_Prop(){
    delete next;
    delete prev;
}

int Back_Prop::insert(Back_Prop*& head, std::string data){
    Back_Prop* newBack_Prop = new Back_Prop(data);

    if(head == nullptr){
        head = newBack_Prop;
        return 0;
    }

    Back_Prop* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newBack_Prop;
    newBack_Prop->prev = temp;

    return 0;
}

int Back_Prop::traverse_forward(Back_Prop* head){
    if(head == nullptr){
        return 0;
    }

    std::cout << head->data << " ";

    traverse_forward(head->next);

    return 0;
}

int Back_Prop::traverse_backward(Back_Prop* head)
{
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return 0;
    }

    if(head->next != nullptr){
        traverse_backward(head->next);
    }

    std::cout << head->data << " ";

    return 0;
}

int Back_Prop::back_propagation(double bigram, double bias, double slope){
    Back_Prop* head = nullptr;

    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return 0;
    }

    if(head->next != nullptr){
        traverse_backward(head->next);
    }

    std::cout << head->data << " ";
    
    return 0;
}