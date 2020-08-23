#include <iostream>
#include "ClassStudent.h"

using namespace std;

int ExeptionAge()
{
    int age;
    cout << "Invalid age" << endl;
    do
    {
        cout << "Enter age: "; cin >> age;
    } while (age <= 10 || age > 80);
    return age;
}

int main()
{
    Student student;

    int age;
    try
    {
        cout << "Enter age: "; cin >> age;
        student.SetAge(age);
    }
    catch (int e)
    {
        if (e == -1)
        {
            student.SetAge(ExeptionAge());
        }
    }
    cout << student.GetAge() << endl;
}

