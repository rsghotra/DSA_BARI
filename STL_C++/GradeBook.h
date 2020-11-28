#include<iostream>
#include<array>
#include<string>
#include<iomanip>
using namespace std;

class GradeBook {
    public:
        static const size_t students{10};
        //const reference to avoid copy
        GradeBook(const string& name, const array<int, students>& gradesArray): courseName{name}, grades{gradesArray} {}
        void setCourseName(const string& name) {
            courseName = name;
        }
        const string& getCourseName() const {
            return courseName;
        }
        void displayMessage() const {
            cout << "Welcome to the gradebook for\n" << getCourseName() << "!" << endl;
        }
        void outputGradesArray() const {
            cout << "\nThe grades are:\n"<< endl;
            //because i need subscript notation
            for(size_t i{0}; i < grades.size();++i) {
                cout << setw(20) << "Student    " << (i+1) << ": " << setw(5) << grades[i] << endl;
            }
        }
        void processGrades() const {
            outputGradesArray();
            cout << setprecision(2) << fixed;
            cout << "\nClass average is " << getAverage() << endl;
            cout <<"Lowest grade is " << getMinimum() 
                << "\nHighest grade is " << getMaximum() << endl;
            outputBarChart();
        }

        int getMinimum() const {
            int lowGrade{100};

            for(int grade: grades) {
                if(grade < lowGrade) {
                    lowGrade = grade;
                }
            }
            return lowGrade;
        }

        int getMaximum() const  {
            int highGrade{0};

            for(int grade: grades) {
                if(grade > highGrade) {
                    highGrade = grade;
                }
            }
            return highGrade;
        }

        double getAverage() const {
            int total{0};
            for(int grade: grades) {
                total += grade;
            }
            return static_cast<double>(total)/grades.size();
        }

        void outputBarChart() const {
            cout <<"\nGrade distribution:" << endl;
            const size_t frequencySize{11};
            array<unsigned int, frequencySize> frequence{};

            for(int grade: grades) {
                ++frequence[grade/10];
            }
            for(size_t i{0}; i < grades.size(); ++i) {
                if(i == 0) {
                    cout << "0-9: ";
                }
                if(i == 10) {
                    cout << "  100: ";
                }
                else {
                    cout << i * 10 << "-" << (i*10)+9 << ": ";
                }

                for(size_t j = 0; j < frequence[i]; ++j) {
                    cout << "*";
                }

                cout << endl;
            }
        }

    private:
        string courseName;
        array<int, students> grades;
};

int main() {
    const array<int, GradeBook::students> grades {87,68,94,100,83,78,85,91,76,87};
    string courseName{"CS101 Introduction to C++ Programming"};
    GradeBook myGradeBook(courseName, grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
}