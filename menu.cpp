#include<iostream>
#include<string>
#include<vector>
#include"menu.h"
#include"gamemainloop.h"
#include<fstream>

extern bool isStoryMode;
extern bool isEndlessMode;

extern double gameLevelFactor;

//定义变量
std::string menu::menuPosition;
std::vector<menuReferenceList> menu::menuList;
//显示菜单
void menu::showCurrentMenu(){
    if (menu::searchThisMenuNameIndex()!=-1){
        std::cout<<menu::menuList[menu::searchThisMenuNameIndex()].thisMenuContent<<std::endl;
    }
    else{
        std::cout<<"没有搜索到。"<<std::endl;
    }
    
}

int menu::searchThisMenuNameIndex(){
    for(int i =0;i<menu::menuList.size();i++){
        if(menu::menuList[i].thisMenuName==menu::menuPosition){
            return i;
        }
    }
    return -1;
}
//读取列表
void menu::readMenuList(){
    std::string temp;
    std::ifstream inReadMenu("datas/menu.txt",std::ios::in);

    if(!inReadMenu){

        std::cout<<"文件打开失败"<<std::endl;

    }

    int menuIndex=0;

    while(std::getline(inReadMenu,temp)){
        size_t index=temp.find(":");

        if (menuIndex >= menu::menuList.size()) {
            menu::menuList.resize(menuIndex + 1);
        }
        if(temp.substr(0,index)=="thisMenuName"){
            menu::menuList[menuIndex].thisMenuName=temp.substr(index+1,temp.size());
        }

        if(temp.substr(0,index)=="thisMenuContent"){
            menu::menuList[menuIndex].thisMenuContent=temp.substr(index+1,temp.size());
        }
        if(menu::menuList[menuIndex].thisMenuName!=""&&menu::menuList[menuIndex].thisMenuContent!=""){
            menuIndex++;
        }
        
    }

    inReadMenu.close();

    
    std::cout << "===== 菜单列表读取结果 =====" << std::endl;
    std::cout << "菜单数量：" << menu::menuList.size() << std::endl;
    for (size_t i = 0; i < menu::menuList.size(); i++) {
        std::cout << "索引 " << i << "：name = [" << menu::menuList[i].thisMenuName << "], content = [" << menu::menuList[i].thisMenuContent << "]" << std::endl;
    }
    std::cout << "==========================" << std::endl;
}

    menu::menu(){
        menu::menuPosition = "startMenu";
        menu::readMenuList();
}
//处理菜单的操作
void menu::handleMenuInput(bool &isContinueGame){
    if(menuPosition=="startMenu"){
        handleStartMenuInput(getInputChoose(),isContinueGame);
    }
    else if(menuPosition=="chooseGameModeMenu"){
        handleChooseGameModeMenuInput(getInputChoose());
    }
    
}

void menu::handleStartMenuInput(std::string operation,bool &isContinueGame){
    if(operation=="1"){
        menuPosition="chooseGameModeMenu";
        menu::showCurrentMenu();
    }else if(operation=="5"){
        isContinueGame = false;
    }
    else{
        std::cout<<"非法操作"<<std::endl;
    }

    // if(operation=="2"){
    //     menuPosition="chooseGameModeMenu";
    // }

    // if(operation=="3"){
    //     menuPosition="chooseGameModeMenu";
    // }

    // if(operation=="4"){
    //     menuPosition="chooseGameModeMenu";
    // }
    
}

void menu::handleChooseGameModeMenuInput(std::string operation){
    if(operation=="1"){
        menuPosition="chooseGameLevelMenu";
        menu::showCurrentMenu();
        isStoryMode=true;
    }
    else if(operation=="2"){
        menuPosition="chooseGameLevelMenu";
        menu::showCurrentMenu();
        isEndlessMode=true;
    }
    else{
        std::cout<<"非法操作"<<std::endl;
    }
}