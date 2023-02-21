// Problem 1

#include <iostream>
#include <thread>
using namespace std;

bool cakeFlag = true;
int waiterCount = 0;

int sum = 0;
int numEntered = 0;


void callWaiter();
void addSum();
void enterLabrynth(int guestNum, bool guestFlag[]);
int generateRandomNumber(int min, int max);





int main()
{
    const int guests = 10;
    //cout << "Input the number of guests: " << endl;

    //cin >> guests;

    int guestID = 0;

    thread threadArray[guests];
    bool guestFlag[guests] = {false};
    //start party 


    while (waiterCount != guests){
        guestID = generateRandomNumber(0, guests - 1);
        threadArray[guestID] = thread(enterLabrynth, guestID, guestFlag);
        threadArray[guestID].join();
    }

    cout << "All guests have entered the labrynth." << endl;
    cout << "Total entered: " << numEntered << endl;
    return 0;
}

void callWaiter()
{
    if (cakeFlag == false)
    {
        cout << "Waiter: " << "Cake is coming!" << endl;
        cakeFlag = true;
        waiterCount++;
    }
    else
    {
        cout << "Error: Waiter can only be called if there is no cake." << endl;
    }
}

void addSum(){
    sum += 1;
}

void enterLabrynth(int guestNum, bool guestFlag[] ) {
    numEntered++;
    cout << guestNum << " has entered the labrynth." << endl;
    // check if there is cake
    if (cakeFlag == false) {
        // call waiter
        callWaiter();
    }
    // check if this guest has entered before
    if (guestFlag[guestNum] == false) {
        // if not, eat the cake
        cakeFlag = false;
        guestFlag[guestNum] = true;
        cout << "repeat: will not eat cake " << guestNum << endl;
    } else {
        cout << "Will eat cake " << guestNum << endl;
    }

} 

int generateRandomNumber(int min, int max) {
    // generate random number between min and max
    return rand() % (max - min + 1) + min;
}


