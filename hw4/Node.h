// Prim Wandeevong // CS 302 - Homework 4: Node.h // 2-6-20 //
#ifndef NODE_H
#define NODE_H
using namespace std;


//Templated Node Class Declaration
template <class ItemType>
class Node
{
    public:
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
        void setItem(const ItemType& anItem);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;

    private:
    ItemType m_item; 
    Node<ItemType>* m_next; 
}; 

#include "Node.cpp"
#endif