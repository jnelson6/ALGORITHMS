

/*********************************************************************************************************
 * Name    : student.cpp
 * Author  : Julia Nelson
 * Version : 1.0
 * Date    : Jan 31, 2020
 * Description : Takes input of Students into a vector. Can find and retrieve data on student performance.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 *********************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Student{
public:
    Student(string first, string last, float gpa, int id) : first_{first}, last_{last}, gpa_{gpa}, id_{id} { }

        string full_name() const {      
            return first_ + " " + last_;
        }
        int id() const {
            return id_;
        }
        float gpa() const { 
            return gpa_;
        }
        void print_info() const {
            cout << fixed << full_name() << ", GPA: " << setprecision(2) << gpa()
            << ", ID: " << id() << endl;
        }

    private:
        string first_;
        string last_;
        float gpa_;
        int id_;
    };

/*
* Takes the students vector and itterates through. Any students whos' GPA
* is <1.0 is added to the failing_students vector, which is then returned.
*/
vector<Student> find_failing_students(const vector<Student> &students) {
    
    vector<Student> failing_students;
    for( auto it = students.cbegin(); it != students.cend(); ++it) {
        if( it -> gpa() < 1.0) {
            failing_students.push_back(*it);
        }
    }
    return failing_students;
}



/**
* Takes a vector of Student objects and prints them to the screen.
* Iterates through the students vector, calling print_info() for each student.
*/
void print_students(const vector<Student> &students) {
    for(int i = 0; i < (int) students.size(); ++i) {        
        students[i].print_info();
    }
}




/**
* Allows the user to enter information for multiple students, then
* find those students whose GPA is below 1.0 and prints them to the
* screen.
*/
int main() {
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;
    vector<Student> failing_students; // vector of failing students
    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    cout << endl << "All students:" << endl;
    print_students(students);
    cout << endl << "Failing students:";
    // Prints ' None' if no students are failing.
    // Otherwise, print each failing student on a separate line.
    
    failing_students = find_failing_students(students);
    if(failing_students.size() == 0){ cout << " None" << endl; }       
    else {
        cout << endl;
        for(int i = 0; i < (int) failing_students.size(); ++i){
            failing_students[i].print_info();
        }
    }
    return 0;
}
