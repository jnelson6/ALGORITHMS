

/*******************************************************************************
 * Name    : student.cpp
 * Author  : Julia Nelson
 * Version : 1.0
 * Date    : September 5, 2019
 * Description : Takes / organizes inputs of Students into a vector, 
 *                 also able to retrieve data and find which students are failing
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Student {
    public:

        // Constructor that uses an initializer list.
        Student(string first, string last, float gpa, int id) : first_{first}, last_{last}, gpa_{gpa}, id_{id} { }

        inline string full_name() const{                    // keyword inline necessary to work
            string full_name = first_ + " " + last_;
            return full_name;
        }

        inline int id() const{
            return id_;
        }

        inline float gpa() const{
            return gpa_;
        }



        // print_info() should print in the format (GPA has 2 decimal places):
        // Bob Smith, GPA: 3.50, ID: 20146
        void print_info() const{
            cout << fixed << full_name() << ", GPA: " << setprecision(2) << gpa() << ", ID: " << id() << endl;

        }

    private:
    // Member variables (fields). Use  trailing _ for these variables.
        string first_, last_; 
        float gpa_;
        int id_;
    };


/**
* Takes a vector of Student objects, and returns a new vector
* with all Students whose GPA is < 1.0.
*/
vector<Student> find_failing_students(const vector<Student> &students) {
    vector<Student> failing_students;
    // Iterates through the students vector, appending each student whose gpa is
    // less than 1.0 to the failing_students vector.
    // iterator code style used from mypoint.cpp class example
    for (auto it = students.cbegin(); it != students.cend(); ++it){     
        if (it-> gpa() < 1.0){
            failing_students.push_back(*it);
        }
    }
    return failing_students;
}


/**
* Takes a vector of Student objects and prints them to the screen.
*/
void print_students(const vector<Student> &students) {
    // Iterates through the students vector, calling print_info() for each student.
    // able to use i rather than it because its not scanning through to check a specific component
    for (int i = 0; i < (int) students.size(); i++){
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

    
    vector<Student> failing_students = find_failing_students(students); //necessary to declare here..(previous location at top of main = failure)
    // Print a space and the word 'None' on the same line if no students are
    // failing.
    if (failing_students.empty()){
        cout << " None";
    }
    // Otherwise, print each failing student on a separate line.
    else{
        cout << endl;                                               // extra line to match test script
        for (int i = 0; i < (int) failing_students.size(); i++){
            failing_students[i].print_info();
        }
        
    }
    return 0;
}













