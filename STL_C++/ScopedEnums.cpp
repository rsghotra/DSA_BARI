#include<iostream>
#include<cstdlib> //contains rand and srand
#include<ctime>
using namespace std;

//Craps simulation
enum class Months {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
unsigned int rollDice();

int main() {

    //scope enumeration with CONSTANTS THAT REPRESENTS THE GAME STATUS
    enum class Status {CONTINUE, WON, LOST};

    //randomize random number generator using current time
    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoints{0};

    Status gameStatus; //Can be CONTINUE, WON OR LOST

    unsigned int sumOfDice = rollDice();

    //determine game status and point(if game continues after first roll)
    switch(sumOfDice) {
        case 7:
        case 11:
            gameStatus = Status::WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = Status::LOST;
            break;
        //for all other ;; lol what i was thinking
        default:
            gameStatus = Status::CONTINUE; //game is not over
            myPoints = sumOfDice;
            cout << "Point is " << myPoints << endl;
            break;
    }
    while(Status::CONTINUE == gameStatus) { //not won not lost
        sumOfDice = rollDice();
        if(sumOfDice == myPoints) {
            gameStatus = Status::WON;
        } else if(sumOfDice == 7) {
            gameStatus = Status::LOST;
        }
    }
    if(Status::WON == gameStatus) {
        cout << "Player wins" << endl;
    } else {
        cout << "Player looses" << endl;
    }
}

unsigned int rollDice() {
    int die1 = 1+rand()%6;
    int die2{1+rand()%6};

    int sum{die1+die2};

    cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;
    return sum;
}