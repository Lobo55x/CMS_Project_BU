// fileutils.cpp
// Implements file utility functions for University CMS
#include "fileutils.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

namespace FileUtils {
vector<Student> loadStudents(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        istringstream ss(line);
        string roll, name, courses, marks, grades, comment;
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, courses, ',');
        getline(ss, marks, ',');
        getline(ss, grades, ',');
        getline(ss, comment, ',');
        Student s(roll, name);
        // Parse enrolled courses
        istringstream cs(courses);
        string c;
        while (getline(cs, c, '|')) if (!c.empty()) s.enrolledCourses.push_back(c);
        // Parse marks
        istringstream ms(marks);
        string m;
        while (getline(ms, m, '|')) {
            size_t pos = m.find(':');
            if (pos != string::npos) s.marks[m.substr(0, pos)] = stoi(m.substr(pos+1));
        }
        // Parse grades
        istringstream gs(grades);
        string g;
        while (getline(gs, g, '|')) {
            size_t pos = g.find(':');
            if (pos != string::npos) s.grades[g.substr(0, pos)] = g[pos+1];
        }
        s.comment = comment;
        students.push_back(s);
    }
    return students;
}

void saveStudents(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    file << "roll,name,courses,marks,grades,comment\n";
    for (const auto& s : students) {
        file << s.roll << ',' << s.name << ',';
        // Courses
        for (size_t i=0; i<s.enrolledCourses.size(); ++i) {
            file << s.enrolledCourses[i];
            if (i+1 < s.enrolledCourses.size()) file << '|';
        }
        file << ',';
        // Marks
        size_t cnt = 0;
        for (const auto& m : s.marks) {
            file << m.first << ':' << m.second;
            if (++cnt < s.marks.size()) file << '|';
        }
        file << ',';
        // Grades
        cnt = 0;
        for (const auto& g : s.grades) {
            file << g.first << ':' << g.second;
            if (++cnt < s.grades.size()) file << '|';
        }
        file << ',' << s.comment << '\n';
    }
}

vector<Faculty> loadFaculty(const string& filename) {
    vector<Faculty> facultyList;
    ifstream file(filename);
    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        istringstream ss(line);
        string username, name, courses;
        getline(ss, username, ',');
        getline(ss, name, ',');
        getline(ss, courses, ',');
        Faculty f(username, name);
        istringstream cs(courses);
        string c;
        while (getline(cs, c, '|')) if (!c.empty()) f.courses.push_back(c);
        facultyList.push_back(f);
    }
    return facultyList;
}

void saveFaculty(const string& filename, const vector<Faculty>& facultyList) {
    ofstream file(filename);
    file << "username,name,courses\n";
    for (const auto& f : facultyList) {
        file << f.username << ',' << f.name << ',';
        for (size_t i=0; i<f.courses.size(); ++i) {
            file << f.courses[i];
            if (i+1 < f.courses.size()) file << '|';
        }
        file << '\n';
    }
}

vector<string> loadAdmins(const string& filename) {
    vector<string> admins;
    ifstream file(filename);
    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        istringstream ss(line);
        string username;
        getline(ss, username, ',');
        admins.push_back(username);
    }
    return admins;
}

vector<string> loadCourses(const string& filename) {
    vector<string> courses;
    ifstream file(filename);
    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        courses.push_back(line);
    }
    return courses;
}

void saveCourses(const string& filename, const vector<string>& courses) {
    ofstream file(filename);
    file << "course\n";
    for (const auto& c : courses) file << c << '\n';
}

void loadComments(const string& filename, vector<Student>& students) {
    ifstream file(filename);
    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        istringstream ss(line);
        string roll, comment;
        getline(ss, roll, ',');
        getline(ss, comment, ',');
        for (auto& s : students) {
            if (s.roll == roll) {
                s.comment = comment;
                break;
            }
        }
    }
}

void saveComments(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    file << "roll,comment\n";
    for (const auto& s : students) {
        file << s.roll << ',' << s.comment << '\n';
    }
}
} // namespace FileUtils