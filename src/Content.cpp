#include "Content.h"
#include <fstream>
#include <iostream>
using namespace std;

Content::Content() {
    contentFile = "content.txt";
}

void Content::viewContent() {
    ifstream infile(contentFile);
    string line;
    int id = 1;
    cout << "--- Content ---\n";
    while (getline(infile, line)) {
        cout << id << ". " << line << endl;
        id++;
    }
    if (id == 1) {
        cout << "No content available.\n";
    }
}