#include<iostream>
using namespace std;

/*
    Priority Queue is nothing but logical arrangements of queues accroding to priority power. Two types of PQ could be:
        1. Limited Element Set Priority - when number of priorities are limited like in OS
            - Element will be added to its corresponding priority queue
            - if the highest priority queue get empty then we go to next
            - if all pqs are empty then list is empty
        2. Element Prirority - When number of prirorities unknown and each element brings its own priority. Two Ways:
            I.
                A. Enqueue Element as it comes - O(1)
                B. Dequeue element - O(2n)
                    - Search for highest priority element - O(n) + Remove and shift elements - O(n)
            II.
                A. Enqueue Element in decreasing order of priority : O(n)
                B. Dequeue Last Element - O(1)

        In this program we will implement 1.
*/

/*
    Number of Priorities = 3;
*/

class Queue {
    private:
        int front;
        int rear;
        int size;
        char* Q;
    public:
        Queue(int);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enqueue(int);
        char dequeue();
        void display();
};

Queue::Queue(int size) {
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->Q = new char[this->size];
}

Queue::~Queue() {
    delete[] Q;
}

bool Queue::isEmpty() {
    if(this->front == this->rear) return true;
    else return false;
}

bool Queue::isFull() {
    if(this->rear == this->front) return true;
    else return false;
}

void Queue::display() {
    for(int i=0;i<this->size;i++) {
        cout << this->Q[i] << " ";
    }
}

void Queue::enqueue(int x) {
    if(isFull()) {
        cout << "Queue is full. Can't enqueue" << endl;
    } else {
        this->rear++;
        this->Q[this->rear] = x;
    }
}

char Queue::dequeue() {
    char x = 0;
    if(isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        this->front++;
        x=this->Q[this->front];
    }
    return x;
}

void enqueue_pq(Queue* q1, Queue* q2, Queue* q3, char x, int priority) {

}

char dequeue_pq(Queue* q1, Queue* q2, Queue* q3) {

}

void display_pq(Queue* q1, Queue* q2, Queue* q3) {
    q1->display();
    q2->display();
    q3->display();
}

int main() {
    /*
        Number of priorities=3
    */
    Queue q1(10);
    Queue q2(10);
    Queue q3(10);

    //Enqueueing in PQ
    enqueue_pq(&q1,&q2,&q3,'A', 1);
    enqueue_pq(&q1,&q2,&q3,'B', 1);
    enqueue_pq(&q1,&q2,&q3,'C', 2);
    enqueue_pq(&q1,&q2,&q3,'D', 3);
    cout << "Dequeued: " << dequeue_pq(&q1,&q2,&q3) << endl;
    cout << "Dequeued: " << dequeue_pq(&q1,&q2,&q3) << endl;
    cout << "Dequeued: " << dequeue_pq(&q1,&q2,&q3) << endl;
    enqueue_pq(&q1,&q2,&q3,'E', 2);
    enqueue_pq(&q1,&q2,&q3,'F', 1);
    enqueue_pq(&q1,&q2,&q3,'G', 2);
    enqueue_pq(&q1,&q2,&q3,'H', 3);
    enqueue_pq(&q1,&q2,&q3,'I', 2);
    enqueue_pq(&q1,&q2,&q3,'J', 2);
    enqueue_pq(&q1,&q2,&q3,'K', 3);
    display_pq(&q1,&q2,&q3);
    cout << "Dequeued: " << dequeue_pq(&q1,&q2,&q3) << endl;
    cout << "Dequeued: " << dequeue_pq(&q1,&q2,&q3) << endl;
    cout << "Dequeued: " << dequeue_pq(&q1,&q2,&q3) << endl;
    return 0;
}