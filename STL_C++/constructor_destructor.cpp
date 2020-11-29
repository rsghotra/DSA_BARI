#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

/*  ORDER OF DESTRUCTION: LOCAL -> STATIC -> GLOBAL
    - Constructors and Destructors for Global, Local and Static objects of classes
        - Constructors for Global objects is called first before anything else
        - Local objects destriuctor will NOT be called if program is terminates with exit or abort function
        - Static objects DESTRUCTOR will not be called if program terminates with abort
*/

#ifndef CREATE_H
#define CREATE_H

#endif

class CreateAndDestroy {
    public:
        CreateAndDestroy(int, string);
        ~CreateAndDestroy();
    private:
        int objectID;
        string message;
};

CreateAndDestroy::CreateAndDestroy(int ID, string messageString) : objectID{ID}, message{messageString} {
    cout << "Object " << objectID << "  constructor runs    " << message << endl;
}
CreateAndDestroy::~CreateAndDestroy() {
    cout << (objectID == 1 || objectID == 6? "\n":"");
    cout << "Object " << objectID << " destructor runs      " << message << endl;
}

void create();
CreateAndDestroy first{1, "(global before main)"};

int main() {
    cout <<"\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second{2, "(local in main)"};
    static CreateAndDestroy third{3, "(local static in main)"};

    create();

    cout << "\n MAIN FUNCTION: EXECUTION RESUMES" << endl;
    CreateAndDestroy fourth{4, "(local in main)"};
    cout <<"\nMAIN FUNCTION: EXECUTION ENDS" << endl;
}



void create() {
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth{5, "(local in create)"};
    static CreateAndDestroy sixth{6, "(local static in create)"};
    CreateAndDestroy seventh{7, "(local in create)"};
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}