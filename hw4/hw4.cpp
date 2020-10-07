#include <iostream>
#include <fstream>
#include "Node.h"
#include "Queue.h"
#include "PriorityNode.h"
#include "PriorityQueue.h"
#define ARRIVAL 'a'
#define DEPARTURE 'd'
using namespace std;

int main()
{
    PriorityQueue<int> arrivals;
    Queue<int> waitTimes;
    int arrivalTime, timeSpent, currentWait;
    int currentTime = 0, count = 0;
    
    ifstream inputStream;
    inputStream.open("line.txt");

    for (int i = 0; i < 10; i++)
    {
        inputStream >> arrivalTime >> timeSpent;
        arrivals.enqueue(timeSpent, arrivalTime);
    }
    inputStream.close();

    while(!arrivals.isEmpty())
    {
        while (currentTime == arrivals.getFrontPriority())
        {
            cout << "Processing arrival event at time: " << currentTime << endl;
            waitTimes.enqueue(arrivals.peek());
            count ++;
            arrivals.dequeue();
        }

        if(!waitTimes.isEmpty())
        {
            currentWait = waitTimes.peek();
            waitTimes.dequeue();
        }
        currentTime++;

        if (currentWait > 0)
        {
            currentWait--;

            if (currentWait == 0)
            {
                cout << "Processing departure event at time " << currentTime << endl;
            }
        }

    }

}