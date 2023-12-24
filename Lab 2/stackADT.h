#ifndef STACKADT_H
#define STACKADT_H

template <class Type>
class stackADT
{
public:
    // Destructor
    virtual ~stackADT() {}

    // Function to initialize the stack
    virtual void initializeStack() = 0;

    // Function to check if the stack is empty
    virtual bool isEmptyStack() const = 0;

    // Function to check if the stack is full
    virtual bool isFullStack() const = 0;

    // Function to push an item onto the stack
    virtual void push(const Type &newItem) = 0;

    // Function to pop an item from the stack
    virtual void pop() = 0;

    // Function to return the top element of the stack
    virtual Type top() const = 0;
};

#endif
