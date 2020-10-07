#include <iostream>
#include <sstream>
#include "SortedList.h"
using namespace std;

SortedList::SortedList() : listSize(0)
{
    listArray = new int[20];
    for(int i = 0; i < 20; i++)
    {
        listArray[i] = 0;
    }
    currentPosition = 0;
}


bool SortedList::insert(const int &entry)
{
    if (listSize > 20)
    {
        return false;
    }
    else
    {
        //Shifts elements up
        for (int i = listSize; i > currentPosition; i--)
        {
            listArray[i] = listArray[i-1];
        }

        listArray[currentPosition] = entry;
        listSize++;
        currentPosition++;
        sort();
        return true;
    }
    
}

bool SortedList::removeEntry(const int &entry)
{
    for(int i = 0; i < listSize; i++)
    {
        if (listArray[i] == entry)
        {
            removePosition(i);
            return true;
        }
    }
    return false;
}
bool SortedList::removePosition(const int &position)
{
    for (int i = position; i < listSize; i++)
    {
        listArray[i] = listArray[i + 1];
    }
    listSize--;
    return true;
}

int SortedList::getPosition(const int &entry)
{
    for(int i = 0; i < listSize; i++)
    {
        if(listArray[i] == entry)
        {
            return i;
        }
    }
}
int SortedList::getEntry(int position) {return listArray[position];}
int SortedList::getLength() {return listSize;}
bool SortedList::isEmpty() {return listSize == 0;}
void SortedList::clear()
{
    for (int i = 0; i < 20; i++)
    {
        listArray[i] = 0;
    }
}

string SortedList::toString() 
{
    ostringstream os;
    os << "[ ";
    for(int i = 0; i < listSize; i++)
    {
        os << listArray[ i ] << " ";
        
    }
    os << "]";
    return os.str();
}
void SortedList::sort()
{
    for (int unsorted = 1; unsorted < listSize; unsorted++)
    {
        int nextItem = listArray[unsorted];
        int loc = unsorted;

        while ( (loc > 0) && (listArray[loc-1] > nextItem))
        {
            listArray[loc] = listArray[loc-1];
            loc--;
        }
        listArray[loc] = nextItem;
    }
}