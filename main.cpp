#include <iostream>
#include "ClassStudent.h"
#include "CLI.h"
#include "ExportToFile.h"
#include "ImportFromFile.h"
#include <vector>

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
    int size = 0;
    string forFile;
    //Student students[3];
    forFile = ImportFromFile("student.csv");
    size = GetSize(forFile);
    cout << endl << size << endl;
    Student *students = new Student[size];
    Import(students, size);
    PrintWelcome();

    char symbol;
    do {
        PrintMenu();
        cout << "Enter menu item - "; cin >> symbol;

        switch (symbol)
        {
            case '1':
                for (int x = 0; x < size; x++){
                    cout << "*********************" << endl;
                    students[x].ShowStudent();
                }
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
    delete [] students;

    system("pause");
}

