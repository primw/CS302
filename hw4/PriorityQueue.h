#ifndef PQUEUE_H
#define PQUEUE_H
#include "PriorityNode.h"


//Forward declaration
template <class T>
class PriorityQueue;

template <class T>
ostream& operator<< (ostream& os,const PriorityQueue<T> &myQueue);

//Class Declaration
template <class T>
class PriorityQueue
{
    public:
        PriorityQueue();
        bool isEmpty() const;
        bool enqueue(const T &newEntry, const int& priority);
        bool dequeue();
        T peek();
        void serialize(ostream &os) const;
        int getFrontPriority();

    private:
        PriorityNode<T>* m_front;
        PriorityNode<T>* m_back;
};

#include "PriorityQueue.cpp"
#endif
