#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* first;
    Node* last;
};


void display(Queue *q) {

}

void enqueue(Queue* q, int data) {

}

int dequeue(Queue* q) {

}

int main() {
    Queue q;
    q.first = q.last = 0;
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);

    cout << "Dequeueing: " << dequeue(&q);
    return 0;
}