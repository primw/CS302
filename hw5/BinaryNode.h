
// Prim Wandeevong // CS 302 - Homework 5: BinaryNode.h // 4-21-19 //
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <class ItemType>
class BinaryNode 
{
    public:
        BinaryNode(const ItemType &anItem);
        ItemType getItem() const;
        BinaryNode<ItemType> *getLeftChildPtr() const;
        BinaryNode<ItemType> *getRightChildPtr() const;
        void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
        void setRightChildPtr(BinaryNode<ItemType> *rightPtr);
    private:
    ItemType m_item;         
    BinaryNode<ItemType> *m_left; 
    BinaryNode<ItemType> *m_right; 
}; 

#include "BinaryNode.cpp"
#endif