#include "User.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

User::User() {
    usersFile = "users.txt";
}

bool User::signup(const string& username, const string& password) {
    ifstream infile(usersFile);
    string line, user, pass;
    while (getline(infile, line)) {
        istringstream iss(line);
        iss >> user >> pass;
        if (user == username) {
            cout << "Username already exists.\n";
            return false;
        }
    }
    infile.close();
    ofstream outfile(usersFile, ios::app);
    outfile << username << " " << password << endl;
    cout << "Signup successful!\n";
    return true;
}

bool User::login(const string& username, const string& password) {
    ifstream infile(usersFile);
    string line, user, pass;
    while (getline(infile, line)) {
        istringstream iss(line);
        iss >> user >> pass;
        if (user == username && pass == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Invalid username or password.\n";
    return false;
}

bool User::isAdmin(const string& username) {
    // For simplicity, "admin" is the admin username
    return username == "admin";
}