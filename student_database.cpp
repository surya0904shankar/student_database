

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;


void admin_login();
void add_student();
void delete_student();
void view_student();
void student_login();



void admin_login()
{
    string name;
    string password;
    cout << "enter the name of the admin" << endl;
    cin >> name;
    cout << "enter the password of the admin" << endl;
    cin >> password;
    if (name == "admin" && password == "srm")
    {
        cout << "login successful" << endl;
        cout << "1.add student" << endl;
        cout << "2.delete student" << endl;
        cout << "3.view student" << endl;
        cout << "4.exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            delete_student();
            break;
        case 3:
            view_student();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "invalid choice" << endl;
            break;
        }
    }
    else
    {
        cout << "invalid login" << endl;
    }
}

void add_student()
{
    string name;
    string roll_no;
    string password;
    string attendance;
    string marks;
    cout << "enter the name of the student" << endl;
    cin >> name;
    cout << "enter the roll no of the student" << endl;
    cin >> roll_no;
    cout << "enter the password of the student" << endl;
    cin >> password;
    cout << "enter the attendance of the student" << endl;
    cin >> attendance;
    cout << "enter the marks of the student" << endl;
    cin >> marks;
    ofstream file;
    file.open("student.csv", ios::app);
    file << name << "," << roll_no << "," << password << "," << attendance << "," << marks << endl;
    file.close();
}

void delete_student()
{
    string name;
    string roll_no;
    string password;
    string attendance;
    string marks;
    cout << "enter the roll no of the student" << endl;
    cin >> roll_no;
    ifstream file;
    file.open("student.csv");
    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> result;
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }
        if (result[1] != roll_no)
        {
            lines.push_back(line);
        }
    }
    file.close();
    ofstream file1;
    file1.open("student.csv");
    for (int i = 0; i < lines.size(); i++)
    {
        file1 << lines[i] << endl;
    }
    file1.close();}
    
void view_student()
{
    string name;
    string roll_no;
    string password;
    string attendance;
    string marks;
    cout << "enter the roll no of the student" << endl;
    cin >> roll_no;
    ifstream file;
    file.open("student.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> result;
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }
        if (result[1] == roll_no)
        {
            cout << "name:" << result[0] << endl;
            cout << "roll no:" << result[1] << endl;
            cout << "password:" << result[2] << endl;
            cout << "attendance:" << result[3] << endl;
            cout << "marks:" << result[4] << endl;
        }
    }
    file.close();
}

int main(){
{
    cout << "1.admin" << endl;
    cout << "2.student" << endl;
    cout << "3.exit" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        admin_login();
        break;
    case 2:
        view_student();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "invalid choice" << endl;
        break;
    }
}}
