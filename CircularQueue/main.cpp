#include<iostream>
using namespace std;

struct CQueue {
    int front;
    int rear;
    int size;
    int* Q;
};

/*
- Circular Linked List:
    - PITFALLS:
        - BOTH FRONT AND REAR STARTS FROM INDEX 0 instead 0f -1 in Linear Queue
        - FRONT IS ALWAYS EMPTY
        - DRAMATICALLY INCREASE SPACE UTILIZATION: AT MOST N-1 ELEMENTS COULD BE STORED
        - CIRCULAR ROATION IS ACHIEVED USING MODULATOR OPERATOR
        - QUEUE IS FULL: IF (R->NEXT)/SIZE == FRONT ==> THEN Q IS FULL
        - QUEUE IS EMPTY WHEN (R == F)
        - EXCELLENT REPRESENTATION OF QUEUE
        - DISPLAY FUNCTION IS ALSO INTERESTING

    - QUEUES - MOST OPTIMALLY IMPLEMENTED IN CIRCULAR FASHION.
    - DISPLAY - WATCH OUT
*/

void enqueue(CQueue* cq, int data) {
    //chk if queue is not full
    if((cq->rear+1)%cq->size == cq->front) {
        cout << "Queue is full." << endl;
    } else {
        cq->rear = (cq->rear+1)%cq->size;
        cq->Q[cq->rear] = data;
    }
}

int dequeue(CQueue* cq) {
    //chk if queue is empty only when both front and rear are at same location
    int x = -1;
    if(cq->front == cq->rear) {
        cout << "Queue is empty" << endl;
    } else {
        cq->front = (cq->front+1)%cq->size;
        x = cq->Q[cq->front];
    }
    return x;
}

void display(CQueue* cq) {
    /*
        - As front is always empty we must start displaying from front +1
        - MUST use while loop as it is not i++ but i=(i+1)%size
    */
   int i = cq->front+1;

   //watch out for the ending query. You would have thought this: while(i != cq->front)
   while(i != ((cq->rear+1)%cq->size)) {
       cout << cq->Q[i] << " ";
       i = (i+1)%cq->size;
   }
   cout << endl;
}

void create(CQueue* cq) {
    cout << "Enter size of circular queue" << endl;
    cin >> cq->size;
    //initialize values
    cq->front = 0;
    cq->rear = 0;
    cq->Q = new int[cq->size]();
}

int main() {
    CQueue cq;
    create(&cq);
    enqueue(&cq,10);
    enqueue(&cq,20);
    enqueue(&cq,30);
    enqueue(&cq,40);
    enqueue(&cq,50);
    enqueue(&cq,60);
    display(&cq);

    printf("%d ",dequeue(&cq));

}