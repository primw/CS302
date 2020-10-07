// Prim Wandeevong // CS 302 - Homework 4: PriorityNode.h // 4-4-20 //
#ifndef PNODE_H
#define PNODE_H
using namespace std;


//Templated Node Class Declaration
template <class ItemType>
class PriorityNode
{
    public:
        PriorityNode();
        PriorityNode(const ItemType& anItem, const int& priority);
        void setItem(const ItemType& anItem);
        void setNext(PriorityNode<ItemType>* nextNodePtr);
        int getPriority();
        ItemType getItem() const;
        PriorityNode<ItemType>* getNext() const;

    private:
        ItemType m_item; 
        int m_priority;
        PriorityNode<ItemType>* m_next; 
}; 

#include "PriorityNode.cpp"
#endif