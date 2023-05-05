#include <string>

using namespace std;

struct User {
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;
    string lastLoginDate;

    User *nextNode;
    User* prevNode;
};

User* login(User* userHead);
void displayMenu(User* userHead, User* current);
