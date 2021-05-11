#ifndef _STACK_H_
#define _STACK_H_

namespace user
{
    /**
     * struct Stack_Node 
     * 
     * Defn: 
     */
    template <typename T>
    struct Stack_Node
    {
        T data_;
        Stack_Node<T> *next_;
    };

    template <typename T>
    class Stack
    {
        Stack_Node<T> *top_ ;
        size_t size_ ;

    public:
        // Default constructor for the stack
        Stack() noexcept; 

        // Pushes element into the stack
        void push(T iData);

        // Removes elements from a stack
        void pop();

        // Get the top_ element in the stack
        T& top();

        // Return the current size of the stack
        size_t size();
        
        // Display Stack
        void display();

        // Destructor 
        ~Stack();
    };
}

#include "Stack.tpp"

#endif