// faculty.cpp
// Implements Faculty class and faculty panel logic for University CMS
#include "faculty.h"
#include <iostream>
#include <algorithm>
using namespace std;

Faculty::Faculty() {}
Faculty::Faculty(const string& username, const string& name)
    : username(username), name(name) {}

// Faculty panel: menu for viewing/updating student records, searching, grading, comments
namespace FacultyPanel {
void run(const string& username, vector<Student>& students, vector<Faculty>& facultyList, const vector<string>& courses) {
    int choice;
    bool running = true;
    while (running) {
        cout << "\n--- Faculty Panel ---\n";
        cout << "1. View All Student Records\n";
        cout << "2. Search Student by Roll or Name\n";
        cout << "3. Update Student Marks\n";
        cout << "4. Assign Letter Grades\n";
        cout << "5. View Course-wise Performance\n";
        cout << "6. Add/Edit Student Comment\n";
        cout << "7. Logout\n";
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                for (const auto& s : students) s.displayInfo();
                break;
            case 2: {
                cout << "Enter roll or name: ";
                string query;
                getline(cin, query);
                bool found = false;
                for (const auto& s : students) {
                    if (s.roll == query || s.name == query) {
                        s.displayInfo();
                        found = true;
                    }
                }
                if (!found) cout << "No student found.\n";
                break;
            }
            case 3: {
                cout << "Enter student roll: ";
                string roll;
                getline(cin, roll);
                auto it = find_if(students.begin(), students.end(), [&](const Student& s){return s.roll == roll;});
                if (it != students.end()) {
                    cout << "Enter course: ";
                    string course;
                    getline(cin, course);
                    cout << "Enter new marks: ";
                    int marks;
                    cin >> marks;
                    cin.ignore();
                    it->marks[course] = marks;
                    cout << "Marks updated.\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                // Assign grades based on marks
                for (auto& s : students) {
                    for (auto& m : s.marks) {
                        int mark = m.second;
                        char grade = 'F';
                        if (mark >= 90) grade = 'A';
                        else if (mark >= 80) grade = 'B';
                        else if (mark >= 70) grade = 'C';
                        else if (mark >= 60) grade = 'D';
                        s.grades[m.first] = grade;
                    }
                }
                cout << "Grades assigned.\n";
                break;
            }
            case 5: {
                cout << "Enter course: ";
                string course;
                getline(cin, course);
                cout << "--- Performance for " << course << " ---\n";
                for (const auto& s : students) {
                    auto it = s.marks.find(course);
                    if (it != s.marks.end()) {
                        cout << s.name << " (" << s.roll << "): " << it->second;
                        auto git = s.grades.find(course);
                        if (git != s.grades.end()) cout << " (" << git->second << ")";
                        cout << "\n";
                    }
                }
                break;
            }
            case 6: {
                cout << "Enter student roll: ";
                string roll;
                getline(cin, roll);
                auto it = find_if(students.begin(), students.end(), [&](const Student& s){return s.roll == roll;});
                if (it != students.end()) {
                    cout << "Enter comment: ";
                    string comment;
                    getline(cin, comment);
                    it->comment = comment;
                    cout << "Comment updated.\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }
            case 7:
                running = false;
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
}
}