#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
private:
    T* data;           // Dynamic array to store queue elements
    int capacity;      // Maximum capacity of the queue
    int front;         // Index of the front element
    int rear;          // Index of the rear element
    int numElements;   // Current number of elements in the queue

    // Helper function to resize the queue when full
    void resize();

public:
    Queue(int initialCapacity = 10);
    Queue(const Queue& other);
    
    Queue& operator=(const Queue& other);
    ~Queue();
    void enqueue(const T& value);  // Add element to the rear
    T& dequeue();                // Remove element from the front
    T& getFront();                 // Get front element (modifiable)
    const T& getFront() const;     // Get front element (read-only)
    T& getRear();                  // Get rear element (modifiable)
    const T& getRear() const;      // Get rear element (read-only)
    
    // Utility functions - all O(1) time complexity
    bool isEmpty() const;          // Check if queue is empty
    bool isFull() const;           // Check if queue is full
    int size() const;              // Get number of elements
    int getCapacity() const;       // Get current capacity
    void clear();                  // Remove all elements
    
    // Additional utility functions
    void display() const;          // Display queue contents
    bool contains(const T& value) const; // Check if value exists in queue
    
    // Friend function for output
    template<typename U>
    friend ostream& operator<<(ostream& os, const Queue<U>& queue);
};

#endif // QUEUE_H