// /*
// - Circular Linked List:
//     - PITFALLS:
//         - BOTH FRONT AND REAR STARTS FROM INDEX 0 instead 0f -1 in Linear Queue
//         - FRONT IS ALWAYS EMPTY
//         - DRAMATICALLY INCREASE SPACE UTILIZATION: AT MOST N-1 ELEMENTS COULD BE STORED
//         - CIRCULAR ROATION IS ACHIEVED USING MODULATOR OPERATOR
//         - QUEUE IS FULL: IF (R->NEXT)/SIZE == FRONT ==> THEN Q IS FULL
//         - QUEUE IS EMPTY WHEN (R == F)
//         - EXCELLENT REPRESENTATION OF QUEUE
//         - DISPLAY FUNCTION IS ALSO INTERESTING

//     - QUEUES - MOST OPTIMALLY IMPLEMENTED IN CIRCULAR FASHION.
//     - DISPLAY - WATCH OUT
// */
#include<iostream>
using namespace std;

class CQueue {
    private:
        int size;
        int front;
        int rear;
        int* Q;
    public:
        CQueue(int);
        ~CQueue();
        void display();
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        bool isFull();
};

CQueue::CQueue(int size) {
    this->size = size;
    this->Q = new int[this->size];
    //watch out we start from zero
    this->front = 0;
    this->rear = 0;
}

CQueue::~CQueue() {
    delete[] Q;
}

bool CQueue::isEmpty() {
    if(this->front == this->rear) return true;
    else return false;
}


bool CQueue::isFull() {
    if((this->rear+1)%this->size == this->front) return true;
    return false;
}

//watch out how you will display the list
void CQueue::display() {
    //because front is alaways empty.
    int i = this->front+1;
    while(i != (this->rear+1)%this->size) {
        cout << this->Q[i] << " ";
        i = (i+1)%(this->size);   
    }
    cout << endl;
}

void CQueue::enqueue(int x) {
    if(!isFull()) {
        this->rear =(this->rear+1)%this->size;
        Q[rear] = x;
    } else {
        cout << "Circular Queue is Full" << endl;
    }
}

int CQueue::dequeue() {
    int x=-1;
    if(!isEmpty()) {
        front = (front+1)%size;
        x = Q[front];
    } else {
        cout << "Circular queue is Empty." << endl;
    }
    return x;
}

int main() {
    int A[] = {1,3,5,7,9};
    CQueue cq(10);
    for(int i=0;i<5;i++) {
        cq.enqueue(A[i]);
    }
    cq.display();
    cq.enqueue(10);
    for(int i=0;i<5;i++) {
        cout << "Dequeued from Circular Queue: " << cq.dequeue() << endl;
    }
    //underflow
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// vector<vector<string>> vect{};


// void set(string val, string location ) {
//   int rowIndex, colIndex;
//   string out = location.substr(1, location.length());
//   rowIndex = stoi(out);
//   colIndex = location[0] - 'A';
  
//   vect[rowIndex][colIndex] = val;
// }
// string get(string location) {
//   int rowIndex, colIndex;
//   string out = location.substr(1, location.length());
//   rowIndex = stoi(out);
//   colIndex = location[0] - 'A';
//   return vect[rowIndex][colIndex];
// }


// // To execute C++, please define "int main()"
// int main() {

  
//   set("10", "A1");
//   set("10", "A2");
//   cout << get("A1") << endl;
  
//   return 0;
// }