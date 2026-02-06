#include<iostream>
#include<string>
#include"save.h"
#include"menu.h"
#include"gamemainloop.h"





int main(){

    setShowMode();

    bool isContinueGame=1;
    menu mainMenu;

    while(isContinueGame){
        mainMenu.showCurrentMenu();
        
        mainMenu.handleMenuInput(isContinueGame);


    }

    return 0;
}