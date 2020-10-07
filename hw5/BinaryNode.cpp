// Prim Wandeevong // CS 302 - Homework 5: BinaryNode.cpp // 4-21-20 //
#include "BinaryNode.h"


//Parameterized Constructor
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &anItem) : m_item(anItem), m_left(NULL), m_right(NULL) 
{
}

//Get Item Method
template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const 
{
    return m_item;
}

//Get Left Method
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const 
{
    return m_left;
}

//Get Right Method
template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const 
{
    return m_right;
}

//Set Left Method
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType> *leftPtr) 
{
    m_left = leftPtr;
}

//Set Right Method
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType> *rightPtr) 
{
    m_right = rightPtr;
}