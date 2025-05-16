#include <iostream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Content.h"
#include <QApplication>
#include "MainWindow.h"
using namespace std;

void showMainMenu() {
    cout << "\n--- CMS Main Menu ---\n";
    cout << "1. Login as Student\n";
    cout << "2. Login as Faculty\n";
    cout << "3. Login as Admin\n";
    cout << "4. Signup (Student Only)\n";
    cout << "5. Exit\n";
    cout << "Select an option: ";
}

void showAdminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Add Content\n";
    cout << "2. Delete Content\n";
    cout << "3. View All Content\n";
    cout << "4. Logout\n";
    cout << "Select an option: ";
}

void showUserMenu() {
    cout << "\n--- User Menu ---\n";
    cout << "1. View Content\n";
    cout << "2. Logout\n";
    cout << "Select an option: ";
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
#include <iostream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Content.h"
using namespace std;

void showMainMenu() {
    cout << "\n--- CMS Main Menu ---\n";
    cout << "1. Login as Student\n";
    cout << "2. Login as Faculty\n";
    cout << "3. Login as Admin\n";
    cout << "4. Signup (Student Only)\n";
    cout << "5. Exit\n";
    cout << "Select an option: ";
}

void showAdminMenu() {
    cout << "\n--- Admin Menu ---\n";
    cout << "1. Add Content\n";
    cout << "2. Delete Content\n";
    cout << "3. View All Content\n";
    cout << "4. Logout\n";
    cout << "Select an option: ";
}

void showUserMenu() {
    cout << "\n--- User Menu ---\n";
    cout << "1. View Content\n";
    cout << "2. Logout\n";
    cout << "Select an option: ";
}

int main() {
    User userManager;
    Admin adminManager;
    Content contentViewer;
    string username, password;
    int choice;
    bool running = true;
    while (running) {
        showMainMenu();
        cin >> choice;
        switch (choice) {
            case 1: { // Student Login
                cout << "Enter student username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (userManager.login(username, password)) {
                    bool studentLoggedIn = true;
                    while (studentLoggedIn) {
                        cout << "\n--- Student Panel ---\n";
                        cout << "1. View Content\n";
                        cout << "2. Add Course\n";
                        cout << "3. Add Marks\n";
                        cout << "4. Logout\n";
                        cout << "Select an option: ";
                        int studentChoice;
                        cin >> studentChoice;
                        cin.ignore();
                        switch (studentChoice) {
                            case 1:
                                contentViewer.viewContent();
                                break;
                            case 2:
                                cout << "Feature: Add Course (to be implemented)\n";
                                break;
                            case 3:
                                cout << "Feature: Add Marks (to be implemented)\n";
                                break;
                            case 4:
                                studentLoggedIn = false;
                                break;
                            default:
                                cout << "Invalid option.\n";
                        }
                    }
                }
                break;
            }
            case 2: { // Faculty Login
                cout << "Enter faculty username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (userManager.login(username, password)) {
                    bool facultyLoggedIn = true;
                    while (facultyLoggedIn) {
                        cout << "\n--- Faculty Panel ---\n";
                        cout << "1. Add Content for Student\n";
                        cout << "2. Logout\n";
                        cout << "Select an option: ";
                        int facultyChoice;
                        cin >> facultyChoice;
                        cin.ignore();
                        switch (facultyChoice) {
                            case 1:
                                cout << "Enter content to add for student: ";
                                {
                                    string content;
                                    getline(cin, content);
                                    adminManager.addContent(content);
                                }
                                break;
                            case 2:
                                facultyLoggedIn = false;
                                break;
                            default:
                                cout << "Invalid option.\n";
                        }
                    }
                }
                break;
            }
            case 3: { // Admin Login
                cout << "Enter admin ID: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (username == "altahanrauf" && password == "2003") {
                    bool adminLoggedIn = true;
                    while (adminLoggedIn) {
                        showAdminMenu();
                        int adminChoice;
                        cin >> adminChoice;
                        cin.ignore();
                        switch (adminChoice) {
                            case 1: {
                                cout << "Enter content to add: ";
                                string content;
                                getline(cin, content);
                                adminManager.addContent(content);
                                break;
                            }
                            case 2: {
                                cout << "Enter content ID to delete: ";
                                int id;
                                cin >> id;
                                adminManager.deleteContent(id);
                                break;
                            }
                            case 3:
                                adminManager.viewAllContent();
                                break;
                            case 4:
                                adminLoggedIn = false;
                                break;
                            default:
                                cout << "Invalid option.\n";
                        }
                    }
                } else {
                    cout << "Invalid admin credentials.\n";
                }
                break;
            }
            case 4: { // Signup (Student Only)
                cout << "Choose a username: ";
                cin >> username;
                cout << "Choose a password: ";
                cin >> password;
                userManager.signup(username, password);
                break;
            }
            case 5:
                running = false;
                cout << "Exiting CMS. Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}