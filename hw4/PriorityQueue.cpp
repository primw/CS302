#include <iostream>
#include "PriorityNode.h"
#include "PriorityQueue.h"
using namespace std;

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    m_front = m_back = NULL;
}

template <class T>
bool PriorityQueue<T>::isEmpty() const
{
    return m_front == NULL;
}

template <class T>
bool PriorityQueue<T>::enqueue(const T &newEntry, const int& priority)
{
    PriorityNode<T>* person = new PriorityNode<T>(newEntry, priority);
    PriorityNode<T>* temp = new PriorityNode<T>();
    temp = m_front;

      //if we have no node, we create head and tail node here
    if(m_front == NULL && m_back == NULL)
    {
        m_front = person;
        m_back = person;
    }
    else
    {
        if(person->getPriority() <= m_front->getPriority())
            {
                temp = m_front;
                m_front = person;
                person->setNext(temp);
            }
            
        else if(person->getPriority() >= m_back->getPriority())
            {
                m_back->setNext(person);
                m_back = person;
            }
            
        temp = m_front  ;
        while(temp->getNext() != NULL)
        {
            if(person->getPriority() < temp->getNext()->getPriority())
            {
                PriorityNode<T>* newy;
                newy = temp->getNext();
                temp->setNext(person);
                person->setNext(newy);
            }
                
                temp = temp->getNext();
        }
            return true;
    }   
}


    template <class T>
    bool PriorityQueue<T>::dequeue()
    {
        PriorityNode<T>* temp = m_front;
        if(m_front == NULL)
        {
            printf("\nQueue is empty, pls Enqueue");
            return false;
        }
        if(m_front == m_back)
        {
            m_front = NULL;
            m_back = NULL;
            return true;
        }

        m_front = temp->getNext();
        free(temp);
        return true;
    }

    template <class T>
    T PriorityQueue<T>::peek()
    {
        if(!isEmpty())
        {
            return m_front->getItem();
        }
        else
        {
            cout << "The queue is empty!" << endl;
        }
        
    }



template <class T>
void PriorityQueue<T>::serialize(ostream &os) const
{
    if(!isEmpty())
    {
        PriorityNode<T>* myNode = m_front;
      
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
template <class T>
ostream& operator<< (ostream& os,const PriorityQueue<T> &myQueue)
{
    myQueue.serialize(os);
    return os;
}


template <class T>
int PriorityQueue<T>::getFrontPriority()
{
    return m_front->getPriority();
}

