// Prim Wandeevong // CS 302 - Homework 1: main.cpp // 2-6-20 //
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

//Function Declaration
void clear();


//Main Function
int main()
{
	int choice = 0, data = 0;
    LinkedList<int> myList;
    
	do
	{
		cout << "________________________________________________________________________________________________________" << endl
             << "Options:" << endl
		     << "1.) Add item" << endl
	         << "2.) Delete most recent entry" << endl
		     << "3.) Count items" << endl
		     << "4.) List all items" << endl
		     << "5.) Exit" << endl
             << "________________________________________________________________________________________________________" << endl
		     << "Choice: ";
		cin >> choice;
        cout << endl;
        

		switch(choice)
		{
			case 1:
                clear();
                cout << "Please enter data you want in your list (int): " << endl;
				cin >> data;
                myList.addItem(data);
				break;
			case 2:
                clear();
				cout << "Deleting the most recent entry......." << endl;
                myList.deleteItem();
				break;
			case 3:
                clear();
				cout << "Your list has " << myList.size() << " items!" << endl;
                break;
			case 4:
                clear();
				cout << "Printing your list!" << endl << myList;
                break;
			case 5:
				cout << "Exiting Program!"<< endl;
                clear();
                break;
			default:
                clear();
				cout << "Invalid Input!" << endl;
                break;
		}
			
	}while(choice != 5);
  
    return 0;
}


//Clear Function
void clear()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

