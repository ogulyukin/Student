#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ClassStudent.h"

using namespace std;

string ImportFromFile(string path){
    ifstream file;
    string str;
    file.open( path, ios::in);

    if (!file.is_open()){
        //TODO if excrption
        //PrintError("Error opening file");
    }else {
        while (!file.eof()) {
            file >> str;
            //temp
            cout << str;

        }
    }
        file.close();
    return str;

};
string GetField(string str, int pos01, int pos02){
    string field = str.substr(pos01,pos02-1);
    return field;
}
int GetNextPos(string str, int pos01, char symbol){
    int pos02 = str.find(symbol, pos01);
    return pos02;
}
int GetIntData(string str, int pos01, int pos02){
    int datePart = stoi(str.substr(pos01, pos02-1));
    return datePart;
}
int GetSize(string temp){
    int pos01 = 0;
    int pos02;
    int count= 0;
    while (pos02 != -1) {
        pos02 = GetNextPos(temp, pos01, '\n');
        pos01 = pos02 + 1;
        if (pos02 != -1)
            count++;
    }

    return count;
}
//todo доделать здесь
int Import(Student students[],int size){
    string temp;
    int pos01 = 0;
    int pos02;
    int age = 18;
    int study;
    temp = ImportFromFile("student.csv");
    for (int x = 0; x < size; x++){
        pos02 = GetNextPos(temp, pos01, ';');
        students[x].lastName = GetField(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ';');
        students[x].firstName = GetField(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, '.');
        students[x].dateBirth.day = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, '.');
        students[x].dateBirth.month = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, '.');
        students[x].dateBirth.year = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ';');
        age = GetIntData(temp, pos01, pos02);
        students[x].SetAge(age);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ';');
        students[x].faculty = GetField(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ';');
        students[x].group = GetField(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ';');
        students[x].stage = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, '\n');
        study = GetIntData(temp, pos01, pos02);
        students[x].study = (!study) ? false:true;
        pos01 = pos02 + 1;
    }
}
