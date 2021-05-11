#include <iostream>
#include "Stack/Stack.hpp"

int main()
{
    user::Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Current stack : ";
    myStack.display();
    std::cout << std::endl;

    std::cout << "Current top : " << myStack.top() << ", now Pop \n";
    myStack.pop();
    std::cout << "Current top : " << myStack.top() << ", now Pop\n";
    myStack.pop();

    myStack.push(5);

    std::cout << "Current stack : ";
    myStack.display();
}