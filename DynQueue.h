#ifndef DYNQUEUE_H
#define DYNQUEUE_H

#include <iostream>
using namespace std;

template <class T>
class DynQueue {
private:
    struct QueueNode {
        T value;
        QueueNode* next;
        QueueNode(T val, QueueNode* nxt = nullptr) {
            value = val;
            next = nxt;
        }
    };

    QueueNode* front;
    QueueNode* rear;

public:
    // Constructor
    DynQueue() {
        front = rear = nullptr;
    }

    // Destructor
    ~DynQueue() {
        clear();
    }

    // Queue operations
    void enqueue(T);
    void dequeue(T&);
    bool isEmpty() const;
    void clear();
};

// Enqueue adds to the rear
template <class T>
void DynQueue<T>::enqueue(T item) {
    QueueNode* newNode = new QueueNode(item);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue removes from the front
template <class T>
void DynQueue<T>::dequeue(T& item) {
    if (isEmpty()) {
        throw runtime_error("Queue is empty.");
    } else {
        QueueNode* temp = front;
        item = front->value;
        front = front->next;
        delete temp;
    }
}

// Check if empty
template <class T>
bool DynQueue<T>::isEmpty() const {
    return front == nullptr;
}

// Clear the queue
template <class T>
void DynQueue<T>::clear() {
    T temp;
    while (!isEmpty()) {
        dequeue(temp);
    }
}

#endif
