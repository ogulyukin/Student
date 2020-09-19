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
        PrintError("Error opening file");
    }else {
        while (!file.eof()) {
            file >> str;
            //temp
            cout << str << endl; //to delete

        }
    }
        file.close();
    return str;

};
string GetField(string str, int pos01, int pos02){
    int len = pos02 - pos01;
    string field = str.substr(pos01,len);
    cout << field << endl; //to delete
    return field;
}
int GetNextPos(string str, int pos01, string symbol){
    int pos02 = str.find(symbol, pos01);
    cout << "pos01 = " << pos01 << " pos02 =  " << pos02 << endl; //to delete
    return pos02;
}
int GetIntData(string str, int pos01, int pos02){
    int len = pos02 - pos01;
    string subStr = str.substr(pos01, len);
    cout << "GetIntData subStr=" << subStr << endl; //to delete
    int datePart = stoi(subStr);
    return datePart;
}
int GetSize(string temp){
    /*int pos01 = 0;
    int pos02;
    int count= 0;
    while (pos02 != -1) {
        pos02 = GetNextPos(temp, pos01, '\n');
        pos01 = pos02 + 1;
        cout << "Get size : " << count << endl;
        cout << pos02 << endl;
        if (pos02 != -1)
            count++;
    }
    return count*/
    int pos = temp.find("EndOfFile:");
    pos += 10;
    string temp01 = temp.substr(pos);
    cout << "temp01: " << temp01 << endl;
    int size = stoi(temp01);
    return size;
}
//todo доделать здесь
void Import(Student students[],int size){
    string temp;
    int pos01 = 0;
    int pos02;
    int age = 18;
    int study;
    temp = ImportFromFile("student.csv");
    if (temp == ""){
        PrintError("Error no data to read from file!");
        return;
    }
    for (int x = 0; x < size; x++){
        cout << "Заход № " << x << endl;
        pos02 = GetNextPos(temp, pos01,";");
        students[x].lastName = GetField(temp, pos01, pos02);
        cout << "Фамилия:" << students[x].lastName << endl; //to delete
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ";");
        students[x].firstName = GetField(temp, pos01, pos02);
        cout << "Имя:" << students[x].firstName << endl; //to delete
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ".");
        students[x].dateBirth.day = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ".");
        students[x].dateBirth.month = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ";");
        students[x].dateBirth.year = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ";");
        age = GetIntData(temp, pos01, pos02);
        students[x].SetAge(age);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01,";");
        students[x].faculty = GetField(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ";");
        students[x].group = GetField(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ";");
        students[x].stage = GetIntData(temp, pos01, pos02);
        pos01 = pos02 + 1;
        pos02 = GetNextPos(temp, pos01, ";");
        study = GetIntData(temp, pos01, pos02);
        students[x].study = (!study) ? false:true;
        pos01 = pos02 + 1;
    }
}

