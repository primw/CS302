// Prim Wandeevong // CS 302 - Homework 1: LinkedList.h // 2-6-20 //
#ifndef LIST_H
#define LIST_H
using namespace std;

//Templated LinkedList Foward Declaration
template <class ItemType> 
class LinkedList;

//Templated Friend Function Foward Declaration
template <class ItemType>
ostream& operator<< (ostream& os, const LinkedList<ItemType> &myList);

//Templated LinkedList Class Declaration
template <class ItemType>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        bool addItem(const ItemType anItem);
        bool deleteItem();
        bool deleteAnItem(const ItemType anItem);
        const int size() const;
        void clear();
        bool checkEmpty() const;
        void serialize(ostream& os) const;
        friend ostream& operator<< <> (ostream& os, const LinkedList<ItemType> &myList);
        ItemType getItem() {return m_back->getItem();}

    private:
        Node<ItemType>* m_front;
        Node<ItemType>* m_back;
        int m_count;
};

#include "LinkedList.cpp"
#endif