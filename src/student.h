// student.h
// Student module header for University CMS
#pragma once
#include <string>
#include <vector>
#include <map>

// Represents a student and their academic info
class Student {
public:
    std::string roll;
    std::string name;
    std::vector<std::string> enrolledCourses;
    std::map<std::string, int> marks; // course -> marks
    std::map<std::string, char> grades; // course -> grade
    std::string comment;

    Student();
    Student(const std::string& roll, const std::string& name);
    void displayInfo() const;
};

// Student panel logic
namespace StudentPanel {
    void run(const std::string& roll, const std::vector<Student>& students);
}