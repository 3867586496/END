#include<iostream>
#include<string>
#include"save.h"
#include"menu.h"
#include"gamemainloop.h"

double gameLevelFactor=0;

bool isEndlessMode=false;
bool isStoryMode=false;

bool isContinueGame=true;


int main(){

    setShowMode();

    menu mainMenu;

    while(isContinueGame){
        mainMenu.showCurrentMenu();
        
        mainMenu.handleMenuInput(isContinueGame);


    }

    return 0;
}