// Prim Wandeevong // CS 302 - Homework 2: Node.cpp // 2-6-20 //
#include <iostream>
#include "Node.h"

 
//Default Constructor
template <class ItemType>
Node<ItemType>::Node() : m_next(NULL)
{
}

//Parameterized Constructor - item
template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : m_item(anItem), m_next(NULL)
{
}

//Parameterized Constructor - item + next
template <class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : m_item(anItem), m_next(nextNodePtr)
{
}

//Set Item Method
template <class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) 
{
    m_item = anItem;
}

//Set Next Method
template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    m_next = nextNodePtr;
}

//Get Item Method
template <class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return m_item;
}

//Get Next Method
template <class ItemType>
Node<ItemType>* Node <ItemType>:: getNext() const
{
    return m_next;
}
