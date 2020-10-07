// Prim Wandeevong // CS 302 - Homework 3: InsertionSort.cpp // 3-3-20 //
#include <iostream>
#include "InsertionSort.h"
using namespace std;


//Parameterized Constructor
template <class T>
InsertionSort<T>::InsertionSort(const int maxSize) : m_size(0), m_maxSize(maxSize), m_comparisons(0), m_swaps(0)
{
    m_arr = new T[maxSize];
}


//Copy Method
template <class T>
void InsertionSort<T>::copy(T array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_arr[i] = array[i];
        m_size++;
    }
}


//Print Method
template <class T>
void InsertionSort<T>::printToFile(string filename) const
{
    ofstream output;
    output.open(filename);
    for (int i = 0; i < m_maxSize; i++)
    {
        output << m_arr[i] << " ";
    }
    output.close();
}


//Sort Method
template <class T>
void InsertionSort<T>::sort()
{
    for (int unsorted = 1; unsorted < m_size; unsorted++)
    {
        T nextItem = m_arr[unsorted];
        int loc = unsorted;

        while ( (loc > 0) && (m_arr[loc-1] > nextItem))
        {
            m_comparisons++;
            m_arr[loc] = m_arr[loc-1];
            m_swaps++;
            loc--;
        }
        m_arr[loc] = nextItem;
    }
}

//Get Swap Method
template <class T>
long int InsertionSort<T>::getSwaps()
{
    return m_swaps;
}

//Get Comparison Method
template <class T>
unsigned long int InsertionSort<T>:: getComparisons()
{
    return m_comparisons;
}