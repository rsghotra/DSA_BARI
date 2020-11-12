#include<iostream>
using namespace std;

struct Queue {
    int size;
    int* Q;
    int front;
    int rear;
};

/*
IMPELENTING QUEUE USING ARRAYS
- Using two pointers - front and rear. BUT IT HAS SEVERE LIMITATIONS OF NOT REUSING SPACE PROPERLY
- Implementation limitation is same what an array could have
*/

bool isFull(Queue* q) {
    if(q->rear == q->size-1) {
        return true;
    }
    return false;
}

bool isEmpty(Queue* q) {
    if(q->rear == q->front) {
        return true;
    }
    return false;
}

void enqueue(Queue* q, int data) {
    //must check if queue is not already full
    if(q->rear == q->size-1) {
        cout << "Queue is full. Can not enqueue." << endl;
        return;
    } else {
        q->rear++;
        q->Q[q->rear] = data;
    }
}

int dequeue(Queue* q) {
    int x = -1;
    //must check if queue is not empty
    //smartly avoiding the collide when both front and rear at -1 and at last . then it is difficult to say whether Queue is empty or full.
    if(q->front == q->rear) {
        cout << "Queue is empty. Can not dequeue." << endl;
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void create(Queue* q) {
    cout << "Enter size of Queue: " << endl;
    cin >> q->size;
    q->Q = new int[q->size];
    q->front = -1;
    q->rear = -1;
}

void display(Queue q) {
    //watchout -- front+1
    for(int i=q.front+1; i<=q.rear;i++) {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue q;
    create(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    display(q);

    cout << "Dequeue: " << dequeue(&q) << endl;
    return 0;
}