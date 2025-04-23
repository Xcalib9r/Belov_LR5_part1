#ifndef _BELOV_MATHTASK_H_
#define _BELOV_MATHTASK_H_

#include <string>
#include <iostream>
using namespace std;

//функция контроля вводимых данных
bool UserInput(string input)
{
    //если строка пустая - ввод некорректен
    if(input.empty()) return false;
    bool onlyDigits=true;
    for(char c:input){
        if(!isdigit(c)){
            onlyDigits=false;
            break;
        }
    }
    //попытаться
    try{
        //преобразование введенного значения в тип
        int number = stoi(input);
        if(number<0) return false;
        if(!onlyDigits) return false;
    }
    catch(...) //если возникла ошибка в блоке try
    {return false;}
    return true;
}
//метод ввода данных
void EnterDigit(int& varLink, const string& label){
    string raw_input;
    cout<<label<<" = ";
    getline(cin,raw_input);
    while(!UserInput(raw_input)){
        cout<<label<<" = ";
        getline(cin,raw_input);
    }
    varLink=stoi(raw_input);
}

//вычисление плозади прямоугольника 
int CalcRectangleArea(int NumberA, int NumberB){
    return NumberA*NumberB;
}
#endif