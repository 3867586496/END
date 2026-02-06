#include"gameMainLoop.h"
#include<windows.h>
#include<string>
#include<iostream>
#include<vector>



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

void dailyUpdate(){

}
//currentTime是指原来的时间，返回的时间是更新后的时间
time timeUpdate(time currentTime,int changedMinute){
    time updatedTime=currentTime;

    updatedTime.minute=(currentTime.minute+(changedMinute%60))%60;

    
    updatedTime.hour+=(currentTime.minute+changedMinute)/60;

    for(int i =0;i<(currentTime.minute+changedMinute)/60;i++){
        hourUpdate();
    }
    
    if(updatedTime.hour>=24){
        updatedTime.day+=updatedTime.hour/24;
        updatedTime.hour=updatedTime.hour%24;

        for(int i =0;i<updatedTime.hour/24;i++){
            dailyUpdate();
        }
    }
    return updatedTime;
}

/*
关于物品id
首先把所有的物品读入对应的类型组中，不同的物品处理方式有差异

*/

int exitGame(){
    return 0;
}



