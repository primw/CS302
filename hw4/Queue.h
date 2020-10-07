// Prim Wandeevong // CS 302 -  Homework 4: Queue.h // 4-4-20 //
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"


//Forward Declaration
template <class T>
class Queue;

template <class T>
ostream& operator<< (ostream& os,const Queue<T> &myQueue);


//Class Declaration
template <class T>
class Queue
{
    public:
        friend ostream& operator<< <> (ostream& os,const Queue<T> &myQueue);
        Queue();
        bool isEmpty() const;
        bool enqueue(const T &newEntry);
        bool dequeue();
        T peek();
        void serialize(ostream &os) const;
        int getCount();

    private:
        Node<T>* m_front;
        Node<T>* m_back;
        int m_count;
};


#include "Queue.cpp"
#endif