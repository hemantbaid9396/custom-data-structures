#include <iostream>
#include <exception>

namespace user
{
    // Default constructor for the stack
    template <typename T>
    Stack<T>::Stack() noexcept
    {
        top_ = nullptr;
        size_ = 0;
    }

    // Pushes element into the stack
    template <typename T>
    void Stack<T>::push(T iData)
    {
        try
        {
            if (top_ == nullptr)
            {
                top_ = new Stack_Node<T>;
                top_->data_ = iData;
                top_->next_ = nullptr;
            }
            else
            {
                Stack_Node<T> *temp = new Stack_Node<T>;
                temp->data_ = iData;
                temp->next_ = top_;
                top_ = temp;
            }
            ++size_;
        }
        catch (std::bad_alloc &excep)
        {
            std::cerr << " Bad Memory Allocation during Stack::push " << excep.what() << "\n";
            exit(1);
        }
        catch (std::exception &excep)
        {
            std::cerr << " Standard exception occurred during Stack::push " << excep.what() << "\n";
            throw excep;
        }
    }

    // Removes elements from a stack
    template <typename T>
    void Stack<T>::pop()
    {
        try
        {
            if (top_ != nullptr)
            {
                Stack_Node<T> *temp = top_;
                top_ = top_->next_;
                delete temp;
                --size_;
            }
        }
        catch (std::exception &excep)
        {
            std::cerr << " Standard exception occurred while Stack::pop" << excep.what() << "\n";
            throw excep;
        }
    }

    // Get the top_ element in the stack
    template <typename T>
    T &Stack<T>::top()
    {
        try
        {
            if (top_ == nullptr)
            {
                throw "Empty Stack";
            }
        }
        catch (std::string &excep)
        {
            std::cerr << " Empty Stack exception occurred while Stack::pop"
                      << "\n";
            throw "Empty Stack";
        }
        catch (std::exception &excep)
        {
            std::cerr << " Standard exception occurred while Stack::pop" << excep.what() << "\n";
            throw excep;
        }
        return top_->data_;
    }

    // Return the current size of the stack
    template <typename T>
    size_t Stack<T>::size()
    {
        return size_;
    }

    // Display Stack
    template <typename T>
    void Stack<T>::display()
    {
        Stack_Node<T> *temp = top_;
        while (temp != nullptr)
        {
            std::cout << temp->data_ << " ";
            temp = temp->next_;
        }
    }

    // Destructor
    template <typename T>
    Stack<T>::~Stack()
    {
        while (top_ != nullptr)
        {
            Stack_Node<T> *temp = top_;
            top_ = top_->next_;
            delete temp;
        }
    }

};