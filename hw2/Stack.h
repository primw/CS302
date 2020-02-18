#ifndef STACK_H
#define STACK_H
#include "Node.h"

//Templated Stack Forward Declaration
template <class ItemType> 
class Stack;

//Templated Friend Function Forward Declaration
template <class ItemType>
ostream& operator<< (ostream& os, const Stack<ItemType> &myStack);

//Templated Stack Class Declaration
template <class ItemType>
class Stack
{
    public:
        Stack();
        Stack(const Stack<ItemType> &other);
        ~Stack();
        Stack& operator=(const Stack<ItemType> &rhs);
        ItemType peek();
        void push(const ItemType anItem);
        void pop();
        void clear();
        bool isEmpty() const;
        bool isFull() const;
        void serialize(ostream& os) const;
        friend ostream& operator<< <> (ostream& os, const Stack<ItemType> &myStack);

    private:
        Node<ItemType>* m_top;
};

#include "Stack.cpp"
#endif