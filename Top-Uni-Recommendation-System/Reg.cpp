#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

struct User;

void importUserFile();
void writeUserFile();

struct User{
    string userId;
    string username;
    string password;
    string realName;
    string email;
    string phoneNo;
    string gender;
    string lastLoginDate;

    User *nextNode;
    User *prevNode;
}*userHead, *userTail;

void insertUser(string userId, string username, string password, string realName, string email, string phoneNo, string gender, string lastLoginDate) {
    User *newNode = new User{userId, username, password, realName, email, phoneNo, gender, lastLoginDate};
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if(userHead == NULL){
        userHead = newNode;
        userTail = newNode;
    }else{
        userTail->nextNode = newNode;
        newNode->prevNode = userTail;
        userTail = newNode;
    }
}

void importUserFile(){
    ifstream file;
    file.open("UserData.csv");
    if(!file){
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)){
        stringstream ss(line); 
        string userId, username, password, realName, email, phoneNo, gender, lastLoginDate;
        getline(ss, userId, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, realName, ',');
        getline(ss, email, ',');
        getline(ss, phoneNo, ',');
        getline(ss, gender, ',');

        insertUser(userId, username, password, realName, email, phoneNo, gender, lastLoginDate);
    }
    file.close();
    return;
}

//Write to file
void writeUserFile(){
    ofstream file;
    file.open("User.csv");
    User *temp = userHead;
    while(temp != NULL){
        file << temp->userId << "," << temp->username << "," << temp->password << "," << temp->realName << "," << temp->email << "," << temp->phoneNo << "," << temp->gender << "," << temp->lastLoginDate << endl;
        temp = temp->nextNode;
    }
    file.close();
}

string newId(){
    User *temp = userTail;
    ostringstream oss;
    string id = temp->userId;
    int num = stoi(id.substr(1, 4));
    num++;
    oss << setw(4) << setfill('0') << num << "\n";
    id = "C" + oss.str();
    return id;
}

string regUsername(){                   //VALIDATION NOT DONE(length and character)
    string new_Username;
    User* temp = userHead;
    cout << "==================================================" << endl;
    cout << "Username: " << endl;
    getline(cin, new_Username);
    while(temp!=NULL){
        if(temp->username == new_Username){
            cout << "Username already exists. Please try again." << endl;
            getline(cin, new_Username);
        }
        temp = temp->nextNode;
    }
    return new_Username;
}

string regPassword(){                   //VALIDATION NOT DONE
    string new_Password;
    cout << "==================================================" << endl;
    cout << "Password: " << endl;
    getline(cin, new_Password);
    return new_Password;
}

string regRealName(){                   //VALIDATION NOT DONE
    string new_realName;
    cout << "==================================================" << endl;
    cout << "Real Name: " << endl;
    getline(cin, new_realName);
    return new_realName;
}

string regEmail(){                      //VALIIDATION NOT DONE
    string new_Email;
    cout << "==================================================" << endl;
    cout << "Email: " << endl;
    getline(cin, new_Email);
    return new_Email;
}

string regPhoneNo(){
    int new_PhoneNo;
    string phone;
    cout << "==================================================" << endl;
    cout << "Phone Number: " << endl;
    cin >> new_PhoneNo;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input" << endl;
        return regPhoneNo();
    }
    phone = to_string(new_PhoneNo);
    if (to_string(new_PhoneNo).length() != 12 || to_string(new_PhoneNo).length() != 11){
        cout << "Invalid input" << endl;
        return regPhoneNo();
    }
    return phone;
}

string regGender(){
    int choice;
    cout << "==================================================" << endl;
    cout << "\nWhat is your gender?\n[ 1 ]\tMale\n[ 2 ]\tFemale" << endl;
    cin >> choice;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input" << endl;
        return regGender();
    }
    switch(choice){
        case 1:
            return "Male";
            break;
        case 2:
            return "Female";
            break;
        default:
            cout << "Invalid input" << endl;
            return regGender();
    }
}

string getCurrentDateString(){
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%m-%d-%Y");
    auto str = oss.str();

    return str;
}

void showRegDetails(string new_Username, string new_Password, string new_realName, string new_Email, string new_PhoneNo, string new_Gender){
    cout << "==================================================" << endl;
    cout << setw(15) << left << "Username" << "\t" << new_Username << endl;
    cout << setw(15) << left << "Password" << "\t" << new_Password << endl;
    cout << setw(15) << left << "Real Name" << "\t" << new_realName << endl;
    cout << setw(15) << left << "Email" << "\t" << new_Email << endl;
    cout << setw(15) << left << "Phone Number" << "\t" << new_PhoneNo << endl;
    cout << setw(15) << left << "Gender" << "\t" << new_Gender << endl;

    cout << "\n\n==================================================\n" << endl;
    cout << "Are you sure you want to register?\n[ 1 ]\tYes\n[ 2 ]\tNo" << endl;
    int choice;
    cin >> choice;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input" << endl;
        return showRegDetails(new_Username, new_Password, new_realName, new_Email, new_PhoneNo, new_Gender);
    }
    switch(choice){
        case 1:
            return;
            break;
        case 2:
            // return;                              //go back to main menu           
            break;
        default:
            cout << "Invalid input" << endl;
            return showRegDetails(new_Username, new_Password, new_realName, new_Email, new_PhoneNo, new_Gender);
    }
}


void regNewUser(){
    int choice;
    string new_Username, new_Password, new_realName, new_Email, new_PhoneNo, new_Gender, new_LastLoginDate, new_Id;
    cout <<   "+------------------------------------------------+" 
         << "\n|               Register New User                |"
         << "\n+------------------------------------------------+\n\n" << endl;
    // string newGenId = newId();
    new_Username = regUsername();
    new_Password = regPassword();
    new_realName = regRealName();
    new_Email = regEmail();
    new_PhoneNo = regPhoneNo();
    new_Gender = regGender();

    showRegDetails(new_Username, new_Password, new_realName, new_Email, new_PhoneNo, new_Gender);
    new_Id = newId();
    new_LastLoginDate = getCurrentDateString();
    cout << "--------------------------------------------------\n" << "\nYour User ID is " << new_Id << endl;
    cout << "Congratulations You Have Successfully Registered an Account!!" << endl;
    insertUser(new_Id,new_Username, new_Password, new_realName, new_Email, new_PhoneNo, new_Gender, new_LastLoginDate);
    //Back to Main Menu
}