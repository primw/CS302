// Prim Wandeevong // CS 302 - Homework 3 : SelectionSort.cpp // 3-3-20 //
#include <iostream>
#include <fstream>
#include <string>
#include "SelectionSort.h"
using namespace std;


//Parameterized Constructor
template <class T>
SelectionSort<T>::SelectionSort(const int maxSize) : m_size(0), m_maxSize(maxSize), m_comparisons(0), m_swaps(0)
{
    m_arr = new T[maxSize];
}


//Sort Method
template <class T>
void SelectionSort<T>::sort()
{
    for (int last = m_size-1; last >= 1; last--) 
    {
        int largest = findIndexOfLargest(last + 1);
        swap(m_arr[largest], m_arr[last]);
        m_swaps++;

    }
}


//Print Method
template <class T>
void SelectionSort<T>::printToFile(string filename) const
{
    ofstream output;
    output.open(filename);

    for (int i = 0; i < m_maxSize; i++) 
    {
        output << m_arr[i] << " ";
    }
}


//Copy Method
template <class T>
void SelectionSort<T>::copy(T array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_arr[i] = array[i];
        m_size++;
    }
}


//Find Index of Largest Method
template <class T>
int SelectionSort<T>::findIndexOfLargest(const int maxIndex)
{
    int indexSoFar = 0;
    for (int currentIndex = 1; currentIndex < m_size; currentIndex++) 
    {
        if (m_arr[currentIndex] > m_arr[indexSoFar]) 
        {
            indexSoFar = currentIndex;
            m_comparisons++;
        }
    }

    return indexSoFar;
}


//Get Swap Method
template <class T>
long int SelectionSort<T>::getSwaps()
{
    return m_swaps;
}

//Get Comparison Method
template <class T>
unsigned long int SelectionSort<T>:: getComparisons()
{
    return m_comparisons;
}