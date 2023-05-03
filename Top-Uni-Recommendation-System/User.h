#include <string>
#ifndef USER_H
#define USER_H
using namespace std;

struct User {
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;

    User* next;
};

User* login(User* head);
void displayMenu(User* current);

#endif