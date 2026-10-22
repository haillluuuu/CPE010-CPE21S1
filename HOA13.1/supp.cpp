#include <iostream>
#include <thread>
using namespace std;

int fNum, lNum;
int result = 0;

// Compares the two numbers
void greaterNum() {
    if (fNum > lNum) {
        result = 1;
    }
    else if (lNum > fNum) {
        result = 2;
    }
    else {
        result = 3;
    }
}

int main() {
    cout << "What Number is Greater Calculator" << endl;

    cout << "Enter First Number: ";
    cin >> fNum;

    cout << "Enter Second Number: ";
    cin >> lNum;

    // Create a thread to compare the numbers
    thread T1(greaterNum);

    // Wait for the thread to finish
    T1.join();

    // Display the result
    if (result == 1) {
        cout << fNum << " is Greater than " << lNum << endl;
    }
    else if (result == 2) {
        cout << lNum << " is Greater than " << fNum << endl;
    }
    else {
        cout << fNum << " is Equal to " << lNum << endl;
    }

    return 0;
}
