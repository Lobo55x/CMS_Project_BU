#include "Admin.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Admin::Admin() {
    contentFile = "content.txt";
}

void Admin::addContent(const string& content) {
    ofstream outfile(contentFile, ios::app);
    outfile << content << endl;
    cout << "Content added successfully!\n";
}

void Admin::deleteContent(int contentId) {
    ifstream infile(contentFile);
    ofstream tempFile("temp.txt");
    string line;
    int id = 1;
    bool found = false;
    while (getline(infile, line)) {
        if (id != contentId) {
            tempFile << line << endl;
        } else {
            found = true;
        }
        id++;
    }
    infile.close();
    tempFile.close();
    remove(contentFile.c_str());
    rename("temp.txt", contentFile.c_str());
    if (found) {
        cout << "Content deleted successfully!\n";
    } else {
        cout << "Content ID not found.\n";
    }
}

void Admin::viewAllContent() {
    ifstream infile(contentFile);
    string line;
    int id = 1;
    cout << "--- All Content ---\n";
    while (getline(infile, line)) {
        cout << id << ". " << line << endl;
        id++;
    }
    if (id == 1) {
        cout << "No content available.\n";
    }
}