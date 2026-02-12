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
extern std::vector<weapon> weaponList;
extern std::vector<armor> armorList;
extern std::vector<material> materialList;

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
    readWeapon(weaponList);
    readWeapon(weaponList);
    readMaterial(materialList);

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
           List[listIndex]=temp.substr(conlonIndex+1);
        }
*/
void readConsumables(std::vector<consumables> &consumablesList){
    std::string temp;
    std::ifstream inReadConsumables("datas/consumables.txt",std::ios::in);

    if(!inReadConsumables){

        std::cout<<"文件打开失败"<<std::endl;
        return;
    }

    int listIndex=0;

    consumablesList.resize(listIndex+2);
    while(std::getline(inReadConsumables,temp)){

        if(temp==""){
            listIndex++;
            consumablesList.resize(listIndex+2);
            continue;
        }

        if(temp.find(":")==-1){
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
    // std::cout<<listIndex<<std::endl;
    // std::cin.get();
    // std::cin.get();

}
void readWeapon(std::vector<weapon> &weaponList){
    std::string temp;
    std::ifstream inReadWeapon("datas/weapon.txt",std::ios::in);

    if(!inReadWeapon){

        std::cout<<"文件打开失败"<<std::endl;
        return;
    }

    int listIndex=0;

    weaponList.resize(listIndex+2);
    while(std::getline(inReadWeapon,temp)){

        if(temp==""){
            listIndex++;
            weaponList.resize(listIndex+2);
            continue;
        }
        
        if(temp.find(":")==-1){
            continue;
        }

        size_t conlonIndex=temp.find(":");

        if(temp.substr(0,conlonIndex)=="damage"){
           weaponList[listIndex].damage=stoi(temp.substr(conlonIndex+1));
        }
        
        if(temp.substr(0,conlonIndex)=="isRanged"){
           weaponList[listIndex].isRanged=stoi(temp.substr(conlonIndex+1));
        }
        
        if(temp.substr(0,conlonIndex)=="level"){
           weaponList[listIndex].level=stoi(temp.substr(conlonIndex+1));
        }
        
        if(temp.substr(0,conlonIndex)=="name"){
           weaponList[listIndex].name=temp.substr(conlonIndex+1);
        }
        
        if(temp.substr(0,conlonIndex)=="spaceTaken"){
           weaponList[listIndex].spaceTaken=stoi(temp.substr(conlonIndex+1));
        }
        
        if(temp.substr(0,conlonIndex)=="useStamina"){
           weaponList[listIndex].useStamina=stoi(temp.substr(conlonIndex+1));
        }

    }

    inReadWeapon.close();
    //测试
    // std::cout<<listIndex<<std::endl;
    // std::cin.get();
    // std::cin.get();

}
void readArmor(std::vector<armor> &armorList){
    std::string temp;
    std::ifstream inReadArmor("datas/armor.txt",std::ios::in);

    if(!inReadArmor){

        std::cout<<"文件打开失败"<<std::endl;
        return;
    }

    int listIndex=0;

    armorList.resize(listIndex+2);
    while(std::getline(inReadArmor,temp)){

        if(temp==""){
            listIndex++;
            armorList.resize(listIndex+2);
            continue;
        }
        
        if(temp.find(":")==-1){
            continue;
        }

        size_t conlonIndex=temp.find(":");

        if(temp.substr(0,conlonIndex)=="armorValue"){
           armorList[listIndex].armorValue=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)=="level"){
           armorList[listIndex].level=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)=="name"){
           armorList[listIndex].name=temp.substr(conlonIndex+1);
        }

        if(temp.substr(0,conlonIndex)=="spaceTaken"){
           armorList[listIndex].spaceTaken=stoi(temp.substr(conlonIndex+1));
        }

    }

    inReadArmor.close();
    //测试
//     std::cout<<listIndex<<std::endl;
//     std::cin.get();
//     std::cin.get();

}
void readMaterial(std::vector<material> &materialList){
    std::string temp;
    std::ifstream inReadMaterial("datas/material.txt",std::ios::in);

    if(!inReadMaterial){

        std::cout<<"文件打开失败"<<std::endl;
        return;
    }

    int listIndex=0;

    materialList.resize(listIndex+2);

    while(std::getline(inReadMaterial,temp)){

        if(temp==""){
            listIndex++;
            materialList.resize(listIndex+2);
            continue;
        }
        
        if(temp.find(":")==-1){
            continue;
        }

        size_t conlonIndex=temp.find(":");

        if(temp.substr(0,conlonIndex)=="name"){
           materialList[listIndex].name=temp.substr(conlonIndex+1);
        }

        if(temp.substr(0,conlonIndex)==""){
           materialList[listIndex].level=stoi(temp.substr(conlonIndex+1));
        }

        if(temp.substr(0,conlonIndex)==""){
           materialList[listIndex].spaceTaken=stoi(temp.substr(conlonIndex+1));
        }

    }

    inReadMaterial.close();
    //测试
    // std::cout<<listIndex<<std::endl;
    // std::cin.get();
    // std::cin.get();

}

void stratNewgame(){
    
}