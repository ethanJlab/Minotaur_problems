// Problem 2
// 3rd method: queue

#include <iostream>
#include <thread>
#include <queue>
using namespace std;

const int guests = 10;
// variable to contract the number of guests will want to visit
const int maxVisits = 100;
int numVisits = 0;
int guestInRoomID = 0;


void printQueue(queue<int> q);
bool isInQueue(queue<int> q, int guestID);
void notifyQueue(queue<int> q);
void push(queue<int> q, int guestID);
int generateRandomNumber(int min, int max);


int main() {
    
    queue<int> vaseLine;
    thread threadArray[guests];

    // we will start with guest 0 in the room    
    int guestID = guestInRoomID;
    printQueue(vaseLine);

    //start party
    while(numVisits < maxVisits)
    {
        //generate random number between 0 and guests and check if they are already in the queue
        guestID = generateRandomNumber(0, guests - 1);
        if (isInQueue(vaseLine, guestID) == false)
        {
            //the guest will join the queue
            threadArray[guestID] = thread(push,vaseLine,guestID);
            cout << "guest " << guestID << " is in the q" << endl;
            threadArray[guestID].join();
        }
        

        // the guest in the room will leave the room and notify the queue
        // this will dequeue the next guest in the queue and update the current guest in the room
        threadArray[guestInRoomID] = thread(notifyQueue, vaseLine);
        threadArray[guestInRoomID].join();
    }    
    cout << "max visists reached" << endl;
    printQueue(vaseLine);
    return 0;
}

void printQueue(queue<int> q)
{
    queue<int> g = q;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

bool isInQueue(queue<int> q, int guestID)
{
    queue<int> g = q;
    while (!g.empty()) {
        if (g.front() == guestID)
        {
            return true;
        }
        g.pop();
    }
    return false;
}

// function for a thread to call once they are done looking at the vase
// function will dequeue the next guest and update the current guest in the room
void notifyQueue(queue<int> q)
{
    if (q.empty())
    {
        cout << "queue is empty" << endl;
        q.push(((guestInRoomID + 1) > guests - 1 ? 0 : (guestInRoomID + 1)));
        //push(q, ((guestInRoomID + 1) > guests - 1 ? 0 : (guestInRoomID + 1)));
        guestInRoomID = q.front();
        numVisits++;
        cout << "guest " << guestInRoomID << " is in the room" << endl;
        q.pop();        
        return;
    }
    guestInRoomID = q.front();
    numVisits++;
    cout << "guest " << guestInRoomID << " is in the room" << endl;
    q.pop();
}

void push(queue<int> q, int guestID)
{
    q.push(guestID);
}

int generateRandomNumber(int min, int max)
{
    int randomNum = rand() % max + min;
    return randomNum;
}