#include <iostream>
#include <exception>

namespace user
{
    template <typename T>
    struct Node
    {
        T data;
        Node<T> *next;
    };

    template <typename T>
    class Stack
    {
        Node<T> *top_ ;
        size_t size_ ;

    public:
        // Default constructor for the stack
        Stack()
        {
            top_ = nullptr;
            size_ = 0 ;
        }

        // Pushes element into the stack
        void push(T data)
        {
            try
            {
                if (top_ == nullptr)
                {
                    top_ = new Node<T>;
                    top_->data = data;
                    top_->next = nullptr;
                }
                else
                {
                    Node<T> *temp = new Node<T>;
                    temp->data = data;
                    temp->next = top_;
                    top_ = temp;
                }
                ++size_ ;
            }
            catch(std::bad_alloc &excep)
            {
                std::cerr << " Bad Memory Allocation during Stack::push " << excep.what() << "\n" ;
                exit(1);
            }
            catch(std::exception &excep)
            {
                std::cerr << " Standard exception occurred during Stack::push " << excep.what() << "\n" ;
                throw excep;
            }
        }
            

        // Removes elements from a stack
        void pop()
        {
            try
            {
                if (top_ != nullptr)
                {
                    Node<T>* temp = top_ ;
                    top_ = top_->next ;
                    delete temp ;
                    --size_ ;
                }
            }
            catch(std::exception &excep)
            {
                std::cerr << " Standard exception occurred while Stack::pop" << excep.what() << "\n" ;
                throw excep;
            }
        }

        // Get the top_ element in the stack
        T& top()
        {
            try
            {
                if( top_ == nullptr )
                {
                    throw "Empty Stack" ;
                }
            }
            catch(std::string &excep)
            {
                std::cerr << " Empty Stack exception occurred while Stack::pop" << "\n" ;
            }  
            catch(std::exception &excep)
            {
                std::cerr << " Standard exception occurred while Stack::pop" << excep.what() << "\n" ;
                throw excep;
            }
            return top_->data ;
        }

        // Return the current size of the stack
        size_t size()
        {
            return size_;
        }
        
        // Display Stack
        void display()
        {
            Node<T>* temp = top_ ;
            while( temp != nullptr )
            {
                std::cout << temp->data << " " ; 
                temp = temp->next ;
            }
        }
        
        // Destructor 
        ~Stack()
        {
            while( top_ != nullptr )
            {
                Node<T>* temp = top_ ;
                top_ = top_->next ;
                delete temp ;
            }
        }
    };
}

int main()
{
    user::Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    
    std::cout << "Current stack : " ;
    myStack.display();
    std::cout << std::endl ;
    
    std::cout << "Current top : " << myStack.top() << ", now Pop \n" ;
    myStack.pop();
    std::cout << "Current top : " << myStack.top() << ", now Pop\n" ;
    myStack.pop();

    myStack.push(5);

    std::cout << "Current stack : " ;
    myStack.display();
}