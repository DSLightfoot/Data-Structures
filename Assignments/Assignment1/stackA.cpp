#include "stackA.h"

#include <iostream>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::cerr, std::overflow_error, std::underflow_error;

StackA::StackA(): stack_pointer(-1){
}

int StackA::status(){
    //Iterate through all of the indexes in the stack and show what they would be
    if (stack_pointer <= -1){
        cout << "Stack is empty.";
        return -1;
    }

    cout << endl << "Stack Contents: " << endl;

    for (int i = 0; i < stack_pointer + 1; i++){
        cout << "[" << stackA[i][0] << stackA[i][1]  << "]" << endl;
    }

    cout << endl;

    return 0;
}

int StackA::push(char bigram[BIGRAM_SIZE]){
    //Push onto stack
    if (stack_pointer >= MAX_STACK_SIZE - 1){
        throw overflow_error("Stack is full");
        return -1;

    }else{
        stack_pointer++;
        //Copy elements
        for (int i = 0; i < BIGRAM_SIZE; i++){
            stackA[stack_pointer][i] = bigram[i];
        }
        return 0;
    }

}

int StackA::pop(char bigram[BIGRAM_SIZE]){
    //Need to check if stack is empty before popping
    if (stack_pointer <= -1){
        throw underflow_error("Stack is empty");
        return -1;

    }else{
        bigram[0] = stackA[stack_pointer][0];
        bigram[1] = stackA[stack_pointer][1];
        
        cout << "Popped: " << stackA[stack_pointer][0] << stackA[stack_pointer][1] << endl;

        stack_pointer--;
        return 0;
    }
}


