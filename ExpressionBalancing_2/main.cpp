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

bool isOperand_comp(char ch) {
    if(ch == '+'|| ch=='-'||ch == '/'|| ch=='*' || ch=='^' || ch=='(' ||ch==')') return 0;
    return 1;
}

int out_stack_precedence(char ch) {
    /*
        *,/ = 2
        +,- = 1
        else = 0 // will handle the scenario when stack is empty. Therefore, incoming operator will always be pushed in.
    */
   if(ch == '(') return 7;
   if(ch == ')') return 0;
   if(ch == '^') return 6;
   if(ch == '*' || ch == '/') return 3;
   if(ch == '+' || ch == '-') return 1;
   return -1;
}

int in_stack_precedence(char ch) {
    /*
        *,/ = 2
        +,- = 1
        else = 0 // will handle the scenario when stack is empty. Therefore, incoming operator will always be pushed in.
    */
   if(ch == '(') return 0;
   if(ch == '^') return 5;
   if(ch == '*' || ch == '/') return 4;
   if(ch == '+' || ch == '-') return 2;
   return -1;
}

char* infix_to_postfix_comprehensive(const char* exp) {
    /*
        ALGO:
            BASIC INFIX TO POSTFIX ALGO DOES NOT WORK FOR R-L ASSOCIATIVE and for BRACKETS TOO
            FOR THIS ALGO YOU WILL NEED TO BUILD YOUR OWN PRECEDENCE TABLE:

        Associativity    Symbol      Out_of_Stack_Precedence     In-Stack Precedence
            L-R           +,-               1                           2
            L-R           *,/               3                           4
            R-L            ^                6                           5
            L-R            (                7                           0
            L-R            )                0                           NA(neverpushed into stack)

        REST OF ALGO BEHAVIOUR IS SIMILAR WITH ONE PITFALL
            - FOR '(' and ')' we do not WANT TO SEND TO POSTFIX EXPRESSION - HENCE MUST SKIP IT

    */
    char* postfix = new char[strlen(exp) + 1];
    int i=0,j=0;
    Node* stk = 0;

    //same as infix while loop will be needed
    while(exp[i]!='\0') {
        if(isOperand_comp(exp[i])) {
            postfix[j++] = exp[i++];
        } else {
            if(isEmpty(stk) || out_stack_precedence(exp[i]) > in_stack_precedence(stackTop(stk))) {
                stk=push(stk, exp[i++]);
            } else if(out_stack_precedence(exp[i]) < in_stack_precedence(stackTop(stk))) {
                postfix[j++] = stackTop(stk);
                stk = pop(stk);
            } else {
                //when precedence is EQUAL which WILL ONLY HAPPEN in CASE OF ( and )
                // IN THIS CASE WATCH OUT:
                // WE WANT TO POPOUT BUT DO NOT WANT TO SEND THE CHAR TO OUTPUT
                //INCREMENT i
                stk=pop(stk);
                i++;
            }
        }
    }
    //watch out when emptying
    while(!isEmpty(stk)) {
        postfix[j++] = stackTop(stk);
        stk = pop(stk);
    }
    postfix[j] = '\0'; //converted from char array to C-string
    return postfix;
}

int evaluate_postfix(char* exp) {
    /*
        POINTS:
            - NOW - WE WILL PUSH OPERANDS INSTEAD OF OPERATORS
            - a = b * c; Order of RHS is important
            - Hence, at the time of popping out. We must remember LIFO
            - Popped out element will be SECOND OPERAND ON RHS. FIRST OPERAND WILL BE POPPED OUT SECOND
    */
   Node* stk = 0;
   int fTerm, sTerm;
   //we can use for loop here cecuse i will be changing in ever iteration.
   for(int i=0;exp[i]!='\0';i++) {
       if(isOperand_basic(exp[i])) {
           //simply push onto stack but subtract the ASI CODE
           stk=push(stk,exp[i]-'0');
       } else {
           //watchout - secondTerm will come out first
           sTerm = stackTop(stk);
           stk = pop(stk);
           fTerm = stackTop(stk);
           stk=pop(stk);
           int r;
           //time to make a switch case:
           switch (exp[i])
           {
           case '*':
                r=fTerm*sTerm;
               break;
           case '/':
                r=fTerm/sTerm;
                break;
            case '+':
                r = fTerm+sTerm;
                break;
            case '-':
                r = fTerm-sTerm;
                break;
           default:
               break;
           }
           stk=push(stk, r);
       }
   }
    int out = stackTop(stk);
    delete stk;
    return out;
}

// Problem Statement
// Write a function for finding the mth last node in a singly linked list.

// For example, given list:
// N1 -> N2 -> N3 -> N4 -> N5 -> N6

// and 
// m = 3

// The function returns N4

// You can assume you have some kind of Node class with a Next property, with which to define a linked list.

// struct Node {
//     int data;
//     Node* next;
// };

int fib(int n) {
    static int fArrat[10];

    if(n <=1) {
        fArrat[n] = n;
        return fArrat[n];
    }
    if(fArrat[n-2] == 0) {
        fArrat[n-2] = fib(n-2);

    }
     if(fArrat[n-1] == 0) {
        fArrat[n-1] = fib(n-1);
        
    }
    fArrat[n] = fArrat[n-1] + fArrat[n-2];
    return fArrat[n];
}

int c(int n, int r) {
    if(r == 0 || r == n) {
        return 1;
    }
    return c(n-1, r-1) + c(n-1, r);
}

Node* mLastNode(Node* head,Node* ptr, int m) {
    static int count = 0;
    if(m<0) return nullptr;
    if(!head) nullptr;
    if(!ptr) return nullptr;
    mLastNode(head, ptr->next, m);
    count++;
    if(count == m) {
        return ptr;
    }
}

int main() {
    const char* exp_basic = "3*5+6/2-4";
    isBalanced_basic(exp_basic) ? (cout << "Basic Expression is balanced.\n"):(cout<<"Basic Expression is not balanced.\n");

    char* post_basic = infix_to_postfix_basic(exp_basic);
    cout << ">==>INFIX TO POSTFIX COVERSION- BASIC: " << post_basic << endl;
    cout << ">==>POSTFIX EVALUATION BASIC: " << evaluate_postfix(post_basic) << endl;
    const char* exp_comp = "{([a+b]*[c-d]/e)}";
    isBalanced_comp(exp_comp) ? (cout << "Comp Expression is balanced.\n"):(cout<<"Comp Expression is not balanced.\n");


    const char* exp_comp3 = "((a+b)*c)-d^e^f";
    cout << ">==>INFIX TO POSFIX COMPREHENSIVE: " << infix_to_postfix_comprehensive(exp_comp3) << endl;
    return 0;
}