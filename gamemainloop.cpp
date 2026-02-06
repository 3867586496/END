#include"gameMainLoop.h"
#include<windows.h>
#include<string>
#include<iostream>



void setShowMode(){

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

void clearConsole(){
    system("cls");
}

//输入用户操作
std::string getInputChoose(){
    std::string temp;
    std::cout<<"请输入操作："<<std::endl;
    std::cin>>temp;
    return temp;
}

void initialize(){

}

void hourUpdate(){

}

void daylyUpdate(){

}

/*
关于物品id
首先把所有的物品读入对应的类型组中，不同的物品处理方式有差异

*/

int exitGame(){
    return 0;
}



