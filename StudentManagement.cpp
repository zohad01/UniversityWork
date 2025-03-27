#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;               


class Student {
    string rollNum, name, fName, address, department, semester, gender, university, search;
    fstream file;

public:
    void addStudent();
    void viewAllStudents();
    void searchStudent();
    void removeStudent();  
};

int main() {
    
    char choice;
    Student obj;

    while (true) {  
        cout << "---------------------------" << endl;
        cout << "1- Add Student Record" << endl;
        cout << "2- View All Student Records" << endl;
        cout << "3- Search Student Record" << endl;
        cout << "4- Remove Student Record" << endl;  
        cout << "5- Exit" << endl;
        cout << "---------------------------" << endl;
        cin >> choice;

        switch (choice) {
            case '1':
                cin.ignore();
                obj.addStudent();
                break;
            case '2':
                cin.ignore();
                obj.viewAllStudents();
                break;
            case '3':
                cin.ignore();
                obj.searchStudent();
                break;
            case '4':
                cin.ignore();
                obj.removeStudent(); 
                break;
            case '5':
                cout << "Exiting the program... Goodbye!" << endl;
                return 0;  
            default:
                cout << "Invalid Choice...!" << endl;
        }
    }

    return 0;
}

void Student::addStudent() {
    cout << "Enter Student Roll Number: ";
    getline(cin, rollNum);
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Father's Name: ";
    getline(cin, fName);
    cout << "Enter Student Address: ";
    getline(cin, address);
    cout << "Enter Student Department: ";
    getline(cin, department);
    cout << "Enter Student Semester: ";
    getline(cin, semester);
    cout << "Enter Student Gender: ";
    getline(cin, gender);
    cout << "Enter Student University: ";
    getline(cin, university);

    
    file.open("students.txt", ios::out | ios::app);
    file << rollNum << "*" << name << "*" << fName << "*" << address << "*"
         << department << "*" << semester << "*" << gender << "*" << university << endl;
    file.close();
    cout << "Student added successfully!" << endl;
}

void Student::viewAllStudents() {
    file.open("students.txt", ios::in);
    if (!file) {
        cout << "No student records found." << endl;
        return;
    }

    while (getline(file, rollNum, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '*');
        getline(file, department, '*');
        getline(file, semester, '*');
        getline(file, gender, '*');
        getline(file, university);

        cout << "\nStudent Roll Number: " << rollNum << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Father's Name: " << fName << endl;
        cout << "Student Address: " << address << endl;
        cout << "Student Department: " << department << endl;
        cout << "Student Semester: " << semester << endl;
        cout << "Student Gender: " << gender << endl;
        cout << "Student University: " << university << endl;
    }
    file.close();
}

void Student::searchStudent() {
    cout << "Enter Student Roll Number to search: ";
    getline(cin, search);

    file.open("students.txt", ios::in);
    bool found = false;
    while (getline(file, rollNum, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '*');
        getline(file, department, '*');
        getline(file, semester, '*');
        getline(file, gender, '*');
        getline(file, university);

        if (rollNum == search) {
            found = true;
            cout << "\nStudent Roll Number: " << rollNum << endl;
            cout << "Student Name: " << name << endl;
            cout << "Student Father's Name: " << fName << endl;
            cout << "Student Address: " << address << endl;
            cout << "Student Department: " << department << endl;
            cout << "Student Semester: " << semester << endl;
            cout << "Student Gender: " << gender << endl;
            cout << "Student University: " << university << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student not found with Roll Number: " << search << endl;
    }

    file.close();
}

void Student::removeStudent() {
    cout << "Enter Student Roll Number to remove: ";
    getline(cin, search);

    
    file.open("students.txt", ios::in);
    if (!file) {
        cout << "No student records found." << endl;
        return;
    }


    fstream tempFile;
    tempFile.open("temp.txt", ios::out);

    bool found = false;

   
    while (getline(file, rollNum, '*')) {
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '*');
        getline(file, department, '*');
        getline(file, semester, '*');
        getline(file, gender, '*');
        getline(file, university);


        if (rollNum != search) {
            tempFile << rollNum << "*" << name << "*" << fName << "*" << address << "*"
                     << department << "*" << semester << "*" << gender << "*" << university << endl;
        } else {
            found = true; 
        }
    }

    if (found) {
        cout << "Student removed successfully!" << endl;
    } else {
        cout << "Student not found with Roll Number: " << search << endl;
    }

   
    file.close();
    tempFile.close();

   
    remove("students.txt");
    rename("temp.txt", "students.txt");
}
