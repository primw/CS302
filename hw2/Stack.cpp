// Prim Wandeevong // CS 302 - Homework 2: Stack.cpp // 2-17-20 //
#include <iostream>
#include "Node.h"
#include "Stack.h"
using namespace std;


//Default Constructor
template <class ItemType>
Stack<ItemType>::Stack() : m_top(NULL)
{
}

//Copy Construtor
template <class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> &other)
{
	m_top = new Node<ItemType>(other.m_top->getItem(), NULL);

	Node<ItemType> * othercpy = other.m_top;
	Node<ItemType> * thiscpy = m_top;
	
    while(othercpy->m_next)
    {
		thiscpy->m_next = new Node<ItemType>(othercpy->getItem(), NULL);
		thiscpy = thiscpy->m_next;
		othercpy = othercpy->m_next;
	}
		
}

//Destructor
template <class ItemType>
Stack<ItemType>::~Stack() 
{
    clear();
}

//Peek Method - Returns value of the top
template<class ItemType>
ItemType Stack<ItemType>::peek()
{
    if(!isEmpty())
    {
        return m_top->getItem();
    }
    else
    {
        cerr << "Your Stack is Empty!" << endl;
    }
    
}
//Push Method - Adds item on top of the Stack
template <class ItemType>
void Stack<ItemType>::push(const ItemType value)
{
    if(!isEmpty())
    {
        Node<ItemType>* myNode = new Node<ItemType>(value, NULL);
        myNode->setNext(m_top);
        m_top = myNode;
    }
    else
    {
       m_top = new Node<ItemType>(value, NULL);
    }
}

//Pop Method - Deletes item on the top of the Stack
template <class ItemType>
void Stack<ItemType>::pop()
{
    if (isEmpty())
    {
        cerr << "Could Not Delete Most Recent Entry - Your Stack is empty :(" << endl;
    }

    else
    {
       
        Node<ItemType>* myNode = new Node<ItemType>();
        myNode = m_top;
        m_top = m_top->getNext();

        delete myNode;        
        myNode = NULL;
    }
    
}

//Clear Method
template <class ItemType>
void Stack<ItemType>::clear()
{
  if(!isEmpty())
  {
    	while(!isEmpty())
        {
			pop();
        }    
  }
  else
    {
		cout << "This Stack is now empty!" << endl;
    }
}

//Check Empty
template <class ItemType>
bool Stack<ItemType>::isEmpty() const
{
   return (m_top == NULL);
}

//Check Full Method
template <class ItemType>
bool Stack<ItemType>::isFull() const
{
    Node<ItemType> temp = new Node<ItemType>();

    if(!temp)
    {
        cerr << "Heap Overflow! - Stack is Full :(" << endl;
        return true;
    }

    else
    {
        return false;
    }
    
}


//Serialize Method
template <class ItemType>
void Stack<ItemType>::serialize(ostream& os) const
{
    if (!isEmpty())
    {
        Node<ItemType>* myNode = m_top;

        os << "\t[";
        while(myNode)
        {
            if(myNode->getNext() == NULL)
            {
                os << myNode->getItem() << "]" << endl;
                
            }
            else
            {
                os << myNode->getItem() << ", ";
            }
            myNode = myNode->getNext();
        }
    }
    else
    {
        cout << "This stack is empty! :(" << endl;
    }
    
}

//Insertion Operator Overload
template <class ItemType>
ostream& operator<< (ostream& os,const Stack<ItemType> &myStack)
{
    myStack.serialize(os);
    return os;
}