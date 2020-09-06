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
    int grades[5]; //Оценки
    void SetAge(int age); //Установка занчения возраста
    int GetAge(); //Получение значения возраста
    double GetAverageGrade(); //Получить среднюю оценку
private:
    double averageGrade; //Средеяя оценка
    int age; //Возраст
    void SetAverageGrade(); //расчет средней оценки
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
double Student::GetAverageGrade() {
    return averageGrade;
}
void Student::SetAverageGrade() {
    int sum = 0;
    for (int x = 0; x < 5; x++){
        sum += averageGrade[x];
    }
    averageGrade = sum / 5;
}