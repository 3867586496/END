#include"gameMainLoop.h"
#include<windows.h>
#include<string>
#include<iostream>
#include<vector>
#include<chrono>
#include<random>

extern double gameDevelopmentFactor;

void randomInitialization(){
    std::mt19937 randomMaker(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<int>probabilityProducer(0,1);
}

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
gameTime timeUpdate(gameTime currentTime,int changedMinute){
    gameTime updatedTime=currentTime;

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

gameTime setTime(int day,int hour,int minute){
    gameTime time={day,hour,minute};
    return time;
}

void calculateGameDevelopmentFactor(gameTime currentTime){

};






