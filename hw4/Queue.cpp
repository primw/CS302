#include "Queue.h"
#include "Node.h"
using namespace std;

template <class T>
Queue<T>::Queue() : m_count(0)
{
    m_front = m_back = NULL;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return m_front == NULL;
}

template <class T>
bool Queue<T>::enqueue(const T &newEntry) 
{
    
    Node<T>* nodePtr = new Node<T>(newEntry);

    if(!isEmpty())
    {
        m_count++;
        m_back->setNext(nodePtr);
        m_back = nodePtr;
        return true;
    }
    else
    {
        m_count++;
        m_front = m_back = nodePtr;
        return true;
    }

    delete nodePtr;
    return false;
    
}


template <class T>
bool Queue<T>::dequeue()
{
    Node<T>* nodeToBeDeleted = new Node<T>();

    if(!isEmpty())
    {
        m_count--;
        nodeToBeDeleted = m_front;
        m_front = m_front->getNext();
        nodeToBeDeleted->setNext(NULL);
        return true;
    }
    else
    {
        cout << "The queue is empty!" << endl;
    }
    return false;
}


template <class T>
T Queue<T>::peek()
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
void Queue<T>::serialize(ostream &os) const
{
    if(!isEmpty())
    {
        Node<T>* myNode = m_front;
      
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
ostream& operator<< (ostream& os,const Queue<T> &myQueue)
{
    myQueue.serialize(os);
    return os;
}

template <class T>
int Queue<T>::getCount()
{
    return m_count;
}


