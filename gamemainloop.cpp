#include"gameMainLoop.h"
#include<windows.h>
#include<string>
#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<fstream>

extern double gameDevelopmentFactor;

extern std::vector<consumables> consumablesList;

extern bool isInitialize;

void randomInitialization(){
    int inputSeed=0;
    std::cout<<"请输入种子："<<std::endl;
        while(!(std::cin>>inputSeed)){
            std::cin.clear();
            std::cin.std::istream::ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"请正常输入种子（1-2,147,483,647）："<<std::endl;
        }

    int normalSeed=std::chrono::system_clock::now().time_since_epoch().count();
    if(inputSeed==0){
        srand(normalSeed);
        rand();
        std::mt19937 randomMaker(rand());
    }else{
        std::mt19937 randomMaker(inputSeed);
    }
    
    std::uniform_real_distribution<double>probabilityProducer(0.0,1.0);
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
    randomInitialization();
    readConsumables(consumablesList);
    isInitialize=true;
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
/*
pattren:
    if(temp.substr(0,conlonIndex)==""){
           
        }

    if(temp.substr(0,conlonIndex)==""){
           consumablesList[listIndex]=temp.substr(conlonIndex+1);
        }
*/
void readConsumables(std::vector<consumables> &consumablesList){
    std::string temp;
    std::ifstream inReadConsumables("datas/consumables.txt",std::ios::in);

    if(!inReadConsumables){

        std::cout<<"文件打开失败"<<std::endl;

    }

    int listIndex=0;

    consumablesList.resize(listIndex+2);
    while(std::getline(inReadConsumables,temp)){

        if(temp==""){
            listIndex++;
            consumablesList.resize(listIndex+2);
            continue;
        }

        size_t conlonIndex=temp.find(":");
        
        

        if(temp.substr(0,conlonIndex)=="name"){
           consumablesList[listIndex].name=temp.substr(conlonIndex+1);
        }

        if(temp.substr(0,conlonIndex)=="level"){
           consumablesList[listIndex].level=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)=="satiety"){
           consumablesList[listIndex].satiety=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)=="thirst"){
           consumablesList[listIndex].thirst=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)=="health"){
           consumablesList[listIndex].health=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)=="spaceTaken"){
           consumablesList[listIndex].spaceTaken=stoi(temp.substr(conlonIndex+1));
        }

        
        
        
    }

    inReadConsumables.close();
    //测试
    std::cout<<listIndex<<std::endl;
    std::cin.get();
    std::cin.get();

}




