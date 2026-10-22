#include <iostream>  // Used for displaying output
#include <thread>    // Used to create threads
#include <mutex>     // Used to protect shared data

using namespace std;

int total = 0;  // Global variable shared by all threads
mutex mtx;      // Prevents simultaneous updates to total

// Adds the given number to the global variable
void add(int number) {
    lock_guard<mutex> lock(mtx);
    total += number;
}

int main() {
    // Create three threads with different values
    thread T1(add, 10);
    thread T2(add, 50);
    thread T3(add, 90);

    // Wait for T1, T2, T3 to finish and display the total
    T1.join();
    cout << "After T1: " << total << endl;

    T2.join();
    cout << "After T2: " << total << endl;

    T3.join();
    cout << "After T3: " << total << endl;

    return 0;  
}
