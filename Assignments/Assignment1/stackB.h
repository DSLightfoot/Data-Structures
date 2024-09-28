//Use a "real" pointer to move with the elements to know size and stack_pointer for index
#ifndef STACKB.H
#define STACKB.H

class StackB{
    private:
        static const int BIGRAM_SIZE = 2;
        static const int MAX_STACK_SIZE = 6;
        int stack_pointer = -1;
        char (*ptr)[2];
    public:
        char stackB[MAX_STACK_SIZE][BIGRAM_SIZE];

        StackB();

        int push(char bigram[BIGRAM_SIZE]);
        int pop(char bigram[BIGRAM_SIZE]);
        int status();

};



#endif //STACKA.H