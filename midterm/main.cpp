#include <iostream>
#include "SortedList.h"
using namespace std;

int main()
{
    SortedList myList;

    myList.insert(1);
    myList.insert(5);
    myList.insert(3);
    cout << myList.toString() << " Length: " << myList.getLength() << endl;

    int entry = myList.getEntry(2);
    cout << "Entry at listArray[2]: " << entry << endl;

    entry = myList.getPosition(5);
    cout << "Position of the entry that is equal to 5: " << entry << endl;

    myList.removeEntry(1);
    cout << myList.toString() << " Length: " << myList.getLength() << endl;

    myList.removePosition(0);
    cout << myList.toString() << " Length: " << myList.getLength() << endl;

    return 0;

}