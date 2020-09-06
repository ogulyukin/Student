#pragma once
#include <iostream>
#include <string>
#include "ClassStudent.h"

using namespace std;

void PrintWelcome()
{
    cout << "===============" << endl;
    cout << "=== Student ===" << endl;
    cout << "===============" << endl;
    cout << endl;
    cout << "****************************" << endl;
    cout << "(c) STEP IT Academy" << endl;
    cout << "email: starinin_a@itstep.org" << endl;
    cout << "****************************" << endl;
    cout << endl;
}

void PrintMenu()
{
    cout << "+++++++++++++++++++++++++++" << endl;
    cout << "Menu:" << endl;
    cout << "1. Show list of students" << endl;
    cout << "2. Add student to list" << endl;
    cout << "3. Change student details" << endl;
    cout << "4. Remove student from list" << endl;
    cout << "5. Clear all list" << endl;
    cout << "6. Export to file" << endl;
    cout << "0. Exit" << endl;
    cout << "+++++++++++++++++++++++++++" << endl;
}

void PrintError(string message)
{
    cout << "!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << "!!! E R R O R !!!" << endl;
    cout << "!!! " << message << " !!!" << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!" << endl;
    cout << endl;
}

void PrintExit()
{
    cout << endl;
    cout << "-----------------" << endl;
    cout << "--- Good byе! ---" << endl;
    cout << "-----------------" << endl;
    cout << endl;
}
void AddStudent(Student students[], const int size){
    for (int x = 0; x < size; x++){
        cout << "Enter info of student: " << endl;
        cout << "Last Name : "; cin >> students[x].lastName;
        cout << "First Name : ";cin >> students[x].firstName;
        cout << "Day Birth : "; cin >> students[x].dateBirth.day;
        cout << "Month of birth : "; cin >> students[x].dateBirth.month;
        cout << "Year of birth : "; cin >> students[x].dateBirth.year;
        //int age;
        //cout << "Age : "; cin >> age;
        students[x].SetAge(18);
        cout << "Faculty : "; cin >> students[x].faculty;
        cout << "Group : "; cin >> students[x].group;
        cout << "Stage : "; cin >> students[x].stage;
        cout << "Is study : "; //cin >>
        students[x].study = true;
    }
}