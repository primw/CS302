// Prim Wandeevong // CS 302 - Homework 1: LinkedList.cpp // 2-6-20 //
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;


//Default Constructor
template <class ItemType>
LinkedList<ItemType>::LinkedList() : m_front(NULL), m_back(NULL), m_count(0)
{
}

//Destructor
template <class ItemType>
LinkedList <ItemType>::~LinkedList() 
{
    clear();
}

//Clear Method
template <class ItemType>
void LinkedList<ItemType>::clear()
{
    while(m_count != 0)
    {
        deleteItem(); 
    }
}

//Check Empty
template <class ItemType>
bool LinkedList<ItemType>::checkEmpty() const
{
   return (m_front == NULL);
}

//Add Item Method
template <class ItemType>
bool LinkedList<ItemType>::addItem(const ItemType anItem)
{
    if(checkEmpty())
    {
        Node<ItemType>* myNode = new Node<ItemType>();

        myNode->setItem(anItem);
        m_front = myNode;
        m_back = myNode;

        m_count++;

        return true;
    }

    else
    {
        Node<ItemType>* myNode = new Node<ItemType>();

        myNode->setItem(anItem);
        myNode->setNext(m_front);
        m_front = myNode;

        m_count++;

        return true;
    }
}

//Delete Item Method
template <class ItemType>
bool LinkedList<ItemType>::deleteItem()
{
    if (checkEmpty())
    {
        cerr << "Could Not Delete Recent Entry - Your list is empty :(" << endl;
        return false;
    }

    else
    {
        if (m_front == m_back)
        {
            Node<ItemType>* myNode = new Node<ItemType>();
            myNode = m_front;
            myNode->setNext(NULL);

            m_front = NULL;
            m_back = NULL;
            
            delete myNode;
            myNode = NULL;

            m_count--;

            return true;
        }

        else if(m_count != 0)
        {
            Node<ItemType>* myNode = new Node<ItemType>();

            myNode = m_front;
            m_front = m_front->getNext();

            myNode->setNext(NULL);
            delete myNode;        
            myNode = NULL;

            
            m_count--;
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
}

//Size Method
template <class ItemType>
const int LinkedList<ItemType>::size() const
{
    return m_count;
}

//Serialize Method
template <class ItemType>
void LinkedList<ItemType>::serialize(ostream& os) const
{
    if (!checkEmpty())
    {
        Node<ItemType>* myNode = new Node<ItemType>();
        int i = size();

        myNode = m_front;

        while(myNode)
        {
            os << "[" << i << "] " << myNode->getItem() << endl;
            i--;

            myNode = myNode->getNext();
        }
    }
    else
    {
        cout << "List is empty!" << endl;
    }
    
}

//Insertion Operator Overload
template <class ItemType>
ostream& operator<< (ostream& os,const LinkedList<ItemType> &myList)
{
    myList.serialize(os);
    return os;
}