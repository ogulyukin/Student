#pragma once
#include <iostream>
#include <string>

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
