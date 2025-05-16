#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
public:
    User();
    bool signup(const string& username, const string& password);
    bool login(const string& username, const string& password);
    bool isAdmin(const string& username);
private:
    string usersFile;
};

#endif // USER_H