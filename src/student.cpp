// student.cpp
// Implements Student class and student panel logic for University CMS
#include "student.h"
#include <iostream>
using namespace std;

Student::Student() {}

Student::Student(const string& roll, const string& name)
    : roll(roll), name(name) {}

// Display student info: name, roll, enrolled courses, marks, grades, comment
void Student::displayInfo() const {
    cout << "\n--- Student Info ---\n";
    cout << "Name: " << name << "\n";
    cout << "Roll: " << roll << "\n";
    cout << "Courses: ";
    for (const auto& c : enrolledCourses) cout << c << " ";
    cout << "\nMarks & Grades:\n";
    for (const auto& m : marks) {
        cout << "  " << m.first << ": " << m.second;
        auto it = grades.find(m.first);
        if (it != grades.end()) cout << " (" << it->second << ")";
        cout << "\n";
    }
    if (!comment.empty()) cout << "Comment: " << comment << "\n";
}

// Student panel: display info, wait for logout
namespace StudentPanel {
void run(const string& roll, const vector<Student>& students) {
    for (const auto& s : students) {
        if (s.roll == roll) {
            s.displayInfo();
            break;
        }
    }
    cout << "\nPress Enter to logout...";
    cin.ignore();
    cin.get();
}
}