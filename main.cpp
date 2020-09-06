#include <iostream>
#include "ClassStudent.h"
#include "CLI.h"
#include "ExportToFile.h"

using namespace std;

int ExeptionAge()
{
    int age;
    do
    {
        cout << "Invalid age" << endl;
        cout << "Enter age: "; cin >> age;
    } while (age <= 10 || age > 80);
    return age;
}

int main()
{
    const int SIZE = 3;
    Student students[SIZE];
    PrintWelcome();

    char symbol;
    do {
        PrintMenu();
        cout << "Enter menu item - "; cin >> symbol;

        switch (symbol)
        {
            case '1':
                break;
            case '2':
                AddStudent(students, SIZE);
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                Export(students, SIZE);
                break;
            case '0':
                PrintExit();
                break;
            default:
                PrintError("Invalid menu item");
                break;
        }
    } while (symbol != '0');

    system("pause");
}

