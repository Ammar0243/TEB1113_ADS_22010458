#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string contact;
    string email;
};

int main() {
    const int SIZE = 5;
    Student student[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter student data " << (i + 1) << ":\n";

        cout << "Id: ";
        cin >> student[i].id;
        cin.ignore(); 

        cout << "Name: ";
        getline(cin, student[i].name);

        cout << "Contact: ";
        getline(cin, student[i].contact);

        cout << "Email: ";
        getline(cin, student[i].email);
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "ID: " << student[i].id << endl;
        cout << "Name: " << student[i].name << endl;
        cout << "Contact: " << student[i].contact << endl;
        cout << "Email: " << student[i].email << endl;
        cout << endl;
    }

    return 0;
}