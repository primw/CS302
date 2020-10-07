#ifndef SORTED_H
#define SORTED_H

class SortedList
{
    public:
        SortedList();
        bool insert(const int &entry);
        bool removeEntry(const int &entry);
        bool removePosition(const int &position);
        int getPosition(const int &entry);
        int getEntry(int position);
        int getLength();
        bool isEmpty();
        void clear();
        void sort();
        std::string toString();
        
    private:
        int *listArray;
        int listSize;
        int currentPosition;

};

#endif