#include <iostream>
#include <string>
#include "DynQueue.h"
using namespace std;

int main() {
    // Test with integers
    DynQueue<int> intQueue;
    cout << "Enqueuing integers 1, 2, 3...\n";
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);

    int num;
    cout << "Dequeuing integers:\n";
    while (!intQueue.isEmpty()) {
        intQueue.dequeue(num);
        cout << num << " ";
    }
    cout << endl;

    // Test with strings
    DynQueue<string> stringQueue;
    cout << "Enqueuing strings \"Apple\", \"Banana\", \"Cherry\"...\n";
    stringQueue.enqueue("Apple");
    stringQueue.enqueue("Banana");
    stringQueue.enqueue("Cherry");

    string str;
    cout << "Dequeuing strings:\n";
    while (!stringQueue.isEmpty()) {
        stringQueue.dequeue(str);
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
