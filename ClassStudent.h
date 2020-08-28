#pragma once
#include <string>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

class Student
{
public:
    string lastName; //Фамилия
    string firstName; //Имя
    Date dateBirth; //Дата рождения
    string faculty; //Факультет
    string group; //Группа
    int stage; //Курс
    bool study; //Учится?
    int scores[5];  // кол-во оценок
    void SetAge(int age); //Установка занчения возраста
    int GetAge(); //Получение значения возраста
    double GetAverageBall(); // Получение значение среднего балла


private:
    double averageBall; // Средний балл
    int age; //Возраст
    void CalculateAverageBall(); // Расчет среднего балла

};

void Student::SetAge(int age)
{
    if (age <= 10  || age > 80) {
        throw -1;
    } else {
        this->age = age;
    }
}

int Student::GetAge()
{
    return age;
}

void Student::CalculateAverageBall()
{
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];
    }
    averageBall = sum/5;
}

double Student::GetAverageBall()
{
    return averageBall;
}