#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    Node* left;
    int val;
    Node* right;
};

class Queue {
    private:
        int front;
        int rear;
        int size;
        Node** Q;
    public:
        Queue(int);
        ~Queue();
        void enqueue(Node*);
        Node* dequeue();
        bool isFull();
        bool isEmpty();
};

#endif