#pragma once
#include <fstream>
#include <string>
#include "ClassStudent.h"
using namespace std;

void ExportToFile(string path, string str){
    ofstream file;
    file.open( path, ios::out | ios::trunc);
    if (!file.is_open()){
        //TODO if excrption
        //PrintError("Error opening file");
    }else{
        file << str << endl;
        file.close();
    }
}
void Export(Student students[], const int size){
    string temp;
    for (int x = 0; x < size; x++){
        temp += students[x].lastName + ";";
        temp += students[x].firstName + ";";
        temp += to_string(students[x].dateBirth.day) + ".";
        temp += to_string(students[x].dateBirth.month) + ".";
        temp += to_string(students[x].dateBirth.year) + ";";
        temp += to_string(students[x].GetAge()) + ";";
        temp += students[x].faculty + ";";
        temp += students[x].group + ";";
        temp += to_string(students[x].stage) + ";";
        temp += to_string(students[x].study) + "\n";
    }
    ExportToFile("student.csv", temp);
}
