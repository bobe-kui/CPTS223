#include "HeapPriorityQueue.h"
#include <iostream>

// TODO: Implement the constructor
HeapPriorityQueue::HeapPriorityQueue() {
    // Initialize size to 0
    this->size = 0;
}

// TODO: Implement the destructor
HeapPriorityQueue::~HeapPriorityQueue() {
    // Cleanup if necessary
    for(int i = 0; i < this->size; i++)
    {
        //delete this->heap[i];
    }
}

// TODO: Implement the copy constructor
HeapPriorityQueue::HeapPriorityQueue(const HeapPriorityQueue& other) {
    // Copy heap elements and size
    for(int i = 0; i < other.size; i++)
    {
        this->heap[i] = other.heap[i];
    }
    this->size = other.size;
}

// TODO: Implement the copy assignment operator
HeapPriorityQueue& HeapPriorityQueue::operator=(const HeapPriorityQueue& other) {
    // Assign heap elements and size properly
    for(int i = 0; i < other.size; i++)
    {
        this->heap[i] = other.heap[i];
    }
    this->size = other.size;
    return *this;
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    // Insert new PrinterJob(str, priority) while maintaining heap order using percolateUp
    PrinterJob newJob(str, priority);
    this->heap[this->size] = newJob;
    if(this->heap[this->size]<this->heap[this->size - 1])
    {
        this->percolateUp(this->size);
    }
    this->size++;
}

// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    // Print and remove PrinterJobs from the heap in priority order and using percolateDown as necessary
    if(this->size == 0)
    {
        cout << "Print queue empty" << endl;
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << this->heap[0].printString << " (Priority: " << this->heap[0].priority << ")" << endl;
            this->percolateDown(this->size);
        }
        this->size = 0;
    }

}

// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    // Maintain heap order when inserting a new PrinterJob
    while(index > 0 && this->heap[index] < this->heap[index-1])
    {
        PrinterJob temp = this->heap[index];
        this->heap[index] = this->heap[index-1];
        this->heap[index-1] = temp;
        index--;
    }


}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    // Maintain heap order when removing a PrinterJob
    for(int i = 0; i < index; i++)
    {
        this->heap[i] = this->heap[i+1];
    }
}
