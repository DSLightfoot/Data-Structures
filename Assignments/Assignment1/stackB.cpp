#include "stackB.h"
//Use a "real" pointer to move with the elements to know size and stack_pointer for index

#include <iostream>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::cerr, std::overflow_error, std::underflow_error;

StackB::StackB(): stack_pointer(-1){
    ptr = stackB;
}

int StackB::status(){
    //Iterate through all of the indexes in the stack and show what they would be
    if (stack_pointer <= -1){
        cout << "Stack is empty.";
        return -1;
    }

    cout << endl << "Stack Contents: " << endl;

    for(int i = 0; i < (stack_pointer + 1); i++){        
        cout << "[" << (*ptr)[0] << (*ptr)[1] << "]" << endl;
        ptr++;  
    }       
    cout << endl;
    return 0;
}

int StackB::push(char bigram[BIGRAM_SIZE]){
    //Push onto stack
    if (stack_pointer >= MAX_STACK_SIZE - 1){
        throw overflow_error("Stack is full");
        return -1;

    }else{
        stack_pointer++;
        //Copy elements
        stackB[stack_pointer][0] = bigram[0];
        stackB[stack_pointer][1] = bigram[1];

        // ptr = &stackB[stack_pointer][0];
        return 0;
    }

}

int StackB::pop(char bigram[BIGRAM_SIZE]){
    //Need to check if stack is empty before popping
    if (stack_pointer <= -1){
        throw underflow_error("Stack is empty");
        return -1;

    }else{
        bigram[0] = stackB[stack_pointer][0];
        bigram[1] = stackB[stack_pointer][1];
        
        cout << "Popped: " << stackB[stack_pointer][0] << stackB[stack_pointer][1] << endl;

        stack_pointer--;
        return 0;
    }
}


