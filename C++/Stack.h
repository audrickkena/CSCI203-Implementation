#ifndef STACK
#define STACK

#include <iostream>

class Stack {
    private:
        int size;
        int lastIndex;
        int *stackData;
    
    public:
        Stack(); // default constuctor
        Stack(int size); // parametized constructor
        ~Stack(); // destructor
        int getSize(void);
        bool isEmpty(void);
        bool isFull(void);
        void push(int e);
        int pop(void);
        void display(void);
};

Stack::Stack(void){
    size = 0;
    lastIndex = 0;
    stackData = nullptr;
}

Stack::Stack(int size){
    this->size = size;
    lastIndex = 0;
    stackData = new int[size];
    for(int i = 0; i < size; i++){
        stackData[i] = -1;
    }
}

Stack::~Stack(void){
    delete stackData;
}

int Stack::getSize(void){
    return size;
}

bool Stack::isEmpty(void){
    return (lastIndex == 0 && stackData[lastIndex] == -1);
}

bool Stack::isFull(void){
    return (size == (lastIndex + 1));
}

void Stack::push(int e){
    if(isFull()){
        std::cout << "Stack is currently full! Cannot push > " << e << std::endl;
    }
    else if(isEmpty()){
        stackData[lastIndex] = e;
    }
    else{
        lastIndex += 1;
        stackData[lastIndex] = e;
    }
}

int Stack::pop(void){
    if(isEmpty()){
        std::cout << "Stack is empty! No element to pop!" << std::endl;
        return -1;
    }
    else{
        int temp = stackData[lastIndex];
        stackData[lastIndex] = -1;
        if(lastIndex != 0){
            lastIndex -= 1;
        }
        return temp;
    }
}

void Stack::display(void){
    std::cout << "[";
    for(int i = 0; i < lastIndex; i++){
        std::cout << stackData[i] << " ";
    }
    std::cout << stackData[lastIndex] << "]" << std::endl;
}

#endif