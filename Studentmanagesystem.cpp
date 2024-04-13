#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::find_if

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int marks;
    int attendance;
    vector<string> courses;
};

// Function to add a new student to the system
void addStudent(vector<Student>& students, string name, int marks, int attendance, vector<string> courses) {
    Student newStudent;
    newStudent.name = name;
    newStudent.marks = marks;
    newStudent.attendance = attendance;
    newStudent.courses = courses;
    students.push_back(newStudent);
}

// Function to display student information
void displayStudent(const Student& student, int serialNumber) {
    cout << "Serial Number: " << serialNumber + 1 << endl;
    cout << "Name: " << student.name << endl;
    cout << "Marks: " << student.marks << endl;
    cout << "Attendance: " << student.attendance << "%" << endl;
    cout << "Courses Taken:" << endl;
    for (const string& course : student.courses) {
        cout << "- " << course << endl;
    }
}

// Function to edit student information
void editStudent(vector<Student>& students, int serialNumber) {
    if (serialNumber >= 0 && serialNumber < students.size()) {
        cout << "Enter new name: ";
        cin >> students[serialNumber].name;
        cout << "Enter new marks: ";
        cin >> students[serialNumber].marks;
        cout << "Enter new attendance: ";
        cin >> students[serialNumber].attendance;
        cout << "Enter new courses taken (press 'q' to finish):" << endl;
        students[serialNumber].courses.clear();
        string course;
        while (cin >> course && course != "q") {
            students[serialNumber].courses.push_back(course);
        }
    } else {
        cout << "Invalid serial number." << endl;
    }
}

// Function to search for a student by name
void searchStudent(const vector<Student>& students, const string& name) {
    auto it = find_if(students.begin(), students.end(), [&name](const Student& student) {
        return student.name == name;
    });

    if (it != students.end()) {
        displayStudent(*it, distance(students.begin(), it));
    } else {
        cout << "Student not found." << endl;
    }
}

int main() {
    vector<Student> students;

    // Adding some sample students
    addStudent(students, "Tarush Rai", 85, 90, {"Math", "Science"});
    addStudent(students, "Alan Indran", 92, 95, {"History", "English"});

    // Displaying student information
    for (int i = 0; i < students.size(); ++i) {
        displayStudent(students[i], i);
        cout << endl;
    }

    // Edit student information
    int serialNumber;
    cout << "Enter serial number of student to edit: ";
    cin >> serialNumber;
    editStudent(students, serialNumber - 1); // Adjust for 0-based indexing

    // Display updated student information
    for (int i = 0; i < students.size(); ++i) {
        displayStudent(students[i], i);
        cout << endl;
    }

    // Search for a student by name
    string searchName;
    cout << "Enter name of student to search: ";
    cin >> searchName;
    searchStudent(students, searchName);

    return 0;
}
