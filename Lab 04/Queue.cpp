#include "Queue.h"
#include<iostream>

// Constructor
template<typename T>
Queue<T>::Queue(int initialCapacity) 
    : capacity(initialCapacity), front(0), rear(-1), numElements(0) {
    if (initialCapacity <= 0) {
        throw invalid_argument("Capacity must be positive");
    }
    data = new T[capacity];
}

// Copy constructor
template<typename T>
Queue<T>::Queue(const Queue& other) 
    : capacity(other.capacity), front(other.front), 
      rear(other.rear), numElements(other.numElements) {
    data = new T[capacity];
    
    // Copy elements considering circular nature
    if (!other.isEmpty()) {
        int current = other.front;
        for (int i = 0; i < other.numElements; i++) {
            data[current] = other.data[current];
            current = (current + 1) % capacity;
        }
    }
}

// Assignment operator
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        delete[] data;
        
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        numElements = other.numElements;
        
        data = new T[capacity];
        
        // Copy elements considering circular nature
        if (!other.isEmpty()) {
            int current = other.front;
            for (int i = 0; i < other.numElements; i++) {
                data[current] = other.data[current];
                current = (current + 1) % capacity;
            }
        }
    }
    return *this;
}

// Destructor
template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

// Resize the queue when full - O(n)
template<typename T>
void Queue<T>::resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];
    
    // Copy elements to new array in linear order
    int current = front;
    for (int i = 0; i < numElements; i++) {
        newData[i] = data[current];
        current = (current + 1) % capacity;
    }
    
    delete[] data;
    data = newData;
    capacity = newCapacity;
    front = 0;
    rear = numElements - 1;
}

// Add element to the rear - O(1) amortized
template<typename T>
void Queue<T>::enqueue(const T& value) {
    if (isFull()) {
        resize();
    }
    
    rear = (rear + 1) % capacity;
    data[rear] = value;
    numElements++;
}

// Remove element from the front - O(1)
template<typename T>
 T&  Queue<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty. Cannot dequeue.");
    }
    
    front = (front + 1) % capacity;
    numElements--;
    
    // Reset indices if queue becomes empty
    if (isEmpty()) {
        front = 0;
        rear = -1;
    }
return data[front];
}

// Get front element (modifiable) - O(1)
template<typename T>
T& Queue<T>::getFront() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty. No front element.");
    }
    return data[front];
}

// Get front element (read-only) - O(1)
template<typename T>
const T& Queue<T>::getFront() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty. No front element.");
    }
    return data[front];
}

// Get rear element (modifiable) - O(1)
template<typename T>
T& Queue<T>::getRear() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty. No rear element.");
    }
    return data[rear];
}

// Get rear element (read-only) - O(1)
template<typename T>
const T& Queue<T>::getRear() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty. No rear element.");
    }
    return data[rear];
}

// Check if queue is empty - O(1)
template<typename T>
bool Queue<T>::isEmpty() const {
    return numElements == 0;
}

// Check if queue is full - O(1)
template<typename T>
bool Queue<T>::isFull() const {
    return numElements == capacity;
}

// Get number of elements - O(1)
template<typename T>
int Queue<T>::size() const {
    return numElements;
}

// Get current capacity - O(1)
template<typename T>
int Queue<T>::getCapacity() const {
    return capacity;
}

// Remove all elements - O(1) for reset, O(n) if destructors needed
template<typename T>
void Queue<T>::clear() {
    front = 0;
    rear = -1;
    numElements = 0;
}

// Display queue contents - O(n)
template<typename T>
void Queue<T>::display() const {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    cout << "Queue (front to rear): ";
    int current = front;
    for (int i = 0; i < numElements; i++) {
        cout << data[current];
        if (i < numElements - 1) {
            cout << " -> ";
        }
        current = (current + 1) % capacity;
    }
    cout << endl;
}

// Check if value exists in queue - O(n)
template<typename T>
bool Queue<T>::contains(const T& value) const {
    int current = front;
    for (int i = 0; i < numElements; i++) {
        if (data[current] == value) {
            return true;
        }
        current = (current + 1) % capacity;
    }
    return false;
}

// Output operator - O(n)
template<typename T>
ostream& operator<<(ostream& os, const Queue<T>& queue) {
    if (queue.isEmpty()) {
        os << "Queue is empty";
        return os;
    }
    
    int current = queue.front;
    os << "Queue (front to rear): ";
    for (int i = 0; i < queue.numElements; i++) {
        os << queue.data[current];
        if (i < queue.numElements - 1) {
            os << " -> ";
        }
        current = (current + 1) % queue.capacity;
    }
    return os;
}

// Explicit template instantiation for common types
template class Queue<int>;
template class Queue<double>;
template class Queue<string>;
template ostream& operator<<(ostream& os, const Queue<int>& queue);
template ostream& operator<<(ostream& os, const Queue<double>& queue);
template ostream& operator<<(ostream& os, const Queue<string>& queue);