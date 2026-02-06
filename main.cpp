#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include"save.h"
#include"menu.h"
#include"gamemainloop.h"





int main(){

    setShowMode();

    menu mainMenu;
    while(1){
        mainMenu.showCurrentMenu();
        
        std::string userChoose= getInputChoose();


    }
}