#ifndef STACKA.H
#define STACKA.H

class StackA{
    private:
        static const int BIGRAM_SIZE = 2;
        static const int MAX_STACK_SIZE = 6;
        int stack_pointer;
    public:
        char stackA[MAX_STACK_SIZE][BIGRAM_SIZE];

        StackA();

        int push(char bigram[BIGRAM_SIZE]);
        int pop(char bigram[BIGRAM_SIZE]);
        int status();

};

#endif //STACKA.H