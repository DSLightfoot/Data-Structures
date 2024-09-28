#ifndef QUEUE.H
#define QUEUE.H

#include <vector>
#include <string>

using std::vector, std::string;


class Queue{
    private:
        static const int BIGRAM_SIZE = 2;
        static const int MAX_QUEUE_SIZE = 6;
        vector<string> queue;
    public:
        int enqueue(const char[BIGRAM_SIZE]);
        int dequeue();
        int status();

};


#endif //QUEUE.H