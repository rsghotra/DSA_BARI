#include<iostream>
#include<cstring>
using namespace std;

// AS we representing stack as a linked list
/*
 - we will always insert or delete node from head
*/

struct Node {
    char data;
    Node* next;
};

bool isEmpty(Node* top) {
    if(!top) return true;
    else return false;
}

bool isFull(Node* top) {
    //since it is a LL so  unlimited capacity unless Heap is full
    Node * t = new Node;
    if(!t) return true;
    return false;
}

//no need to 
Node* push(Node* top, char x) {
    Node* t = new Node;
    t->data = x;
    t->next = top;
    top = t;
    return top;
}

Node* pop(Node* top) {
    if(!top) {
        cout << "Stack Underflow, can't pop." << endl;
        return nullptr;
    }
    Node* p = top;
    top = top->next;
    p = 0;
    return top;
}

char stackTop(Node* top) {
    if(!top) {
        cout << "Stack Underflow, can't pop." << endl;
        return 0;
    }
    return top->data;
}

void display(Node* top) {
    Node* p = top;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int peek(Node* top, int pos) {
    Node* p = top;
    for(int i=0;p!=NULL && i<pos-1;i++) {
        p = p->next;
    }
    if(!p) {
        cout << "Invalid index supplied. Can's peek" << endl;
        return -1;
    } else {
        return p->data;
    }
}


bool isBalanced_comp(const char* exp) {
    //first i would like to creat a stack where to store the incoming expression stream
    //size of stack I will take to length of expression.
    /*
    Algo:
        1. Create a stack
        2. If incoming char is '(','{',[ push on to stack
        3. if incoming char is ')','}',']' then stack's TOP must have corresponding opening bracket
        4. If stack is found to be empty then immediately returned not balanced.
        5. If expression finished but stack is not empty 
    */
   Node* stk = 0;
   for(int i=0;exp[i]!='\0';i++) {
       if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
           stk=push(stk,exp[i]);
       } else {
           if(isEmpty(stk)) return false;
           char stkTop = stackTop(stk);
           switch(exp[i]) {
                case ')':
                    if(stkTop=='(') stk=pop(stk);
                    else return false;
                    break;
                case '}':
                    if(stkTop=='{') stk=pop(stk);
                    else return false;
                    break;
                case ']':
                    if(stkTop=='[') stk=pop(stk);
                    else return false;
                    break;
           }
       }
   }
   if(isEmpty(stk)) return true;
   return false;
}

bool isBalanced_basic(const char* exp) {
    //first i would like to creat a stack where to store the incoming expression stream
    //size of stack I will take to length of expression.
    /*
    Algo:
        1. Create a stack
        2. If incoming char is '(' push on to stack
        3. if incoming char is ')' then stack's TOP must have '('
        4. If stack is found to be empty then immediately returned not balanced.
        5. If expression finished but stack is not empty 
    */
    Node* stk=0;
    for(int i=0;exp[i]!='\0';i++) {
        //iterating over string
        if(exp[i]=='(') {
            stk=push(stk, exp[i]);
        } else if(exp[i] == ')') {
            if(isEmpty(stk)) return false;
            stk=pop(stk);
        }
    }
    //if expression is balanced then stack must be empty at this point of time.
    if(isEmpty(stk)) return true;
    return false;;
}

bool isOperand_basic(char ch) {
    if(ch == '+'|| ch=='-'||ch == '/'|| ch=='*') return 0;
    return 1;
}

int precedence_basic(char ch) {
    /*
        *,/ = 2
        +,- = 1
        else = 0 // will handle the scenario when stack is empty. Therefore, incoming operator will always be pushed in.
    */
   if(ch == '*' || ch == '/') return 2;
   if(ch == '+' || ch == '-') return 1;
   //==>Smart trick here. Will handle empty stack
   else return 0;

}

char* infix_to_postfix_basic(const char* exp) {
    /*
        ALGO:
            Points:
                - OUTPUT STRING MUST BE TERMINATED BY NULL ELSE IT WILL BE AN CHAR ARRAY
                - OUTPUT STR LENGTH IS EQUAL TO INPUT+1
                - Only OPERATORS WILL GO IN STACK
                - OPERANDS ARE DIRECTLY ADDED TO STRING
                - IF INCOMING OPERATOR IS OF HIGHER PRECEDENCE THAN THE TOP OF STACK THEN PUSH IN STACK
                - IF INCOMING OPERATOR HAS LOWER OR EQUAL PRECEDENCE. STAY WHERE YOU ARE. KEEP POPPING ELEMENTS FROM STACK UNTIL
                    STACK IS EMPTY OR HIGHER PRECEDENCE ISUSED
            PITFALLS:
                - MUST USE WHILE LOOP AS I WILL NOT MOVE IN EVERY ITERATION
    */
    Node* stk = 0;
    char* postfix = new char[strlen(exp) + 1];
    int i=0, j=0;
    while(exp[i]!='\0') {
        if(isOperand_basic(exp[i])) {
            postfix[j++] = exp[i++];
        } else {
            if(isEmpty(stk) || precedence_basic(exp[i]) > precedence_basic(stackTop(stk))) {
                //push into stack and move ONLY i;
                stk = push(stk, exp[i++]);
            } else {
                //see i is not moving
                postfix[j++] = stackTop(stk);
                stk = pop(stk);
            }
        }
    }
    while(!isEmpty(stk)) {
        postfix[j++] = stackTop(stk);
        stk = pop(stk);
    }
    //must terminate the postfix with null to make it a string
    postfix[j] = '\0';
    return postfix;
}

int main() {
    const char* exp_basic = "a+b*c-d/e";
    isBalanced_basic(exp_basic) ? (cout << "Basic Expression is balanced.\n"):(cout<<"Basic Expression is not balanced.\n");

    char* post_basic = infix_to_postfix_basic(exp_basic);
    cout << ">==>INFIX TO POSTFIX - BASIC: " << post_basic << endl;

    const char* exp_comp = "{([a+b]*[c-d]/e)}";
    isBalanced_comp(exp_comp) ? (cout << "Comp Expression is balanced.\n"):(cout<<"Comp Expression is not balanced.\n");
    return 0;
}