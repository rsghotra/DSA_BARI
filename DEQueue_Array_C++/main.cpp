#include<iostream>
using namespace std;

/*
DEQueue = In which both front and rear have the capability to insert and delete
PITFALLS:
    - How front is going to insert
    - how rear is going to delete
    - when front is full
    - when rear is empty
    NOTE: In standard operations i.e. dequeue from front and enqueue from rear WILL use standard isFull and isEmpty functions
            BUT NON STANDARD CALLS SUCH AS DEQUEREAR AND ENQUEUE FRONT WILL NEED TO HANDLE SPECIALLY
*/


class DEQueue{
    private:
        int front;
        int rear;
        int size;
        int* Q;
    public:
        DEQueue(int);
        ~DEQueue();
        void display();
        void enqueueFront(int x);
        void enqueueRear(int x);
        int dequeueFront();
        int dequeueRear();
        bool isFull();
        bool isEmpty();
};

DEQueue::DEQueue(int size) {
    //initialize the queue
    this->size = size;
    this->rear = -1;
    this->front = -1;
    this->Q = new int[this->size];
}

DEQueue::~DEQueue() {
    delete [] Q;
}

bool DEQueue::isFull() {
    if(this->rear == this->size-1) return true;
    else return false;
}

bool DEQueue::isEmpty() {
    if(this->front == this->rear) return true;
    else return false;
}

void DEQueue::display() {
    //watch out - we must start from front+1
    for(int i = this->front+1; i <= this->rear;i++) {
        cout << this->Q[i] << " ";
    }
    cout << endl;
}

void DEQueue::enqueueRear(int x) {
    //checking using standard function for full condition
    if(isFull()) {
        cout << "DEQueue is full. Can not enqueue." << endl;
    } else {
        //standar procedure; increase rear add value
        this->rear++;
        this->Q[this->rear] = x;
    }
}

int DEQueue::dequeueFront() {
    //standard operation
    int x = -1;
    if(isEmpty()) {
        cout << "DEQueue is empty. Nothing to dequeue" << endl;
    } else {
        //standard behavior
        this->front++;
        x=this->Q[this->front];
    }
    return x;
}

/*
    - NON STANDARD Operations of the DEQUEUE
    - SPECIAL CHECKS OF EMPTINESS AND FULLNESS
*/

void DEQueue::enqueueFront(int x) {
    //as front is always point to empty space. Therefore, we fill the space and move the font ptr back. 
    //Because when front ptr increases - size of list actually decresese - unless the queue is circular
    //front will move backward
    //pushing into front is not possible if front == -1. In that case queue will be considered full.
    if(this->front == -1) {
        cout << "Enqueue from front is not possible as front == -1" << endl;
    } else{
        //WATCH OUT
        this->Q[this->front]=x;
        this->front--; //holysmoke
    }
}

int DEQueue::dequeueRear() {
    //as rear always point to a VALID space. and it is a dequeue operation. We extract value decremenet rear
    //as rear decreases - size of list decreases as well.
    int x = -1;
    if(this->rear == -1) {
        cout << "DEQueue is empty. Can't dequeue" << endl;
    } else {
        x = this->Q[this->rear];

        this->rear--; //holysmoke
    }
    return x;
}

int main() {
    int A[5] = {1,3,5,7,9};
    int B[4] = {2,4,6,8};

    DEQueue deq(4);
    for(int i = 0; i < 5; i++) {
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);

    //dequeue - will increase the front value.
    for(int i = 0; i < 5; i++) {
        cout << "Dequeued: " << deq.dequeueFront() << endl;
    }
    deq.dequeueFront();
    //at this time front is at last index of the arrayit
    for(int i = 0; i<4; i++) {
        //at this time front is at last postin which is 4.
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);

    for(int i = 0; i<4; i++) {
        //at this time front is at last postin which is 4.
        cout << "Dequeued: " << deq.dequeueRear() << endl;
    }

    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();
    return 0;
}
