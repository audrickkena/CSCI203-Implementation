#ifndef QUEUE
#define QUEUE

#include <iostream>

class Queue{
    private:
        int size;
        int frontIndex;
        int backIndex;
        int *queueData;

    public:
        Queue(); // default constructor
        Queue(int size); // constructor that takes in an int that is used to assign the size of the queue
        ~Queue(); // deconstructor
        int getSize(void);
        int getTop(void);
        int getTotalUsed(void);
        int getNextIndex(int num);
        void setSize(int size);
        bool isEmpty(void);
        bool isFull(void);
        void enqueue(int data);
        int dequeue(void);
        void display(void);
};

Queue::Queue(void){
    queueData = nullptr;
    size = 0;
}

Queue::Queue(int size){
    this->size = size;
    frontIndex = 0;
    backIndex = 0;
    queueData = new int[size];
    for(int i = 0; i < size; i++){
        queueData[i] = -1;
    }
}

Queue::~Queue(void){
    delete queueData;
}

int Queue::getSize(void){
    return size;
}

int Queue::getTop(void){
    if(isEmpty()){
        std::cout << "Queue is empty! No top to return" << std::endl;
        return -1;
    }
    else{
        return queueData[frontIndex];
    }
}

int Queue::getTotalUsed(void){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(queueData[i] != -1){
            count += 1;
        }
    }
    return count;
}

int Queue::getNextIndex(int num){
    if(num + 1 == size){
        return 0;
    }
    else{
        return num + 1;
    }
}

void Queue::setSize(int size){
    if(queueData == nullptr){
        this->size = size;
        frontIndex = 0;
        backIndex = 0;
        queueData = new int[size];
        for(int i = 0; i < size; i++){
            queueData[i] = -1;
        }
    }
    else{
        std::cout << "Queue already made! SetSize cannot be used." << std::endl;
    }
}

bool Queue::isEmpty(void){
    if(frontIndex == backIndex && queueData[frontIndex] == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Queue::isFull(void){
    if(getNextIndex(backIndex) == frontIndex){
        return true;
    }
    else{
        return false;
    }
}

void Queue::enqueue(int data){
    if(isFull()){
        std::cout << "The queue is full! Failed to enqueue, " << data << " into the queue" << std::endl;
    }
    else if(isEmpty()){
        queueData[backIndex] = data;
    }
    else{
        backIndex = getNextIndex(backIndex);
        queueData[backIndex] = data;
    }
}

int Queue::dequeue(){
    int temp = 0;
    if(isEmpty()){
        std::cout << "The queue is empty! Failed to dequeue!" << std::endl;
    }
    else{
        temp = queueData[frontIndex];
        queueData[frontIndex] = -1;
        if(frontIndex != backIndex){
            frontIndex = getNextIndex(frontIndex);
        }
    }
    return temp;
}

void Queue::display(void){
    std::cout << "[";
    for(int i = 0; i < size - 1; i++){
        std::cout << queueData[i] << " ";
    }
    std::cout << queueData[size - 1] << "]" << std::endl;
}

#endif