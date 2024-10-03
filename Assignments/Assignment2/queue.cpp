#include "queue.h"
#include <stdexcept>
#include <iostream>

using std::overflow_error, std::underflow_error, std::cout, std::endl, std::cin;

int Queue::enqueue(const char arr[2]){
    // Check if queue is full
    if (queue.size() >= MAX_QUEUE_SIZE){
        throw overflow_error("Queue is full");
        return -1;
    }

    queue.push_back(string(arr, 2));
    return 0;
}

int Queue::dequeue(const char arr[2]){
    // Check if queue is empty
    if (queue.size() <= 0){
        throw underflow_error("Queue is empty");
        return -1;
    }

    //Remove from queue
    cout << "Dequeued: " << queue[0] << endl;
    queue.erase(queue.begin());
    return 0;

}

int Queue::status(){
    if (queue.empty()){
        cout << "Queue is empty." << endl;
        return -1;
    }

    cout << "Queue Contents: " << endl;
    for (auto& item: queue){
        cout << "[" << item << "] ";
    }

    return 0;
}