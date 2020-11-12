#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};


void display(Queue *q) {
    Node* ptr = q->front;
    while(ptr) {
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    cout << endl;
}

void enqueue(Queue* q, int data) {
    /*
        Special Cases:
            - Queue is full - Heap is full
            - Queue is empty

    */
    Node* t = new Node;
    if(t==0) {
        cout << "Queue is full because heap is full. Can't enqueue" << endl;
    } else {
        t->data = data;
        t->next = 0;
        //sp2
        if(q->front==0)  {
            //initialize front, rear
            q->front = q->rear = t;
        } else {
            q->rear->next = t;
            q->rear = t;
        }
    }
}

int dequeue(Queue* q) {
    /*
        Special Cases:
            - When list is empty
    */
   int x = -1;
   if(q->front == 0) {
        cout << "Queue is empty" << endl;
   } else {
       Node* ptr = q->front;
       q->front = q->front->next;
       x = ptr->data;
       ptr=0;
   }

   return x;
}

int main() {
    Queue q;
    q.front = q.rear = 0;
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);

    cout << "Dequeueing: " << dequeue(&q) << endl;
    cout << "Dequeueing: " << dequeue(&q) << endl;
    return 0;
}