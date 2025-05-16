#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;

class Admin {
public:
    Admin();
    void addContent(const string& content);
    void deleteContent(int contentId);
    void viewAllContent();
private:
    string contentFile;
};

#endif // ADMIN_H