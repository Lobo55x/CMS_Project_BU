// faculty.h
// Faculty module header for University CMS
#pragma once
#include <string>
#include <vector>
#include <map>
#include "student.h"

// Represents a faculty member
class Faculty {
public:
    std::string username;
    std::string name;
    std::vector<std::string> courses;

    Faculty();
    Faculty(const std::string& username, const std::string& name);
};

// Faculty panel logic
namespace FacultyPanel {
    void run(const std::string& username, std::vector<Student>& students, std::vector<Faculty>& facultyList, const std::vector<std::string>& courses);
}