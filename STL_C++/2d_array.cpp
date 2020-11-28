#include<array>
#include "GradeBook.h"
using namespace std;

int main() {

    array<array<int, GradeBook::tests>, GradeBook::students> grades {{
        {87,96,70},
        {68,87,90},
        {94,100,90},
        {100,81,82},
        {93,65,85},
        {78,87,65},
        {85,75,83},
        {91,94,100},
        {76,72,84},
        {87,93,73},
    }};

    GradeBook myGradeBook("CS101 Introcustion to C++ Programming", grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
}