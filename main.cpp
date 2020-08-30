#include <iostream>
#include "ClassStudent.h"
#include "CLI.h"

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
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '0':
                cout << "Good byе!" << endl;
                break;
            default:
                cout << "Invalid menu item" << endl;
                break;
        }
    } while (symbol != '0');

    system("pause");
}

