
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

struct User {
    string username;
    string password;
};

void login(const string& username, const string& password) {
    bool found = false;
    string stored_password;

    // Read the user credentials from the CSV file
    ifstream user_file("user.csv");
    string line;
    while (getline(user_file, line)) {
        stringstream ss(line);
        string stored_username;
        getline(ss, stored_username, ',');
        getline(ss, stored_password, ',');
        if (username == stored_username) {
            found = true;
            break;
        }
    }
    user_file.close();

    // Check if the username is found and the password matches
    if (found) {
        if (password == stored_password) {
            // If the password is correct, log the user in and record the login time in the log book
            ofstream log_file("log_book.csv", ios::app);
            log_file << username << "," << password << "," << time(0) << "\n";
            log_file.close();

            cout << "Login successful!" << endl;
        }
        else {
            cout << "Incorrect password!" << endl;
        }
    }
    else {
        cout << "Username not found!" << endl;
    }
}

int main() {
    // Prompt the user to enter their username and password
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Call the login function with the user credentials
    login(username, password);

    return 0;
}
