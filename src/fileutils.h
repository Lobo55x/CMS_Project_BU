// fileutils.h
// File utility functions for University CMS
#pragma once
#include <string>
#include <vector>
#include "student.h"
#include "faculty.h"

namespace FileUtils {
    // Load students from CSV
    std::vector<Student> loadStudents(const std::string& filename);
    // Save students to CSV
    void saveStudents(const std::string& filename, const std::vector<Student>& students);

    // Load faculty from CSV
    std::vector<Faculty> loadFaculty(const std::string& filename);
    // Save faculty to CSV
    void saveFaculty(const std::string& filename, const std::vector<Faculty>& facultyList);

    // Load admin usernames from CSV
    std::vector<std::string> loadAdmins(const std::string& filename);
    // Load courses from CSV
    std::vector<std::string> loadCourses(const std::string& filename);
    // Save courses to CSV
    void saveCourses(const std::string& filename, const std::vector<std::string>& courses);
    // Load comments from CSV
    void loadComments(const std::string& filename, std::vector<Student>& students);
    // Save comments to CSV
    void saveComments(const std::string& filename, const std::vector<Student>& students);
}