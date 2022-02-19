#include "Stack.h"

int main(int argc, char** argv){
    Stack testStack(5);
    std::cout << "Stack size check: " << testStack.getSize() << std::endl;
    testStack.push(1);
    testStack.push(1);
    testStack.push(1);
    testStack.push(1);
    testStack.push(1);
    testStack.push(2);
    
    std::cout << "Stack before pop:" << std::endl;
    testStack.display();
    int temp = testStack.pop();
    std::cout << "Stack after pop:" << std::endl;
    testStack.display();
    std::cout << "Element popped: " << temp << std::endl;
}