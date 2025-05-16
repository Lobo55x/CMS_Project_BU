#include <iostream>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Content.h"
using namespace std;

void showMainMenu() {
    cout << "\n--- CMS Main Menu ---\n";
    cout << "1. Login\n";
    cout << "2. Signup\n";
    cout << "3. Exit\n";
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
            case 1: // Login
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (userManager.login(username, password)) {
                    if (userManager.isAdmin(username)) {
                        bool adminLoggedIn = true;
                        while (adminLoggedIn) {
                            showAdminMenu();
                            int adminChoice;
                            cin >> adminChoice;
                            cin.ignore(); // Clear newline
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
                        bool userLoggedIn = true;
                        while (userLoggedIn) {
                            showUserMenu();
                            int userChoice;
                            cin >> userChoice;
                            switch (userChoice) {
                                case 1:
                                    contentViewer.viewContent();
                                    break;
                                case 2:
                                    userLoggedIn = false;
                                    break;
                                default:
                                    cout << "Invalid option.\n";
                            }
                        }
                    }
                }
                break;
            case 2: // Signup
                cout << "Choose a username: ";
                cin >> username;
                cout << "Choose a password: ";
                cin >> password;
                userManager.signup(username, password);
                break;
            case 3:
                running = false;
                cout << "Exiting CMS. Goodbye!\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}