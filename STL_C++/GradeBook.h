#include<array>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;

class GradeBook {
    public:
        //check this out static, const, size_t, public
        static const size_t students{10};
        static const size_t tests{3};
            GradeBook(const string& name, const array<array<int, tests>, students>& a) : courseName{name}, grades{a}{}

            void setCourseName(const string& name) {
                courseName = name;
            }

            //==>Watch out const return function to retrieve course name
            const string& getCourseName() const {
                return courseName;
            }

            void displayMessage() const {
                cout << "Welcome to the gradebook for\n" << getCourseName() << "!" << endl;
            }

            double getAverage(const array<int, tests>& a) const {
                int total{0};
                for(int grade: a) {
                    total+= grade;
                }
                return static_cast<double>(total)/a.size();
            }

            //outputs the contents of the grade array
        void outputGrades() const {
            cout << "\nThe grades are:\n\n";
            cout << "               ";

            for(size_t test{0}; test < tests; ++test) {
                cout << "Test" << setw(2) << tests + 1;
            }

            cout << "Average" << endl;

            for(size_t student{0}; student < students; ++student) {
                cout << "Student" << setw(2) << student+1;

                for(size_t test{0}; test < grades[student].size(); ++test) {
                    cout << setw(8) << grades[student][test];
                }

                //calculate average
                double average = getAverage(grades[student]);
                cout << setw(9) << setprecision(2) << fixed << average << endl;
            }

        }

        void processGrades() const {
            outputGrades();
            cout << "\nLowest grade in the grade book is " << getMinimum()
                << "\nHighest grade in the grade book is " << getMaximum()
                << endl;
        }

        int getMinimum() const {
            int lowestGrade{100};

            for(const auto& student: grades) {
                for(const auto& grade: student) {
                    if(grade < lowestGrade) {
                        lowestGrade = grade;
                    }
                }
            }
            return lowestGrade;
        }
        int getMaximum() const {
            int highestGrade{0};

            for(const auto& student: grades) {
                for(const auto& grade: student) {
                    if(highestGrade < grade) {
                        highestGrade = grade;
                    }
                }
            }
            return highestGrade;
        }
        private:
            string courseName;
            array<array<int, tests>, students> grades;
};