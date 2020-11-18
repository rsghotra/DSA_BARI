#include "Queue.h"
using namespace std;

Queue::Queue(int size) {
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->Q = new Node*[size];
}

Queue::~Queue() {
    delete [] this->Q;
}

bool Queue::isFull() {
    if(this->rear == this->size-1) return true;
    else return false;
}

bool Queue::isEmpty() {
    if(this->front == this->rear) return true;
    else return false;
}

void Queue::enqueue(Node* n) {
    if(!isFull()) {
        this->Q[this->rear++] = n;
    }
}

Node* Queue::dequeue() {
    if(!isEmpty()) return this->Q[this->front++];
    else return nullptr;
}